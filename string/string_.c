#include <memory.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "string_.h"

char _stringBuffer[MAX_STRING_SIZE + 1];

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
        fprintf(stderr, "%s - OK\n", funcName);
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