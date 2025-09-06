#include <stdio.h>
#include <stdlib.h>

char* pls_create(char *init, int len){
  char *s = malloc(1+len+1); //alloco len +1 (string size)
  unsigned char *lenptr = (unsigned char*)s; 
  *lenptr = len;
  for(int j = 0; j < len; j++){
    s[j+1] = init [j];
  }
  s[len+1] = 0; // termino la stringa
  return s;
}

void pls_print(char *s){
  unsigned char *lenptr = (unsigned char *)s;
  for (int j = 0; j < *lenptr; j++){
    putchar(s[j+1]);
  }
  printf("\n");
}

char *pls_get_c_string(char *s){
  return s+1;
}

int main(void){
  char *mystr = pls_create("Hello WorldHelloWorldHello World", 33);
  pls_print(mystr);

  printf("%s\n", mystr);
  printf("%s\n", pls_get_c_string(mystr));
  free(mystr);
  return 0;
}
