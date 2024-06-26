#include <memory.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "string_.h"
#include <stdlib.h>
#include <assert.h>

char _stringBuffer[MAX_STRING_SIZE + 1]; // стринг баффер как ты меня заебал cyka

BagOfWords _bag;
BagOfWords _bag2;

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

char *strpbrk_(const char *str, const char *delim) {
    const char *ptr = str;

    while (*ptr != '\0') {
        const char *d = delim;
        while (*d != '\0') {
            if (*ptr == *d) {
                return (char *) ptr;
            }
            d++;
        }
        ptr++;
    }

    return NULL;
}

char *strtok_(char *str, const char *delim) {
    static char *savedToken = NULL;

    if (str != NULL) {
        savedToken = str;
    }

    if (savedToken == NULL) {
        return NULL;
    }

    char *tokenStart = savedToken;
    char *tokenEnd = strpbrk_(savedToken, delim);

    if (tokenEnd != NULL) {
        *tokenEnd = '\0';
        savedToken = tokenEnd + 1;
    } else {
        savedToken = NULL;
    }

    return tokenStart;
}

char *strcat_(char *dest, const char *src) {
    char *ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }

    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

void strcpy_(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

char *strncpy_(char *destination, const char *source, size_t num) {
    char *start = destination;

    while (num && (*destination++ = *source++)) {
        num--;
    }

    if (num) {
        while (--num) {
            *destination++ = '\0';
        }
    }

    return start;
}

int strncmp_(const char *s1, const char *s2, size_t n) {
    while (n--) {
        if (*s1 != *s2) {
            return (unsigned char) *s1 - (unsigned char) *s2;
        }
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    return 0;
}

char *strrchr_(const char *str, int c) {
    char *last = NULL;
    while (*str != '\0') {
        if (*str == c) {
            last = (char *) str;
        }
        str++;
    }
    return last;
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
    } else
        return true;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word;
    bag->size = 0;
    while (getWord(s, &word)) {
        bag->words[bag->size] = word;
        bag->size++;
        s = word.end;
    }
}

char *copyReverse(char *rbeginSource, const char *rendSource, char
*beginDestination) {
    while (rbeginSource != rendSource)
        (*beginDestination++) = *rbeginSource--;

    return beginDestination;
}

void reverseWordsBag(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);
    char *copyS = s;
    for (int i = 0; i < _bag.size; i++) {
        copyS = copyReverse(_bag.words[i].end - 1, _bag.words[i].begin -
                                                   1, copyS);
        *copyS++ = ' ';
    }
    if (copyS != s)
        copyS--;

    *copyS = '\0';
}

bool isWordPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return false;
        begin++;
        end--;
    }

    return true;
}

size_t howManyWordsPalindromes(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPalindromes = 0;
    char *commaPos = find(beginSearch, endS, ',');
    bool lastComma = *commaPos == '\0' && endS - beginSearch != 0;

    while (*commaPos != '\0' || lastComma) {
        beginSearch = findNonSpace(beginSearch);
        countPalindromes += isWordPalindrome(beginSearch, commaPos);
        beginSearch = commaPos + 1;
        if (lastComma)
            break;

        commaPos = find(beginSearch, endS, ',');
        lastComma = *commaPos == '\0';
    }

    return countPalindromes;
}

void mergeStrings(char *s1, char *s2, char *result) {
    char *word1 = strtok_(s1, " ");
    char *word2 = strtok_(s2, " ");

    while (word1 != NULL || word2 != NULL) {
        if (word1 != NULL) {
            strcat_(result, word1);
            strcat_(result, " ");
            word1 = strtok_(NULL, " ");
        }
        if (word2 != NULL) {
            strcat_(result, word2);
            strcat_(result, " ");
            word2 = strtok_(NULL, " ");
        }
    }
}

