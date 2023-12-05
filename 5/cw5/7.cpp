#include <stdio.h>

// Lab 5 Task 7

double sn(unsigned n) {
    if (n < 2) {
        return 2. * n;
    }
    double sum = 6., k2 = 4.;
    double a0 = 1., a1 = 0., b0 = 1.;
    for (unsigned i = 3; i <= n; i++) {
        b0 += a0;
        k2 *= 2.;
        double a_k = a0 / i + a1 * b0;
        a1 = a0;
        a0 = a_k;
        sum += k2 / (a0 + b0);
    }
    return sum;
}

int main(void) {
    unsigned n;
    scanf("%u", &n);

    printf("%lf", sn(n));
}