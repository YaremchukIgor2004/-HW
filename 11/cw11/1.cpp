#include <stdio.h>
#include <stdlib.h>

// Lab 11 Task 1

void write_nums(const double* nums, size_t n, FILE* file) {
    fwrite(nums, sizeof(double), n, file);
}

void read_print_nums(FILE* file) {
    double num;
    while (!feof(file)) {
        if (fread(&num, sizeof(double), 1, file) != 1) {
            break;
        }
        printf("%lf,", num);
    }
    putchar('\n');
}

int main(void) {
    size_t n;
    scanf("%zu", &n);

    double* numbers = (double*)malloc(sizeof(double) * n);
    for (size_t i = 0; i < n; i++) {
        scanf("%lf", numbers + i);
    }

    char filename[256];
    scanf("%255s", filename);

    FILE* f = fopen(filename, "wb");
    write_nums(numbers, n, f);
    fclose(f);
    free(numbers);

    f = fopen(filename, "rb");
    read_print_nums(f);
    fclose(f);
}