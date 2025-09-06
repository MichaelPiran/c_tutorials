#include <stdio.h>

// **argv puntatote di puntatore a array di char
// argv contien eun indirizzo di memoria  al quale sono memnorizzati altri indirizzi di memoria

int main(int argc, char **argv){
  for (int i=0; i<argc; i++){
    printf("%d: %s\n", i , argv[i]); 
  }
}
