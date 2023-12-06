#include <stdio.h>
#include <math.h>

//5.16.g
double calculate_y(double x, double epsilon) {
    double term = 1.0;
    double y = term;
    int n = 1; 

    while (fabs(term) >= epsilon) {
        term *= x / n; 
        y += term; 
        n++;
    }

    return y;
}

int main() {
    double x, epsilon;

    printf("x: ");
    scanf("%lf", &x);

    printf("epsilon: ");
    scanf("%lf", &epsilon);

    double result = calculate_y(x, epsilon);
    printf("e^%lf = %lf\n", x, result);

    return 0;
}