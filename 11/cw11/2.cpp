#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Lab 11 Task 2

int main(void) {
    double a;
    scanf("%lf", &a);

    char f_filename[256];
    char f_filename_out[256];
    char g_filename[256];

    scanf("%255s", f_filename);
    scanf("%255s", g_filename);
    snprintf(f_filename_out, 256, "%s.tmp", f_filename);

    FILE* f_file = fopen(f_filename, "rb");
    FILE* f_file_out = fopen(f_filename_out, "wb");
    FILE* g_file = fopen(g_filename, "wb");

    double num;
    while (!feof(f_file) && fread(&num, sizeof(double), 1, f_file) == 1) {
        fwrite(&num, sizeof(double), 1, fabs(num) < a ? g_file : f_file_out);
    }

    fclose(f_file);
    fclose(f_file_out);
    fclose(g_file);

    remove(f_filename);
    rename(f_filename_out, f_filename);
}