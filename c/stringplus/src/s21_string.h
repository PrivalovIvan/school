#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define s21_size_t unsigned long long
#define s21_NULL 0
#define SPACE(c) c == '\t' or c == '\n' or c == '\v' or c == '\f' or c == '\r'
#define LENGTH s21_analysis_format(&set, (char *)format)
#define NUM(c) c >= '0' and c <= '9'
#define HEX_X(c) c >= 'A' and c <= 'F'
#define HEX_x(c) c >= 'a' and c <= 'f'
#define s21_isspace(c) (c == ' ' or SPACE(c) ? 1 : 0)

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strcpy(char *dst, const char *src);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sprintf(char *restrict str, const char *restrict format, ...);

// S21_SSCANF
typedef struct param_for_sscanf {
  int *num_d, *num_i;
  float *num_db;
  unsigned int *u_num;
  int count_n;

  char *simbol, *ch;
  wchar_t *chL;
  void *p;

  int l, c, o, h, L, x;

  int length;
} flags;

/**
 * Функция перебирает строку формата, далее в свиче находит соответствующий
 * кейс.
 */
int s21_sscanf(const char *str, const char *format, ...);

/**
 * Функция перебирает посимвольно строку формата на предмет наличия опций
 * длины и ширины. Возвращает длину.
 */
int s21_analysis_format(flags *set, char *format);

/**
 * Функция производит разбор строки и разделяет ее на лексемы по
 * пробелам/установленной длины, присваивая каждую итерацию в парсере переменной
 * set.ch новое значение этой лексемы.
 */
char *s21_analysis_string(char *str, char *ch, int length, flags *set);

/**
 * Фуннкция переводит из 16- и 8- ричных систем счисления в 10-чную.
 */
long int s21_octal_and_hex_number_system(char *s, flags *set);

/**
 * Функция нужна для копирования данных из char в wchar_t.
 * Используется для параметра lc И ls.
 */
s21_size_t s21_mbstowcs(wchar_t *dest, const char *src, s21_size_t n);

/**
 * Функция разбирает строку и переводит ее в числовое значение
 * соответствующее адресу памяти.
 */
int s21_parse_pointer(const char *str, void **ptr);

typedef struct func_sscanf {
  void (*func[128])(flags *set, va_list args, int *count, char *ch);
} func;

void setting_the_menu(func *menu);
void s21_print_f(flags *set, va_list args, int *count, char *ch);
void s21_print_s(flags *set, va_list args, int *count, char *ch);
void s21_print_c(flags *set, va_list args, int *count, char *ch);
void s21_print_d(flags *set, va_list args, int *count, char *ch);
void s21_print_x(flags *set, va_list args, int *count, char *ch);
void s21_print_i(flags *set, va_list args, int *count, char *ch);
void s21_print_u(flags *set, va_list args, int *count, char *ch);
void s21_print_p(flags *set, va_list args, int *count, char *ch);

#endif
