#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
  int n;
  double matrix1[2][3];
  for (int i=0; i<2; i++)
    for (int j=0; j<3; j++)
      matrix1[i][j]=i;

  double **matrix2;
  matrix2 = (double **)malloc(2*sizeof(double *));
  for (int i=0; i<2; i++) {
    matrix2[i] = (double *)malloc(3*sizeof(double));
    for (int j=0; j<3; j++)
      matrix2[i][j] = i;
  }
  
  for (int i=0; i<2; i++) {
    for (int j=0; j<3; j++)
      printf("(%d,%d) %.4f %.4f\n", i,j, matrix1[i][j], matrix2[i][j]);
  }

  double *ptr = matrix1;
  for (int i=0; i<6; i++)
    printf("(%d) %.4f\n", i, *ptr++);

  ptr = matrix2;
  for (int i=0; i<6; i++)
    printf("(%d) %.4f\n", i, *ptr++);
}
