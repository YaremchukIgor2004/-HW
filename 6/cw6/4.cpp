#include <stdio.h>

// Lab 7 Task 4

void scan_array(int(*array)[5]) {
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = ", i);
        scanf("%d", *array + i);
    }
}

int max_in_array(const int(*array)[5]) {
    int ret = (*array)[0];
    for (int i = 1; i < 5; i++) {
        if ((*array)[i] > ret) {
            ret = (*array)[i];
        }
    }
    return ret;
}

int main() {
    int arr[5];
    scan_array(&arr);
    int max = max_in_array(&arr);
    printf("max = %d\n", max);
}