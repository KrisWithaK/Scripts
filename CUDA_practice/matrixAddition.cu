#include <iostream>
#include <math.h>


__global__ void add(int n, float* x, float* y){

    int index = threadIdx.x;
    int stride = blockDim.x;

    for(int i = index; i < n; i += stride){
        y[i] = x[i] + y[i];
    }

    //if(index < n){
    //    y[index] = x[index] + y[index];
    //}

}




int main(){
    int N = 1<<20; // 1M elements

    float *x;
    float *y;

    // allocate unified memory - accessible from cpu or gpu
    cudaMallocManaged(&x, N*sizeof(float));
    cudaMallocManaged(&y, N*sizeof(float));


    // initialize x and y arrays on the host
    for(int i = 0; i < N; i++){
        x[i] = 1.0f;
        y[i] = 2.0f;
    }


    // Run kernel on 1M elements on the CPU
    add<<<1, 256>>>(N,x,y);

    // wait for GPU to finnish before accessing on host
    cudaDeviceSynchronize();

    // free memory
    cudaFree(x);
    cudaFree(y);


}
