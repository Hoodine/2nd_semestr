#include "vector.h"
#include <stdio.h>
#include <malloc.h>

vector createVector(size_t n) {
    if (n == 0)
        return (vector) {NULL, 0, n};

    vector v1 = {malloc(sizeof(int) * n), 0, n};

    if (v1.data != NULL)
        return v1;
    else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    } else if (newCapacity < v->size) {
        v->data = realloc(v->data, sizeof(int) * newCapacity);
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else {
        v->data = realloc(v->data, sizeof(int) * newCapacity);
        v->capacity = newCapacity;

        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = v->capacity == v->size ?
              v->data :
              realloc(v->data, sizeof(int) * (v->capacity = v->size));
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}