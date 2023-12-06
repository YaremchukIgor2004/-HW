#include <stdio.h>

// Lab 7 Task 5

void count_odd_even(const int* arr, int n, int* odd, int* even) {
    *odd = 0;
    *even = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            (*even)++;
        }
        else {
            (*odd)++;
        }
    }
}

int main(void) {
    int arr[50];
    int n = 50;
    for (int i = 0; i < 50; i++) {
        printf("a[%d] = ", i);
        scanf("%d", arr + i);
        if (arr[i] == 0) {
            n = i;
            break;
        }
    }

    int odd, even;
    count_odd_even(arr, n, &odd, &even);
    printf("odd: %d, even: %d\n", odd, even);
}