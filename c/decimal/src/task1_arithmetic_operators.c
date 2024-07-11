#include "s21_decimal.h"

//сложение первого числа со вторым, не учитывая 3-ий бит. Если переполнение,
//возвращает 1 и не меняет result
int add_decimal_simple(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result) {
  if (result == NULL) return -1;
  s21_decimal val1Cpy = value_1;
  s21_decimal val2Cpy = value_2;
  s21_decimal val3Cpy = *result;
  clearDecimal(&val3Cpy, 0);
  int ten = 0;
  int pool = 0;
  int index;
  for (int i = 0; i < 96; i++) {
    index = i / 32;
    pool = (val1Cpy.bits[index] & 1) + (val2Cpy.bits[index] & 1) + ten;
    if (pool == 1) {
      val3Cpy.bits[index] |= MINUS;
      ten = 0;
    } else if (pool == 2) {
      ten = 1;
    } else if (pool == 3) {
      val3Cpy.bits[index] |= MINUS;
      ten = 1;
    }
    val1Cpy.bits[index] >>= 1;
    val2Cpy.bits[index] >>= 1;
    if ((i + 1) % 32 != 0) val3Cpy.bits[index] >>= 1;
  }
  int ret = 0;
  if (ten == 1)
    ret = 1;
  else
    *result = val3Cpy;
  return ret;
}
//вычитание первого числа на второе, не учитывая 3-ий бит. Если первое число
//меньше, возвращает 0 и не меняет result
int subDecimalSimple(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result) {
  if (result == NULL) return -1;
  int answer = 0;
  int comparison = comparisonDecimalSimple(value_1, value_2);
  if (comparison == -1 || comparison == 0) {
    s21_decimal val1Cpy = value_1;
    s21_decimal val2Cpy = value_2;
    s21_decimal val3Cpy = *result;
    clearDecimal(&val3Cpy, 0);
    int ten = 0;
    int index;
    int temp1;
    int temp2;
    for (int i = 0; i < 96; i++) {
      index = i / 32;
      temp1 = val1Cpy.bits[index] & 1;
      if (temp1 == 1) {
        temp1 -= ten;
        ten = 0;
      } else
        temp1 += ten;

      temp2 = val2Cpy.bits[index] & 1;

      if (temp1 == 1 && temp2 == 0) {
        val3Cpy.bits[index] |= MINUS;
      } else if (temp1 == 0 && temp2 == 1) {
        val3Cpy.bits[index] |= MINUS;
        ten = 1;
      }
      val1Cpy.bits[index] >>= 1;
      val2Cpy.bits[index] >>= 1;
      if ((i + 1) % 32 != 0) val3Cpy.bits[index] >>= 1;
    }
    *result = val3Cpy;
  } else
    answer = 1;
  return answer;
}
//умножение на 10 и не учитывая 3-ий бит. Возвращает 0, если не было
//переполнения
int mult10DecimalSimple(s21_decimal *num, int howMany) {
  s21_decimal numCpy = *num;
  int flag = 0;
  int i = 0;
  for (; flag == 0 && i < howMany; i++) {
    if ((numCpy.bits[2] & MINUS)) {
      flag = 1;
    } else if (numCpy.bits[2] & (MINUS >> 1)) {
      flag = 1;
    } else if (numCpy.bits[2] & (MINUS >> 2)) {
      flag = 1;
    } else {
      shiftLeft3BitDecimal(&numCpy, 3, 0);
      flag = add_decimal_simple(*num, numCpy, &numCpy);
      flag = add_decimal_simple(*num, numCpy, &numCpy);
    }
    if (flag == 0) *num = numCpy;
  }
  //если переполнение, подскажет, сколько осталось сделать умножений на 10
  //иначе вернёт 0
  return howMany - i + flag;
}
//умножение на 5 не учитывая 3-ий бит. Возвращает 0, если не было переполнения
int mult5DecimalSimple(s21_decimal *num, int howMany) {
  s21_decimal numCpy = *num;
  int flag = 0;
  int i = 0;
  for (; flag == 0 && i < howMany; i++) {
    if ((numCpy.bits[2] & MINUS)) {
      flag = 1;
    } else if (numCpy.bits[2] & (MINUS >> 1)) {
      flag = 1;
    } else {
      shiftLeft3BitDecimal(&numCpy, 2, 0);
      flag = add_decimal_simple(*num, numCpy, &numCpy);
    }
    if (flag == 0) *num = numCpy;
  }
  //если переполнение, подскажет, сколько осталось сделать умножений на 10
  //иначе вернёт 0
  return howMany - i + flag;
}
//деление на 10, не учитывая 3-ий бит. Возвращает остаток последнего деления на
// 10
s21_decimal div10DecimalSimple(s21_decimal *var, int howMany) {
  unsigned long temp = 0;
  for (int i = 0; i < howMany; i++) {
    temp = (*var).bits[2];
    (*var).bits[2] /= 10;

    temp = temp % 10;
    temp <<= 32;
    temp += (*var).bits[1];
    (*var).bits[1] = (unsigned)(temp / 10);

    temp %= 10;
    temp <<= 32;
    temp += (*var).bits[0];
    (*var).bits[0] = (unsigned)(temp / 10);
  }
  s21_decimal fraction = {{temp % 10, 0, 0, 0}};
  return fraction;
}

