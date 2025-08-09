#include <stdio.h>

int main(void){
  int x = 5;
  int *y = &x; // int *y = NULL; y = &x;
  
  int **z = &y; // pointer to pointer 
  printf("x vive in %p e vale %d\n", y, x);
  printf("y vive in %p\n", z);
  printf("%d, %d, %d bytes\n", (int)sizeof(x), (int)sizeof(y), (int)sizeof(z));
  return 0;
}
