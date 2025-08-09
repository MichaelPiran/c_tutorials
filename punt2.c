#include <stdio.h>

int main(void){
  char mystr[] = "Hello world";
  char *p = mystr; // because array does not need &mystr

  printf("At %p i can see: %s\n", mystr, mystr);
  printf("%c%c\n", p[0], p[1]);
  printf("%c%c\n", *p, *(p+1));
  
  short *p1 = (short*) mystr;
  p1++; // incr the pointer of the dimension of type, so 2 byte (short)
  printf("%d\n", *p1); //print the ascii charcarcter
  printf("%c\n", *p1);
  p1++; 
  printf("%d\n", *p1); 
  printf("%c\n", *p1); 
  p1++; 
  printf("%d\n", *p1); 
  printf("%c\n", *p1); 


  return 0;
}
