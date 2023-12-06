#include <stdio.h>
#include <stdlib.h>

//10.6.i
struct Vector {
    int size;
    double* elements;
};

struct Vector createVector(int size) {
    struct Vector vector;
    vector.size = size;
    vector.elements = (double*)malloc(size * sizeof(double));
    return vector;
}

void printVector(struct Vector vector) {
    printf("Vector (size: %d): [", vector.size);
    for (int i = 0; i < vector.size; i++) {
        printf("%.2f", vector.elements[i]);
        if (i < vector.size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void inputVector(struct Vector* vector) {
    printf("Enter the elements of the vector:\n");
    for (int i = 0; i < vector->size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%lf", &vector->elements[i]);
    }
}

// Функція для звільнення пам'яті, виділеної для вектора
void freeVector(struct Vector* vector) {
    free(vector->elements);
    vector->size = 0;
}

int main() {
    int size;
    printf("Enter the size of the vector: ");
    scanf("%d", &size);

    struct Vector myVector = createVector(size);

    inputVector(&myVector);
    printVector(myVector);
    freeVector(&myVector);

    return 0;
}
