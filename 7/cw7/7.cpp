#include <stdio.h>

// Lab8 task 7

#define N 32

double calc_det(double* mat, unsigned n, unsigned i, unsigned* p, unsigned used) {
    if (i == n) {
        unsigned inv_count = 0;
        for (unsigned j = 0; j < n; j++)
            for (unsigned k = j + 1; k < n; k++) {
                if (p[k] > p[j])
                    inv_count++;
            }

        double det = 1.;
        for (unsigned j = 0; j < n; j++)
            det *= mat[j * n + p[j]];

        return inv_count & 1 ? det : -det;
    }
    double sum = 0.;
    for (unsigned j = 0; j < n; j++) {
        if (~used >> j & 1) {
            p[i] = j;
            sum += calc_det(mat, n, i + 1, p, used | 1 << j);
        }
    }
    return sum;
}

int main(void) {
    double mat[N * N];
    unsigned perm[N];


    unsigned n;
    scanf("%u", &n);
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < n; j++) {
            //printf("m[%u][%u] = ", i, j);
            scanf("%lf", &mat[i * n + j]);
        }

    double det = calc_det(mat, n, 0, perm, 0);
    printf("det = %lf\n", det);
}