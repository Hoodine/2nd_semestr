#ifndef INC_2NDSEMESTR_STRING__H
#define INC_2NDSEMESTR_STRING__H

#include <stdbool.h>
#include "stdio.h"

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define ALPHABET_SIZE 26

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

//возвращает длину строки
size_t strlen_(const char *begin);

// Функции обработки слова
char *strpbrk_(const char *str, const char *delim);

char *strtok_(char *str, const char *delim);

char *strcat_(char *dest, const char *src);

void strcpy_(char *dest, const char *src);

char *strncpy_(char *destination, const char *source, size_t num);

int strncmp_(const char *s1, const char *s2, size_t n);

char *strrchr_(const char *str, int c);

//возвращает указатель
//на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end.
char *find(char *begin, char *end, int ch);

//возвращает указатель на первый пробельный
// символ, расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ.
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ.
char *findSpace(char *begin);

//Возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin (последний символ
//строки, за которым следует ноль-символ) и заканчивая rend
//(адрес символа перед началом строки). Если символ не найден, возвращается адрес rend.
char *findNonSpaceReverse(char *rbegin, const char *rend);

//Возвращает указатель на первый пробельный символ справа, расположенный на ленте
//памяти, начиная с rbegin и заканчивая rend. Если символ не найден,
//возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend);

//записывает по адресу beginDestination
//фрагмент памяти, начиная с адреса beginSource до endSource
//возвращает указатель на следующий свободный фрагмент памяти в
//destination О
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

//Записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с beginSource
//заканчивая endSource, удовлетворяющие функции-предикату f. Функция
//возвращает указатель на следующий свободный для записи фрагмент в
//памяти П
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

//Записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы
//функции К
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

// Возвращает указатель на конец строки А
char *getEndOfString(char *begin);

// Удаляет из строки все пробельные символы Л
void removeNonLetters(char *s);

// Посмотри описание copy, copyIf, copyIfReverse, getEndOfString и removeNonLetters
// и реши ребус :)
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

// Сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);

//удаляет повторяющиеся символы
void removeAdjacentEqualLetters(char *s);

// Возвращает значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

// преобразовывает слово таким образом, чтобы цифры были перенесены
// в начало слова и изменить порядок следования цифр в слове на обратный
void reversedDigitToStart(WordDescriptor word);

// преобразовывает слово таким образом, чтобы цифры были перенесены
// в начало слова
void digitToStart(WordDescriptor word);

// Преобразовывает строку таким образом, чтобы цифры каждого слова были
// перенесены в начало слова без изменения порядка следования их в слове,
// буквы перенесены в конец слова
void digitsToStart(char *s);

// Возвращает значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа конца слова
int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

// Преобразовывает строку, заменяя каждую цифру соответствующим ей числом пробелов
void replaceDigitsToNumOfSpaces(char *s);

// Заменяет все вхождения слова w1 на слово w2
void replace(char *source, char *w1, char *w2);

// Определяет, являются ли два слова одинаковыми
bool areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//Определяет, упорядочены ли лексикографически слова данного предложения
bool areWordsOrdered(char *s);

//Выводит слова данной строки в обратном порядке по одному в строке экрана
void getBagOfWords(BagOfWords *bag, char *s);

// Копирует символы из заданного диапазона строки в обратном порядке в другую строку.
// Начиная с указателя rbeginSource и до rendSource,
// символы копируются в строку, начиная с указателя beginDestination.
char *copyReverse(char *rbeginSource, const char *rendSource, char
*beginDestination);

// Разбивает входную строку s на слова, затем переворачивает каждое слово
// и объединяет их в одну строку
void reverseWordsBag(char *s);

// Проверяет, является ли заданное слово палиндромом.
bool isWordPalindrome(char *begin, char *end);

// Подсчитывает количество палиндромов в строке, разделенной запятыми.
size_t howManyWordsPalindromes(char *s);

//объединяет две строки s1 и s2, разбивая их на слова
//с помощью функции strtok_ и объединяя слова
//в результирующую строку result
void mergeStrings(char *s1, char *s2, char *result);

//Преобразовывает строку, изменяя порядок следования слов в строке на обратный.
void reverseWords(char *str);

// Выводит перове слово перед словом с буквой А
void printWordBeforeFirstWordWithA(char *s);

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s,
                                                               WordDescriptor *w);

void wordDescriptorToString(WordDescriptor word, char *destination);

BagOfWords createBagOfWordsFromString(char *s);

int isWordInBagOfWords(WordDescriptor word, BagOfWords bag);

// Определяет последнее из слов первой строки, которое есть во второй строке.
WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2);

// Определяет, есть ли в строке одинаковые слова
bool hasDuplicateWords(char *s);

// Сравнивает 2 слова между собой
int compareWords(char *word1, char *word2);

// Разбирает строку
void parseString(char *str, BagOfWords *bag);

// Определяет, есть ли в данной строке пара слов, составленных
// из одинакового набора букв.
int findPairWithSameLetters(BagOfWords *bag);

// Функция для получения строки из слов, которые отличны от последнего слова
char *getWordsExceptLast(char *str);

//Находит слово, предшествующее первому вхождению 𝑤 в 𝑠1
char *findWordBeforeFirstOccurrence(char *s1, char *s2);

// Функция для проверки, является ли слово палиндромом
bool isPalindromeInString(char *s);

// Функция для удаления слов-палиндромов из строки
void removePalindromes(char *str);

// Функция, которая дополняет строку, содержащую меньшее количество слов, последними
// словами строки, в которой содержится большее количество слов
void append(char *s1, char *s2);

// Функция для проверки вхождения букв из заданного слова в строку
bool checkWordInString(const char *word, const char *str);

#endif