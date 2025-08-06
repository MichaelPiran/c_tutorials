#include <stdio.h>

int main(void){
  int a = 8;
  {
    int a = 10;
    printf("a = %d\n", a);
    printf("a is stored at: %p\n", &a);
  }
  printf("a = %d\n", a);
  printf("a is stored at: %p\n", &a);


  int c = 5;
  if (c > 3) {
    printf("i > 3");
  } else {
    printf("i <= 3");
  }
  printf("\n");
  return 0;

}
