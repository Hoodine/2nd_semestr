#ifndef INC_2NDSEMESTR_VECTORVOID_H
#define INC_2NDSEMESTR_VECTORVOID_H

#ifndef UNIKUM_VECTORVOID_H
#define UNIKUM_VECTORVOID_H

#include <limits.h>


typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора
    size_t size;         // размер вектора
    size_t capacity;     // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;

//создает вектор типа baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

//изменяет текущий объём выделенной памяти
void reserveV(vectorVoid *v, size_t newCapacity);

//освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *v);

//удаляет элементы из контейнера, но не освобождает выделенную память
void clearV(vectorVoid *v);

//освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v);

#endif