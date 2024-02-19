#include "libs/data_structures/matrix/matrix.h"
#include <stdio.h>

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];

    return sum;
}

int main() {
    matrix *ms = getMemArrayOfMatrices(1, 3, 3);

    inputMatrices(ms, 1);

    swapRows(ms, 0, 1);

    swapColumns(ms, 0, 1);

    //insertionSortRowsMatrixByRowCriteria(ms, getSum);

    selectionSortColsMatrixByColCriteria(ms, getSum);

    outputMatrices(ms, 1);

    freeMemMatrices(ms, 1);

    printf("I love programming (well actually i hate matrix tbh)");

    return 0;
}