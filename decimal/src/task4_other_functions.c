#include "s21_decimal.h"

//округление
s21_decimal divDecimalAndGetFractional(s21_decimal *res, int i, int exp) {
  int j = i;
  s21_decimal fraction = {{0, 0, 0, 0}};
  if (exp != 0) {
    fraction = div10DecimalSimple(res, 1);
    add_decimal_simple(fraction, divDecimalAndGetFractional(res, ++i, exp - 1),
                       &fraction);
  }
  if (j != 0)
    mult10DecimalSimple(&fraction, 1);
  else
    set_exp(&fraction, exp);
  return fraction;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  *result = value;
  div10DecimalSimple(result, getExp(*result));
  set_exp(result, 0);
  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  *result = value;
  int exp = getExp(*result);
  if (exp != 0) {
    s21_decimal fractional = divDecimalAndGetFractional(result, 0, exp);

    s21_decimal half = {{5, 0, 0, 0}};
    set_exp(&half, 1);
    s21_decimal one = {{1, 0, 0, 0}};
    if (s21_is_equal(half, fractional)) {
      if ((result->bits[0] & 1) == 1) add_decimal_simple(one, *result, result);
    } else if (s21_is_greater(fractional, half)) {
      add_decimal_simple(one, *result, result);
    }
    set_exp(result, 0);
  }
  return 0;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  *result = value;
  int exp = getExp(*result);
  if (exp != 0) {
    s21_decimal fractional = divDecimalAndGetFractional(result, 0, exp);
    s21_decimal zero = {{0, 0, 0, 0}};
    if (have_minus_decimal(*result) == 1 && s21_is_greater(fractional, zero)) {
      s21_decimal one = {{1, 0, 0, 0}};
      add_decimal_simple(*result, one, result);
    }
    set_exp(result, 0);
  }
  return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  *result = value;

  if ((result->bits[3] & MINUS) == MINUS)
    result->bits[3] ^= MINUS;
  else
    result->bits[3] |= MINUS;
  return 0;
}
//!округление