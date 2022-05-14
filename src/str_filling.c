#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#include "s21_sprintf.h"
#include "s21_support_funcs.h"

void choose_specificator(struct formating *new_format, char **str, va_list arg,
                        int *str_length) {
    s21_size_t formatted_len = 0;
    char *formatted = s21_NULL;
    int count_bytes = 0;
    // создаем указаель на буфер для отформатированной строки

    if (new_format->spec.c_enabled) {
        if (new_format->length.l_enabled) {
            (void*)setlocale(LC_ALL, "");
            wchar_t wide_char = va_arg(arg, wint_t);
            char mb[MB_CUR_MAX];
            s21_memset(mb, '\0', MB_CUR_MAX);
            wctomb(mb, wide_char);
            formatted = c_fillment_wchar(new_format, mb, &count_bytes);
            if (count_bytes == 0) count_bytes = 1;
        } else {
            int temp_char = va_arg(arg, int);
            formatted = c_fillment(new_format, temp_char);
            count_bytes = 1;
        }
    } else if (new_format->spec.s_enabled) {
        if (new_format->length.l_enabled) {
            (void*)setlocale(LC_ALL, "");
            wchar_t* buff = va_arg(arg, wchar_t*);
            int i = wcstombs(0, buff, wcslen(buff) * MB_CUR_MAX + 1);
            char *char_buff = x_calloc(i + 1, sizeof(char));
            wcstombs(char_buff, buff, wcslen(buff) * MB_CUR_MAX + 1);
            formatted = s_fillment(new_format, char_buff);
            free(char_buff);
        } else {
            formatted = s_fillment(new_format, va_arg(arg, char *));
        }
    } else if (new_format->spec.d_enabled) {
        formatted = d_fillment(new_format, arg);
    } else if (new_format->spec.f_enabled) {
        long double temp_char = va_arg(arg, double);
        formatted = f_fillment(new_format, temp_char);
    } else if (new_format->spec.i_enabled) {
        formatted = d_fillment(new_format, arg);
    } else if (new_format->spec.u_enabled) {
        new_format->flag.plus = 0;
        new_format->flag.space = 0;
        formatted = u_fillment(new_format, arg);
    }
    formatted_len = s21_strlen(formatted);
    if (new_format->spec.c_enabled && new_format->width) {
        *str_length += new_format->width;
    } else if (new_format->spec.c_enabled && !new_format->width) {
        *str_length += count_bytes;
    } else {
        *str_length += formatted_len;
    }
    s21_memcpy(*str, formatted, formatted_len);  // копируем буфер в str
    free(formatted);
    (*str) += formatted_len;  // сдвигаем указатель в str после добавления
}

void add_width(struct formating *new_format, char *str, int length) {
    int width = new_format->width;
    int len = length;
    char str_copy[100];  // создаем копию строки
    s21_strcpy(str_copy, str);
    char spaces[100];  // буфер для пробелов

    if (width && width > len) {  // есть ширина
        s21_memset(spaces, ' ',
                   width - len);  // заполняем пробелами до начала числа
        spaces[width - len] = '\0';
        if (new_format->flag.minus) {  // есть выравнивание по левой стороне
            s21_strcat(str, spaces);  // кладем в str
        } else {  // нет выравнивания по левой стороне
            s21_strcpy(str, spaces);
            s21_strcat(str, str_copy);
        }
    }
}
