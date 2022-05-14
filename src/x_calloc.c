#include "s21_sprintf.h"
#include "s21_support_funcs.h"
// сколько, какого размера
// возвращает указатель на выделенную память либо прерывает выполнение
void* x_calloc(size_t nmemb, size_t size) {
    void* pointer = s21_NULL;
    pointer = calloc(nmemb, size);
    if (pointer == s21_NULL) {
        exit(1);
    }
    return pointer;
}
