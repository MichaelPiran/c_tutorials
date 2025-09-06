/*
 *  Similar as before
 *  increase the string length and improve quality of algorithm
 *  |LLLL|CCCC|My string here!
 *  4 byte di length + conto delle reference
 *  il reference counter non è implementato
 *  usare una struct per facilitare
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char* pls_create(char *init, int len){
  char *s = malloc(4+len+1); //alloco len +1 (string size)
  uint32_t *lenptr = (uint32_t*)s; 
//  uint32_t *count = (uint32_t*)(s+4);
  *lenptr = len;

  s += 4;
  for(int j = 0; j < len; j++){
    s[j] = init [j];
  }
  s[len] = 0; // termino la stringa
  return s;
}

void pls_print(char *s){
  uint32_t *lenptr = (uint32_t *)(s-4);
  for (int j = 0; j < *lenptr; j++){
    putchar(s[j]);
  }
  printf("\n");
}

void pls_free(char *s){
  free(s-4);
}

uint32_t pls_len(char *s){
  uint32_t *lenptr = (uint32_t *)(s-4);
  return *lenptr;
}

char *global_string;

int main(void){
  char *mystr = pls_create("Hello WorldHelloWorldHello World", 33);
  global_string = mystr;

  pls_print(mystr);
  printf("%s %d\n", mystr, (int)pls_len(mystr));
  pls_free(mystr);
  // global string is empty
  printf("%s\n", global_string);
  return 0;
}
