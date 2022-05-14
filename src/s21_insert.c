#include "s21_support_funcs.h"
#include "s21_string.h"
// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *buffer = s21_NULL;
    if (str && src && str[0] != '\0') {
        s21_size_t str_length = s21_strlen(str);
        s21_size_t src_length = s21_strlen(src);
        s21_size_t i = 0;
        s21_size_t j;
        s21_size_t k;
        buffer = (char *)x_calloc(src_length + str_length + 1, sizeof(char));
        // выделяем память под новую строку длинной = str + src

        if (buffer && start_index < src_length && src && str) {
            // если память выделилась и start_index меньше чем основная строка
            for (; i < start_index; ++i) {  // заполняем новый массив от 0 до start_index
                buffer[i] = src[i];
            }

            for (j = 0; j < str_length; ++j) {  // заполняем новый массив от start_index до конца str
                         // строки
                buffer[i] = str[j];
                i++;
            }

            for (k = start_index; k < src_length; ++k) {
                // заполняем новый массив от конца str строки до конца src строки
                buffer[i] = src[k];
                i++;
            }

            buffer[i] = '\0';
        }
    }
    return buffer;
}
