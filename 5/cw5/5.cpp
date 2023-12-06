#include <stdio.h>

// Lab 5 Task 5

int main(void) {
    int a = -99, b = -99, c = -99;
    unsigned n = 3;
    while (a <= 0) {
        int t = a + c + 100;
        c = b;
        b = a;
        a = t;
        n++;
    }
    printf("s[%u] = %d\n", n, a);
}