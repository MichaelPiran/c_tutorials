#include <stdio.h>

int sum(int a,int b){
  return a+b;
}

void incr(void){
  int x = 1;
  x =  x+1;
  printf("%d\n", x);
}

int main(void){
  incr();
  return 0;
}
