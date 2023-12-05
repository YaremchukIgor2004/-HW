#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Lab 9 Task 3

typedef struct {
    double* data;
    size_t size;
} Vec;

static inline Vec vec_allocate(size_t size) {
    return (Vec) { .data = (double*)malloc(sizeof(double) * size), .size = size };
}

static inline void vec_free(Vec vec) {
    if (vec.data) free(vec.data);
}

static inline Vec vec_null() {
    return (Vec) { .data = 0, .size = 0 };
}

static inline Vec vec_input(size_t size) {
    const Vec vec = vec_allocate(size);
    double* v = vec.data;
    while (size--) scanf("%lf", v++);
    return vec;
}

static inline bool vec_is_valid(Vec vec) {
    return vec.data != 0;
}

static inline Vec vec_sub(Vec a, Vec b) {
    if (a.size != b.size || !vec_is_valid(a) || !vec_is_valid(b)) {
        return vec_null();
    }
    Vec c = vec_allocate(a.size);
    for (size_t i = 0; i < a.size; i++) {
        c.data[i] = a.data[i] - b.data[i];
    }
    return c;
}

int main(void) {
    size_t n;
    scanf("%zu", &n);

    Vec a = vec_input(n);
    Vec b = vec_input(n);
    Vec c = vec_sub(a, b);

    if (vec_is_valid(c)) {
        for (size_t i = 0; i < n; i++) {
            printf("%lf ", c.data[i]);
        }
    }

    vec_free(a);
    vec_free(b);
    vec_free(c);
}