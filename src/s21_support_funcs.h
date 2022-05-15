#ifndef SRC_SPRINTF_SUPPORT_FUNCS_H_
#define SRC_SPRINTF_SUPPORT_FUNCS_H_

#include "s21_sprintf.h"

int parse(struct formating* new_format, const char** format);
void check_specificator(struct formating* new_format, const char** format, int* flag);
void check_flag(struct formating* new_format, const char** format, int* flag);
void check_width(struct formating* new_format, const char** format, int* flag);
void check_precision(struct formating* new_format, const char** format, int* flag);
void check_length(struct formating* new_format, const char** format, int* flag);
int ascii_to_int(const char** str);
void choose_specificator(struct formating* new_format, char** str, va_list arg, int* str_length);

void add_not_valid(const char** format, char** str, int* str_length);
void parse_till_percent(struct formating* new_format, const char** format, char** str, va_list arg, int* str_len);
void add_first_char(struct formating* new_format, const char** format, char** str);
void add_chars(struct formating* new_format, const char** format, char** str, int* str_length);

void add_width(struct formating* new_format, char* str, int length);
char* c_fillment(struct formating* new_format, int arg);
char* c_fillment_wchar(struct formating* new_format, char* arg, int *count_bytes);

char* s_fillment(struct formating* new_format, char* arg);
void find_precision_to_str(struct formating* new_format, int* arg_len, char* tmp_arg);

char* d_fillment(struct formating* new_format, va_list arg);
void length_cast(struct formating* new_format, va_list arg, long int* num);
void find_precision_to_int(struct formating* new_format, char** str, long int number);
char* int_to_str(struct formating* new_format, long int number, char* str);
int count_char(long int number);
void find_flag_to_int(struct formating* new_format, long int* number, char** str);

char* u_fillment(struct formating* new_format, va_list arg);
void u_length_cast(struct formating* new_format, va_list arg, unsigned long int* num);
int count_unsigned_chars(unsigned long int number);
char *unsigned_to_str(struct formating* new_format, unsigned long int number, char *str, int length);
void find_precision_to_unsigned(struct formating* new_format, char **str, int length);

char *f_fillment(struct formating* new_format, long double arg);
void find_flag_to_float(struct formating* new_format, long double* number, char *str);
void round_value(char* float_str, int precision);
int check_rightpart_zeroes(long long int rightpart);

void* x_calloc(size_t nmemb, size_t size);

void check_percent(struct formating* new_format, const char** format, char** str, int* str_length);

#endif  // SRC_SPRINTF_SUPPORT_FUNCS_H_
