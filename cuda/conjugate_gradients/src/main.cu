#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cuda_runtime.h>
#include "main.cuh"
#include "conjugateGradient.cuh"
#include "blocks.cuh"
#include "abort.cuh"
#include "allocDevMem.cuh"
#include "device_launch_parameters.h"


#define systemSize 1000
#define nthreads_reduction 128

int main(){
      //host/device allocations
      ConjugateGradientDataPtrs ptr;

      ptr.hostPtr = NULL; 
      allocHostMemorySpace(ptr.hostPtr);

      ptr.deviceData = NULL; 
      allocDeviceMemorySpace(ptr.deviceData);

      ptr.devicePtr = NULL;
      createDevicePtr(ptr.devicePtr, ptr.deviceData);

      //generate a linear system (Ax=b) with known solution
      formEqSystem(ptr);

      //solve with conjugate gradient
      constexpr int maximum_iterations = 10000;
      constexpr double stopping_criterior = -16;
      conjugatGradientSolver(ptr, maximum_iterations, stopping_criterior);

      //host/device deallocations
      freeHostMemory(ptr.hostPtr);
      freeDeviceMemory(ptr.deviceData);
      destroyDevicePtr(ptr.devicePtr);
}

// --------------------------------------------------------------------------------------
//                             H O S T  -  F U N C T I O N S
// --------------------------------------------------------------------------------------
void allocHostMemorySpace(ConjugateGradientData*& hostPtr){
      constexpr int nbThreads = nthreads_reduction;
      constexpr int nbBlocks  = getBlocks(nbThreads, systemSize);

      hostPtr = new ConjugateGradientData();

      hostPtr->mult1 = (double*)malloc(sizeof(double)); *(hostPtr->mult1) = 0.;
      hostPtr->mult2 = (double*)malloc(sizeof(double)); *(hostPtr->mult2) = 0.;

      hostPtr->alpha = (double*)malloc(sizeof(double)); *(hostPtr->alpha) = 0.;
      hostPtr->beta  = (double*)malloc(sizeof(double)); *(hostPtr->beta)  = 0.;

      hostPtr->projection = NULL;
      hostPtr->direction  = NULL;
      hostPtr->residual   = NULL;

      hostPtr->rhs     = NULL;
      hostPtr->diag    = NULL;
      hostPtr->offDiag = NULL;

      hostPtr->solution = (double*)malloc(systemSize*sizeof(double));
      hostPtr->aux      = (double*)malloc(nbBlocks  *sizeof(double));

      for (int i=0; i<systemSize; i++) {hostPtr->solution[i] = 0.;}
}

void allocDeviceMemorySpace(ConjugateGradientData*& deviceData){
      //allocate enough GPU memory for deviceData members
      deviceData = (ConjugateGradientData*)GPUalloc(sizeof(ConjugateGradientData), "deviceData");
}

void createDevicePtr(ConjugateGradientData*& devicePtr, ConjugateGradientData*& deviceData){
      devicePtr = (ConjugateGradientData*)GPUalloc(deviceData, sizeof(ConjugateGradientData), "devicePtr");
}

void freeHostMemory(ConjugateGradientData*& hostPtr){
      //deallocate hostPtr members from CPU memory
      if (hostPtr) free(hostPtr); hostPtr = NULL;
}

void freeDeviceMemory(ConjugateGradientData*& deviceData){
      //deallocate hostPtr members from GPU memory
      if (deviceData) cudaFree(deviceData); deviceData = NULL;
}

void destroyDevicePtr(ConjugateGradientData*& devicePtr){
      if (devicePtr) cudaFree(devicePtr); devicePtr = NULL;
}

void formEqSystem(ConjugateGradientDataPtrs& ptr){
      // Generate a tridiagonal Symmetric Positive Definite square matrix A :
      // --------------------------------------------------------------------
      const int nthr  = 128;
      const int nblck = getBlocks(nthr,systemSize);

      getSPD_GPU<<<nblck,nthr>>>(ptr.devicePtr);
      //check("getSPD_GPU failed");
}

