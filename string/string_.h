#ifndef INC_2NDSEMESTR_STRING__H
#define INC_2NDSEMESTR_STRING__H

#include "stdio.h"
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define ALPHABET_SIZE 26

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

//возвращает длину строки
size_t strlen_(const char *begin);

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
char* findSpace(char *begin);

//Возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin (последний символ
//строки, за которым следует ноль-символ) и заканчивая rend
//(адрес символа перед началом строки). Если символ не найден, возвращается адрес rend.
char* findNonSpaceReverse(char *rbegin, const char *rend);

//Возвращает указатель на первый пробельный символ справа, расположенный на ленте
//памяти, начиная с rbegin и заканчивая rend. Если символ не найден,
//возвращается адрес rend.
char* findSpaceReverse(char *rbegin, const char *rend);

//записывает по адресу beginDestination
//фрагмент памяти, начиная с адреса beginSource до endSource
//возвращает указатель на следующий свободный фрагмент памяти в
//destination О
char* copy(const char *beginSource, const char *endSource,
           char *beginDestination);

//Записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с beginSource
//заканчивая endSource, удовлетворяющие функции-предикату f. Функция
//возвращает указатель на следующий свободный для записи фрагмент в
//памяти П
char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

//Записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы
//функции К
char* copyIfReverse(char *rbeginSource, const char *rendSource,
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

#endif
