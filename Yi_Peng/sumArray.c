#include <stdio.h>
#include <stdlib.h>
int mySum(int *data, int size);

int main(int argc, const char **argv) {
  int size = argc - 1;
  printf("size of argv = %d\n",  size);
  int *data = (int *)malloc(size*sizeof(int));
  for (int i = 0; i<size; i++)
      data[i] = atoi(argv[i+1]);
  int sum = mySum(data,size);
  printf("summation of array = %d\n",  sum);
  free(data);
  return 0;
}

// recursive dunction factorial, i.e. it calls itself
int mySum(int *data, int size) {
  if (size == 1) 
    return data[size-1];
  else 
    return data[size-1]+mySum(data, size-1);
}
	
