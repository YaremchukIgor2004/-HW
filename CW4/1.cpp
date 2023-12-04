#include <stdio.h>
#include <math.h>


double rec_sin_n(int n, double x) {
    for (int i = 0; i < n; i++) {
        x = sin(x);
    }
    return x;
}

int main(void) {
    int n;
    double x;
    scanf("%d%lf", &n, &x);
    printf("%lf", rec_sin_n(n, x));
}