//общие функции для bigDicimal

//
int get_exp_from_big_decimal(s21_bigDecimal dst) {
  unsigned bit7 = dst.bits[7];
  bit7 >>= 15;
  int answer = 0;
  for (int i = 0; i < 5; i++) {
    bit7 >>= 1;
    if ((bit7 & 1) == 1) answer += myMiniPow(2, i);
  }

  return answer;
}

int set_expInBigDecimal(s21_bigDecimal *dst, int exp) {
  if (dst == NULL) return -1;
  if (exp < 0) return 0;
  int bit7 = (*dst).bits[7];
  bit7 >>= 21;
  bit7 <<= 1;
  int twoInLvl;
  for (int i = 4; i > -1; i--) {
    twoInLvl = myMiniPow(2, i);
    if (exp >= twoInLvl) {
      bit7 |= 1;
      exp -= twoInLvl;
    } else
      bit7 |= 0;

    bit7 <<= 1;
  }
  bit7 <<= 15;
  (*dst).bits[7] = bit7;
  return 0;
}

void from_decimal_to_big_decimal(s21_decimal src, s21_bigDecimal *dst) {
  dst->bits[0] = src.bits[0];
  dst->bits[1] = src.bits[1];
  dst->bits[2] = src.bits[2];
  dst->bits[3] = 0;
  dst->bits[4] = 0;
  dst->bits[5] = 0;
  dst->bits[6] = 0;
  dst->bits[7] = src.bits[3];
}

void from_big_decimal_to_decimal(s21_bigDecimal bigDecimal,
                                 s21_decimal *decimal) {
  decimal->bits[0] = bigDecimal.bits[0];
  decimal->bits[1] = bigDecimal.bits[1];
  decimal->bits[2] = bigDecimal.bits[2];
  decimal->bits[3] = bigDecimal.bits[7];
}

int shiftLeft7BitBigDecimal(s21_bigDecimal *num, unsigned howMany,
                            int whatInsert) {
  int overflow6bit = 0;
  for (unsigned i = 0; i < howMany; i++) {
    if ((num->bits[5] & MINUS) == MINUS) overflow6bit = 1;

    num->bits[6] <<= 1;
    if ((num->bits[5] & MINUS) == MINUS) num->bits[6] |= 1;
    num->bits[5] <<= 1;
    if ((num->bits[4] & MINUS) == MINUS) num->bits[5] |= 1;
    num->bits[4] <<= 1;
    if ((num->bits[3] & MINUS) == MINUS) num->bits[4] |= 1;
    num->bits[3] <<= 1;
    if ((num->bits[2] & MINUS) == MINUS) num->bits[3] |= 1;
    num->bits[2] <<= 1;
    if ((num->bits[1] & MINUS) == MINUS) num->bits[2] |= 1;
    num->bits[1] <<= 1;
    if ((num->bits[0] & MINUS) == MINUS) num->bits[1] |= 1;
    num->bits[0] <<= 1;
    num->bits[0] |= whatInsert;
  }
  return overflow6bit;
}

