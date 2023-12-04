// 3.16
/* �������� �������� ���� �� �� ������ ���� ���� ��������, 
��������� ������ �� ����� �������� �� ���� ���� ������. 
���� ������� �� �������� ����� ���� ������, �� ���� �������������.
*/

#include <stdio.h>
#include <math.h>

int circleflag(double x1, double y1, double r1, double x2, double y2, double r2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (distance <= r1 + r2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    double x1, y1, r1, x2, y2, r2;

    printf("������ ���������� �� ����� ��� ������� ���� (x y radius): ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("������ ���������� �� ����� ��� ������� ���� (x y radius): ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    if (circleflag(x1, y1, r1, x2, y2, r2)) {
        printf("���� �������������\n");
    }
    else {
        printf("���� �� �������������\n");
    }

    return 0;
}
