#include <stdio.h>
#include <time.h>

static int long numSteps = 100000;
double pi_incr (double x);
int main() {
    clock_t t1, t2;
    t1 = clock();
    double pi = 0.0; double time = 0.0; double x = 0.0;
    double x_incr = 1.0/numSteps;
    printf("t_incr = %f \n", x_incr);

    for (int i = 0; i<numSteps; i++) {
        pi += pi_incr(x)*x_incr;
        x += x_incr;   
    
    }

    t2 = clock(); 
    time = ((double)(t2-t1))/CLOCKS_PER_SEC;
    printf("PI = %f, duration: %f ms \n",pi,time);
    return 0;
}

double pi_incr (double x) {
      double pi_incr = 4.0/(1+x*x);
      return pi_incr;
    }
