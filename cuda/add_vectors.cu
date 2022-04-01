#include <iostream>
#include <stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

// Forward declarations of GPU kernels
__global__ void GPUprintThreadId();
__global__ void GPUvectorAdd(int N, double *d_a, double *d_b, double *d_c);

// Forward declarations of host functions
void *allocGPUmemory(void *hostp, std::size_t bytes);
void stop(const std::string &error_message);


int main() {
	// Set the size of the problem and the total amount of required memory
	constexpr int N = 128;
	std::size_t bytes = sizeof(double) * N;

	// Allocate host memory
	double *h_a = new double[N];
	double *h_b = new double[N];
	double *h_c = new double[N];

	// Initialize the two input arrays
	for (int ii = 0; ii < N; ++ii) {
		h_a[ii] = static_cast<double>(ii);
		h_b[ii] = static_cast<double>(ii);
		h_c[ii] = 0.0;
	}

	// Allocate device memory
	double* d_a = static_cast<double *>(allocGPUmemory(static_cast<void *>(h_a), bytes));
	double* d_b = static_cast<double *>(allocGPUmemory(static_cast<void *>(h_b), bytes));
	double* d_c = static_cast<double *>(allocGPUmemory(static_cast<void *>(h_c), bytes));

	// Initialize and run CUDA kernel
	int numThreads = 32;
	int numBlocks = (N + numThreads - 1) / numThreads;

	std::cout << "Initiating CUDA kernel with: " << numBlocks << " blocks, and " << numThreads << " threads.\n";
	std::cout << "-------------------------------------------------------\n";
	std::cin.get();

	// Deploy kernels
	GPUprintThreadId<<<numBlocks, numThreads>>>();

	GPUvectorAdd<<<numBlocks, numThreads>>>(N, d_a, d_b, d_c);

	cudaError_t err = cudaDeviceSynchronize();
	if (err != cudaSuccess) stop("ERROR: CUDA KERNEL WAS NOT LAUNCHED SUCCESSFULLY\n");

	// Copy resulted array from device to host
	err = cudaMemcpy(h_c, d_c, bytes, cudaMemcpyDeviceToHost);
	if (err != cudaSuccess) stop("ERROR: COPY FROM DEVICE TO HOST WAS NOT SUCCESSFUL\n");

	// Print the final result
	for (int ii = 0; ii < N; ++ii) {
		std::cout << h_c[ii] << '\n';
	}

	// Deallocate device memory
	cudaFree(d_a); d_a = NULL;
	cudaFree(d_b); d_b = NULL;
	cudaFree(d_c); d_c = NULL;

	// Deallocate host memory 
	if (h_a) { delete[] h_a; h_a = NULL; }
	if (h_b) { delete[] h_b; h_b = NULL; }
	if (h_c) { delete[] h_c; h_c = NULL; }

	std::cin.get();

	return 0;
}


// Kernel definitions
__global__ void GPUvectorAdd(int N, double *d_a, double *d_b, double *d_c) {
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
