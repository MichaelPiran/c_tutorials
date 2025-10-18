#include <stdio.h>

struct foo {
    unsigned char a : 4;
    unsigned char b : 4;
    unsigned char c : 8;
};

int main() {
    struct foo f;
    printf("%zu\n", sizeof(f));
    f.a = 16;
    f.b = 2;
    f.c = 16;
    printf("%d %d %d\n", f.a, f.b, f.c);
    return 0;
}