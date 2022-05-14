#include "s21_string.h"

// Безопасно копирует n символов из src в dest
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    s21_size_t count = n;  // дописал Вадим
    void *dest_start = dest;  // указатель на начало destination
    // кастуем указатели void в char для сравнений чтобы знать размер элемента
    char *char_dest = (char*)dest;
    char *char_src = (char*)src;

    if (dest <= src || char_dest >= (char_src + count)) {
        // проверяем что dest до src или после + кол-во элементов которые мы копируем
        while (count--) {
            *char_dest = *char_src;  // копируем символы из src в dest
            char_dest++, char_src++;
        }
    } else {  // если происходит наложение
        char_dest += count - 1;
        char_src += count - 1;
        while (count--) {
            *char_dest = *char_src;
            char_dest--, char_src--;
        }
    }
    return dest_start;
}
