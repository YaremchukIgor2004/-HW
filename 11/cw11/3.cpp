#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Lab 11 Task 3

bool has_3_divs(int num) {
    int i = 2;
    while (i * i < num) {
        if (num % i == 0) return false;
        i++;
    }
    return i * i == num;
}

int main(void) {
    char f_filename[256];
    char g_filename[256];

    scanf("%255s", f_filename);
    scanf("%255s", g_filename);

    FILE* f_file = fopen(f_filename, "wb");
    FILE* g_file = fopen(g_filename, "wb");

    int num;
    while (scanf("%d", &num) == 1 && num != 0) {
        fwrite(&num, sizeof(int), 1, f_file);
        if (has_3_divs(num)) {
            fwrite(&num, sizeof(int), 1, g_file);
        }
    }

    fclose(f_file);
    fclose(g_file);
}