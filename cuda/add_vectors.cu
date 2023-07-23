#include <iostream>
#include <stdio.h>
#include <cublas_v2.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

// Forward declarations of GPU kernels
__global__ void GPUprintThreadId();
__global__ void GPUvectorAdd(int N, float *d_a, float *d_b, float *d_c);

// Forward declarations of host functions
void *allocGPUmemory(void *hostp, std::size_t bytes);
void stop(const std::string &error_message);

int main() {
  // Set the size of the problem and the total amount of required memory
  constexpr int N = 1 << 26;

  std::cout << "vector size is equal to: " << N << '\n';
  std::size_t bytes = sizeof(float) * N;

  // Allocate host memory
  float *h_a     = new float[N];
  float *h_b     = new float[N];
  float *h_c     = new float[N];
  float *h_cblas = new float[N];

  // Initialize vectors
  for (int ii = 0; ii < N; ++ii) {
    h_a[ii]     = static_cast<float>(ii);
    h_b[ii]     = static_cast<float>(ii);
    h_c[ii]     = 0.0f;
    h_cblas[ii] = 0.0f;
  }

  // Allocate device memory
  float *d_a = static_cast<float *>(allocGPUmemory(static_cast<void *>(h_a), bytes));
  float *d_b = static_cast<float *>(allocGPUmemory(static_cast<void *>(h_b), bytes));
  float *d_c = static_cast<float *>(allocGPUmemory(static_cast<void *>(h_c), bytes));

  // Initialize and run CUDA kernel
  int numThreads = 32;
  int numBlocks = (N + numThreads - 1) / numThreads;

  std::cout << "Initiating CUDA kernel with: " << numBlocks << " blocks, and " << numThreads << " threads.\n";
  std::cout << "-------------------------------------------------------\n";
  std::cin.get();

  // Deploy custom vector addition kernel
  std::cout << "Running custom vector addition kernel\n";
  //GPUprintThreadId<<<numBlocks, numThreads>>>();
  GPUvectorAdd<<<numBlocks, numThreads>>>(N, d_a, d_b, d_c);

  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaSuccess) stop("ERROR: CUDA KERNEL WAS NOT LAUNCHED SUCCESSFULLY\n");

  // Copy the resulting array from device back to the host
  err = cudaMemcpy(h_c, d_c, bytes, cudaMemcpyDeviceToHost);
  if (err != cudaSuccess) stop("ERROR: COPY FROM DEVICE TO HOST WAS NOT SUCCESSFUL\n");

  // Deploy cublas saxpy kernel
  cublasHandle_t handle;
  cublasCreate(&handle);

  cublasSetVector(N, sizeof(float), h_a, 1, d_a, 1);
  cublasSetVector(N, sizeof(float), h_a, 1, d_a, 1);

  const float scale = 1.0;

  cublasSaxpy(handle, N, &scale, (float *)(d_a), 1, (float *)(d_b), 1);

  cublasGetVector(N, sizeof(float), d_b, 1, h_cblas, 1);

  cublasDestroy(handle);

  float maxError = 0.0;
  for (int ii = 0; ii < N; ++ii) {
    maxError = std::max(maxError, abs(h_c[ii] - h_cblas[ii]));
    //std::cout << h_c[ii] << "  " << h_cblas[ii] << ", Max error: " << maxError << '\n';
  }

  if (maxError < 1.0e-5) {
    std::cout << "Program executed successfully\n";
  } else {
    std::cout << "Something went wrong\n";
  }

  // Deallocate device memory
  cudaFree(d_a); d_a = NULL;
  cudaFree(d_b); d_b = NULL;
  cudaFree(d_c); d_c = NULL;

  // Deallocate host memory
  if (h_a)     { delete[] h_a; h_a = NULL; }
  if (h_b)     { delete[] h_b; h_b = NULL; }
  if (h_c)     { delete[] h_c; h_c = NULL; }
  if (h_cblas) { delete[] h_cblas; h_cblas = NULL; }

  std::cout << "Program finished\n";
  std::cin.get();

  return 0;
}

// Kernel definitions
__global__ void GPUvectorAdd(int N, float *d_a, float *d_b, float *d_c) {
  int threadId = blockDim.x * blockIdx.x + threadIdx.x;

  if (threadId < N) {
    d_c[threadId] = d_a[threadId] + d_b[threadId];
  }
}

__global__ void GPUprintThreadId() {
  printf(" blockID:  %d, threadID: %d\n", blockIdx.x, threadIdx.x);
}

// Host function definitions
void *allocGPUmemory(void *hostp, std::size_t bytes) {
  void* devp = NULL;
  cudaError_t err1 = cudaMalloc(&devp, bytes);
  if (err1 != cudaSuccess) stop("ERROR: CUDA MEMORY ALLOCATION WAS NOT SUCCESSFUL -> TYPE 1");

  cudaError_t err2 = cudaMemcpy(devp, hostp, bytes, cudaMemcpyHostToDevice);
  if (err2 != cudaSuccess) stop("ERROR: CUDA MEMORY ALLOCATION WAS NOT SUCCESSFUL -> TYPE 2");

  return devp;
}

void stop(const std::string &error_message) {
  std::cerr << error_message << '\n';
  exit(1);
}
