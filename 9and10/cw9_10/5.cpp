#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Lab 10 Task 5

#define MAX_NAME_SIZE 32

typedef struct {
    const char* name;
    double height;
} MountainData;

MountainData mntn_input() {
    char* name = malloc(MAX_NAME_SIZE);
    MountainData data = {
        .name = name,
    };
    printf("name ?= ");
    scanf("%s", name);
    printf("height ?= ");
    scanf("%lf", &data.height);
    return data;
}

void mntn_display(const MountainData* data) {
    printf("%s: %lf\n", data->name, data->height);
}

int mntn_find_heightest(const MountainData* data, int count) {
    double h = -1.;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (data[i].height > h) {
            h = data[i].height;
            index = i;
        }
    }
    return index;
}

int mntn_find_by_name(const MountainData* data, int count, const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    unsigned n;
    scanf("%n", &n);
    MountainData* data = (MountainData*)malloc(sizeof(MountainData) * n);
    for (unsigned i = 0; i < n; i++) {
        data[i] = mntn_input();
    }

    char name_buf[MAX_NAME_SIZE];
    scanf("%s", name_buf);

    int index = mntn_find_by_name(data, n, name_buf);
    if (index >= 0) {
        printf("h: %lf\n", data[index].height);
    }

    for (unsigned i = 0; i < n; i++) {
        free((void*)data[i].name);
    }
    free(data);
}