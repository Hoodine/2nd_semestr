#ifndef LAB_ALG_H
#define LAB_ALG_H

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct subset_line{
    char *line;
    int num_operators;
} subset_line;

typedef struct PNFK{
    int *arr_constituent;
    int size_arr_c;
} PNFK;

typedef struct set_theoretic_method_result{
    int *result_arr_TMP;
    int size_res_arr;
} set_theoretic_method_result;

typedef struct set{
    subset_line term;
    PNFK perfect_form;
    set_theoretic_method_result result_STM;
} set;

bool changeBool(bool a);

bool difference(bool a, bool b);

bool unification(bool a, bool b);

bool intersection(bool a, bool b);

bool symmetricalDifference(bool a, bool b);

bool getConditionSubset(int num_c, char lit);

void unGetTok(int op, const char **p);

void skipWhite(const char **p);

int getTok(const char **p, int num_c, bool *vp);

bool evalPri(const char **p, int);

bool evalTerm(const char **p, int num_c);

bool evalExpr(const char **p, int num_c);

bool evalPri(const char **p, int num_c);

bool isConstituentInPNFK(const char *expr, int num_c);

subset_line inputSubsetLine(int amount_subset);

PNFK getArrNumConstituents(subset_line subset);

int test();

#endif