void shiftRight7BitBigDecimal(s21_bigDecimal *num, unsigned howMany,
                              int whatInsert) {
  for (unsigned i = 0; i < howMany; i++) {
    num->bits[0] >>= 1;
    if ((num->bits[1] & 1) == 1) num->bits[0] |= MINUS;
    num->bits[1] >>= 1;
    if ((num->bits[2] & 1) == 1) num->bits[1] |= MINUS;
    num->bits[2] >>= 1;
    if ((num->bits[3] & 1) == 1) num->bits[2] |= MINUS;
    num->bits[3] >>= 1;
    if ((num->bits[4] & 1) == 1) num->bits[3] |= MINUS;
    num->bits[4] >>= 1;
    if ((num->bits[5] & 1) == 1) num->bits[4] |= MINUS;
    num->bits[5] >>= 1;
    if ((num->bits[6] & 1) == 1) num->bits[5] |= MINUS;
    num->bits[6] >>= 1;
    if ((num->bits[7] & 1) == 1) num->bits[6] |= MINUS;

    if (whatInsert != 0) num->bits[6] |= MINUS;
  }
}

int clearBigDecimal(s21_bigDecimal *dst) {
  if (dst == NULL) return -1;

  for (int i = 0; i <= 7; i++) (*dst).bits[i] = 0;

  return 0;
}

int bit3456isZero(s21_bigDecimal var) {
  int res = 0;
  if (var.bits[3] == 0 && var.bits[4] == 0 && var.bits[5] == 0 &&
      var.bits[6] == 0)
    res = 1;
  return res;
}

int isBigDecimalZero(s21_bigDecimal var) {
  int ret = 1;
  for (int i = 0; i < 7; i++)
    if (var.bits[i] != 0) ret = 0;
  return ret;
}
//простое сравнение
int comparisonBigDecimalSimple(s21_bigDecimal num1, s21_bigDecimal num2) {
  if (isBigDecimalZero(num1)) num1.bits[7] = 0;
  if (isBigDecimalZero(num2)) num1.bits[7] = 0;

  int answer = 0;
  int indexBits;
  for (int i = 215; answer == 0 && i > -1; i--) {
    indexBits = i / 32;
    if ((num1.bits[indexBits] & MINUS) > (num2.bits[indexBits] & MINUS))
      answer = -1;
    else if ((num1.bits[indexBits] & MINUS) < (num2.bits[indexBits] & MINUS))
      answer = 1;
    num1.bits[indexBits] <<= 1;
    num2.bits[indexBits] <<= 1;
  }
  return answer;
}
//простое сложение
int add_big_decimal_simple(s21_bigDecimal value_1, s21_bigDecimal value_2,
                           s21_bigDecimal *result) {
  if (result == NULL) return -1;
  s21_bigDecimal val1Cpy = value_1;
  s21_bigDecimal val2Cpy = value_2;
  s21_bigDecimal val3Cpy;
  clearBigDecimal(&val3Cpy);
  int ten = 0;
  int pool = 0;
  int index;
  for (int i = 0; i < 224; i++) {
    index = i / 32;
    pool = (val1Cpy.bits[index] & 1) + (val2Cpy.bits[index] & 1) + ten;
    if (pool == 1) {
      val3Cpy.bits[index] |= MINUS;
      ten = 0;
    } else if (pool == 2) {
      ten = 1;
    } else if (pool == 3) {
      val3Cpy.bits[index] |= MINUS;
      ten = 1;
    }
    val1Cpy.bits[index] >>= 1;
    val2Cpy.bits[index] >>= 1;
    if ((i + 1) % 32 != 0) val3Cpy.bits[index] >>= 1;
  }
  int ret = 0;
  if (ten == 1)
    ret = 1;
  else
    *result = val3Cpy;
  return ret;
}
//простое вычитание
int subBigDecimalSimple(s21_bigDecimal value_1, s21_bigDecimal value_2,
                        s21_bigDecimal *result) {
  if (result == NULL) return -1;
  int answer = 0;
  int comparison = comparisonBigDecimalSimple(value_1, value_2);
  if (comparison == -1 || comparison == 0) {
    s21_bigDecimal val3Cpy = {{0, 0, 0, 0, 0, 0, 0, 0}};
    int ten = 0;
    int index;
    int temp1;
    int temp2;
    for (int i = 0; i < 216; i++) {
      index = i / 32;
      temp1 = value_1.bits[index] & 1;
      if (temp1 == 1) {
        temp1 -= ten;
        ten = 0;
      } else
        temp1 += ten;

      temp2 = value_2.bits[index] & 1;

      if (temp1 == 1 && temp2 == 0) {
        val3Cpy.bits[index] |= MINUS;
      } else if (temp1 == 0 && temp2 == 1) {
        val3Cpy.bits[index] |= MINUS;
        ten = 1;
      }
      value_1.bits[index] >>= 1;
      value_2.bits[index] >>= 1;
      if ((i + 1) % 32 != 0) val3Cpy.bits[index] >>= 1;
    }
    *result = val3Cpy;
  } else
    answer = 1;
  return answer;
}
//простое деление
s21_decimal div10BigDecimalSimple(s21_bigDecimal *var, int howMany) {
  s21_decimal fractional = {{0, 0, 0, 0}};
  unsigned long temp = 0;
  int j;
  for (int i = 0; i < howMany; i++) {
    temp = (*var).bits[6];
    (*var).bits[6] /= 10;

    for (j = 5; j >= 0; j--) {
      temp %= 10;
      temp <<= 32;
      temp += (*var).bits[j];
      (*var).bits[j] = (unsigned)(temp / 10);
    }
  }
  fractional.bits[0] = (unsigned)(temp % 10);
  set_exp(&fractional, howMany);
  return fractional;
}
//простое умножение
int mult10BigDecimalSimple(s21_bigDecimal *num, int howMany) {
  s21_bigDecimal numCpy = *num;
  int flag = 0;
  int i = 0;
  for (; flag == 0 && i < howMany; i++) {
    if ((numCpy.bits[6] & MINUS)) {
      flag = 1;
    } else if (numCpy.bits[6] & (MINUS >> 1)) {
      flag = 1;
    } else if (numCpy.bits[6] & (MINUS >> 2)) {
      flag = 1;
    } else {
      shiftLeft7BitBigDecimal(&numCpy, 3, 0);
      flag = add_big_decimal_simple(*num, numCpy, &numCpy);
      flag = add_big_decimal_simple(*num, numCpy, &numCpy);
    }
    if (flag == 0) *num = numCpy;
  }
  //если переполнение, подскажет, сколько осталось сделать умножений на 10
  //иначе вернёт 0
  return howMany - i + flag;
}

