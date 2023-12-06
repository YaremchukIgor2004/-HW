#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Lab 11 Task 4

typedef struct {
    float x, y;
} Vertex;

typedef struct {
    Vertex a, b;
} Rect;

int max_rect_index(const char* filename, float* max_area_out) {
    FILE* f = fopen(filename, "rb");
    Rect r;
    int i = 0, max_i = 0;
    float max_area = 0.;
    while (!feof(f) && fread(&r, sizeof(r), 1, f) == 1) {
        float area = fabsf((r.a.x - r.b.x) * (r.a.y - r.b.y));
        if (area > max_area) {
            max_area = area;
            max_i = i;
        }
        i += 1;
    }
    fclose(f);
    if (max_area_out) {
        *max_area_out = max_area;
    }
    return i;
}

void replace_rect_index(const char* filename, int index, Rect r) {
    FILE* f = fopen(filename, "wb");
    fseek(f, index * sizeof(Rect), SEEK_SET);
    fwrite(&r, sizeof(Rect), 1, f);
    fclose(f);
}

int main(void) {
    const char* filename = "file.rects";
    // usage example
    replace_rect_index(filename, max_rect_index(filename, NULL), (Rect) { {0.f, 0.f}, { 1.f, 1.f } });
}