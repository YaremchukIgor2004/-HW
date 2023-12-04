#include <stdio.h>
#include <math.h>

void task1() {
    int number;
    printf("Введіть натуральне тризначне число: ");
    scanf("%d", &number);

    int units = number % 10;
    int tens = (number / 10) % 10;
    int hundreds = number / 100;
    printf("Одиниць: %d, Десятків: %d, Сотень: %d\n", units, tens, hundreds);

    int sum = units + tens + hundreds;
    printf("Сума цифр: %d\n", sum);


    int reversedNumber = units * 100 + tens * 10 + hundreds;
    printf("c) Перевернуте число: %d\n", reversedNumber);
}

void task2() {
    int number;
    printf("Введіть натуральне тризначне число: ");
    scanf("%d", &number);

    int units = number % 10;
    int tens = (number / 10) % 10;
    int hundreds = number / 100;

    if (units != tens && tens != hundreds && units != hundreds) {
        printf("Всі можливі перестановки: %d%d%d, %d%d%d, %d%d%d\n",
            units, tens, hundreds, units, hundreds, tens, tens, units, hundreds);
    }
    else {
        printf("Існують однакові числа.\n");
    }
}

void task3() {
    int num1, num2, num3;
    printf("Введіть три цілих числа, записаних через кому: ");
    scanf("%d, %d, %d", &num1, &num2, &num3);

    if (abs(num1) < 1024 && abs(num2) < 1024 && abs(num3) < 1024) {
        int product = num1 * num2 * num3;
        printf("Добуток чисел: %d\n", product);
    }
    else {
        printf("Не всі числа гарантовані модулю менше 2^10.\n");
    }
}

void task5() {
    int num1, num2;
    printf("Введіть перше число: ");
    scanf("%d", &num1);
    printf("Введіть друге число: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        printf("%d більше за %d\n", num1, num2);
    }
    else if (num1 < num2) {
        printf("%d менше за %d\n", num1, num2);
    }
    else {
        printf("Числа рівні між собою\n");
    }
}

void task6() {
    double a, b, c;
    printf("Введіть три дійсних числа: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double maxMagnitude = fmax(fabs(a), fmax(fabs(b), fabs(c)));
    double minMagnitude = fmin(fabs(a), fmin(fabs(b), fabs(c)));

    printf("Найбільше за модулем: %f\n", maxMagnitude);
    printf("Найменше за модулем: %f\n", minMagnitude);
}

void task7() {
    double a, b, c;
    printf("Введіть коефіцієнти a, b, c для рівняння ax^2 + bx + c = 0: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        printf("Рівняння має два розв'язки.\n");
    }
    else if (discriminant == 0) {
        printf("Рівняння має один розв'язок.\n");
    }
    else {
        printf("Рівняння має два комплексні розв'язки.\n");
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
