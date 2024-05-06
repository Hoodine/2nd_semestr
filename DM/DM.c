#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "DM.h"
#include "../libs/algorithms/array/array.h"

bool changeBool(bool a) {
    return a ? 0 : 1;
}

bool difference(bool a, bool b) {
    if (a - b == true)
        return true;

    return false;
}

bool unification(bool a, bool b) {
    return a | b;
}

bool intersection(bool a, bool b) {
    return a & b;
}

bool symmetricalDifference(bool a, bool b) {
    return a ^ b;
}

bool getConditionSubset(int num_c, char lit) {
    return num_c & (1 << ((int) lit - 65));
}

void unGetTok(int op, const char **p) {
    (*p)--;
}

void skipWhite(const char **p) {
    while (isspace(**p))
        (*p)++;
}

int getTok(const char **p, int num_c, bool *vp) {
    skipWhite(p);
    char c = **p;
    if (isalpha(c)) {
        int v = getConditionSubset(num_c, c);
        if (vp)
            *vp = v;

        (*p)++;

        return '1';
    }

    (*p)++;

    return c;
}

bool evalTerm(const char **p, int num_c) {
    bool r = evalPri(p, num_c);
    while (1) {
        int op = getTok(p, num_c, NULL);
        if (op == '&')
            r = intersection(r, evalPri(p, num_c));
        else {
            unGetTok(op, p);
            return r;
        }
    }
}

bool evalExpr(const char **p, int num_c) {
    bool r = evalTerm(p, num_c);
    while (1) {
        int op = getTok(p, num_c, NULL);
        switch (op) {
            case '|':
                r = unification(r, evalTerm(p, num_c));
                break;
            case '-':
                r = difference(r, evalTerm(p, num_c));
                break;
            case '^':
                r = symmetricalDifference(r, evalTerm(p, num_c));
                break;
            default:
                unGetTok(op, p);
                return r;
        }
    }
}

bool evalPri(const char **p, int num_c) {
    bool v;
    int op = getTok(p, num_c, &v);
    switch (op) {
        case '1':
            return v;
        case '~':
            return changeBool(evalPri(p, num_c));
        case '(':
            v = evalExpr(p, num_c);
            op = getTok(p, num_c, NULL);
            if (op != ')') {
                fprintf(stderr, "missing ')'\n");
                unGetTok(op, p);
            }

            return v;
    }
}

bool isConstituentInPNFK(const char *expr, int num_c) {
    return evalExpr(&expr, num_c);
}

subset_line inputSubsetLine(int amount_subset) {
    char *line = (char *) malloc(sizeof(char) * 100);
    printf("Enter expression: ");

    assert(fgets(line, sizeof(char) * 100, stdin) != NULL);
    puts(line);

    return (subset_line) {line, amount_subset};
}

PNFK getArrNumConstituents(subset_line subset) {
    int max_size = pow(2, subset.num_operators);
    int *arr = malloc(sizeof(int) * subset.num_operators);
    int size = 0;
    for (int i = 0; i < max_size; i++) {
        if (isConstituentInPNFK(subset.line, i)) {
            arr[size] = i;
            size++;
        }
    }
    arr = (int *) realloc(arr, sizeof(int) * size);

    return (PNFK) {arr, size};
}

int test() {
    while (1) {
        subset_line subset = inputSubsetLine(3);
        puts(subset.line);
        PNFK perfect_form = getArrNumConstituents(subset);
        outputArray_(perfect_form.arr_constituent, perfect_form.size_arr_c);
    }
}