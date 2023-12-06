//1.11
#include <stdio.h>
#include <math.h>

void task11() {
    char str1[] = "Hello";
    char str2[] = "World";

    printf("!!!");
    printf(" %s, %s ", str1, str2);
    printf("!!!");
    printf("\n");
}

//1.16
void task16() {
    printf("x----|-1-|-2-|-3-|-4-|-5-|\n");
    printf("------|---|---|---|---|---|\n");
    printf("F(x)|%.2f|%.2f|%.2f|%.2f|%.2f|\n", exp(-1), exp(-4), exp(-9), exp(-16), exp(-25));
    printf("    |%.2f|%.2f|%.2f|%.2f|%.2f|\n", sqrt(1), sqrt(2), sqrt(3), sqrt(4), sqrt(5));
}

int main() {
    task11();
    task16();
}