#include "libs/data_structures/matrix/matrix.h"
#include "assert.h"
#include <stdlib.h>
#include <memory.h>

void test_getMemMatrix() {
    matrix m = getMemMatrix(2, 2);
    assert(m.nCols == 2 && m.nRows == 2);
    // проверка выделения памяти
    assert(m.values != NULL);
    freeMemMatrix(&m);

    // проверка на других входных данных
    m = getMemMatrix(2, 9);
    assert(m.nCols == 9 && m.nRows == 2);
    assert(m.values != NULL);

    //освобождаем память
    freeMemMatrix(&m);
}

void test_getMemArrayOfMatrices() {
    matrix *ms = getMemArrayOfMatrices(2, 2, 2);
    // проверка на данные о колоннах и столбцах
    assert(ms->nCols == 2 && ms->nRows == 2);
    //проверка выделения памяти
    assert(ms != NULL);
    freeMemMatrices(ms, 2);

    ms = getMemArrayOfMatrices(9, 5, 2);
    // проверка на данные о колоннах и столбцах
    assert(ms->nCols == 2 && ms->nRows == 5);
    //проверка выделения памяти
    assert(ms != NULL);
    freeMemMatrices(ms, 2);
}

void test_freeMemMatrix() {
    //создаем и чистим массив
    matrix m = getMemMatrix(2, 2);
    freeMemMatrix(&m);
    assert(m.values == NULL);

    //проверка на других данных
    m = getMemMatrix(3, 6);
    freeMemMatrix(&m);
    assert(m.values == NULL);
}

void test_swapRows() {
    // Матрица m
    matrix m = createMatrixFromArray((int[]) {
                                             4, 5, 6,
                                             1, 2, 3,},
                                     2, 3);
    // Предполагаемый результат exp_res
    matrix exp_res = createMatrixFromArray((int[]) {
                                                   1, 2, 3,
                                                   4, 5, 6},
                                           2, 3);
    // Обмен строк в массиве m
    swapRows(&m, 0, 1);

    // Проверка на соответствие массива m и exp_res
    assert(areTwoMatricesEqual(&m, &exp_res));
    freeMemMatrix(&m);
    freeMemMatrix(&exp_res);
}

void test_swapColumns() {
    // Матрица m
    matrix m = createMatrixFromArray((int[]) {
                                             1, 4,
                                             2, 5,
                                             3, 6,},
                                     3, 2);
    // Предполагаемый результат exp_res
    matrix exp_res = createMatrixFromArray((int[]) {
                                                   4, 1,
                                                   5, 2,
                                                   6, 3,},
                                           3, 2);
    // Обмен колон в массиве m
    swapColumns(&m, 0, 1);

    // Проверка на соответствие массива m и exp_res
    assert(areTwoMatricesEqual(&m, &exp_res));
    freeMemMatrix(&m);
    freeMemMatrix(&exp_res);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 3,
                                             7, 8, 9,
                                             4, 5, 6},
                                     3, 3);
    matrix exp_res = createMatrixFromArray((int[]) {
                                                   1, 2, 3,
                                                   4, 5, 6,
                                                   7, 8, 9},
                                           3, 3);

    insertionSortRowsMatrixByRowCriteria(&m, getSum);

    assert(areTwoMatricesEqual(&m, &exp_res));
    freeMemMatrix(&m);
    freeMemMatrix(&exp_res);

    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 1,
                                              1, 1,
                                              0, 0},
                                      3, 2);
    matrix exp_res1 = createMatrixFromArray((int[]) {
                                                    0, 0,
                                                    1, 1,
                                                    1, 1},
                                            3, 2);

    insertionSortRowsMatrixByRowCriteria(&m1, getSum);

    assert(areTwoMatricesEqual(&m1, &exp_res1));
    freeMemMatrix(&m1);
    freeMemMatrix(&exp_res1);
}

void test_selectionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray((int[]) {
                                             7, 4, 1,
                                             8, 5, 2,
                                             9, 6, 3},
                                     3, 3);
    matrix exp_res = createMatrixFromArray((int[]) {
                                                   1, 4, 7,
                                                   2, 5, 8,
                                                   3, 6, 9},
                                           3, 3);

    selectionSortColsMatrixByColCriteria(&m, getSum);

    assert(areTwoMatricesEqual(&m, &exp_res));
    freeMemMatrix(&m);
    freeMemMatrix(&exp_res);

    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 0, 0,
                                              0, 1, 0},
                                      2, 3);
    matrix exp_res1 = createMatrixFromArray((int[]) {
                                                    0, 0, 1,
                                                    0, 1, 0},
                                            2, 3);

    selectionSortColsMatrixByColCriteria(&m1, getSum);

    assert(areTwoMatricesEqual(&m1, &exp_res1));
    freeMemMatrix(&m1);
    freeMemMatrix(&exp_res1);
}

