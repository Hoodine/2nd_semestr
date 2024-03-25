#include "string/string_.h"
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void test_removeExtraSpaces1() {
    char str[] = "Hallo   , pen   is dirty      ?";
    char exp[] = "Hallo , pen is dirty ?";
    removeExtraSpaces(str);

    ASSERT_STRING(exp, str);
}

void test_removeExtraSpaces2() {
    char str[] = "";
    char exp[] = "";
    removeExtraSpaces(str);

    ASSERT_STRING(exp, str);
}

void test_removeExtraSpaces3() {
    char str[] = "ABoba , ebal slona";
    char exp[] = "ABoba , ebal slona";
    removeExtraSpaces(str);

    ASSERT_STRING(exp, str);
}

void test_removeExtraSpaces4() {
    char str[] = "      ";
    char exp[] = "";
    removeExtraSpaces(str);

    ASSERT_STRING(exp, str);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces1();
    test_removeExtraSpaces2();
    test_removeExtraSpaces3();
    test_removeExtraSpaces4();
}

void test() {
    test_removeExtraSpaces();

}

int main() {
    test();

    return 0;
}