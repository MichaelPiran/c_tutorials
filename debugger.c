#include <stdio.h>

/*
  Install gdb: 
  	sudo apt install gdb
  Compile:
  	gcc -g debugger.c
  Run:
  	gbd ./a.out
  Command:
  	l 			-> list code
	r 			-> run code
	info break 		-> list all brakpoints
	b file.c:N 		-> set breakpoint in file.c at line N
	disable/enable N 	-> disable/enable breakpoint number
	n			-> next line
	q			-> quit
	...
*/

int main(void){
  int a = 12;
  int b = 10;
  int x = a + b;
  printf("%d\n", x);
  x = 0;
  return 0;
}
