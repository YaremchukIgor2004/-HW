#include <stdio.h>

// Lab 8 task 3

void read_mat(double* mat, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%lf", &mat[i * m + j]);
        }
}

int main(void) {
    double mat[20 * 20];
    int n, m;
    scanf("%u%u", &n, &m);
    read_mat(mat, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%lf ", mat[i * m + j]);
        putchar('\n');
    }
}