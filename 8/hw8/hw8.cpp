#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** createMatrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

void fillRandom(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;  // random number between 0 and 1
        }
    }
}

void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addColumn(double** matrix, int rows, int* cols) {
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)realloc(matrix[i], (*cols + 1) * sizeof(double));

        for (int j = *cols; j > 0; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }

        matrix[i][0] = (double)rand() / RAND_MAX;
    }

    (*cols)++;
}

int findMaxRow(double** matrix, int rows, int cols) {
    int maxRow = 0;
    double maxElement = matrix[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
            }
        }
    }

    return maxRow;
}

void addRowAfterMax(double** matrix, int* rows, int cols) {
    int maxRow = findMaxRow(matrix, *rows, cols);
    matrix = (double**)realloc(matrix, (*rows + 1) * sizeof(double*));
    for (int i = *rows; i > maxRow + 1; i--) {
        matrix[i] = matrix[i - 1];
    }
    matrix[maxRow + 1] = (double*)malloc(cols * sizeof(double));
    for (int j = 0; j < cols; j++) {
        matrix[maxRow + 1][j] = (double)rand() / RAND_MAX;
    }
    (*rows)++;
}

int main() {
    srand(time(NULL));
    int N, M;
    printf("Enter the number of rows (N): ");
    scanf("%d", &N);
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);

    double** matrix = createMatrix(N, M);
    fillRandom(matrix, N, M);

    printf("Initial matrix:\n");
    printMatrix(matrix, N, M);

    addColumn(matrix, N, &M);
    printf("\nMatrix after adding a column to the beginning:\n");
    printMatrix(matrix, N, M);

    addRowAfterMax(matrix, &N, M);
    printf("\nMatrix after adding a row after the row with the maximum element:\n");
    printMatrix(matrix, N, M);


    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
