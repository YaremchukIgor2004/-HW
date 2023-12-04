#include <stdio.h>
#include <math.h>

//Task 6

int main(void) {
    int n;
    scanf("%d", &n);

    double a = 0.;
    for (int i = 0; i < n; i++) {
        a = sqrt(a + 2.);
    }

    printf("a) %lf\n", a);

    double b = 0.;
    for (int i = 0; i < n; i++) {
        b = sqrt(3 * (n - i) + b);
    }

    printf("b) %lf\n", b);
}