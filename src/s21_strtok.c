#include "s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim
char *s21_strtok(char *str, const char *delim) {
    static char *new = s21_NULL;
    if (!str) {  // при повторном вызове функции мы меняем указатель str на начало новой лексемы
        str = new;
        if (str == s21_NULL) {
            return s21_NULL;
        }
    }

    str += s21_strspn(str, delim);  // проверяем сколько разделителей в начале новой лексемы
    if (*str == '\0') {
        new = s21_NULL;
        return new;
    }

    new = str + s21_strcspn(str, delim);  // количество символов до следующего разделителя
    if (new[0] != '\0') {  // если не конец строки
        new[0] = '\0';  // заменяем первый разделитель на \0
        new++;  // перемещаемся на следующий символ
    } else {
        new = s21_NULL;
    }
    return str;
    
}
