#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки
void *s21_memchr(const void *str, int c, s21_size_t n) {
    s21_size_t i;
    int flag = 0;
    for (i = 0; i < n; i++) {
        if (*((char*)str + i) == c) {  // если чар, на который указывает str + i равен чару с
            flag = 1;  // нашли вхождение
            break;  // выходим из цикла так как нашли исокомый символ не дойдя до n-ного байта
        }
    }
    if (flag == 0) {  // если дошли до конца массива либо до n-ного байта и не нашли искомый чар
        str = s21_NULL;

    } else {  // если нашли искомый чар, запоминаем его местоположение
        str = (char*)str + i;
    }
    return (char*)str;  // возвращаем либо местоположение либо NULL
}
