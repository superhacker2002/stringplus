#include "s21_string.h"

// Копирует до n символов из строки, на которую указывает src, в dest
char* s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)  // пока i < n и мы не дошли до конца массива
        dest[i] = src[i];  // приравниваем dest элемент к src элементу
    dest[i] = '\0';
    return dest;  // возвращаем указатель на измененный массив
}
