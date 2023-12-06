#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Lab 9 Task 2

unsigned input_array(int** const arr) {
    int* m = (int*)malloc(sizeof(int) * 100), * m_beg = m, * m_end = m + 100;
    while (m < m_end) {
        scanf("%d", m);
        if (*m == 0) {
            break;
        }
        m++;
    }
    *arr = m_beg;
    return (unsigned)(m - m_beg);
}

int main(void) {
    int* arr;
    unsigned n = input_array(&arr);

    int squares = 0, cubes = 0;
    for (unsigned i = 0; i < n; i++) {
        int num = arr[i];
        bool is_sqruare = false, is_cube = false;
        // naive check
        for (int j = 1; j * j <= num; j++) {
            is_sqruare |= j * j == num;
            is_cube |= j * j * j == num;
        }
        squares += is_sqruare;
        cubes += is_cube;
    }
    printf("squares: %d cubes: %d\n", squares, cubes);
    free(arr);
}