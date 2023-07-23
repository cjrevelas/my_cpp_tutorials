#ifndef MAIN_H
#define MAIN_H

#include "cuda_runtime.h"
#include "conjugateGradient.cuh"

// --------------------------------------------------------------------------------------
//                             H O S T  -  F U N C T I O N S
// --------------------------------------------------------------------------------------
void allocHostMemorySpace(ConjugateGradientData *&hostPtr);
void allocDeviceMemorySpace(ConjugateGradientData *&deviceData);
void createDevicePtr(ConjugateGradientData *&devicePtr, ConjugateGradientData *&deviceData);

void freeHostMemory(ConjugateGradientData *&hostPtr);
void freeDeviceMemory(ConjugateGradientData *&deviceData);
void destroyDevicePtr(ConjugateGradientData *&devicePtr );

void formEqSystem(ConjugateGradientDataPtrs &ptr);

void conjugatGradientSolver(ConjugateGradientDataPtrs &ptr, const int maxIter, const double tolerance);

void initSolution(ConjugateGradientDataPtrs &ptr);
void initConjugateDirection(ConjugateGradientDataPtrs &ptr);

void computeBeta(ConjugateGradientDataPtrs &ptr);
void computeAlpha(ConjugateGradientDataPtrs &ptr);
void computeResidual(ConjugateGradientDataPtrs &ptr);

void updateSolution(ConjugateGradientDataPtrs &ptr);
void updateResidual(ConjugateGradientDataPtrs &ptr);
void updateConjugateDirection(ConjugateGradientDataPtrs &ptr);

void dotProduct(ConjugateGradientDataPtrs &ptr, ConjugateGradientEnum A, ConjugateGradientEnum B, ConjugateGradientEnum C);

void matVec(ConjugateGradientDataPtrs &ptr, ConjugateGradientEnum A, ConjugateGradientEnum B);

void writeSolution(ConjugateGradientDataPtrs &ptr);

// --------------------------------------------------------------------------------------
//                                    K E R N E L S
// --------------------------------------------------------------------------------------
__global__ void getSPD_GPU(ConjugateGradientData *data);
__global__ void initSolutionGPU(ConjugateGradientData *data);
__global__ void initConjugateDirectionGPU(ConjugateGradientData *data);
__global__ void computeResidualGPU(ConjugateGradientData *data);

__global__ void matVecGPU(double *diag, double *offDiag, double *x, double *y);

__global__ void updateSolutionGPU(ConjugateGradientData *data, const double alpha);
__global__ void updateResidualGPU(ConjugateGradientData *data, const double alpha);
__global__ void updateConjugateDirectionGPU(ConjugateGradientData *data, const double beta);

#endif
