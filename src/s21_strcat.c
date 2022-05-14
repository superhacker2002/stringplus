#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest
char *s21_strcat(char *dest, const char *src) {
    char *ptr = dest + s21_strlen(dest);  // создаем указатель на конец dest
    while (*src != '\0') {  // добавляем символы из src в dest
        *ptr++ = *src++;
    }
    *ptr = '\0';  // добавляем знак конца строки
    return dest;
}
