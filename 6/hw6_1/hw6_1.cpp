#include <stdio.h>
#include <float.h>

//7.9.æ
int main() {
    int n;
    printf("(n): ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Incorrect n.\n");
        return 1;
    }
    double min_a = DBL_MAX;
    double min_a_squared = DBL_MAX;

    for (int i = 0; i < n; i++) {
        double a;
        printf("a%d: ", i + 1);
        scanf("%lf", &a);
        min_a = (a < min_a) ? a : min_a;
        min_a_squared = (a * a < min_a_squared) ? a * a : min_a_squared;
    }

    double result = min_a * min_a - min_a_squared;
    printf("Result: %lf\n", result);

    return 0;
}