void reverseWords(char *str) {
    int i = 0;
    _bag.size = 0;
    WordDescriptor word;

    while (*str && _bag.size < 1) {
        if (*str != ' ' && *(str + 1) == ' ' || *(str + 1) == '\0') {
            word.begin = str - i;
            word.end = str + 1;
            _bag.words[_bag.size] = word;
            _bag.size++;
            i = -1;
        }

        str++;
        i++;
    }

    while (*str) {
        if (*str != ' ' && *(str + 1) == ' ' || *(str + 1) == '\0') {
            word.begin = str - i + 1;
            word.end = str + 1;
            _bag.words[_bag.size] = word;
            _bag.size++;
            i = -1;
        }
        str++;
        i++;
    }

    char *reversedStr = malloc(strlen_(str) + 1);
    char *p = reversedStr;

    for (int j = _bag.size - 1; j >= 0; j--) {
        for (char *p = _bag.words[j].begin; p < _bag.words[j].end; p++) {
            *reversedStr = *p;
            reversedStr++;
        }
        *reversedStr = ' ';
        reversedStr++;
    }

    *reversedStr = '\0';

    strcpy_(str, p);

    free(p);
}

void printWordBeforeFirstWordWithA(char *s) {
    char *word = NULL;
    char *token = strtok_(s, " ");

    while (token != NULL) {
        int foundA = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (tolower(token[i]) == 'a') {
                foundA = 1;
                break;
            }
        }

        if (foundA) {
            if (word != NULL) {
                printf("%s\n", word);
                return;
            }
        } else {
            word = token;
        }

        token = strtok_(NULL, " ");
    }
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    if (s == NULL || strlen_(s) == 0)
        return EMPTY_STRING;

    char *wordBegin = NULL;
    char *wordEnd = NULL;
    char *token = strtok_(s, " ");

    while (token != NULL) {
        int foundA = 0;
        for (int i = 0; token[i] != '\0'; i++)
            if (tolower(token[i]) == 'a') {
                foundA = 1;
                break;
            }

        if (foundA) {
            if (wordBegin != NULL) {
                w->begin = wordBegin;
                w->end = wordEnd;
                return WORD_FOUND;
            } else
                return FIRST_WORD_WITH_A;

        } else {
            wordBegin = token;
            wordEnd = token + strlen_(token);
        }

        token = strtok_(NULL, " ");
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    int length = word.end - word.begin;
    strncpy_(destination, word.begin, length);
    destination[length] = '\0';
}

BagOfWords createBagOfWordsFromString(char *s) {
    BagOfWords bag;
    bag.size = 0;

    char *wordBegin = s;
    for (; *s; s++) {
        if (isspace(*s)) {
            if (s > wordBegin) {
                bag.words[bag.size].begin = wordBegin;
                bag.words[bag.size].end = s;
                bag.size++;
            }

            wordBegin = s + 1;
        }
    }

    if (s > wordBegin) {
        bag.words[bag.size].begin = wordBegin;
        bag.words[bag.size].end = s;
        bag.size++;
    }

    return bag;
}

int isWordInBagOfWords(WordDescriptor word, BagOfWords bag) {
    for (size_t i = 0; i < bag.size; ++i) {
        if (strncmp_(word.begin, bag.words[i].begin, word.end - word.begin) == 0)
            return 1;
    }

    return 0;
}

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    BagOfWords bag = createBagOfWordsFromString(s2);
    WordDescriptor lastWord = {NULL, NULL};

    BagOfWords wordsInS1 = createBagOfWordsFromString(s1);
    for (size_t i = 0; i < wordsInS1.size; ++i) {
        if (isWordInBagOfWords(wordsInS1.words[i], bag))
            lastWord = wordsInS1.words[i];
    }

    return lastWord;
}

bool hasDuplicateWords(char *s) {
    char *words[100];
    int wordCount = 0;

    char *word = strtok_(s, " ");
    while (word != NULL) {
        words[wordCount] = word;
        wordCount++;
        word = strtok_(NULL, " ");
    }

    for (int i = 0; i < wordCount; i++)
        for (int j = i + 1; j < wordCount; j++)
            if (strcmp(words[i], words[j]) == 0)
                return true;

    return false;
}

