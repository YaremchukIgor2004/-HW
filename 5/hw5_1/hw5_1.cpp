#include <stdio.h>
#include <math.h>

//5.11.ã
double calculate_ak(int k) {
    if (k == 1) {
        return 0;
    }
    else if (k == 2) {
        return 1;
    }
    else {
        return calculate_ak(k - 1) + calculate_ak(k - 2) * tgamma(k - 1);
    }
}

double calculate_Sn(int n) {
    double sum = 0;
    for (int k = 1; k <= n; k++) {
        sum += tgamma(k) * calculate_ak(k);
    }
    return sum;
}

int main() {
    int n;

    printf("n: ");
    scanf("%d", &n);

    printf("Sum Sn = %lf\n",calculate_Sn(n));

    return 0;
}