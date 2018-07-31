#include <stdio.h>

static int long numSteps = 100000;
double pi_incr (double t);
int main() {

    double pi = 0.0; double time = 0.0; 
    double time_incr = 1.0/numSteps;
    printf("time_incr = %f \n", time_incr);
    for (int i = 0; i<numSteps; i++) {
        pi += pi_incr(time)*time_incr;
        time += time_incr;        
    }
    printf("PI = %f, duration: %f ms \n",pi,time);
    return 0;
}

double pi_incr (double t) {
      double pi_incr = 4.0/(1+t*t);
      return pi_incr;
    }