void conjugatGradientSolver(ConjugateGradientDataPtrs& ptr, const int maximum_iterations, const double stopping_criterior){
      std::ofstream file("cg.conv", std::ios::out | std::ios::trunc);

      initSolution          (ptr);
      computeResidual       (ptr);
      initConjugateDirection(ptr);

      for (int iter=0; iter<maximum_iterations; iter++){
            matVec    (ptr, _Direction_, _Projection_);
            dotProduct(ptr, _Direction_, _Projection_, _Mult2_);
            dotProduct(ptr, _Residual_ , _Residual_  , _Mult1_);
            computeAlpha(ptr);

            const double residual = log10( sqrt(*ptr.hostPtr->mult1) + 1.E-21 );

            if (residual < stopping_criterior || iter%10 == 0 || iter == maximum_iterations-1){
                  std::cout << std::setw( 8) << iter     << " " << std::setw(15) << residual << std::endl;
            }

            file << std::setw( 8) << iter     << " " << std::setw(15) << residual << "\n";

            if (residual < stopping_criterior){
                  std::cout << "# Conjugate Gradient converged !!! \n"; break;
            }

            updateSolution(ptr);
            updateResidual(ptr);

            dotProduct (ptr, _Residual_, _Residual_, _Mult2_);
            computeBeta(ptr);

            updateConjugateDirection(ptr);
      }
      file.close();

      writeSolution(ptr);
}

void initSolution(ConjugateGradientDataPtrs& ptr){
      const int nthr  = 128;
      const int nblck = getBlocks(nthr,systemSize);
      
      initSolutionGPU<<<nblck,nthr>>>(ptr.devicePtr);
      //check("initSolutionGPU failed");
}

void computeResidual(ConjugateGradientDataPtrs& ptr){
      const int nthr  = 128;
      const int nblck = getBlocks(nthr,systemSize);

      computeResidualGPU<<<nblck,nthr>>>(ptr.devicePtr);
      //check("computeResidualGPU failed");
}

void initConjugateDirection(ConjugateGradientDataPtrs& ptr){
      const int nthr  = 128;
      const int nblck = getBlocks(nthr,systemSize);

      initConjugateDirectionGPU<<<nblck,nthr>>>(ptr.devicePtr);
      //check("initConjugateDirectionGPU failed");
}

void dotProduct(ConjugateGradientDataPtrs& ptr, ConjugateGradientEnum A, ConjugateGradientEnum B, ConjugateGradientEnum C){
      //     Ipologiste to esoteriko ginomeno ton dianismaton A kai B. To apotelesma na 
      // filaxthei sti scalar metabliti C pou prepei gnorizoun toso i CPU oso kai i GPU.
      // 
    const int nthr = 128;
    const int nblck = getBlocks(nthr, systemSize);

    matVec();
      //
      // B O I T H E I A :
      //
      //   ta "ptr.hostPtr->get(A)", "ptr.hostPtr->get(B)" kai "ptr.hostPtr->get(C)" sas
      // girizoun tous CPU pointers ton dianismaton A kai B kai tis scalar posotitas C
      // antistoixa.
      //
      //   omoia ta "ptr.deviceData->get(A)", "ptr.deviceData->get(B)" kai "ptr.deviceData->get(C)"
      // sas girizoun tous antistoixous GPU pointers. Pointers diladi pou deixnoun se theseis
      // mnimis tis GPU
      //
}

void matVec(ConjugateGradientDataPtrs& ptr, ConjugateGradientEnum A, ConjugateGradientEnum B){
      const int nthr  = 128;
      const int nblck = getBlocks(nthr,systemSize);

      matVecGPU<<<nblck,nthr>>>(ptr.deviceData->get(_Diag_), ptr.deviceData->get(_OffDiag_), ptr.deviceData->get(A), ptr.deviceData->get(B));
      //check("matVecGPU failed");
}

void computeAlpha(ConjugateGradientDataPtrs& ptr){
      *ptr.hostPtr->alpha = *ptr.hostPtr->mult1 / *ptr.hostPtr->mult2;
}

void computeBeta(ConjugateGradientDataPtrs& ptr){
      *ptr.hostPtr->beta = *ptr.hostPtr->mult2 / *ptr.hostPtr->mult1;
}

void updateSolution(ConjugateGradientDataPtrs& ptr){
      const int nthr  = 128;
      const int nblck = getBlocks(nthr, systemSize);

      updateSolutionGPU<<<nblck,nthr>>>(ptr.devicePtr, *ptr.hostPtr->alpha);
      //check("updateSolutionGPU failed");
}

