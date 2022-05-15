#include "s21_string.h"
#include "s21_support_funcs.h"

// Возвращает новую строку, в которой удаляются все начальные
// и конечные вхождения набора заданных символов (trim_chars) из данной строки (src)
void *s21_trim(const char *src, const char *trim_chars) {
    char *result = s21_NULL;
    int target = 0;

    if (src && trim_chars) {  // если нам пришли не нал-поинтеры
        char *trim_buff;
        int target_pass = 0, k = 0;
        result = (char*)x_calloc((s21_strlen(src) +
                         1), sizeof(char));  // выделяем память под результирующую строку

        if (s21_strlen(trim_chars) ==
            0) {  // если длина входящей подстроки равна нулю
            trim_buff =
                " ";  // приравнием подстроку к пробелу, удалять будем пробелы
        } else {
            trim_buff = (char *)
                trim_chars;  // иначе приравнием буфер подстроки к подстроке
        }

        if (s21_strlen(src) < 1 || s21_strlen(trim_buff) < 1) {
            target = 1;
        }  // если длина строки меньше 1, или длина подстроки меньше 1, таргет =
           // 1 => возвращаем налл

        for (s21_size_t i = 0; src[i] && !target;
             ++i) {  // пока не дойдем до конца строки и таргет = 0
            for (s21_size_t j = 0; trim_buff[j] && !target_pass;
                 ++j) {  // пока не дойдем до конца подстроки и таргет пасс = 0
                         // (пройдем до конца трим буф строки один раз)
                if (trim_buff[j] ==
                    src[i]) {  // кладем в буффер подстроки эл-т из строки
                    ++i;
                    j = -1;  // чтобы не смещаться
                }
            }

            target_pass = 1;
            result[k] = src[i];
            ++k;
        }

        result[k] = '\0';

        for (s21_size_t j = 0; trim_buff[j] && !target;
             ++j) {  // пока не дойдем до конца буффера подстроки и таргет = 0
            if (trim_buff[j] == result[k - 1]) {
                --k;
                j = -1;
            }
        }

        result[k] = '\0';
    }
    return target ? s21_NULL : result;
}
