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

int main() {
    test_task1();

    return 0;
}