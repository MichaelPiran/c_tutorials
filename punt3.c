#include <stdio.h>

int main(void){
  char str[] = "AACC";
  short *s = (short *)str;
  printf("%d %d\n", str[0], str[1]); // printa A (65) A (65)
  printf("%d %d\n", s[0], s[1]); // printa AA e CC in hex
				 
  char str1[] = "Hello0001234\00002222"; // \000 is the null byte
  char *p = str1;
  while (*p){
    putchar(*p);
    p++;
  }
  printf("\n");

  return 0;
}
