#include <stdio.h>
#include "libs/data_structures/bitset/bitset.h"
#include <assert.h>

void test_bitset_create() {
    bitset set1 = bitset_create(0); // Создание пустого множества с универсумом 0
    bitset set2 = bitset_create(31); // Создание пустого множества с универсумом 31
    bitset set3 = bitset_create(17); // Создание пустого множества с универсумом 17
}

void test_bitset_in() {
    bitset set1 = {111, 31}; // Множество 1 = {0, 1, 2, 3, 5, 6}
    int value1 = 0; // Искомое значение 1

    bitset set2 = {111, 31}; // Множество 2 = {0, 1, 2, 3, 5, 6}
    int value2 = 100; // Искомое значение 2

    // Проверка, есть ли Значение 1 есть в Множестве 1, ожидаемый ответ - Да
    assert(bitset_in(set1, value1) == 1);

    // Проверка, есть ли Значение 2 есть в Множестве 2, ожидаемый ответ - Нет
    assert(bitset_in(set2, value2) == 0);
}

void test_bitset_isEqual() {
    bitset set1 = {111, 31}; // Множество 1 = {0, 1, 2, 3, 5, 6}
    bitset set2 = {111, 31}; // Множество 2 = {0, 1, 2, 3, 5, 6}

    bitset set3 = {6969, 31}; // Множество 3 = {0, 3, 4, 5, 8, 9, 11, 12}
    bitset set4 = {6939, 31}; // Множество 4 = {0, 1, 3, 4, 8, 9, 11, 12}

    // Проверка, равны ли Множества 1 и 2, ожидаемый ответ - Да
    assert((bitset_isEqual(set1, set2)) == 1);

    // Проверка, равны ли Множества 3 и 4, ожидаемый ответ - Нет
    assert((bitset_isEqual(set3, set4)) == 0);
}

void test_bitset_isSubset() {
    bitset set1 = {1111, 31}; // Множество 1 = {0, 1, 2, 4, 6, 10}
    bitset set2 = {1110, 31}; // Множество 2 = {1, 2, 4, 6, 10}

    bitset set3 = {111, 31}; // Множество 3 = {0, 1, 2, 3, 5, 6}
    bitset set4 = {110, 31}; // Множество 4 = {1, 2, 3, 5, 6}

    bitset set5 = {1, 31}; // Множество 5 = {0}
    bitset set6 = {1, 31}; // Множество 6 = {0}

    // Проверка, Множество 2 - подмножество для Множества 1, ожидаемый ответ - Да
    assert(bitset_isSubset(set1, set2) == 1);

    // Проверка, Множество 4 - подмножество для Множества 3, ожидаемый ответ - Да
    assert(bitset_isSubset(set3, set4) == 1);

    // Проверка, Множество 6 - подмножество для Множества 5, ожидаемый ответ - Нет
    assert(bitset_isSubset(set5, set6) == 0);
}

void test_bitset_insert() {
    bitset set1 = {6968, 31}; // Множество 1 = {3, 4, 5, 8, 9, 11, 12}
    int value1 = 0; //  Значение 1

    bitset_insert(&set1, value1); // Вставка Значения 1 в Множество 1

    bitset exp_res = {6969, 31}; // Предпол. результат = {0, 3, 4, 5, 8, 9, 11, 12}

    // Проверка изменённого Множества 1 с Предпол. результатом на равенство
    assert(set1.values == exp_res.values);
}

void test_bitset_deleteElement() {
    bitset set1 = {6969, 31}; // Множество 1 = {0, 3, 4, 5, 8, 9, 11, 12}
    int value1 = 0; // Значение 1

    bitset_deleteElement(&set1, value1); // Удаление Значения 1 из Множества 1

    bitset exp_res = {6968, 31}; // Предпол. результат = {3, 4, 5, 8, 9, 11, 12}

    // Проверка изменённого Множества 1 с Предпол. результатом на равенство
    assert(set1.values == exp_res.values);
}

void test_bitset_union() {
    bitset set1 = {110, 31}; // Множество 1 = {1, 2, 3, 5, 6}
    bitset set2 = {1, 31}; // Множество 2 = {0}

    bitset res = bitset_union(set1, set2); // Результат = {0, 1, 2, 3, 5, 6}
    bitset exp_res = {111, 31}; // Предпол. результат = {0, 1, 2, 3, 5, 6}

    // Проверка Результата с Предпол. результатом на равенство
    assert(res.values == exp_res.values);
}

void test_bitset_intersection() {
    bitset set1 = {1111, 31}; // Множество 1 = {0, 1, 2, 4, 6, 10}
    bitset set2 = {12, 31}; // Множество 2 = {2, 3}

    bitset exp_res = {4, 31}; // Предпол. результат = {2}
    bitset res = bitset_intersection(set1, set2); // Результат = {2}

    // Проверка Результата с Предпол. результатом на равенство
    assert(res.values == exp_res.values);
}

void test_bitset_difference() {
    bitset set1 = {111, 31}; // Множество 1 = {0, 1, 2, 3, 5, 6}
    bitset set2 = {110, 31}; // Множество 2 = {1, 2, 3, 5, 6}

    bitset res = bitset_difference(set1, set2); // Результат = {0}
    bitset exp_res = {1, 31}; // Предпол. результат = {0}

    // Проверка Результата с Предпол. результатом на равенство
    assert(res.values == exp_res.values);
}

void test_bitset_symmetricDifference() {
    bitset set1 = {100, 31}; // Множество 1 = {2, 5, 6}
    bitset set2 = {110, 31}; // Множество 2 = {1, 2, 3, 5, 6}

    bitset res = bitset_symmetricDifference(set1, set2); // Результат = {1, 3}
    bitset exp_res = {10, 31}; // Предпол. результат = {1, 3}

    // Проверка Результата с Предпол. результатом на равенство
    assert(res.values == exp_res.values);
}

void test_bitset_complement() {
    bitset set1 = {110, 6}; // Множество 1 = {1, 2, 3, 5, 6}

    bitset exp_res = {0 - 111, 6}; // Предпол. результат = {0, 4}
    bitset res = bitset_complement(set1); // Результат = {0, 4}

    // Проверка Результата с Предпол. результатом на равенство
    assert(res.values == exp_res.values);
}

void test_bitset_print() {
    bitset set1 = bitset_create(2); // Множество 1 = {}
    bitset set2 = {100, 12}; // Множество 2 = {2, 5, 6}

    // Вывод Множества 1
    bitset_print(set1);

    // Вывод Множества 2
    bitset_print(set2);
}

// Объединение всех тестов в 1 функцию
void bitset_test() {
    test_bitset_create();
    test_bitset_in();
    test_bitset_isEqual();
    test_bitset_isSubset();
    test_bitset_insert();
    test_bitset_deleteElement();
    test_bitset_union();
    test_bitset_intersection();
    test_bitset_difference();
    test_bitset_symmetricDifference();
    test_bitset_complement();
    test_bitset_print();
}

int main() {
    bitset_test();
    printf("Bitset testing is complete, all is OK\n");

    return 0;
}