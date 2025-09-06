#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <unistd.h>

// utilizzo reference counting

struct pls {
  uint32_t len;
  uint32_t ref_count;
  uint32_t magic; 
  char str[];
};

char* pls_create(char *init, int len){
  struct pls *p = malloc(sizeof(struct pls) + len + 1);
  p->len = len;
  p->ref_count = 1;
  p->magic = 0xDEADBEEF;
  for(int j = 0; j < len; j++){
    p->str[j] = init[j];
  }
  p->str[len] = 0; // termino la stringa
  return p->str;
}

void pls_print(char *s){
  struct pls *p = (struct pls*)(s - sizeof(*p)); // uguale a s - sizeof(struct pls)
  for (int j = 0; j < p->len; j++) {
    putchar(p->str[j]);
  }
  printf("\n");
}

void pls_free(char *s){
  free(s - sizeof(struct pls));
}

void pls_validate(struct pls *p){
  if (p->magic != 0xDEADBEEF){
    printf("Invalid string: Aborting\n");
    exit(1);
  }
}

// drop the ref count of the string object
// free the object if ref count=0
void pls_release(char *s){
  struct pls *p = (struct pls*)(s - sizeof(*p));
  printf("Release - Current ref_count is: %d\n", (int)p->ref_count); 

  pls_validate(p);

  p->ref_count --;
  if(p->ref_count == 0){
    p->magic = 0;
    pls_free(s);
  }
}

// Increase ref counting of the string object
void pls_retain(char *s){
  struct pls *p = (struct pls*)(s - sizeof(*p));
//  printf("Retain - Current ref_count is: %d\n", (int)p->ref_count);
  if (p->ref_count == 0){
    printf("Aborted on retain of illegal string\n");
    exit(1);
  }
  p->ref_count++;
}

uint32_t pls_len(char *s){
  uint32_t *lenptr = (uint32_t *)(s-4);
  return *lenptr;
}

char *global_string;

int main(void){
  char *mystr = pls_create("Hello WorldHelloWorldHello World", 33);
  global_string = mystr;
  pls_retain(mystr);

  pls_print(mystr);
  pls_print(mystr);
  printf("%s %d\n", mystr, (int)pls_len(mystr));

  pls_release(mystr);
  printf("%s\n", global_string);
  pls_release(mystr);
  pls_release(mystr); // puntera a qualcosa che non esiste più
  return 0;
}
