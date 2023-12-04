#include <stdio.h>
#include <math.h>

// Lab 4 Task 3

double t4_a(int n, double x) {
    double xpow = 1.;
    double sum = 1.;

    for (int i = 0; i < n; i++) {
        xpow *= x;
        sum += xpow;
    }

    return sum;
}

double t4_b(int n, double x, double y) {
    double xpow = 1., ypow = 1.;
    double sum = 1.;

    double x2 = x * x;

    for (int i = 0; i < n; i++) {
        xpow *= x2;
        ypow *= y;
        sum += xpow * ypow;
    }

    return sum;
}

int main(void) {
    printf("a) %lf\n", t4_a(3, 2.));
    printf("b) %lf\n", t4_b(4, 1., 2.));
}