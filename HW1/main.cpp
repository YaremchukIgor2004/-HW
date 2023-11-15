#include <stdio.h>
#include <math.h>

// Задача 1
void task1() {
    int x_values[] = {1, 2, 3, 4, 5};
    double y_values[] = {3.0, 1.0, 5.0, 4.0, 2.1};

    printf("x | ");
    for (int i = 0; i < 5; i++) {
        printf("%d | ", x_values[i]);
    }
    printf("\n");
    printf("- | ");
    for (int i = 0; i < 5; i++) {
        printf("- - | ");
    }
    printf("\n");
    printf("y | ");
    for (int i = 0; i < 5; i++) {
        printf("%.1f | ", y_values[i]);
    }
    printf("\n");
}

// Задача 2
void task2() {
    char str1[] = "Hello";
    char str2[] = "World";

    printf("!!!");
    printf(" %s, %s ", str1, str2);
    printf("!!!");
    printf("\n");
}

// Задача 3
void task3() {
    double T = 365 + 1.0 / (4 + (1.0 / (7 + (1.0 / (1 + 1.0 / 3)))));
    printf("T = %.3lf\n", T);
}

// Задача 4
void task4() {
    double number = 10.0; // Замініть на ваше число
    double result = log10(number);
    printf("Log10(%.3lf) = %.3lf\n", number, result);
}

// Задача 5
void task5() {
    double a = 2.0; // Прискорення
    double t = 3.0; // Час
    double v = 12.0; // Швидкість
    double distance = 0.5 * a * t * t;
    double time_to_reach_v = v / a;

    printf("Distance: %.2lf\n", distance);
    printf("Time to reach v: %.2lf\n", time_to_reach_v);
}

// Задача 6
void task6() {
    double m = 5.0; // Маса
    double v = 10.0; // Швидкість
    double ke = 0.5 * m * v * v;
    printf("Kinetic Energy: %.2lf\n", ke);
}

// Задача 7
void task7() {
    printf("x----|-1-|-2-|-3-|-4-|-5-|\n");
    printf("------|---|---|---|---|---|\n");
    printf("F(x)|%.2f|%.2f|%.2f|%.2f|%.2f|\n", exp(-1), exp(-4), exp(-9), exp(-16), exp(-25));
    printf("    |%.2f|%.2f|%.2f|%.2f|%.2f|\n", sqrt(1), sqrt(2), sqrt(3), sqrt(4), sqrt(5));
}

// Задача 8
void task8() {
    double number = 1234.5678; // Замініть на ваше число
    double result = pow(number, 8);
    printf("%.20lf\n", result);
}

// Задача 9
void task9() {
    char board[] = {'O', 'X', ' ', ' ', 'X', 'O', 'X', 'O', ' '};

    printf("%c | %c | %c\n", board[0], board[1], board[2]);
    printf("---------\n");
    printf("%c | %c | %c\n", board[3], board[4], board[5]);
    printf("---------\n");
    printf("%c | %c | %c\n", board[6], board[7], board[8]);
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();

    return 0;
}
