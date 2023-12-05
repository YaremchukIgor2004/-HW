#include <stdio.h>

// Lab 5 Task 4

int main(void) {
    unsigned n;
    scanf("%u", &n);

    double prod = 1., q = 1.;
    for (unsigned i = 1; i <= n; i++) {
        q /= i;
        prod *= 1. + q;
    }
    printf("a) %lf\n", prod);


    prod = 1., q = -1.;
    for (unsigned i = 3; i <= n; i++) {
        q *= i * i / -2.;
        prod *= 1. + q;
    }
    printf("b) %lf\n", prod);
}