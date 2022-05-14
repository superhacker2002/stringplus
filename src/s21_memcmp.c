#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int result = 0;
    s21_size_t i;
    const unsigned char* string1 = str1;  // создаем запасные const unsigned
    const unsigned char* string2 = str2;  // char указатели, работать будем с ними

    for (i = 0; i < n; i++) {  // пока не дойдем до n-ного байта
        if (*(string1 + i) != *(string2 + i)) {  // если нашли разные байты
            result = 1;  // флаг
            break;  // выходим из цикла, так как нашли первое включение
        }
    }

    if (result == 1) {  // если в множестве от 0-го эл-та массива до n-ного байта есть разные символы
        result = *(string1 + i) - *(string2 + i);  // записываем разницу в байтах по таблице ASCII
    }

    return result;  // возвращаем 0/+ число/- число
}

