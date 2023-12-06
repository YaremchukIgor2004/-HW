#include <stdio.h>
#include <stdint.h>

// Lab 5 Task 3

unsigned steps_to_1(uint64_t n) {
    unsigned steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = n * 3 + 1;
        }
        steps += 1;
    }
    return steps;
}

int main(void) {
    unsigned max_n = 0, max_steps = 0;
    for (unsigned i = 1; i <= 1000; i++) {
        unsigned steps = steps_to_1(i);
        if (steps > max_steps) {
            max_steps = steps;
            max_n = i;
        }
    }
    printf("max steps `%u` for numer %u\n", max_steps, max_n);
}