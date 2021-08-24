#ifndef ALLOCATE_DEVICE_MEMORY_H
#define ALLOCATE_DEVICE_MEMORY_H

#include "cuda_runtime.h"
#include "abort.cuh"
#include <string>

void* GPUalloc(const int size, const std::string error_message){
	void* devp = NULL;

	cudaError_t err = cudaMalloc(&devp, size);
	if (err != cudaSuccess) Stop("GPU allocation failed" + error_message);

	return devp;
}

void* GPUalloc(void* hostp, const int size, const std::string error_message){
	void* devp = NULL;
	cudaError_t err1 = cudaMalloc(&devp, size);
	if (err1 != cudaSuccess) Stop("GPU allocation failed -" + error_message + "-\n");

	cudaError_t err2 = cudaMemcpy(devp, hostp, size, cudaMemcpyHostToDevice);
	if (err2 != cudaSuccess) Stop("invalid copy -" + error_message + "-\n");

	return devp;
}

#endif