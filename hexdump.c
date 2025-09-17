#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pls {
  long len; // non metto int per evitare il padding
  char *str; 
};
struct pls1 {
  long len;
  char str[20];
};

#define HEXDUMP_CHARS_PER_LINE 16
void hexdump(void *p, size_t len){
  unsigned char *byte = p;
  size_t po = 0; //print offset
  for (size_t j = 0; j < len; j++){
    printf("%02X", byte[j]);
    if ((j+1) % HEXDUMP_CHARS_PER_LINE == 0 || j == len-1){
      if (j == len-1){
        int pad = HEXDUMP_CHARS_PER_LINE - (len % HEXDUMP_CHARS_PER_LINE);
	pad %= HEXDUMP_CHARS_PER_LINE;
	for (int i = 0; i<pad; i++) printf("~~");
      }

      printf("\t");
      for (size_t i = po; i <= j; i++){
	int c = isprint(byte[i]) ? byte[i] : '.';
        printf("%c", (char)c );
      }
      printf("\n");
      po = j+1;
    }
  }
}

int main(void){
//  struct pls s; 

//  s.len = 10;
//  s.str = malloc(10+1);
  
  // literal string
//  memcpy(s.str, "1234567890", 11);

//  printf("%p\n", "1234567890"); // it prints the pointer of the litteral string
//  printf("---\n");

//  printf("%p\n", s.str);  
//  hexdump(&s, sizeof(s));
//  printf("---\n");

  struct pls1 s1;
//  memset(&s1, 0xff, sizeof(s1));
  s1.len = 10;
  memcpy(s1.str, "1234567890", 11);
  printf("%p\n", s1.str);  
  hexdump(&s1, sizeof(s1));
  printf("---\n");
  hexdump(&s1, sizeof(s1)-1);
  printf("---\n");
  hexdump(&s1, sizeof(s1)-4);
  printf("---\n");
  hexdump(&s1, sizeof(s1)-3);
  printf("---\n");

  printf("%p\n", &s1);
  printf("%p\n", s1.str); // si trova 8 byte dopo
  return 0;
}

