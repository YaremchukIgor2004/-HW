#include <stdio.h>

int main() {
    float x, y;

    printf("Введіть значення x: ");
    scanf("%f", &x);

    y = 16 * x * x * x * x + 8 * x * x * x + 4 * x * x + 2 * x + 1;

    printf("Значення многочлена для x = %.2f: %.2f\n", x, y);
}
