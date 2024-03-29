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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isEmpty(v)) {
        reserve(v, 1);
        v->data[0] = x;
        v->size++;
    } else {
        if (isFull(v))
            reserve(v, v->capacity * 2);

        v->data[v->size] = x;
        v->size++;
    }
}

void popBack(vector *v) {
    if (!isEmpty(v)) {
        v->size--;
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

int *atVector(vector *v, size_t index) {
    return &v->data[index];
}

int *back(vector *v) {
    return &v->data[v->size - 1];
}

int *front(vector *v) {
    return &v->data[0];
}