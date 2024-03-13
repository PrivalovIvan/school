#include "s21_decimal.h"

//если нужно обнулить все байты, то пишем 1, иначе 0
int clearDecimal(s21_decimal *dst, int allClear) {
  if (dst == NULL) return -1;

  (*dst).bits[0] = 0;
  (*dst).bits[1] = 0;
  (*dst).bits[2] = 0;
  if (allClear == 1) (*dst).bits[3] = 0;

  return 0;
}

int myMiniPow(int num, int exp) {
  int ret = 1;
  for (int i = 0; i < exp; i++) ret *= num;
  return ret;
}
//получение порядка у decimal
int getExp(const s21_decimal var) {
  int bit3 = var.bits[3];
  bit3 >>= 15;
  int ret = 0;
  for (int i = 0; i < 5; i++) {
    bit3 >>= 1;
    ret += (bit3 & 1) * myMiniPow(2, i);
  }
  return ret;
}
//установка порядка у decimal
int set_exp(s21_decimal *dst, int exp) {
  if (dst == NULL) return 1;
  if (exp < 0) return 0;
  int bit3 = (*dst).bits[3];
  bit3 >>= 21;
  bit3 <<= 1;
  int twoInLvl;
  for (int i = 4; i > -1; i--) {
    twoInLvl = myMiniPow(2, i);
    if (exp >= twoInLvl) {
      bit3 |= 1;
      exp -= twoInLvl;
    } else
      bit3 |= 0;

    bit3 <<= 1;
  }
  bit3 <<= 15;
  (*dst).bits[3] = bit3;
  return 0;
}
//проверяет, есть ли минус в децимал
int have_minus_decimal(s21_decimal num) {
  int haveMinus = 0;
  if ((num.bits[3] & MINUS) == MINUS) haveMinus = 1;
  return haveMinus;
}
//проверяет децимал на нулевой
int isDecimalZero(s21_decimal var) {
  int ret = 0;
  if (var.bits[0] == 0 && var.bits[1] == 0 && var.bits[2] == 0) ret = 1;
  return ret;
}
//двигеает 0, 1, 2 биты влево. В аргументах (2) на сколько двигать и (3) что
//вставлять справа (0 или 1)
int shiftLeft3BitDecimal(s21_decimal *num, unsigned howMany, int whatInsert) {
  int ret = 0;
  for (unsigned i = 0; i < howMany && ret == 0; i++) {
    if ((num->bits[2] & MINUS) == MINUS) ret = 1;

    num->bits[2] <<= 1;
    if ((num->bits[1] & MINUS) == MINUS) num->bits[2] |= 1;
    num->bits[1] <<= 1;
    if ((num->bits[0] & MINUS) == MINUS) num->bits[1] |= 1;
    num->bits[0] <<= 1;
    num->bits[0] |= whatInsert;
  }
  return ret;
}
//двигеает 0, 1, 2 биты вправо. В аргументах (2) на сколько двигать и (3) что
//вставлять слева (0 или 1)
void shiftRight3BitDecimal(s21_decimal *num, unsigned howMany, int whatInsert) {
  for (unsigned i = 0; i < howMany; i++) {
    num->bits[0] >>= 1;
    if ((num->bits[1] & 1) == 1) num->bits[0] |= MINUS;
    num->bits[1] >>= 1;
    if ((num->bits[2] & 1) == 1) num->bits[1] |= MINUS;
    num->bits[2] >>= 1;
    if (whatInsert == 1) num->bits[2] |= MINUS;
  }
}
