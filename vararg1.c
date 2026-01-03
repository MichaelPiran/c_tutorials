#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

void foo(const char *fmt, ...){
  va_list ap;
  va_start(ap, fmt);
  char mybuf[32];
  //vprintf(fmt, ap); 
  vsnprintf(mybuf, sizeof(mybuf), fmt, ap);
  size_t len = strlen(mybuf);
  size_t padding = (80-len)/2;
  for(size_t j=0; j < padding; j++) printf(" ");
  printf("%s\n", mybuf);
  va_end(ap);
}

int main(void){
  printf("Hello World\n");
  foo("Ciao da: %d %d\n", 10, 20);
  return 0;
}
