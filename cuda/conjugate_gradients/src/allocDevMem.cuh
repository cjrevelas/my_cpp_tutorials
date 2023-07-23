#ifndef ALLOCATE_DEVICE_MEMORY_H
#define ALLOCATE_DEVICE_MEMORY_H

#include <string>
#include "cuda_runtime.h"
#include "abort.cuh"

void *GPUalloc(const int size, const std::string &errorMessage) {
  void *devp = NULL;

  cudaError_t err = cudaMalloc(&devp, size);
  if (err != cudaSuccess) Stop("GPU allocation failed" + errorMessage);

  return devp;
}

void *GPUalloc(void *hostp, const int size, const std::string &errorMessage){
  void *devp = NULL;
  cudaError_t err1 = cudaMalloc(&devp, size);
  if (err1 != cudaSuccess) Stop("GPU allocation failed -" + errorMessage + "-\n");

  cudaError_t err2 = cudaMemcpy(devp, hostp, size, cudaMemcpyHostToDevice);
  if (err2 != cudaSuccess) Stop("invalid copy -" + errorMessage + "-\n");

  return devp;
}

#endif
