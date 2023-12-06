#include <stdio.h>
#include <math.h>

//Task 8

int main(void) {
    int k = 0, m;
    scanf("%d", &m);

    int i = 1;
    while (i * 4 <= m) {
        i *= 4;
        k++;
    }

    printf("%d\n", k);

    i = 1;
    k = 0;
    do {
        k++;
        i *= 4;
    } while (i <= m);

    printf("%d\n", k - 1);
}