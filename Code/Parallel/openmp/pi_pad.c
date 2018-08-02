#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PAD 64
#define DATA_SIZE 100000

int main() {
    int nThreads = 0;
    double pi=0, x[DATA_SIZE], sum[64][PAD];
    double x_incr = 1.0/DATA_SIZE;
    printf("x_incr = %f \n", x_incr);
    for (int i=0; i<DATA_SIZE; i++) x[i] = 0;
    for (int i=0; i<DATA_SIZE; i++) x[i] += x_incr*i;
    for (int i=0; i<64; i++) sum[i][0] = 0;
    double tdata = omp_get_wtime();
    #pragma omp parallel
    {
      int tid = omp_get_thread_num();
      int numT = omp_get_num_threads();
      if (tid ==0) nThreads = numT;
      for (int i = tid; i<DATA_SIZE; i+=numT) {
        sum[tid][0] += 4.0/(1+x[i]*x[i])*x_incr;
      }

    }
    for (int i=0; i<nThreads; i++)
      pi += sum[i][0];
    tdata = omp_get_wtime() - tdata;

    printf("PI = %f, duration: %f ms \n",pi,tdata);
    return 0;
}


