File Edit Options Buffers Tools C Help                                          
#include <omp.h>
#include <stdio.h>
#include <time.h>

static int long numSteps =  1000000000;

int main() {
  double pi = 0.0;
  double x = 0.5*x;
  double x_incr = 1.0/numSteps;
  printf("dx = %f \n", x_incr);
  double tdata = omp_get_wtime();
#pragma omp parallel for reduction(+:pi) private(x)
  for (int i = 0; i<numSteps; i++) {
    x = (i+0.5)*x_incr;
    pi += 4.0/(1.+x*x);
  }

  pi *= x_incr;
  double end = omp_get_wtime();

  printf("PI = %f, duration: %.4g sec \n",pi,end-tdata);
  return 0;
}



