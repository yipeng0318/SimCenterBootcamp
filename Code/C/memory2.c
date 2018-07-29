#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
  int n;
  double **array1 =0;

  printf("enter n: ");
  scanf("%d", &n);
  
  // allocate memory & set the data
  array1 = (double **)malloc(n*sizeof(double *));
  for (int i=0; i<n; i++) {
    array1[i] = (double *)malloc(n*sizeof(double));
    for (int j=0; j<n; j++)
      array1[i][j] = i;
  }
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      printf("(%d,%d) %.4f\n", i,j, array1[i][j]);
  }

  // free the data
  for (int i=0; i<n; i++)
    free(array1[i]);
  free(array1);

}
