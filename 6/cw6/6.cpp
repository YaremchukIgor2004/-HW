#include <stdio.h>

// Lab 7 Task 6

void scan_vec(double* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("vec[%d] = ", i);
        scanf("%lf", array + i);
    }
}

void print_vec(const double* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("vec[%d] = %lf\n", i, array[i]);
    }
}

void vec_sum(const double* a, const double* b, double* c, int n) {
    while (n--) {
        *c++ = *a++ + *b++;
    }
}

double vec_dot(const double* a, const double* b, int n) {
    double result = 0;
    while (n--) {
        result += *a++ * *b++;
    }
    return result;
}

int main(void) {
    int n;
    scanf("%d", &n);

    double a[20], b[20], c[20];
    printf("vec_a:\n");
    scan_vec(a, n);
    printf("vec_b:\n");
    scan_vec(b, n);


    vec_sum(a, b, c, n);
    double prod = vec_dot(a, b, n);

    printf("dot: %lf\nsum:\n", prod);
    print_vec(c, n);
}