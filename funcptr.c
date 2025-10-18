#include <stdio.h>

int main(void); // function prototype

void hello(void) {
    printf("Hello, World!\n");
}
void baubau(void) {
    printf("Baubau, World!\n");
}

void call_n_times(int n, void (*func)(void)) {
    while (n--){
        func();
    }
}

int main() {
    printf("%p\n", main); // print main address

    int (*myf)(void); // function pointer
    myf = main;       // assign main to function pointer
    printf("%p\n", myf);
    
    // myf(); // call main via function pointer

    // void (*x)(void); 
    // x = hello;
    // x();
    // x = baubau;
    // x();

    call_n_times(3, hello);
    call_n_times(2, baubau);

    return 0;
}