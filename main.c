#include "stdio.h"
#include <limits.h>
#include <conio.h>
#include <malloc.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/vector/vector.h"

void firstTask(matrix *m, size_t countRequests, size_t *requestsArray[]) {
    size_t row1, col1, row2, col2;
    for (size_t request = 0; request < countRequests; request++) {
        row1 = requestsArray[request][0];
        col1 = requestsArray[request][1];
        row2 = requestsArray[request][2];
        col2 = requestsArray[request][3];
        for (size_t indRow = row1; indRow <= row2; indRow++)
            for (size_t indCol = col1; indCol <= col2; indCol++)
                m->values[indRow][indCol]++;
    }
}

void test_firstTask() {
    matrix got = createMatrixFromArray((int[]) {
                                               0, 0, 0,
                                               0, 0, 0,
                                               0, 0, 0},
                                       3, 3);
    size_t countRequests = 2;
    size_t firstRequest[4] = {1, 1, 2, 2};
    size_t secondRequest[4] = {0, 0, 1, 1};
    size_t *requests[2] = {firstRequest, secondRequest};
    firstTask(&got, countRequests, requests);
    matrix expected = createMatrixFromArray((int[]) {
                                                    1, 1, 0,
                                                    1, 2, 1,
                                                    0, 1, 1},
                                            3, 3);

    assert(areTwoMatricesEqual(&got, &expected));
}

int main() {
    test_firstTask();

    return 0;
}