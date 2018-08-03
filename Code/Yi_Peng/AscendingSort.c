#include <stdio.h>
#include <stdlib.h>
void Sort(int *data, int size);

int main(int argc, const char **argv) {
  int size = argc - 1;
  printf("size of argv = %d\n",  size);
  int *data = (int *)malloc(size*sizeof(int));
  for (int i = 0; i<size; i++)
      data[i] = atoi(argv[i+1]);
  Sort(data,size);
  for (int i = 0; i<size; i++)
      printf("%d ",  data[i]);
  printf("\n");
  free(data);
  return 0;
}

// recursive dunction factorial, i.e. it calls itself
void Sort(int *data, int size) {
   int tem;
   for (int i = 0; i<size; i++) {
       for (int j = 0; j<size-i-1; j++) {
           if (data[j] > data[j+1] ) {
              tem = data[j];
              data[j] = data[j+1];
              data[j+1] = tem;
           }
       }
   }
               
         
   
}
