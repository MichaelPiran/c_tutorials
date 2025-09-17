#include <stdio.h>
#include <ctype.h>

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
  FILE *fp = fopen("stdio1.c", "r");
  if (fp == NULL){
    printf("Unable to open file\n");
    return 1;
  }
   
  char buf[32];
  size_t nread;
  while(1){
    nread = fread(buf, 1, sizeof(buf), fp);
    if (nread == 0) break;
    hexdump(buf, nread);
  }
  fclose(fp);
  return 0;
}
