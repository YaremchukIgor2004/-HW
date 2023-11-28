#include <stdio.h>
#include <math.h>

void task1() {
    int number;
    printf("������ ���������� ��������� �����: ");
    scanf("%d", &number);

    int units = number % 10;
    int tens = (number / 10) % 10;
    int hundreds = number / 100;
    printf("�������: %d, �������: %d, ������: %d\n", units, tens, hundreds);

    int sum = units + tens + hundreds;
    printf("���� ����: %d\n", sum);


    int reversedNumber = units * 100 + tens * 10 + hundreds;
    printf("c) ����������� �����: %d\n", reversedNumber);
}

void task2() {
    int number;
    printf("������ ���������� ��������� �����: ");
    scanf("%d", &number);

    int units = number % 10;
    int tens = (number / 10) % 10;
    int hundreds = number / 100;

    if (units != tens && tens != hundreds && units != hundreds) {
        printf("�� ������ ������������: %d%d%d, %d%d%d, %d%d%d\n",
            units, tens, hundreds, units, hundreds, tens, tens, units, hundreds);
    }
    else {
        printf("������� ������� �����.\n");
    }
}

void task3() {
    int num1, num2, num3;
    printf("������ ��� ����� �����, ��������� ����� ����: ");
    scanf("%d, %d, %d", &num1, &num2, &num3);

    if (abs(num1) < 1024 && abs(num2) < 1024 && abs(num3) < 1024) {
        int product = num1 * num2 * num3;
        printf("������� �����: %d\n", product);
    }
    else {
        printf("�� �� ����� ���������� ������ ����� 2^10.\n");
    }
}

void task5() {
    int num1, num2;
    printf("������ ����� �����: ");
    scanf("%d", &num1);
    printf("������ ����� �����: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        printf("%d ����� �� %d\n", num1, num2);
    }
    else if (num1 < num2) {
        printf("%d ����� �� %d\n", num1, num2);
    }
    else {
        printf("����� ��� �� �����\n");
    }
}

void task6() {
    double a, b, c;
    printf("������ ��� ������ �����: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double maxMagnitude = fmax(fabs(a), fmax(fabs(b), fabs(c)));
    double minMagnitude = fmin(fabs(a), fmin(fabs(b), fabs(c)));

    printf("�������� �� �������: %f\n", maxMagnitude);
    printf("�������� �� �������: %f\n", minMagnitude);
}

void task7() {
    double a, b, c;
    printf("������ ����������� a, b, c ��� ������� ax^2 + bx + c = 0: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        printf("г������ �� ��� ����'����.\n");
    }
    else if (discriminant == 0) {
        printf("г������ �� ���� ����'����.\n");
    }
    else {
        printf("г������ �� ��� ��������� ����'����.\n");
    }
}

int main() {
    task1();
    task2();
    task3();
    task5();
    task6();
    task7();

    return 0;
}