void updateResidual(ConjugateGradientDataPtrs& ptr){
      const int nthr  = 128;
      const int nblck = getBlocks(nthr, systemSize);

      updateResidualGPU<<<nblck,nthr>>>(ptr.devicePtr, *ptr.hostPtr->alpha);
      //check("updateResidualGPU failed");
}

void updateConjugateDirection(ConjugateGradientDataPtrs& ptr){
      const int nthr  = 128;
      const int nblck = getBlocks(nthr,systemSize);

      updateConjugateDirectionGPU<<<nblck,nthr>>>(ptr.devicePtr, *ptr.hostPtr->beta);
      //check("updateConjugateDirectionGPU failed");
}

void writeSolution(ConjugateGradientDataPtrs& ptr){
      std::ofstream file;
      file.open("cg.res",std::ios::out | std::ios::trunc);

      cudaError_t err = cudaMemcpy(ptr.hostPtr->solution, ptr.deviceData->solution, systemSize*sizeof(double), cudaMemcpyDeviceToHost);
      if (err != cudaSuccess) Stop("memory copy failed");

      for (int i=0; i<systemSize; i++){
            file << std::setw(15) << ptr.hostPtr->solution[i] << "\n";
      }

      file.close();
}


// --------------------------------------------------------------------------------------
//                                    K E R N E L S
// --------------------------------------------------------------------------------------
__global__ void getSPD_GPU(ConjugateGradientData* data){
      const int index = blockIdx.x*blockDim.x + threadIdx.x;
      if (index >= systemSize) return;

      constexpr double h    = 0.05;
      constexpr double T0   = 300.0;
      constexpr double Tinf = 200.0;
      constexpr double Tend = 400.0;
      constexpr double len  =  10.0;

      constexpr double dx   = len / double(systemSize-1);
      constexpr double fac  = h*dx*dx;

      // initialize solution :
      //double sol = 0.;
      //if (index == 0)            sol = T0;   // Dirichlet condition
      //if (index == systemSize-1) sol = Tend; // Dirichlet condition

      //data->solution[index] = sol;

      // LHS / RHS :
      double rhs     = Tinf* fac;
      double diag    = 2.  + fac;
      double offDiag =-1.;

      if (index == 0           ) { rhs = T0;   diag = 1.; }
      if (index == systemSize-1) { rhs = Tend; diag = 1.; }

      data->rhs [index] = rhs;
      data->diag[index] = diag;

      if (index < systemSize-1) data->offDiag[index] = offDiag;
}

__global__ void initSolutionGPU(ConjugateGradientData* data){
      //initialize solution vector to zero except for the boundaries
      const int index = blockIdx.x * blockDim.x + threadIdx.x;

      constexpr double T0 = 300.0;
      constexpr double Tend = 400.0;

      double sol = 0.0;

      if (index == 0) sol = T0;
      if (index == systemSize - 1) sol = Tend;

      data->solution[index] = sol;
}

__global__ void initConjugateDirectionGPU(ConjugateGradientData* data){
      //initialize the conjugate gradient direction
      const int index = blockIdx.x * blockDim.x + threadIdx.x;

      //initially the conjugate direction is equal to the initial residual: p0 = r0 = b0 - A * x0
      computeResidualGPU(data);
      data->direction[index] = data->residual[index];
}

__global__ void computeResidualGPU(ConjugateGradientData* data){
      const int index = blockIdx.x * blockDim.x + threadIdx.x;
      //residual = rhs - A*solution
      matVecGPU(data->diag, data->offDiag, data->solution, data->projection);
      data->residual[index] = data->rhs[index] - data->projection[index];
}

__global__ void matVecGPU(double* diag, double* offDiag, double* x, double* y){
      //  y = A*x
      // Ipologiste to ginomeno A*x me y to apotelesma tou ipologismou
}

__global__ void updateSolutionGPU(ConjugateGradientData* data, const double alpha){
      // Ananeoste ti lisi ("solution")
}

__global__ void updateResidualGPU(ConjugateGradientData* data, const double alpha){
      // Ananeoste to residual
}

__global__ void updateConjugateDirectionGPU(ConjugateGradientData* data, const double beta){
      // Ananeoste tis conjugate directions ("direction")
}