void test_isSquareMatrix() {
    matrix m1 = getMemMatrix(2, 2);
    assert(isSquareMatrix(&m1) == 1);

    matrix m2 = getMemMatrix(3, 2);
    assert(isSquareMatrix(&m2) != 1);
}

void test_areTwoMatricesEqual() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              7, 8, 9,
                                              4, 5, 6},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              7, 8, 9,
                                              4, 5, 6},
                                      3, 3);
    assert(areTwoMatricesEqual(&m1, &m2) == 1);

    matrix m3 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              7, 8, 9},
                                      2, 3);
    matrix m4 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              7, 8, 9,
                                              4, 5, 6},
                                      3, 3);
    assert(areTwoMatricesEqual(&m3, &m4) == 0);

    matrix m5 = createMatrixFromArray((int[]) {
                                              0, 0, 0,
                                              0, 0, 0,
                                              0, 0, 0},
                                      3, 3);
    matrix m6 = createMatrixFromArray((int[]) {
                                              1, 0, 0,
                                              0, 0, 0,
                                              0, 0, 0},
                                      3, 3);
    assert(areTwoMatricesEqual(&m5, &m6) == 0);
}

void test_isEMatrix() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1},
                                     3, 3);
    assert(isEMatrix(&m) == 1);

    matrix m1 = createMatrixFromArray((int[]) {
                                              0, 0, 1,
                                              0, 1, 0,
                                              1, 0, 0},
                                      3, 3);
    assert(isEMatrix(&m1) == 0);

    matrix m2 = createMatrixFromArray((int[]) {
                                              0, 0, 1,
                                              0, 1, 0},
                                      2, 3);
    assert(isEMatrix(&m2) == 0);
}

void test_isSymmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1},
                                     3, 3);
    assert(isSymmetricMatrix(&m) == 1);

    matrix m1 = createMatrixFromArray((int[]) {
                                              80, 0, 1,
                                              0, 1, 0,
                                              0, 3, 5},
                                      3, 3);
    assert(isSymmetricMatrix(&m1) == 0);

    matrix m2 = createMatrixFromArray((int[]) {
                                              0, 0, 1,
                                              0, 1, 0},
                                      2, 3);
    assert(isSymmetricMatrix(&m2) == 0);
}

void test_transposeSquareMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9},
                                      3, 3);
    matrix exp_res1 = createMatrixFromArray((int[]) {
                                                    1, 4, 7,
                                                    2, 5, 8,
                                                    3, 6, 9},
                                            3, 3);

    transposeSquareMatrix(&m1);

    assert(areTwoMatricesEqual(&m1, &exp_res1) == 1);
}

void test_getMinValuePos() {
    //нахождение минимума с 1 значением
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              1, 3, 0,},
                                     2, 3);
    position p = getMinValuePos(m);

    assert(p.rowIndex == 1 && p.colIndex == 2);
    freeMemMatrix(&m);

    //нахождение минимума с множеством значений
    m = createMatrixFromArray((int[]) {1, 0, 1,
                                       0, 3, 0,},
                              2, 3);
    position p1 = getMinValuePos(m);

    assert(p1.rowIndex == 0 && p1.colIndex == 1);
    freeMemMatrix(&m);
}

void test_getMaxValuePos() {
    //нахождение максимума с 1 значением
    matrix m = createMatrixFromArray((int[]) {1, 0, 1,
                                              1, 3, 9,},
                                     2, 3);
    position p = getMaxValuePos(m);

    assert(p.rowIndex == 1 && p.colIndex == 2);
    freeMemMatrix(&m);

    //нахождение максимума с множеством значений
    m = createMatrixFromArray((int[]) {1, 9, 1,
                                       9, 3, 9,},
                              2, 3);
    position p1 = getMaxValuePos(m);

    assert(p1.rowIndex == 0 && p1.colIndex == 1);
    freeMemMatrix(&m);
}

void test() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_freeMemMatrix();
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_selectionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {
    test();

    return 0;
}