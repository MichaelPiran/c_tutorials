#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp_int(const void *a, const void *b) { // constant pointers
    // -1 if a < b
    // 0 if a == b
    // 1 if a > b
    const int *ap = a;
    const int *bp = b;

    if (ap[0] < bp[0]) return -1;
    if (ap[0] > bp[0]) return 1;
    else return 0;
    // return *ap - *bp;
}
int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = rand() & 15; // random number between 0 and 15, always the same
    }
    a[2] = INT_MAX;
    a[3] = INT_MIN;
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    qsort(a, 10, sizeof(int), cmp_int);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}