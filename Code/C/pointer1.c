#include <stdio.h>
int main() {
  int x=10, y=20;
  int *px = 0;

  px = &x;
  y = *px + 1;
  printf("x: %d y: %d \n",x,y);
  return(0);
}
