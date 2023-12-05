#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Lab 7 Task 3

#define N 10

int main(void) {
    double a[N];
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", a + i);
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i] > M_E ? a[i] : 0;
    }
    printf("larger than e: %lf\n", sum);
}