#include <stdio.h>
#include <math.h>

float cosine(float x) {
    return cos(x);
}

float hypot(float a, float b) {
    return sqrt(a * a + b * b);
}

float triangleArea(float a, float b, float c) {
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

float polynomial(float x) {
    return 16 * x * x * x * x + 8 * x * x * x + 4 * x * x + 2 * x + 1;
}

float Rosenbrock2d(float x, float y) {
    return 100 * pow(x * x - y, 2) + pow(x - 1, 2);
}

void task1() {
    float x;
    printf("1) Введіть значення x для косинуса: ");
    scanf("%f", &x);
    printf("   Косинус(%.2f) = %.2f\n", x, cos(x));
}

void task2() {
    float a, b;
    printf("\n2) Введіть довжину катета a: ");
    scanf("%f", &a);
    printf("   Введіть довжину катета b: ");
    scanf("%f", &b);
    printf("   Гіпотенуза = %.2f\n", hypot(a, b));
}

void task3() {
    float side1, side2, side3;
    printf("\n3) Введіть довжину сторони a: ");
    scanf("%f", &side1);
    printf("   Введіть довжину сторони b: ");
    scanf("%f", &side2);
    printf("   Введіть довжину сторони c: ");
    scanf("%f", &side3);
    printf("   Площа трикутника = %.2f\n", triangleArea(side1, side2, side3));
}

void task4() {
    float x;
    printf("\n4) Введіть значення x для багаточлена: ");
    scanf("%f", &x);
    printf("   Значення багаточлена для x = %.2f: %.2f\n", x, polynomial(x));
}

void task5() {
    printf("\n5) Перевірка Rosenbrock2d:\n");
    printf("   Rosenbrock2d(2, 3) = %.2f\n", Rosenbrock2d(2, 3));
    printf("   Rosenbrock2d(0, 0) = %.2f\n", Rosenbrock2d(0, 0));
    printf("   Rosenbrock2d(-1, 1) = %.2f\n", Rosenbrock2d(-1, 1));
}

void task6() {
    float Ax, Ay, Bx, By, Cx, Cy;
    printf("\n6) Введіть координати вершин трикутника:\n");
    printf("   A (x y): ");
    scanf("%f %f", &Ax, &Ay);
    printf("\n");
    printf("   B (x y): ");
    scanf("%f %f", &Bx, &By);
    printf("\n");
    printf("   C (x y): ");
    scanf("%f %f", &Cx, &Cy);

    float sideA = hypot(Bx - Cx, By - Cy);
    float sideB = hypot(Cx - Ax, Cy - Ay);
    float sideC = hypot(Ax - Bx, Ay - By);
    printf("   Площа трикутника = %.2f\n", triangleArea(sideA, sideB, sideC));
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();

    return 0;
}