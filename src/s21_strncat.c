#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    unsigned len_dest = s21_strlen(dest);
    unsigned len_src = s21_strlen(src);

    if (len_src < n) {  // если src короче кол-ва байт которые надо добавить в dest
        s21_strcpy(&dest[len_dest], src);  // копируем в конец dest
    } else {  // если одинаковой длины или длиннее
        s21_strncpy(&dest[len_dest], src, n);  // копируем до заданного байта
        dest[len_dest + n] = '\0';  // добавляем знак конца строки
    }
    return dest;
}
