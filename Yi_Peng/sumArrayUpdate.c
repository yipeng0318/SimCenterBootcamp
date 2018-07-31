#include <stdio.h>
#include <stdlib.h>
int mySum(int s[10]);

int main(int argc, const char **argv) {
  int s[10] = {0};
  int size = argc - 1;
  printf("size of argv = %d\n",  size);
  int *data = (int *)malloc(size*sizeof(int));
  for (int i = 0; i<size; i++) {
      data[i] = atoi(argv[i+1]);
      s[data[i]%10] = s[data[i]%10] + 1;
  }
  int sum = mySum(s);
  printf("summation of array = %d\n",  sum);
  free(data);
  return 0;
}

// recursive dunction factorial, i.e. it calls itself
int mySum(int s[10]) {
  int sum = 0;
  for (int i = 0; i<10; i++) {
      if (s[i]>0)
          sum += i*s[i];
  }
  return sum;
}
