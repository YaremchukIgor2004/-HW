#include <stdio.h>

// Lab 5 Task 6

// a)
double b_n(double b, unsigned n) {
    double bn = b;
    while (n--) {
        bn = b + 1. / bn;
    }
    return bn;
}

// b)
double l_n(unsigned n) {
    double ln = 4 * n + 2;
    while (n--) {
        ln = 4. * n + 2. + 1. / ln;
    }
    return ln;
}

// c)
double x_2n(unsigned n) {
    double x_2n = 1.5;
    while (n--) {
        x_2n = 1. / (1. / x_2n + 2.) + 1.;
    }
    return x_2n;
}


int main(void) {
    double b;
    unsigned n;
    scanf("%lf%u", &b, &n);

    // a)
    printf("a) b_n(%lf, %u) = %lf\n", b, n, b_n(b, n));
    // b)
    printf("b) l_n(%u) = %lf\n", n, l_n(n));
    // c)
    printf("c) x_2n(%u) = %lf\n", n, x_2n(n));
}