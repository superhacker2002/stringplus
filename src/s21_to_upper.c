#include "s21_string.h"
#include "s21_support_funcs.h"

void* s21_to_upper(const char* str) {
    s21_size_t i = 0;
    s21_size_t length = 0;
    char* buffer = s21_NULL;
    if (str) {
        length = s21_strlen(str);
        buffer = (char*)x_calloc(length + 1, sizeof(char));
    }
    // создаем переменную длины входящего массива str
    // выделяем память под буффер

    if (str) {  // если указатель не нулевой
        while (i <= length) {  // пока не дойдем до конца массива (включая знак
                               // конца строки)
            if (str[i] >= 97 && str[i] <= 122) {
                // если текущий чар принадлежит множеству ловеркейс букв
                buffer[i] = str[i] - 32;  // присваиваем текущему эл-ту буффера
                                          // аналогичную букву, но апперкейс
            } else {
                buffer[i] = str[i];
            }
            i++;  // инкремент
        }
    }
    return buffer;  // возвращаем буффер
}
