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
    printf("1) ������ �������� x ��� ��������: ");
    scanf("%f", &x);
    printf("   �������(%.2f) = %.2f\n", x, cos(x));
}

void task2() {
    float a, b;
    printf("\n2) ������ ������� ������ a: ");
    scanf("%f", &a);
    printf("   ������ ������� ������ b: ");
    scanf("%f", &b);
    printf("   ó�������� = %.2f\n", hypot(a, b));
}

void task3() {
    float side1, side2, side3;
    printf("\n3) ������ ������� ������� a: ");
    scanf("%f", &side1);
    printf("   ������ ������� ������� b: ");
    scanf("%f", &side2);
    printf("   ������ ������� ������� c: ");
    scanf("%f", &side3);
    printf("   ����� ���������� = %.2f\n", triangleArea(side1, side2, side3));
}

void task4() {
    float x;
    printf("\n4) ������ �������� x ��� �����������: ");
    scanf("%f", &x);
    printf("   �������� ����������� ��� x = %.2f: %.2f\n", x, polynomial(x));
}

void task5() {
    printf("\n5) �������� Rosenbrock2d:\n");
    printf("   Rosenbrock2d(2, 3) = %.2f\n", Rosenbrock2d(2, 3));
    printf("   Rosenbrock2d(0, 0) = %.2f\n", Rosenbrock2d(0, 0));
    printf("   Rosenbrock2d(-1, 1) = %.2f\n", Rosenbrock2d(-1, 1));
}

void task6() {
    float Ax, Ay, Bx, By, Cx, Cy;
    printf("\n6) ������ ���������� ������ ����������:\n");
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
    printf("   ����� ���������� = %.2f\n", triangleArea(sideA, sideB, sideC));
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