#include <stdio.h>
#include <stdlib.h>
float mySum(float *data, int size);

float main(int argc, const char **argv) {
  int size = argc - 1;
  printf("size of argv = %d\n",  size);
  float *data = (float *)malloc(size*sizeof(float));
  for (int i = 0; i<size; i++)
      data[i] = atof(argv[i+1]);
  float sum = mySum(data,size);
  printf("summation of array = %f\n",  sum);
  free(data);
  return 0;
}

// recursive dunction factorial, i.e. it calls itself
float mySum(float *data, int size) {
  if (size == 1) 
    return data[size-1];
  else 
    return data[size-1]+mySum(data, size-1);
}
	
