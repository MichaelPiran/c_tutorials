#include <stdio.h>

void conta_recursion(int start, int end){
  if (start > end) return;
  printf("%d, %p\n", start, &start);
  conta_recursion(start+1,end);
}

void conta_iterate(int start, int end) {
iterate:
  if (start > end) return;
  printf("%d, %p\n", start, &start);
  start = start +1;
  goto iterate;
}

int main(void){
//  conta_iterate(0,9);
 conta_recursion(0,9);
 return 0;
}
