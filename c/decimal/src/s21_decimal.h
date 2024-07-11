#ifndef s21_DECIMAL_H
#define s21_DECIMAL_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINUS 0x80000000
#define MAX "79228162514264337593543950335"
#define MIN "-79228162514264337593543950335"

typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_bigDecimal;

union parseFloat {
  float f;
  struct {
    unsigned int m : 23;
    unsigned int e : 8;
    unsigned int s : 1;
  } parts;
  unsigned int32_bytes;
};

//----------------------------------------------------------------------------
//общие функции

int myMiniPow(int num, int exp);

int getExp(const s21_decimal var);

int set_exp(s21_decimal *dst, int exp);
//проверяет, есть ли минус в децимал
int have_minus_decimal(s21_decimal num);
//проверяет децимал на нулевой
int isDecimalZero(s21_decimal var);
//двигеает 0, 1, 2 биты влево. В аргументах (2) на сколько двигать и (3) что
//вставлять справа (0 или 1). Вернёт 1, если затёр единичку
int shiftLeft3BitDecimal(s21_decimal *num, unsigned howMany, int whatInsert);
//двигеает 0, 1, 2 биты вправо. В аргументах (2) на сколько двигать и (3) что
//вставлять слева (0 или 1)
void shiftRight3BitDecimal(s21_decimal *num, unsigned howMany, int whatInsert);
//Нулями забивает 0, 1, 2 биты. Если нужно занулить бит 3, во втором аргументе
//писать 1, иначе 0
int clearDecimal(s21_decimal *dst, int allClear);
//сравнение чисел, учитывая 3-ий бит. Вернёт -1, если первое число больше
//второго, и 1, если наоборот. Вернёт 0, если числа равны
int comparisonDecimalSimple(s21_decimal num1, s21_decimal num2);

//!общие функции
//----------------------------------------------------------------------------
//простая арифметика

//сравнение чисел, не учитывая 3-ий бит. Вернёт -1, если первое число больше
//второго, и 1, если наоборот. Вернёт 0, если числа равны
int comparisonDecimal(s21_decimal num1, s21_decimal num2);
//сложение первого числа со вторым, не учитывая 3-ий бит. Если переполнение,
//возвращает 1 и не меняет result
int add_decimal_simple(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);
//вычитание первого числа на второе, не учитывая 3-ий бит. Если первое число
//меньше, возвращает 0 и не меняет result
int subDecimalSimple(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result);
//умножение на 10 и не учитывая 3-ий бит. Возвращает 0, если не было
//переполнения
int mult10DecimalSimple(s21_decimal *num, int howMany);
//умножение на 5 не учитывая 3-ий бит. Возвращает 0, если не было переполнения
int mult5DecimalSimple(s21_decimal *num, int howMany);
//деление без остатка и не учитывая 3-ий бит
s21_decimal div10DecimalSimple(s21_decimal *var, int howMany);

//!простая арифметика
//----------------------------------------------------------------------------
//из parser_char_decimal.c

//Из децимал в строу
int fromDecimalToChar(const s21_decimal src, char *dst, int lenDst);

//!из parser_char_decimal.c
//----------------------------------------------------------------------------
//+
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
//-
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
//*
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
///
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
//<
int s21_is_less(s21_decimal, s21_decimal);
//<=
int s21_is_less_or_equal(s21_decimal, s21_decimal);
//>
int s21_is_greater(s21_decimal, s21_decimal);
//>=
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
//==
int s21_is_equal(s21_decimal, s21_decimal);
//!=
int s21_is_not_equal(s21_decimal, s21_decimal);
// from int
int s21_from_int_to_decimal(int src, s21_decimal *dst);
// from float
int s21_from_float_to_decimal(float src, s21_decimal *dst);
// in int
int s21_from_decimal_to_int(s21_decimal src, int *dst);
// in float
int s21_from_decimal_to_float(s21_decimal src, float *dst);
//округление в сторону -inf
int s21_floor(s21_decimal value, s21_decimal *result);
//округление
int s21_round(s21_decimal value, s21_decimal *result);
//оставляет только целую часть
int s21_truncate(s21_decimal value, s21_decimal *result);
//меняет знак
int s21_negate(s21_decimal value, s21_decimal *result);

#endif