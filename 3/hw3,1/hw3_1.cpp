//3.23.e
#include <stdio.h>
#include <math.h>


double isReLu(double a, double x) {
    if (x < 0) {
        return x / sqrt(1 + a * x * x);
    }
    else {
        return x;
    }
}

double derivativeIsReLu(double a, double x) {
    if (x < 0) {
        double denom = sqrt(1 + a * x * x);
        return (1 - a * x * x / (denom * denom * denom)) / denom;
    }
    else {
        return 1;
    }
}

int main() {
    double a, x;

    printf("Введіть значення параметра a: ");
    scanf("%lf", &a);
    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("isReLu(%f, %f) = %f\n", a, x, isReLu(a, x));
    printf("Похідна isReLu(%f, %f) = %f\n", a, x, derivativeIsReLu(a, x));

    return 0;
}
