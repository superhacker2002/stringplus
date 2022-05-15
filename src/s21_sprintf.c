#include "s21_sprintf.h"
#include "s21_support_funcs.h"

int s21_sprintf(char* str, const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    struct formating new_format;  // создаем структуру
    int str_length = 0;

    while (*format != '\0') {
        int parse_result = 0;
        s21_memset(&new_format, 0, sizeof(struct formating));  // заполнение структуры нулями
        new_format.precision = -1;
        if (*format == '%') {  // если встретили %
            format++;  // переключаемся на следующий после процента символ
            parse_result = parse(&new_format, &format);
            // проверяем входит ли этот символ в символы форматирования
            if (parse_result == IS_PERCENT) {
                // если следующий знак после % процент
                *str++ = '%';
                format++;
                str_length += 1;
                continue;
            } else if (parse_result == NOT_VALID) {
                add_not_valid(&format, &str, &str_length);
                // все до следующего % добавляем в str
            } else if (parse_result == IS_SPEC) {  // если следующий знак спецификатор
                choose_specificator(&new_format, &str, arg, &str_length);
                format++;
            } else {  // если это какой-либо знак форматирования
                parse_till_percent(&new_format, &format, &str, arg, &str_length);
                // записываем в структуру все следующие значения
            }
        } else {
            add_not_valid(&format, &str, &str_length);  // все до следующего % добавляем в str
        }
    }
    va_end(arg);
    *str = '\0';
    return str_length;
}

