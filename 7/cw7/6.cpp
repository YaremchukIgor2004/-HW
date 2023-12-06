#include <stdio.h>

// Lab8 task 6

#define N 100
#define M 100

int main(void) {
    double a[N][M];

    unsigned n, m;
    scanf("%u%u", &n, &m);
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < m; j++)
            scanf("%lf", &a[i][j]);

    int k;
    scanf("%d", &k);
    unsigned k2 = k > 0 ? (unsigned)k : 0 - (unsigned)k;
    double sum = 0.;
    for (unsigned i = 0; i < n; i++) {
        // i - j = k
        unsigned j = i - k2;
        if (j < m) {
            sum += a[i][j];
        }
    }
    printf("%lf\n", sum);
}