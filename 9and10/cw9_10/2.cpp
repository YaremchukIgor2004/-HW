#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include <ctype.h>

// Lab 10 Task 2

typedef struct {
    uint8_t r : 3;
    uint8_t f : 3;
} ChessSquare;

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

bool can_queen_move(ChessSquare from, ChessSquare to) {
    return from.r == to.r || from.f == to.f ||
        from.r - from.f == to.r - to.f ||
        from.r + from.f == to.r + to.f;
}

int main(void) {
    ChessSquare a, b;
    bool is_corect_input = input_square(&a) && input_square(&b);
    if (!is_corect_input) {
        printf("incorrect input\n");
        return 0;
    }
    printf("%s", can_queen_move(a, b) ? "true" : "false");
}