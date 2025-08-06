#include <stdio.h>

int main(void){
 int i=0;

again:
  printf("%d\n", i);
  i++;
  if (i<10) goto again;


  int j = 0;
  while(j < 10)  {
    printf("%d\n", j);
    j++;
  }
  return 0;
}
