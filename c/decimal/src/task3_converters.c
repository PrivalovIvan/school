#include "s21_decimal.h"

//парсеры
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) return 1;
  clearDecimal(dst, 1);
  if (src < 0) {
    (*dst).bits[3] = (*dst).bits[3] | MINUS;
    // src = src * (-1);
    src = ~src + 1;
  }
  (*dst).bits[0] = src;
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) return 1;
  int answer = 0;
  s21_decimal var1 = src;
  s21_truncate(var1, &var1);
  s21_decimal var2 = {{0, 0, 0, 0}};
  if (have_minus_decimal(var1) == 0) {
    //максимальное положительное число в int
    var2.bits[0] = 2147483647;
    if (s21_is_greater(var1, var2))
      answer = 1;
    else
      *dst = (int)var1.bits[0];
  } else {
    //максимальное отрицательное число в int
    var2.bits[0] = 2147483648;
    var2.bits[3] = MINUS;
    if (s21_is_less(var1, var2))
      answer = 1;
    else {
      *dst = (int)(~var1.bits[0]);
      *dst += 1;
    }
  }
  return answer;
}

//перевожу децимал в строку, а из строки через стандартную функцию atof во float
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL) return 1;
  char srcChar[32];
  fromDecimalToChar(src, srcChar, 31);
  // s21_decimal temp = roundAndCutStrForFromDecimalToFloat(srcChar, 7);
  // fromDecimalToChar(temp, srcChar, 31);
  *dst = atof(srcChar);
  return 0;
}

int getCountNumberWithNeedZeroFromDecimal(s21_decimal var) {
  char stringDecimal[32];
  fromDecimalToChar(var, stringDecimal, 31);
  int count = 0;
  int i = 0;
  if (stringDecimal[0] == '0') {
    int flag = 0;
    for (i = 1; i < 31 && flag == 0; i++)
      if (stringDecimal[i] >= '1' && stringDecimal[i] <= '9') flag = 1;
    i--;
  }
  for (; i < 31 && stringDecimal[i] != '\0'; i++) {
    if (stringDecimal[i] >= '0' && stringDecimal[i] <= '9') count++;
  }

  return count;
}

void roundForFloat(s21_decimal *var, int count) {
  s21_decimal fraction = div10DecimalSimple(var, count);

  if (fraction.bits[0] > 4) {
    s21_decimal one = {{1, 0, 0, 0}};
    add_decimal_simple(*var, one, var);
  }
}

int reduceLeadZero(unsigned *var) {
  if (var == 0) return -1;
  int count = 0;
  for (; (*var & 1) == 0; count++) *var >>= 1;
  return count;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err = 0;
  union parseFloat f = {f.f = src};
  s21_decimal dstCpy = {{8388608, 0, 0, 0}};
  dstCpy.bits[0] += f.parts.m;
  int p = f.parts.e - 127;
  p -= 23;
  p += reduceLeadZero(&dstCpy.bits[0]);
  int exp;
  if (p <= 0) {
    int temp = (-p > 28) ? 28 : -p;
    mult5DecimalSimple(&dstCpy, temp);
    exp = temp;
    p += temp;
    // shiftRight3BitDecimal(&dstCpy, -p, 0);
    //весь нижний if это костыль, чтобы округлять значения, которые слишком
    //маленькие
    if (p != 0) {
      mult10DecimalSimple(&dstCpy, 1);
      shiftRight3BitDecimal(&dstCpy, -p, 0);
      if (getCountNumberWithNeedZeroFromDecimal(dstCpy) <= 8) {
        roundForFloat(&dstCpy, 1);
      } else
        div10DecimalSimple(&dstCpy, 1);
    }
  } else {
    shiftLeft3BitDecimal(&dstCpy, p, 0);
    exp = 0;
  }
  //округление
  set_exp(&dstCpy, exp);
  int countNumbers = getCountNumberWithNeedZeroFromDecimal(dstCpy);

  if (countNumbers <= 7)
    countNumbers = 0;
  else
    countNumbers -= 7;

  roundForFloat(&dstCpy, countNumbers);
  mult10DecimalSimple(&dstCpy, countNumbers);

  if (f.parts.s == 1) dstCpy.bits[3] |= MINUS;
  *dst = dstCpy;
  return err;
}