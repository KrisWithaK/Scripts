#include <wb.h>

#define wbCheck(stmt)                                                     \
  do {                                                                    \
    cudaError_t err = stmt;                                               \
    if (err != cudaSuccess) {                                             \
      wbLog(ERROR, "Failed to run stmt ", #stmt);                         \
      wbLog(ERROR, "Got CUDA error ...  ", cudaGetErrorString(err));      \
      return -1;                                                          \
    }                                                              \
  } while (0)

// Compute C = A * B
__global__ void matrixMultiply(float *A, float *B, float *C, int numARows,
                               int numAColumns, int numBRows,
                               int numBColumns, int numCRows,
                               int numCColumns) {
  //@@ Insert code to implement matrix multiplication here
  int x = blockIdx.x*blockDim.x + threadIdx.x;
  int y = blockIdx.y*blockDim.y + threadIdx.y;
 
  
  if(x < numCColumns && y < numCRows){
    float partialSum = 0;
    for(int i = 0; i < numAColumns; i++){
      partialSum += (float)A[y*numAColumns+i]*B[i*numBColumns + x];
    }
    C[y*numCColumns + x] = partialSum;
  }
}

int main(int argc, char **argv) {
  wbArg_t args;
  float *hostA; // The A matrix
  float *hostB; // The B matrix
  float *hostC; // The output C matrix
  float *deviceA;
  float *deviceB;
  float *deviceC;
  int numARows;    // number of rows in the matrix A
  int numAColumns; // number of columns in the matrix A
  int numBRows;    // number of rows in the matrix B
  int numBColumns; // number of columns in the matrix B
  int numCRows;    // number of rows in the matrix C (you have to set this)
  int numCColumns; // number of columns in the matrix C (you have to set
                   // this)

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");
  hostA = (float *)wbImport(wbArg_getInputFile(args, 0), &numARows,
                            &numAColumns);
  hostB = (float *)wbImport(wbArg_getInputFile(args, 1), &numBRows,
                            &numBColumns);
  //@@ Set numCRows and numCColumns
  // for AB to be valid, number of columns in A = num of rows in B
  numCRows = numARows;
  numCColumns = numBColumns;
  
  
  //@@ Allocate the hostC matrix
  wbTime_stop(Generic, "Importing data and creating memory on host");
  hostC = (float *)malloc(sizeof(float)*numCColumns*numCRows);
  
  for(int i = 0; i < numCColumns*numCRows; i++){
    hostC[i] = 1;
  }
  
  
  wbLog(TRACE, "The dimensions of A are ", numARows, " x ", numAColumns);
  wbLog(TRACE, "The dimensions of B are ", numBRows, " x ", numBColumns);

  wbTime_start(GPU, "Allocating GPU memory.");
  //@@ Allocate GPU memory here
  cudaMalloc(&deviceA, sizeof(float)*numAColumns*numARows);
  cudaMalloc(&deviceB, sizeof(float)*numBColumns*numBRows);
  cudaMalloc(&deviceC, sizeof(float)*numCColumns*numCRows);

  wbTime_stop(GPU, "Allocating GPU memory.");

  wbTime_start(GPU, "Copying input memory to the GPU.");
  //@@ Copy memory to the GPU here
  cudaMemcpy(deviceA, hostA, sizeof(float)*numAColumns*numARows, cudaMemcpyHostToDevice);
  cudaMemcpy(deviceB, hostB, sizeof(float)*numBColumns*numBRows, cudaMemcpyHostToDevice);
  
  wbTime_stop(GPU, "Copying input memory to the GPU.");

  //@@ Initialize the grid and block dimensions here
  dim3 blockDim(32,32,1);
  dim3 numBlocks(ceil(numCColumns/(float)blockDim.x), ceil(numCRows/(float)blockDim.y), 1); 
  

  wbTime_start(Compute, "Performing CUDA computation");
  //@@ Launch the GPU Kernel here
  matrixMultiply<<<numBlocks, blockDim>>>(deviceA, deviceB, deviceC, numARows, numAColumns, numBRows, numBColumns, 
                                          numCRows, numCColumns);

  cudaDeviceSynchronize();
  wbTime_stop(Compute, "Performing CUDA computation");

  wbTime_start(Copy, "Copying output memory to the CPU");
  //@@ Copy the GPU memory back to the CPU here
  cudaMemcpy(hostC, deviceC, sizeof(float)*numCRows*numCColumns, cudaMemcpyDeviceToHost);

  wbTime_stop(Copy, "Copying output memory to the CPU");

  wbTime_start(GPU, "Freeing GPU Memory");
  //@@ Free the GPU memory here
  cudaFree(deviceA);
  cudaFree(deviceB);
  cudaFree(deviceC);

  wbTime_stop(GPU, "Freeing GPU Memory");

  wbSolution(args, hostC, numCRows, numCColumns);

  free(hostA);
  free(hostB);
  free(hostC);

  return 0;
}
