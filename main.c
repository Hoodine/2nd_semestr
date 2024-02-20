#include "libs/data_structures/matrix/matrix.h"
#include <stdio.h>

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];

    return sum;
}

int main() {
    matrix ms = getMemMatrix(3, 3);
    //matrix ms2 = getMemMatrix(3, 3);

    inputMatrix(&ms);
    //inputMatrix(&ms2);

    //swapRows(&ms, 0, 1);

    //swapColumns(&ms, 0, 1);

    //insertionSortRowsMatrixByRowCriteria(&ms, getSum);

    //selectionSortColsMatrixByColCriteria(ms, getSum);

    if (isSymmetricMatrix(&ms))
        printf("Heheheha, Grrrr\n");
    else
        printf("No hehehaha\n");

    outputMatrix(ms);
    //outputMatrix(ms2);

    freeMemMatrix(&ms);
    //freeMemMatrix(&ms2);

    printf("I love programming (well actually i hate matrix tbh)");

    return 0;
}