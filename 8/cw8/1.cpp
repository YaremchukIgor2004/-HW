#include <stdio.h>
#include <stdlib.h>

// Lab 9 Task 1

int main(void) {
    unsigned n;
    scanf("%u", &n);
    double* arr = (double*)malloc(n * sizeof(double));

    if (!arr)
        return EXIT_FAILURE;

    for (unsigned i = 0; i < n; i++) {
        scanf("%lf", arr + i);
    }

    double sqr_sum = 0.;
    for (unsigned i = 0; i < n; i++)
        sqr_sum += arr[i] * arr[i];

    printf("%lf\n", sqr_sum);

    free(arr);
}