//!общие функции для bigDicimal

//арифметика

//доводит два биг децимала до одной степени
void scale_big_decimal(s21_bigDecimal *value_1, s21_bigDecimal *value_2) {
  int exp1 = get_exp_from_big_decimal(*value_1);
  int exp2 = get_exp_from_big_decimal(*value_2);
  int diffExp = 0;
  if (exp1 > exp2) {
    diffExp = exp1 - exp2;
    mult10BigDecimalSimple(value_2, diffExp);
    set_expInBigDecimal(value_2, exp2 + diffExp);
  } else if (exp1 < exp2) {
    diffExp = exp2 - exp1;
    mult10BigDecimalSimple(value_1, diffExp);
    set_expInBigDecimal(value_1, exp1 + diffExp);
  }
}
//делит
s21_decimal divBigDecimalUpToDecimalAndGetFractional(s21_bigDecimal *res,
                                                     int *i, int *exp) {
  int j = *i;
  s21_decimal fraction = {{0, 0, 0, 0}};
  if (bit3456isZero(*res) == 0) {
    *i = *i + 1;
    *exp = *exp - 1;
    fraction = div10BigDecimalSimple(res, 1);
    add_decimal_simple(fraction,
                       divBigDecimalUpToDecimalAndGetFractional(res, i, exp),
                       &fraction);
  }
  if (j != 0)
    mult10DecimalSimple(&fraction, 1);
  else
    set_exp(&fraction, *i);
  return fraction;
}

