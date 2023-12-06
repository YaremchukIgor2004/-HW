#include <stdio.h>

// Lab 5 Task 1

int main(void) {
    double a, s = 0.;
    scanf("%lf", &a);
    int n = 1;
    while (s < a) {
        s += 1. / n;
        n++;
    }
    printf("a) %lf\nb) n = %d\n", s, n - 1);
}