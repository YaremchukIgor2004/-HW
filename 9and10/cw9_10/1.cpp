#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include <ctype.h>

// Lab 10 Task 1

typedef struct {
    uint16_t year;
    uint16_t month;
    uint16_t day;
} Date;

typedef struct {
    uint8_t r : 3;
    uint8_t f : 3;
} ChessSquare;

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point a, b;
} AARect;

typedef struct {
    size_t n;
    // array from n+1 element;
    double* coefficients;
} Poly;

void input_date(Date* date) {
    scanf("%" SCNu16 "%" SCNu16 "%" SCNu16, &date->day, &date->month, &date->year);
}

void print_date(const Date* date) {
    printf("%" PRIu16 ".%" PRIu16 ".%" PRIu16, date->day, date->month, date->year);
}

bool input_square(ChessSquare* square) {
    char f, r;
    if (2 != scanf("%c%c", &f, &r))
        return false;
    f = (char)toupper(f);
    if (f < 'A' || f > 'H' || r < '1' || r > '7')
        return false;
    square->f = f - 'A';
    square->r = r - '1';
    return true;
}

void print_square(const ChessSquare* square) {
    printf("%c%c", (char)(square->f + 'A'), (char)(square->r + '1'));
}

void input_rect(AARect* rect) {
    scanf("%f%f%f%f", &rect->a.x, &rect->a.y, &rect->b.x, &rect->b.y);
}

void print_rect(const AARect* rect) {
    printf("(%f, %f) (%f, %f)", rect->a.x, rect->a.y, rect->b.x, rect->b.y);
}

void free_poly(Poly* poly) {
    if (poly->coefficients) {
        free(poly->coefficients);
    }
}

void input_poly(Poly* poly) {
    free_poly(poly);
    size_t n;
    scanf("%zu", &n);
    poly->n = n;
    poly->coefficients = (double*)malloc(sizeof(double) * (n + 1));
    for (size_t i = 0; i <= n; i++) scanf("%lf", poly->coefficients + i);
}

void print_poly(const Poly* poly) {
    if (!poly || !poly->coefficients) return;
    printf("%zu", poly->n);
    for (size_t i = poly->n; i >= 1; i--)
        printf("%lf * x^%zu + ", poly->coefficients[i], i);
    printf("%lf", poly->coefficients[0]);
}

int main(void) {
    Poly poly = { 0 };
    input_poly(&poly);
    poly.coefficients[0] = 42;
    print_poly(&poly);
    free_poly(&poly);
}