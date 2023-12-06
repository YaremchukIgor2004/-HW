#include <stdio.h>

// Lab 8 task 2

int main(void) {
    double mat[3][3] = { {1.0, 2,3,}, {4,5,6}, {7,8,9} };

    {
        double a;
        int i, j;
        scanf("%d%d%lf", &i, &j, &a);

        if (0 <= i && i < 3 && 0 <= j && j < 3)
            mat[i][j] = a;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%lf ", mat[i][j]);
        putchar('\n');
    }
}