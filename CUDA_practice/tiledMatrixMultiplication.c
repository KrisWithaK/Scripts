#include <wb.h>

#define wbCheck(stmt)                                                     \
  do {                                                                    \
    cudaError_t err = stmt;                                               \
    if (err != cudaSuccess) {                                             \
      wbLog(ERROR, "Failed to run stmt ", #stmt);                         \
      wbLog(ERROR, "Got CUDA error ...  ", cudaGetErrorString(err));      \
      return -1;                                                          \
    }                                                                     \
  } while (0)


 #define TILED_WIDTH 16

// Compute C = A * B
__global__ void matrixMultiplyShared(float *A, float *B, float *C,
                                     int numARows, int numAColumns,
                                     int numBRows, int numBColumns,
                                     int numCRows, int numCColumns) {
  //@@ Insert code to implement matrix multiplication here
  //@@ You have to use shared memory for this MP
  
  
  __shared__ float A_subMatrix[TILED_WIDTH][TILED_WIDTH];
  __shared__ float B_subMatrix[TILED_WIDTH][TILED_WIDTH];
  
  
  // threads and thread blocks eaiser to use
  int tx = threadIdx.x;
  int ty = threadIdx.y;
  int bx = blockIdx.x;
  int by = blockIdx.y;
  
  // row and column of C block
  int row = by*TILED_WIDTH + ty;
  int col = bx*TILED_WIDTH + tx;
 
  float partialSum = 0;
  // store into shared memory
  for(int currTile = 0; currTile < ceil(numAColumns/(float)TILED_WIDTH); currTile++){
   
    if(row < numARows && (currTile*TILED_WIDTH + tx) < numAColumns){
      A_subMatrix[ty][tx] = A[row*numAColumns + currTile*TILED_WIDTH + tx];
    }
    else{
      A_subMatrix[ty][tx] = 0;
    }
    if(col < numBColumns && (currTile*TILED_WIDTH + ty) < numBRows){
      B_subMatrix[ty][tx] = B[numBColumns*(currTile*TILED_WIDTH + ty) + col];
    }
    else{
      B_subMatrix[ty][tx] = 0;
    }

    // perform matrix multiplication
    __syncthreads();
    for(int i = 0; i < TILED_WIDTH; i++){
      partialSum += A_subMatrix[ty][i]*B_subMatrix[i][tx];
    }
    __syncthreads();
  
  }
  // put into resulting matrix
  if (row < numCRows && col < numCColumns){
    C[row*numCColumns+col] = partialSum;
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
  numCRows = numARows;
  numCColumns = numBColumns;
  
  //@@ Allocate the hostC matrix
  hostC = (float *)malloc(sizeof(float)*numCColumns*numCRows);
  
  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The dimensions of A are ", numARows, " x ", numAColumns);
  wbLog(TRACE, "The dimensions of B are ", numBRows, " x ", numBColumns);

  wbTime_start(GPU, "Allocating GPU memory.");
  //@@ Allocate GPU memory here
  cudaMalloc((void **) &deviceA, sizeof(float)*numAColumns*numARows);
  cudaMalloc((void **) &deviceB, sizeof(float)*numBColumns*numBRows);
  cudaMalloc((void **) &deviceC, sizeof(float)*numCColumns*numCRows);
  
  wbTime_stop(GPU, "Allocating GPU memory.");

  wbTime_start(GPU, "Copying input memory to the GPU.");
  //@@ Copy memory to the GPU here
  cudaMemcpy(deviceA, hostA, sizeof(float)*numAColumns*numARows, cudaMemcpyHostToDevice);
  cudaMemcpy(deviceB, hostB, sizeof(float)*numBColumns*numBRows, cudaMemcpyHostToDevice);
  wbTime_stop(GPU, "Copying input memory to the GPU.");

  //@@ Initialize the grid and block dimensions here
  dim3 blockDim(TILED_WIDTH,TILED_WIDTH,1);
  dim3 numBlocks(ceil(numCColumns/(float)blockDim.x),ceil(numCRows/(float)blockDim.y),1);

  wbTime_start(Compute, "Performing CUDA computation");
  //@@ Launch the GPU Kernel here
  matrixMultiplyShared<<<numBlocks,blockDim>>>(deviceA, deviceB, deviceC, numARows, numAColumns, numBRows, 
                                               numBColumns, numCRows, numCColumns);

  cudaDeviceSynchronize();
  wbTime_stop(Compute, "Performing CUDA computation");

  wbTime_start(Copy, "Copying output memory to the CPU");
  //@@ Copy the GPU memory back to the CPU here
  cudaMemcpy(hostC, deviceC, sizeof(float)*numCColumns*numCRows, cudaMemcpyDeviceToHost);

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

