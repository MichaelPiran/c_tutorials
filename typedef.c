#include <stdio.h>

typedef int errorcode;

typedef struct {
  int n;
  int d;
} fract;

typedef fract *fractptr;

errorcode foo(void){
  return -10;
}

void main(void){
  errorcode a = foo();
  printf("%d\n", a);

  fract f;  
  fractptr fp = &f;
  f.n = 10;
  f.d = 20;
  printf("%d/%d strored at %p\n", f.n, f.d, fp);
}
