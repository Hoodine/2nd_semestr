#include "libs/data_structures/matrix/matrix.h"
#include "assert.h"
#include <stdlib.h>

void task1(matrix *m) {
    int max, min;
    max = getMaxValuePos(*m).rowIndex;
    min = getMinValuePos(*m).rowIndex;

    swapRows(m, max, min);
}

void test_task1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9},
                                     3, 3);
    matrix exp_res = createMatrixFromArray((int[]) {7, 8, 9,
                                                    4, 5, 6,
                                                    1, 2, 3},
                                           3, 3);

    task1(&m);

    assert(areTwoMatricesEqual(&m, &exp_res));
    freeMemMatrix(&m);
    freeMemMatrix(&exp_res);
}

int getMax(int *a, int n) {
    int max = a[0];

    for (int i = 1; i < n; ++i)
        max = max > a[i] ? max : a[i];

    return max;
}

void sortRowsByMinElement(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void task2(matrix *m) {
    sortRowsByMinElement(m);
}

void test_task2() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 1,
                                              3, 2, 3},
                                     3, 3);
    matrix exp_res = createMatrixFromArray((int[]) {3, 2, 3,
                                                    7, 1, 2,
                                                    1, 8, 1},
                                           3, 3);

    task2(&m);

    assert(areTwoMatricesEqual(&m, &exp_res));
    freeMemMatrix(&m);
    freeMemMatrix(&exp_res);
}

int getMin(int *a, int n) {
    int min = a[0];

    for (int i = 1; i < n; ++i)
        min = min < a[i] ? min : a[i];

    return min;
}

void sortColsByMinElement(matrix *m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

void task3(matrix *m) {
    sortColsByMinElement(m);
}

void test_task3() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                              2, 5, 1, 8, 2, 7,
                                              6, 1, 4, 4, 8, 3},
                                     3, 6);
    matrix exp_res = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                    5, 1, 2, 2, 7, 8,
                                                    1, 4, 6, 8, 3, 4},
                                           3, 6);

    task3(&m);

    assert(areTwoMatricesEqual(&m, &exp_res));
    freeMemMatrix(&m);
    freeMemMatrix(&exp_res);
}

void test() {
    test_task1();
    test_task2();
    test_task3();

}

int main() {
    test();

    return 0;
}