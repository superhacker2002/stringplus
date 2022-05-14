#include "s21_string.h"

// Сравнивает не более первых n байтов str1 и str2
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    while (*str1 == *str2 && n--) {  // пока str1 = str2 и n != 0 -> инкрементируем n
        str1++;
        str2++;
    }
    return (n == 0) ? 0 : *str1 - *str2;
}
