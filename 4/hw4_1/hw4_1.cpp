#include <stdio.h>
#include <math.h>
//4.27.ж


double calculatePi(double epsilon) {
    double pi = 0.0;
    double term = 1.0;
    int k = 1;

    while (term >= epsilon) {
        term = 0.0;
        for (int m = 1; m <= k; ++m) {
            term += 1.0 / pow((4 * m - 2), k);
        }

        pi += term;
        ++k;
    }

    return pi * 8;
}

int main() {
    double epsilon;
    printf("Введіть точність (ε): ");
    scanf("%lf", &epsilon);

    double result = calculatePi(epsilon);

    printf("Pi з точністю %.15lf: %.15lf\n", epsilon, result);

    return 0;
}
