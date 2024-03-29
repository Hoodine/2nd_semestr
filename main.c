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
    char str[] = "ABoba , slona net";
    char exp[] = "ABoba , slona net";
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

void test_removeAdjacentEqualLetters1() {
    char str[] = "1111  22222 aaaaaaabbbbbaaaaa";
    char exp[] = "1 2 aba";
    removeAdjacentEqualLetters(str);

    ASSERT_STRING(exp, str);
}

void test_removeAdjacentEqualLetters2() {
    char str[] = "";
    char exp[] = "";
    removeAdjacentEqualLetters(str);

    ASSERT_STRING(exp, str);
}

void test_removeAdjacentEqualLetters3() {
    char str[] = "A B C";
    char exp[] = "A B C";
    removeAdjacentEqualLetters(str);

    ASSERT_STRING(exp, str);
}

void test_removeAdjacentEqualLetters4() {
    char str[] = "AAAaaa";
    char exp[] = "Aa";
    removeAdjacentEqualLetters(str);

    ASSERT_STRING(exp, str);
}


void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters1();
    test_removeAdjacentEqualLetters2();
    test_removeAdjacentEqualLetters3();
    test_removeAdjacentEqualLetters4();
}

void test_digitsToStart1() {
    char str[] = "1bo58ob9a 223924 faadba";
    char exp[] = "1589booba 223924 faadba";
    digitsToStart(str);

    ASSERT_STRING(exp, str);
}

void test_digitsToStart2() {
    char str[] = "";
    char exp[] = "";
    digitsToStart(str);

    ASSERT_STRING(exp, str);
}

void test_digitsToStart3() {
    char str[] = "123abc abc123 1a2b3c";
    char exp[] = "123abc 123abc 123abc";
    digitsToStart(str);

    ASSERT_STRING(exp, str);
}

void test_digitsToStart() {
    test_digitsToStart1();
    test_digitsToStart2();
    test_digitsToStart3();
}

void test() {
    test_removeExtraSpaces();
    test_removeAdjacentEqualLetters();
    test_digitsToStart();
}

int main() {
    test();

    return 0;
}