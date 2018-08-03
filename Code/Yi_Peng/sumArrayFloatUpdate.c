#include <stdio.h>
#include <stdlib.h>
float mySum(float *data, int *count, int size);

float main(int argc, const char **argv) {
  int size = argc - 1;
  printf("size of argv = %d\n",  size);
  float *data = (float *)malloc(size*sizeof(float));
  int *count = (int *)malloc(size*sizeof(int));

/*
  for (int i = 0; i<size; i++)
      data[i] = atof(argv[i+1]);
*/

  for (int i = 0; i<size; i++) {
       data[i] = 0;
       count[i] = 0;
  }
  //count[0] = 1;
  for (int i = 0; i<size; i++) {
      data[i] = atof(argv[i+1]);
      int j = i;
      for (j>0; j==0; j--) {
          if (data[i] == data[j-1]) {
             count[j-1] = count[j-1] +1;
             data[i] = 0;
       } 
           
         
      }
       if (count[i] == 0) {count[i] = count[i]+1;}
  }
      
  float sum = mySum(data,count, size);
  printf("summation of array = %f\n",  sum);
  free(data);
  free(count);
  return 0;
}

// recursive dunction factorial, i.e. it calls itself
float mySum(float *data, int *count, int size) {

  if (size == 1) 
    return data[size-1]*count[size-1];
  else 
    return data[size-1]*count[size-1]+mySum(data, count, size-1);
}
	
