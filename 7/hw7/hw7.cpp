#include <stdio.h>

//8.25
void swapRows(int matrix[][3], int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void swapCols(int matrix[][3], int col1, int col2, int rows) {
    for (int i = 0; i < rows; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

int main() {
    int rows, cols;
    printf("n*m: ");
    scanf("%d", &rows);
    cols = rows;

    int matrix[3][3]; 

    printf("Input element of matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int minPositive = -1;
    int minRow = -1;
    int minCol = -1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 0 && (minPositive == -1 || matrix[i][j] < minPositive)) {
                minPositive = matrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    if (minPositive != -1) {
        swapRows(matrix, minRow, minCol, cols);
        swapCols(matrix, minRow, minCol, rows);

        printf("\nNew matrix:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("\nThe matrix does not contain positive elements.\n");
    }

    return 0;
}
