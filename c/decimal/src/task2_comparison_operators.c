#include "s21_decimal.h"

int comparisonDecimalSimple(s21_decimal num1, s21_decimal num2) {
  s21_decimal var1 = num1;
  s21_decimal var2 = num2;

  int answer = 0;
  int indexBits;
  for (int i = 95; answer == 0 && i > -1; i--) {
    indexBits = i / 32;
    if ((var1.bits[indexBits] & MINUS) > (var2.bits[indexBits] & MINUS))
      answer = -1;
    else if ((var1.bits[indexBits] & MINUS) < (var2.bits[indexBits] & MINUS))
      answer = 1;
    var1.bits[indexBits] <<= 1;
    var2.bits[indexBits] <<= 1;
  }
  return answer;
}

//округляет сколько нужно цифр (count) и возвращает остаток последней итерации
//округления (3.45 => 3.4 и вернет 5)
s21_decimal s21_roundBank(s21_decimal value, s21_decimal *result, int count) {
  s21_decimal fraction = {{0, 0, 0, 0}};
  if (count > 0) {
    *result = value;
    int exp = getExp(*result);
    set_exp(result, exp - count);

    div10DecimalSimple(result, count);
    s21_decimal temp = *result;
    mult10DecimalSimple(&temp, count);

    subDecimalSimple(value, temp, &fraction);
    set_exp(&fraction, count);
  }
  return fraction;
}
//подгоняет две степени под одну и возвращает остаток от числа, которое пришлось
//поделить для скейла. Иначе вернет 0
s21_decimal scale(s21_decimal *num1, s21_decimal *num2) {
  int exp1 = getExp(*num1);
  int exp2 = getExp(*num2);
  int diffExp;
  s21_decimal fraction = {{0, 0, 0, 0}};
  if (exp1 > exp2) {
    diffExp = exp1 - exp2;
    int howManyDiv = mult10DecimalSimple(num2, diffExp);
    set_exp(num2, exp2 + (diffExp - howManyDiv));
    fraction = s21_roundBank(*num1, num1, howManyDiv);
  } else if (exp1 < exp2) {
    diffExp = exp2 - exp1;
    int howManyDiv = mult10DecimalSimple(num1, diffExp);
    set_exp(num1, exp1 + (diffExp - howManyDiv));
    fraction = s21_roundBank(*num2, num2, howManyDiv);
    // div10DecimalSimple(num2, howManyDiv);
  }
  return fraction;
}
//сравнивает децимал. Если левое число больше, вернёт -1, если правое, то 1.
//Если равны - 0.
int comparisonDecimal(s21_decimal num1, s21_decimal num2) {
  s21_decimal var1 = num1;
  s21_decimal var2 = num2;
  if (isDecimalZero(var1)) var1.bits[3] = 0;
  if (isDecimalZero(var2)) var2.bits[3] = 0;

  int answer = 0;

  if ((var1.bits[3] & MINUS) && (var2.bits[3] & MINUS)) {
    var1.bits[3] ^= MINUS;
    var2.bits[3] ^= MINUS;
    answer = comparisonDecimal(var1, var2) * (-1);
  } else if (var1.bits[3] & MINUS)
    answer = 1;
  else if (var2.bits[3] & MINUS)
    answer = -1;
  else {
    scale(&var1, &var2);
    answer = comparisonDecimalSimple(var1, var2);
  }
  return answer;
}

//сравнения
int s21_is_less(s21_decimal num1, s21_decimal num2) {
  int answer = 0;
  int temp = comparisonDecimal(num1, num2);
  if (temp == 1) answer = 1;
  return answer;
}

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  int answer = 0;
  int temp = comparisonDecimal(num1, num2);
  if (temp == 1 || temp == 0) answer = 1;
  return answer;
}

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  int answer = 0;
  int temp = comparisonDecimal(num1, num2);
  if (temp == -1) answer = 1;
  return answer;
}

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  int answer = 0;
  int temp = comparisonDecimal(num1, num2);
  if (temp == -1 || temp == 0) answer = 1;
  return answer;
}

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int answer = 0;
  int temp = comparisonDecimal(num1, num2);
  if (temp == 0) answer = 1;
  return answer;
}

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  int answer = 0;
  int temp = comparisonDecimal(num1, num2);
  if (temp != 0) answer = 1;
  return answer;
}
//!сравнения