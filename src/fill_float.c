#include "s21_sprintf.h"
#include "s21_support_funcs.h"


char *f_fillment(struct formating* new_format, long double arg) {
    int precision = 0;  // если мы не получили точность от пользователя оставляем её дефолтной
    long double temp_arg = arg;
    if (new_format->precision > 0 || new_format->precision == 0) {
    // если есть точность или она нулевая
        precision = new_format->precision;
    } else {
        precision = 6;
    }
    int is_negative = 0;
    if (arg < 0) {  // если число отрицательное
        is_negative = 1;  // флаг для дальнейшего перевода числа в строку
    }
    char* float_str = (char*)x_calloc(100, sizeof(char));
    find_flag_to_float(new_format, &temp_arg, float_str);  // проверяем был ли флаг и кладем знак
    long double rightpart = 0;
    long double leftpart = 0;
    rightpart = modfl(temp_arg, &leftpart);
    rightpart = (rightpart * powl(10,19));

    if (new_format->flag.plus || new_format->flag.space || is_negative == 1) {
        // если были флаги или число было отрицательным
        int_to_str(new_format, leftpart, float_str + 1);
        // кладем целую часть в строку начиная со второго символа
    } else {
        int_to_str(new_format, leftpart, float_str);  // кладем целую часть в строку начиная с первого символа
    }
    int len = s21_strlen(float_str);  // находим длину целой части
    *(float_str + len) = '.';  // добавляем точку после целой части
    if (rightpart == 0) {  // если дробная часть оказалась нулевой
        s21_memset(float_str + len + 1, '0', precision);
        // заполняем нулями строку после точки в количестве точности
    } else {
        int zeroes = check_rightpart_zeroes(rightpart);  // если после точки были нули
        if (zeroes) s21_memset(float_str + len + 1, '0', zeroes);
        int_to_str(new_format, rightpart, float_str + zeroes + len + 1);
        // переводим дробную часть в строку
        round_value(float_str, precision);  // округляем дробную часть
    }
    if (precision == 0) {  // если точность была нулевой обрезаем точку
        *(float_str + len) = '\0';
    }
    add_width(new_format, float_str, s21_strlen(float_str));  // добавляем ширину
    return float_str;
}

int check_rightpart_zeroes(long int rightpart) {
    return 19 - count_char(rightpart);
}

void round_value(char *float_str, int precision) {
    int n = -1;
    int exit_flag = 0;
    do {
        n++;
    } while (float_str[n] != '.');
    int k = n + precision;
    int int_part_length = n;
    n += precision + 1;
    if (float_str[n] > '5') {
        exit_flag = 1;
    } else if (float_str[n] == '5') {
        n++;
        while (float_str[n] != '\0') {
            if (float_str[n] == '0') {
                n++;
            } else {
                exit_flag = 1;
                break;
            }
        }
    } else {
        float_str[n + precision + 1] = '\0';
    }

    if (exit_flag == 1) {
        while (k >= 0) {
            if (float_str[k] == '9') {
                float_str[k] = '0';
                k--;
            } else if (float_str[k] == '.') {
                k--;
            } else {
                float_str[k] += 1;
                break;
            }
        }
    }
    float_str[int_part_length + precision + 1] = '\0';
}

void find_flag_to_float(struct formating* new_format, long double* number, char *str) {
    // обработка флагов + и пробел
    if (*number < 0) {  // если число отрицательное
        *str = '-';  // кладем в строку минус
        *number *= -1;
        // число делаем положительным для дальнейшего преобразования в строку
    } else {
        if (new_format->flag.plus) {
            *str = '+';  // если был флаг плюс кладем плюс
        } else if (new_format->flag.space) {
            *str = ' ';  // для флага пробел кладем пробел
        }
    }
}
