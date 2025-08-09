// prefixed lenght string

#include <stdio.h>

void pls_init(char *s, char *init, int len){
  /*
   *  passo la size per evitare che venga saltato il byte a null
   *  Hell\000 world verrebbe accorciato */
  unsigned char *lenptr = (unsigned char*)s; 
  *lenptr = len;
  for(int j = 0; j < len; j++){
    s[j+1] = init [j];
  }
}

void pls_print(char *s){
  unsigned char *lenptr = (unsigned char *)s;
  for (int j = 0; j < *lenptr; j++){
    putchar(s[j+1]);
  }
  printf("\n");
}

int main(void){
  char buf[256];
  pls_init(buf, "Hello World", 11);
  pls_print(buf);
  char buf1[256];
  pls_init(buf1, "Hell\000 World", 11);
  pls_print(buf1);
  return 0;
}
