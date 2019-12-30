#include <wb.h>

#define wbCheck(stmt)                                                     \
  do {                                                                    \
    cudaError_t err = stmt;                                               \
    if (err != cudaSuccess) {                                             \
      wbLog(ERROR, "CUDA error: ", cudaGetErrorString(err));              \
      wbLog(ERROR, "Failed to run stmt ", #stmt);                         \
      return -1;                                                          \
    }                                                                     \
  } while (0)

//@@ Define any useful program-wide constants here
#define OUTPUT_TILE_WIDTH 4
#define BLOCK_WIDTH 6 // tileWidth + maskwidth - 1
#define MASK_WIDTH 3

//@@ Define constant memory for device kernel here
__constant__ float MASK[MASK_WIDTH][MASK_WIDTH][MASK_WIDTH];

__global__ void conv3d(float *input, float *output, const int z_size,
                       const int y_size, const int x_size) {
  //@@ Insert kernel code here
  
  // define vars
  __shared__ float cache[BLOCK_WIDTH][BLOCK_WIDTH][BLOCK_WIDTH];
  
  int tx = threadIdx.x;
  int ty = threadIdx.y;
  int tz = threadIdx.z;
  
  int x_out = blockIdx.x*OUTPUT_TILE_WIDTH + tx;
  int y_out = blockIdx.y*OUTPUT_TILE_WIDTH + ty;
  int z_out = blockIdx.z*OUTPUT_TILE_WIDTH + tz;
  
  // load into cache
  if((x_out-1) >= 0 && (y_out-1) >= 0 && (z_out-1) >= 0 && (x_out-1) < x_size && (y_out-1) < y_size && (z_out-1) < z_size){
    cache[tx][ty][tz] = input[(x_out-1) + (y_out-1)*x_size + (z_out-1)*x_size*y_size];
  }
  else{
    cache[tx][ty][tz] = 0.0;
  }
  
  
  // calculate convolution using cache
  __syncthreads();
  float partialSum = 0.0;
  if(tx < OUTPUT_TILE_WIDTH && ty < OUTPUT_TILE_WIDTH && tz < OUTPUT_TILE_WIDTH){
    for(int i = 0; i < MASK_WIDTH; i++){
      for(int j = 0; j < MASK_WIDTH; j++){
        for(int k = 0; k < MASK_WIDTH; k++){
          partialSum += MASK[i][j][k]*(float)cache[tx+i][ty+j][tz+k];
        }
      }
    }
    

    // write to output
    if(x_out < x_size && y_out < y_size && z_out < z_size){
      output[z_out*x_size*y_size + y_out*x_size + x_out] = partialSum;
    }
    
  }
  
 
}

int main(int argc, char *argv[]) {
  wbArg_t args;
  int z_size;
  int y_size;
  int x_size;
  int inputLength, kernelLength;
  float *hostInput;
  float *hostKernel;
  float *hostOutput;
  float *deviceInput;
  float *deviceOutput;

  args = wbArg_read(argc, argv);

  // Import data
  hostInput = (float *)wbImport(wbArg_getInputFile(args, 0), &inputLength);
  hostKernel =
      (float *)wbImport(wbArg_getInputFile(args, 1), &kernelLength);
  hostOutput = (float *)malloc(inputLength * sizeof(float));

  // First three elements are the input dimensions
  z_size = hostInput[0];
  y_size = hostInput[1];
  x_size = hostInput[2];
  wbLog(TRACE, "The input size is ", z_size, "x", y_size, "x", x_size);
  assert(z_size * y_size * x_size == inputLength - 3);
  assert(kernelLength == 27);

  wbTime_start(GPU, "Doing GPU Computation (memory + compute)");
  
  
  
  wbTime_start(GPU, "Doing GPU memory allocation");
  //@@ Allocate GPU memory here
  // Recall that inputLength is 3 elements longer than the input data
  // because the first  three elements were the dimensions
  cudaMalloc((void**) &deviceInput, sizeof(float)*(inputLength-3));
  cudaMalloc((void**) &deviceOutput, sizeof(float)*(inputLength-3));
  wbTime_stop(GPU, "Doing GPU memory allocation");

  
  
  wbTime_start(Copy, "Copying data to the GPU");
  //@@ Copy input and kernel to GPU here
  // Recall that the first three elements of hostInput are dimensions and
  // do
  // not need to be copied to the gpu
  cudaMemcpy(deviceInput, &hostInput[3], sizeof(float)*(inputLength-3), cudaMemcpyHostToDevice);
  cudaMemcpyToSymbol(MASK, hostKernel, sizeof(float)*kernelLength);
  wbTime_stop(Copy, "Copying data to the GPU");

  
  
  wbTime_start(Compute, "Doing the computation on the GPU");
  //@@ Initialize grid and block dimensions here
  dim3 blockDim(BLOCK_WIDTH,BLOCK_WIDTH,BLOCK_WIDTH);
  dim3 numBlocks(ceil(x_size/(float)OUTPUT_TILE_WIDTH), ceil(y_size/(float)OUTPUT_TILE_WIDTH), 
                 ceil(z_size/(float)OUTPUT_TILE_WIDTH));
  //@@ Launch the GPU kernel here
  conv3d<<<numBlocks, blockDim>>>(deviceInput, deviceOutput, z_size, y_size, x_size);
  cudaDeviceSynchronize();
  wbTime_stop(Compute, "Doing the computation on the GPU");

  
  
  wbTime_start(Copy, "Copying data from the GPU");
  //@@ Copy the device memory back to the host here
  // Recall that the first three elements of the output are the dimensions
  // and should not be set here (they are set below)
  cudaMemcpy(&hostOutput[3], deviceOutput, sizeof(float)*(inputLength-3), cudaMemcpyDeviceToHost);
  wbTime_stop(Copy, "Copying data from the GPU");

  
  
  wbTime_stop(GPU, "Doing GPU Computation (memory + compute)");

  // Set the output dimensions for correctness checking
  hostOutput[0] = z_size;
  hostOutput[1] = y_size;
  hostOutput[2] = x_size;
  wbSolution(args, hostOutput, inputLength);

  // Free device memory
  cudaFree(deviceInput);
  cudaFree(deviceOutput);

  // Free host memory
  free(hostInput);
  free(hostOutput);
  return 0;
}

