#include <memory.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "string_.h"
#include <stdlib.h>
#include <assert.h>

char _stringBuffer[MAX_STRING_SIZE + 1]; // стринг баффер как ты меня заебал cyka

int randint(int n) {
    if ((n - 1) == RAND_MAX) {
        return rand();
    } else {

        assert (n <= RAND_MAX);

        int end = RAND_MAX / n;
        assert (end > 0);
        end *= n;

        int r;
        while ((r = rand()) >= end);

        return r % n;
    }
}

char *vopros() {
    int otvet = randint(5);
    switch (otvet) {
        case 1:
            return "Boomer";
            break;
        case 2:
            return "Zoomer";
            break;
        case 3:
            return "Millenial";
            break;
        case 4:
            return "Alpha";
            break;
        default:
            return "Doomer";
    }
}

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *copy(const char *beginSource, const char *endSource, char
*beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);

    //*(beginDestination + size) = '\0';

    return beginDestination + size;
}

char *copyIf(char *beginSource, const char *endSource, char
*beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    //*beginDestination = '\0';

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char
*beginDestination, int (*f)(int)) {
    char *rbeginDest = beginDestination;
    while (rbeginSource >= rendSource) {
        if (f(*rbeginSource)) {
            *rbeginDest = *rbeginSource;
            rbeginDest++;
        }
        rbeginSource--;
    }

    //*rbeginDest = '\0';

    return rbeginDest;
}

char *getEndOfString(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK %s\n", funcName, vopros());
}

void removeExtraSpaces(char *s) {
    int i, j;

    for (i = 0, j = 0; s[i]; i++) {
        if (s[i] != ' ' || (i > 0 && s[i - 1] != ' ')) {
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}

void removeAdjacentEqualLetters(char *s) {
    if ((s == NULL || strlen(s) == 0))
        return;

    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] != s[i + 1]) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void reversedDigitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);

    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);

    char *recPosition = copyIf(_stringBuffer,
                               endStringBuffer,
                               word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}


void digitsToStart(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {

        digitToStart(word);
        beginSearch = word.end;
    }
}

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);
    if (*word->begin == *rend)
        return 0;

    word->begin = findSpaceReverse(word->end, rend);
    word->begin++;

    return 1;
}

void replaceDigitsToNumOfSpaces(char *s) {
    _stringBuffer[0] = '\0';
    copy(s, getEndOfString(s), _stringBuffer);
    char *readPtr = _stringBuffer;
    char *recPtr = s;

    while (*readPtr != '\0') {
        if (strlen_(s) >= MAX_STRING_SIZE) {
            fprintf(stderr, "Out of MAX_STRING_SIZE");
            exit(1);
        }

        if (!isdigit(*readPtr)) {
            *recPtr = *readPtr;
            readPtr++;
            recPtr++;
        } else {
            int counter = *readPtr - 48;
            readPtr++;
            for (int j = counter; j > 0; --j) {
                *recPtr = ' ';
                recPtr++;
            }
        }
    }

    *recPtr = '\0';
    *readPtr = '\0';
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;

    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (memcmp(readPtr, w1, w1Size) == 0) {
            for (int i = 0; i < w2Size; ++i) {
                *recPtr = w2[i];
                recPtr++;
            }

            readPtr += w1Size;

        } else {
            *recPtr = *readPtr;
            readPtr++;
            recPtr++;
        }
    }

    *recPtr = '\0';
}

bool areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *ptr1 = w1.begin;
    char *ptr2 = w2.begin;
    while (ptr1 <= w1.end && ptr2 <= w2.end) {
        if (*ptr1 != *ptr2)
            return false;

        ptr1++;
        ptr2++;
    }

    if (ptr1 > w1.end && ptr2 > w2.end)
        return true;
    else
        return false;
}

bool areWordsOrdered(char *s) {
    WordDescriptor word1;
    WordDescriptor word2;
    if (getWord(s, &word1)) {
        word2 = word1;
        while (getWord(s, &word1)) {
            if (areWordsEqual(word1, word2) < 0)
                return false;
            word2 = word1;
            s = word1.end;
        }
        return true;
    } else {
        return true;
    }
}
