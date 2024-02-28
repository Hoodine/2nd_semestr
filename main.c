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

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            assert(m.values[i][j] == exp_res.values[i][j]);
}

int getMax(int *a, int n) {
    int max = a[0];

    for (int i = 1; i < n; ++i) {
        max = max > a[i] ? max : a[i];
    }

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

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            assert(m.values[i][j] == exp_res.values[i][j]);
}

void test() {
    test_task1();
    test_task2();

}

int main() {
    test();

    return 0;
}