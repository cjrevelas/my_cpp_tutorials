#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <stdio.h>
#include <iostream>

__global__ void printThreadId();

int main() {
    std::cout << "Hello\n";

    printThreadId << <2, 16 >> > ();

    cudaError_t err = cudaDeviceSynchronize();

    if (err != cudaSuccess) {
        std::cerr << "something went wrong...\n";
        exit(1);
    }

    std::cin.get();

    return 0;
}

__global__ void printThreadId() {
    int threadId = blockDim.x * blockIdx.x + threadIdx.x;

    printf("# hello world from thread %d of block %d and id %d\n", threadIdx.x, blockIdx.x, threadId);
}