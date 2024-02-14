#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);

    assert(v.size == 1);
    assert(v.data[0] == 1);
    assert(v.capacity == 1);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 4);
    assert(*atVector(&v, 0) == 1);

    clear(&v);
    pushBack(&v, 5);
    pushBack(&v, 42);
    pushBack(&v, 1);
    assert(*atVector(&v, 1) == 42);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 4);
    assert(*atVector(&v, 2) == 4);

    clear(&v);
    pushBack(&v, 5);
    pushBack(&v, 42);
    pushBack(&v, 1);
    assert(*atVector(&v, 2) == 1);
}

void test_back_oneElementInVector() {
    vector v = createVector(3);
    pushBack(&v, 8);
    assert(*back(&v) == 8);

    clear(&v);
    pushBack(&v, 42);
    assert(*back(&v) == 42);
}

void test_front_oneElementInVector() {
    vector v = createVector(3);
    pushBack(&v, 8);
    assert(*front(&v) == 8);

    clear(&v);
    pushBack(&v, 42);
    assert(*front(&v) == 42);
}

void test() {
    test_pushBack();
    test_popBack_notEmptyVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}