#ifndef INC_2NDSEMESTR_STRING__H
#define INC_2NDSEMESTR_STRING__H

#include "stdio.h"

// возвращает количество символов в строке (не считая ноль-символ)
size_t strlen_(const char *begin);

// возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти между адресами begin и end не включая end
char* find(char *begin, char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных
char* findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ
char* findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend
// Если символ не найден, возвращается адрес rend
char* findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend
// Если символ не найден, возвращается адрес rend
char* findSpaceReverse(char *rbegin, const char *rend);

#endif