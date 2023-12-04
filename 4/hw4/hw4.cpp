#include <stdio.h>

//4.18.�
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        unsigned long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

// ������� ��� ��������� ����� �� �������
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double calculateAnswer(double x, int k) {
    return power(x, 2 * k + 1) / factorial(2 * k + 1);
}

int main() {
    double x;
    printf("������ �������� x: ");
    scanf("%lf", &x);

    int n;
    printf("������ ������� �������� ����������� (n): ");
    scanf("%d", &n);

    printf("����������� ��������:\n");
    for (int k = 0; k < n; ++k) {
        double element = calculateAnswer(x, k);
        printf("x_%d = %lf\n", k, element);
    }

    return 0;
}