#include <stdio.h>

// Lab 8 task 5

void transpose_mat(double* mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            double temp = mat[i * n + j];
            mat[i * n + j] = mat[j * n + i];
            mat[j * n + i] = temp;
        }
}

int main(void) {
    double mat[9] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    transpose_mat(mat, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%lf ", mat[i * 3 + j]);
        putchar('\n');
    }
}