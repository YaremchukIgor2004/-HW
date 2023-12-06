#include <stdio.h>

//7.11.b
double hermite_polynomial(int n, double x) {
    if (n == 0) {
        return 1.0;
    }
    else if (n == 1) {
        return 2.0 * x;
    }
    else {
        double Hn_minus_1 = 2.0 * x;
        double Hn_minus_2 = 1.0;
        double Hn = 0.0;

        for (int i = 2; i <= n; i++) {
            Hn = 2.0 * x * Hn_minus_1 - 2.0 * (i - 1) * Hn_minus_2;
            Hn_minus_2 = Hn_minus_1;
            Hn_minus_1 = Hn;
        }

        return Hn;
    }
}

void print_hermite_coefficients(int p) {
    for (int n = 0; n <= p; n++) {
        printf("H%d(x): ", n);

        for (int i = 0; i <= n; i++) {
            if (i > 0) {
                printf(" + ");
            }

            printf("%d * x^%d", (1 << (n - i - 1)), (n - i));
        }

        printf("\n");
    }
}

int main() {
    int p;
    printf("Polynome Hermite (p < 256): ");
    scanf("%d", &p);

    if (p < 0 || p >= 256) {
        printf("Incorrect p.\n");
        return 1;
    }

    printf("Polynome Hermite for %d:\n", p);
    print_hermite_coefficients(p);

    double x = 1.5;
    printf("\nPolynome Hermite H%d(%lf) = %lf\n", p, x, hermite_polynomial(p, x));

    return 0;
}
