#include "s21_string.h"
#include "s21_support_funcs.h"

void* s21_to_lower(const char* str) {
    s21_size_t i = 0;
    s21_size_t length = s21_strlen(str);  // создаем переменную длины входящего массива str
    char* buffer = s21_NULL;
    buffer =
        (char*)x_calloc(length + 1, sizeof(char));  // выделяем память под буффер

    if (str) {  // если указатель не нулевой
        while (i <= length) {  // пока не дойдем до конца массива (включая знак
                               // конца строки)
            if (str[i] >= 65 && str[i] <= 90) {  // если текущий чар принадлежит
                                                 // множеству апперкейс букв
                buffer[i] = str[i] + 32;  // присваиваем текущему эл-ту буффера
                                          // аналогичную букву, но ловеркейс
            } else {
                buffer[i] = str[i];
            }
            i++;  // инкремент
        }
    }
    return buffer;  // возвращаем буффер
}
