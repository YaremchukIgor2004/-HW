#include <stdio.h>

double polynom1(double x, double y) {
    return x * x * y * y + x * x * x * y * y * y + x * x * x * x * y * y * y * y;
}

double polynom2(double x, double y) {
    return x + y + x * x + y * y + x * x * x + y * y * y + x * x * x * x + y * y * y * y;
}

int main() {
    double x, y;

    printf("Введіть значення x: ");
    scanf("%lf", &x);
    printf("Введіть значення y: ");
    scanf("%lf", &y);

    printf("Результат для многочлена 1: %.2f\n", polynom1(x, y));
    printf("Результат для многочлена 2: %.2f\n", polynom2(x, y));
}
