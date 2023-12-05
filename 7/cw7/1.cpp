#include <stdio.h>

// Lab 8 task 1

int main(void) {
    int mat[3][3] = { {1,2,3,}, {4,5,6}, {7,8,9} };
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[i][j] == m)
                mat[i][j] = n;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", mat[i][j]);
        putchar('\n');
    }
}