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

void test_replaceDigitsToNumOfSpaces1() {
    char str[MAX_STRING_SIZE] = "1bo58ob9a";
    char exp[] = " bo             ob         a";
    replaceDigitsToNumOfSpaces(str);

    ASSERT_STRING(exp, str);
}

void test_replaceDigitsToNumOfSpaces2() {
    char str[MAX_STRING_SIZE] = "p0s5ka2 k1l";
    char exp[] = "ps     ka   k l";
    replaceDigitsToNumOfSpaces(str);

    ASSERT_STRING(exp, str);
}

void test_replaceDigitsToNumOfSpaces3() {
    char str[MAX_STRING_SIZE] = "";
    char exp[] = "";
    replaceDigitsToNumOfSpaces(str);

    ASSERT_STRING(exp, str);
}

void test_replaceDigitsToNumOfSpaces() {
    test_replaceDigitsToNumOfSpaces1();
    test_replaceDigitsToNumOfSpaces2();
    test_replaceDigitsToNumOfSpaces3();
}

void test_replace1() {
    char str[MAX_STRING_SIZE] = "aboba i love my mom aboba";
    char w1[] = "aboba";
    char w2[] = "goddamn";
    replace(str, w1, w2);
    char exp[MAX_STRING_SIZE] = "goddamn i love my mom goddamn";

    ASSERT_STRING(exp, str);
}

void test_replace2() {
    char str[MAX_STRING_SIZE] = "i love aboba, my mom is baking aboba";
    char w1[] = "aboba";
    char w2[] = "cake";
    replace(str, w1, w2);
    char exp[MAX_STRING_SIZE] = "i love cake, my mom is baking cake";

    ASSERT_STRING(exp, str);
}

void test_replace3() {
    char str[MAX_STRING_SIZE] = "where is my mom mom dad";
    char w1[] = "mom";
    char w2[] = "";
    replace(str, w1, w2);
    char exp[MAX_STRING_SIZE] = "where is my   dad";

    ASSERT_STRING(exp, str);
}

void test_replace() {
    test_replace1();
    test_replace2();
    test_replace3();
}

void test_areWordsOrdered1() {
    char s[] = "";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered2() {
    char s[] = "dream";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered3() {
    char s[] = "pass op";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered4() {
    char s[] = "pass pass";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered5() {
    char s[] = "a ab baaa ca cd";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered() {
    test_areWordsOrdered1();
    test_areWordsOrdered2();
    test_areWordsOrdered3();
    test_areWordsOrdered4();
    test_areWordsOrdered5();
}

void test_reverseWordsBag1() {
    char s[MAX_STRING_SIZE] = "h e y";
    reverseWordsBag(s);
    
    ASSERT_STRING("h e y", s);
}

void test_reverseWordsBag2() {
    char s[MAX_STRING_SIZE] = "Artyom";
    reverseWordsBag(s);

    ASSERT_STRING("moytrA", s);
}

void test_reverseWordsBag3() {
    char s[MAX_STRING_SIZE] = "";
    reverseWordsBag(s);

    ASSERT_STRING("", s);
}

void test_reverseWordsBag() {
    test_reverseWordsBag1();
    test_reverseWordsBag2();
    test_reverseWordsBag3();
}


void test() {
    test_removeExtraSpaces();
    test_removeAdjacentEqualLetters();
    test_digitsToStart();
    test_replaceDigitsToNumOfSpaces();
    test_replace();
    test_areWordsOrdered();
    test_reverseWordsBag();
}

int main() {
    test();

    return 0;
}