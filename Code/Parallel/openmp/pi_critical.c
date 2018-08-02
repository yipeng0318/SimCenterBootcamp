#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 100000

int main() {
    double pi = 0;
    double x_incr = 1.0/DATA_SIZE;
    printf("x_incr = %f \n", x_incr);
    double x[DATA_SIZE];
    for (int i=0; i<DATA_SIZE; i++) x[i] = 0;
    for (int i=0; i<DATA_SIZE; i++) x[i] += x_incr*i;
    double tdata = omp_get_wtime();
    #pragma omp parallel
    {
      int tid = omp_get_thread_num();
      int numT = omp_get_num_threads();
      for (int i = tid; i<DATA_SIZE; i+=numT) {
        #pragma omp critical
        pi += 4.0/(1+x[i]*x[i])*x_incr;
      }

    }
    tdata = omp_get_wtime() - tdata;

    printf("PI = %f, duration: %f ms \n",pi,tdata);
    return 0;
}


