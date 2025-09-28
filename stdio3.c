#include <stdio.h>
#include <unistd.h>

int main(void){
  // before wait 5 sec and then print
  // if i put \n it prints anc then sleep
  // ==> the output buffer is emptied when \n is met and other...
  // printf, putchar non chiamamno direttamente la funzione di sistema, ma riempiono un buffer
  printf("Hello Workd!");
  sleep(5);
  return 0;
}