//вернет 1, если было переполнение
int for_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
            s21_decimal *fraction) {
  s21_bigDecimal val1;
  from_decimal_to_big_decimal(value_1, &val1);
  s21_bigDecimal val2;
  from_decimal_to_big_decimal(value_2, &val2);
  s21_bigDecimal res;
  s21_decimal fractionCopy = {{0, 0, 0, 0}};
  scale_big_decimal(&val1, &val2);
  add_big_decimal_simple(val1, val2, &res);
  int exp = get_exp_from_big_decimal(val1);
  int i = 0;

  fractionCopy = divBigDecimalUpToDecimalAndGetFractional(&res, &i, &exp);

  int overflow = 0;
  if (exp < 0)
    overflow = 1;
  else {
    from_big_decimal_to_decimal(res, result);
    set_exp(result, exp);
    *fraction = fractionCopy;
  }
  return overflow;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return -1;

  s21_decimal res = {{0, 0, 0, 0}};
  int minus1 = have_minus_decimal(value_1);
  int minus2 = have_minus_decimal(value_2);

  int overflow;
  if (minus1 == 0 && minus2 == 1) {
    s21_negate(value_2, &value_2);
    overflow = s21_sub(value_1, value_2, &res);
  } else if (minus1 == 1 && minus2 == 0) {
    s21_negate(value_2, &value_2);
    overflow = s21_sub(value_1, value_2, &res);
  } else {
    s21_decimal fraction;
    overflow = for_add(value_1, value_2, &res, &fraction);
    if (overflow == 0) {
      s21_decimal half = {{5, 0, 0, 0}};
      set_exp(&half, 1);
      s21_decimal one = {{1, 0, 0, 0}};

      if ((res.bits[0] & 1) == 0 && s21_is_greater(fraction, half))
        overflow = add_decimal_simple(res, one, &res);
      else if ((res.bits[0] & 1) == 1 &&
               s21_is_greater_or_equal(fraction, half))
        overflow = add_decimal_simple(res, one, &res);

      if ((value_1.bits[3] & MINUS) == MINUS) res.bits[3] |= MINUS;
    }
    if (overflow == 1 && have_minus_decimal(value_1) == 1) {
      overflow = 2;
    }
  }
  if (overflow == 0) *result = res;
  return overflow;
}
//вернёт 1, если первое число меньше второго
int for_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
            s21_decimal *fraction) {
  s21_bigDecimal val1;
  from_decimal_to_big_decimal(value_1, &val1);
  s21_bigDecimal val2;
  from_decimal_to_big_decimal(value_2, &val2);
  s21_bigDecimal res = {{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_decimal fractionCopy = {{0, 0, 0, 0}};
  scale_big_decimal(&val1, &val2);

  int sign = subBigDecimalSimple(val1, val2, &res);

  if (sign == 1) subBigDecimalSimple(val2, val1, &res);

  int exp = get_exp_from_big_decimal(val1);
  int i = 0;

  fractionCopy = divBigDecimalUpToDecimalAndGetFractional(&res, &i, &exp);

  from_big_decimal_to_decimal(res, result);
  set_exp(result, exp);
  set_exp(&fractionCopy, i);
  *fraction = fractionCopy;

  return sign;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return -1;
  s21_decimal res = {{0, 0, 0, 0}};
  int minus1 = have_minus_decimal(value_1);
  int minus2 = have_minus_decimal(value_2);

  int answer;
  if (minus1 == 0 && minus2 == 1) {
    s21_negate(value_2, &value_2);
    answer = s21_add(value_1, value_2, &res);
  } else if (minus1 == 1 && minus2 == 0) {
    s21_negate(value_2, &value_2);
    answer = s21_add(value_1, value_2, &res);
  } else {
    s21_decimal fraction;
    int sign = for_sub(value_1, value_2, &res, &fraction);
    s21_decimal half = {{5, 0, 0, 0}};
    set_exp(&half, 1);
    s21_decimal one = {{1, 0, 0, 0}};

    if ((res.bits[0] & 1) == 0 && s21_is_greater(fraction, half)) {
      add_decimal_simple(res, one, &res);
    } else if ((res.bits[0] & 1) == 1 &&
               s21_is_greater_or_equal(fraction, half)) {
      add_decimal_simple(res, one, &res);
    }

    if (sign == 1)
      res.bits[3] |= ((value_1.bits[3] ^ MINUS) & MINUS);
    else
      res.bits[3] |= (value_1.bits[3] & MINUS);

    answer = 0;
  }
  if (answer == 0) *result = res;
  return answer;
}

//вспомогательные функции для s21_mul
//делит два биг децимала, не учитывая 7 бит, возвращает остаток от деления
s21_bigDecimal divBigDecimalToBigDecimalSimple(s21_bigDecimal value_1,
                                               s21_bigDecimal value_2,
                                               s21_bigDecimal *result) {
  s21_bigDecimal value_1Copy = value_1;
  s21_bigDecimal value_2Copy;
  clearBigDecimal(result);

  s21_bigDecimal temp = {{0, 0, 0, 0}};

  for (; comparisonBigDecimalSimple(value_1Copy, value_2) < 1;) {
    value_2Copy = value_2;
    clearBigDecimal(&temp);
    temp.bits[0] = 1;
    for (; comparisonBigDecimalSimple(value_1Copy, value_2Copy) < 1;) {
      shiftLeft7BitBigDecimal(&temp, 1, 0);
      shiftLeft7BitBigDecimal(&value_2Copy, 1, 0);
    }
    shiftRight7BitBigDecimal(&temp, 1, 0);
    add_big_decimal_simple(*result, temp, result);

    shiftRight7BitBigDecimal(&value_2Copy, 1, 0);

    subBigDecimalSimple(value_1Copy, value_2Copy, &value_1Copy);
  }
  return value_1Copy;
}
//до этого получили целую часть, теперь нахожу дробную
int getFullBigDecimalAfterDiv(s21_bigDecimal fraction, s21_bigDecimal value_2,
                              s21_bigDecimal *resultBig) {
  if (isBigDecimalZero(fraction)) return 0;
  s21_bigDecimal digitInFraction = {{0, 0, 0, 0, 0, 0, 0, 0}};
  int exp = 0;
  int overflow = 0;
  for (; exp < 29 && overflow == 0; exp++) {
    overflow = mult10BigDecimalSimple(resultBig, 1);
    if (overflow == 0) {
      mult10BigDecimalSimple(&fraction, 1);
      fraction =
          divBigDecimalToBigDecimalSimple(fraction, value_2, &digitInFraction);
      add_big_decimal_simple(*resultBig, digitInFraction, resultBig);
    }
  }
  set_expInBigDecimal(resultBig, exp);
  return overflow;
}
//довожу бигдецимал до децимала и возвращаю остаток (для округления)
s21_decimal roundForDiv(s21_bigDecimal *res, int *i, int *exp) {
  int j = *i;
  s21_decimal fraction = {{0, 0, 0, 0}};
  if (bit3456isZero(*res) == 0 || *exp > 28) {
    *i = *i + 1;
    *exp = *exp - 1;
    fraction = div10BigDecimalSimple(res, 1);
    add_decimal_simple(fraction, roundForDiv(res, i, exp), &fraction);
  }
  if (j != 0)
    mult10DecimalSimple(&fraction, 1);
  else {
    set_exp(&fraction, *i);
  }
  return fraction;
}
//округление децимала
int lastRoundDiv(s21_decimal *resultCopy, s21_decimal fraction) {
  int err = 0;
  s21_decimal half = {{5, 0, 0, 0}};
  set_exp(&half, 1);
  s21_decimal one = {{1, 0, 0, 0}};
  if (s21_is_equal(half, fraction)) {
    if (((*resultCopy).bits[0] & 1) == 1)
      err = add_decimal_simple(*resultCopy, one, resultCopy);
  } else if (s21_is_greater(fraction, half)) {
    err = add_decimal_simple(*resultCopy, one, resultCopy);
  }
  return err;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (isDecimalZero(value_2)) return 3;
  s21_bigDecimal value_1Big;
  from_decimal_to_big_decimal(value_1, &value_1Big);
  s21_bigDecimal value_2Big;
  from_decimal_to_big_decimal(value_2, &value_2Big);
  s21_bigDecimal resultBig;
  clearBigDecimal(&resultBig);

  scale_big_decimal(&value_1Big, &value_2Big);

  s21_bigDecimal fraction =
      divBigDecimalToBigDecimalSimple(value_1Big, value_2Big, &resultBig);

  int err = getFullBigDecimalAfterDiv(fraction, value_2Big, &resultBig);

  int exp = get_exp_from_big_decimal(resultBig);
  int i = 0;
  s21_decimal miniFraction = roundForDiv(&resultBig, &i, &exp);
  s21_decimal resultCopy = {{0, 0, 0, 0}};
  if (exp < 0 || err != 0) {
    err++;
  } else {
    from_big_decimal_to_decimal(resultBig, &resultCopy);
    err += lastRoundDiv(&resultCopy, miniFraction);
  }

  if ((value_1.bits[3] & MINUS) != (value_2.bits[3] & MINUS))
    resultCopy.bits[3] |= MINUS;

  if (err != 0)
    if ((resultCopy.bits[3] & MINUS) == MINUS)
      err = 2;
    else
      err = 1;
  else {
    set_exp(&resultCopy, exp);
    *result = resultCopy;
  }
  return err;
  return err;
}

void multDecimalToDecimalInBigDecimalSimple(s21_decimal value_1,
                                            s21_decimal value_2,
                                            s21_bigDecimal *result) {
  int overflow = 0;
  s21_bigDecimal val1Cpy;
  from_decimal_to_big_decimal(value_1, &val1Cpy);
  s21_bigDecimal val2Cpy;
  from_decimal_to_big_decimal(value_2, &val2Cpy);
  s21_bigDecimal resCpy = {{0, 0, 0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < 96 && overflow == 0; i++) {
    if ((val2Cpy.bits[0] & 1) == 1)
      add_big_decimal_simple(val1Cpy, resCpy, &resCpy);

    shiftRight7BitBigDecimal(&val2Cpy, 1, 0);
    shiftLeft7BitBigDecimal(&val1Cpy, 1, 0);
  }
  *result = resCpy;
}

int forMult(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
            s21_decimal *fraction) {
  s21_bigDecimal resultBigDecimal = {{0, 0, 0, 0, 0, 0, 0, 0}};
  multDecimalToDecimalInBigDecimalSimple(value_1, value_2, &resultBigDecimal);

  int exp = getExp(value_1) + getExp(value_2);
  int i = 0;
  s21_decimal fractionCopy =
      divBigDecimalUpToDecimalAndGetFractional(&resultBigDecimal, &i, &exp);
  int overflow = 0;

  if (exp >= 0) {
    set_expInBigDecimal(&resultBigDecimal, exp);
    from_big_decimal_to_decimal(resultBigDecimal, result);
    *fraction = fractionCopy;
  } else {
    overflow = 1;
  }

  return overflow;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (isDecimalZero(value_1) || isDecimalZero(value_2)) {
    clearDecimal(result, 1);
    return 0;
  }

  s21_decimal fraction = {{0, 0, 0, 0}};
  s21_decimal resultCopy = {{0, 0, 0, 0}};
  int overflow = forMult(value_1, value_2, &resultCopy, &fraction);
  if (isDecimalZero(resultCopy)) overflow = 1;

  int minus = 0;
  if ((value_1.bits[3] & MINUS) == MINUS && (value_2.bits[3] & MINUS) == 0)
    minus = 1;
  else if ((value_1.bits[3] & MINUS) == 0 && (value_2.bits[3] & MINUS) == MINUS)
    minus = 1;

  if (overflow == 0) {
    s21_decimal half = {{5, 0, 0, 0}};
    set_exp(&half, 1);
    s21_decimal one = {{1, 0, 0, 0}};

    if ((resultCopy.bits[0] & 1) == 0 && s21_is_greater(fraction, half))
      overflow = add_decimal_simple(resultCopy, one, &resultCopy);
    else if ((resultCopy.bits[0] & 1) == 1 &&
             s21_is_greater_or_equal(fraction, half))
      overflow = add_decimal_simple(resultCopy, one, &resultCopy);

    if (overflow == 0) {
      if (minus == 1) resultCopy.bits[3] |= MINUS;
      *result = resultCopy;
    }
  }
  if (overflow == 1) overflow += minus;

  return overflow;
}
//!арифметика