int compareWords(char *word1, char *word2) {
    int count1[26] = {0};
    int count2[26] = {0};

    size_t len1 = strlen_(word1);
    size_t len2 = strlen_(word2);

    if (len1 != len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        count1[tolower(word1[i]) - 'a']++;
        count2[tolower(word2[i]) - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }

    return 1;
}

void parseString(char *str, BagOfWords *bag) {
    char *token = strtok_(str, " ");
    while (token != NULL) {
        bag->words[bag->size].begin = token;
        bag->words[bag->size].end = token + strlen_(token);
        bag->size++;
        token = strtok_(NULL, " ");
    }
}

int findPairWithSameLetters(BagOfWords *bag) {
    for (int i = 0; i < bag->size - 1; i++) {
        for (int j = i + 1; j < bag->size; j++) {
            if (compareWords(bag->words[i].begin, bag->words[j].begin)) {
                char result1[MAX_WORD_SIZE], result2[MAX_WORD_SIZE];
                wordDescriptorToString(bag->words[i], result1);
                wordDescriptorToString(bag->words[j], result2);
                return 1;
            }
        }
    }

    return 0;
}

char *getWordsExceptLast(char *str) {
    char *last_space = strrchr_(str, ' ');
    if (last_space != NULL)
        *last_space = '\0';

    return str;
}

char *findWordBeforeFirstOccurrence(char *s1, char *s2) {
    BagOfWords bag;
    bag.size = 0;

    char *delimiters = " ,.?!;:"; // пример разделителей
    char *token = strtok_(s1, delimiters);
    while (token != NULL) {
        WordDescriptor word;
        word.begin = token;
        word.end = token + strlen_(token);
        bag.words[bag.size++] = word;
        token = strtok_(NULL, delimiters);
    }

    char *w = NULL;
    token = strtok_(s2, delimiters);
    while (token != NULL) {
        for (size_t i = 0; i < bag.size; i++) {
            if (strcmp(bag.words[i].begin, token) == 0) {
                w = token;
                break;
            }
        }
        if (w != NULL) {
            break;
        }
        token = strtok_(NULL, delimiters);
    }

    if (w == NULL) {
        return "0";
    }

    for (size_t i = 0; i < bag.size; i++) {
        if (strcmp(bag.words[i].begin, w) == 0) {
            if (i > 0) {
                return bag.words[i - 1].begin;
            } else {
                return "0";
            }
        }
    }

    return "0";
}

bool isPalindromeInString(char *s) {
    size_t length = strlen_(s);
    for (int i = 0; i < length / 2; i++)
        if (tolower(s[i]) != tolower(s[length - i - 1]))
            return false;

    return true;
}

void removePalindromes(char *str) {
    char *token = strtok_(str, " ");
    char result[1000] = "";

    while (token != NULL) {
        if (!isPalindromeInString(token)) {
            strcat_(result, token);
            strcat_(result, " ");
        }

        token = strtok_(NULL, " ");
    }

    strcpy(str, result);
}

// Функция, которая дополняет строку, содержащую меньшее количество слов, последними
// словами строки, в которой содержится большее количество слов
void append(char *s1, char *s2) {
    BagOfWords bag1 = createBagOfWordsFromString(s1);
    BagOfWords bag2 = createBagOfWordsFromString(s2);
    if (bag1.size < bag2.size) {
        if (bag1.size == 1)
            bag1.size++;
        else
            bag1.size--;

        if (bag2.size == 2)
            bag2.size++;

        char *p = bag2.words[bag2.size - bag1.size].begin;
        char *q = s1;
        while (*q != '\0')
            q++;

        *q = ' ';
        q++;
        while (*p != '\0') {
            *q = *p;
            q++;
            p++;
        }
        *q = '\0';

    } else if (bag1.size > bag2.size) {
        if (bag2.size == 1)
            bag2.size++;
        else
            bag2.size--;

        if (bag1.size == 2)
            bag1.size++;

        char *p = bag1.words[bag1.size - bag2.size].begin;
        char *q = s2;
        while (*q != '\0')
            q++;

        *q = ' ';
        q++;
        while (*p != '\0') {
            *q = *p;
            q++;
            p++;
        }

        *q = '\0';
    }
}

bool checkWordInString(const char *word, const char *str) {
    bool letters[ALPHABET_SIZE] = {false};

    for (; *str; ++str) {
        if (*str >= 'a' && *str <= 'z') {
            letters[*str - 'a'] = true;
        } else if (*str >= 'A' && *str <= 'Z') {
            letters[*str - 'A'] = true;
        }
    }

    for (; *word; ++word) {
        if (*word >= 'a' && *word <= 'z') {
            if (!letters[*word - 'a']) {
                return false;
            }
        } else if (*word >= 'A' && *word <= 'Z') {
            if (!letters[*word - 'A']) {
                return false;
            }
        }
    }

    return true;
}