#include <stdio.h>
#include <string.h>
#include <limits.h>

// union tells the two field start at the same memory location
// Diferent objects are stored in the same memory location
struct foo{
    union { 
        int i;
        unsigned char a[4];
    };
};

int main() {
    struct foo f;

    f.i = INT_MAX;
    printf("%d [%d %d %d %d]\n", f.i, f.a[0], f.a[1], f.a[2], f.a[3]);

    f.i = INT_MIN;
    printf("%d [%d %d %d %d]\n", f.i, f.a[0], f.a[1], f.a[2], f.a[3]);

    f.i = -1;
    printf("%d [%d %d %d %d]\n", f.i, f.a[0], f.a[1], f.a[2], f.a[3]);

    return 0;
}