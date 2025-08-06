#include <stdio.h>

int main(void){
  int a[3] = {10,100,50};
  char str[6] = {'h','e','l','l','o',0};
  char str2[] = "hello";
  printf("%s\n", str2);
  printf("sizeof: %lu\n", sizeof(str2));
  return 0;
}
