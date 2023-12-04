#include <stdio.h>
#include <math.h>

// Lab 4 Task 2

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d! = 1", n);
    for (int i = 2; i <= n; i++) {
        printf("*%d", i);
    }
    printf("\n%d! = %d", n, n);
    for (int i = n - 1; i >= 1; i--) {
        printf("*%d", i);
    }
    putchar('\n');
}