#include <stdio.h>

void incr(int *p){
  *p = *p + 1;
}

int main(void){
  int x = 5;
  int *y = NULL; // pointer

  printf("x is %d\n", x);
  
  y = &x; // y = memory address of x
  printf("x is stored at the address: %p\n", y);

  *y = 10; // assign 10 to the value pointed by y. It is equal to y[0]=10
  printf("x now is %d\n", x);

  incr(y);
  printf("x now is %d\n", x);

  return 0;
}
