#include "s21_decimal.h"

void shiftLeftString(char* arr, int howMany, char whatInsert) {
  int len = strlen(arr);
  for (; howMany > 0; howMany--) {
    for (int i = 0; i < len - 1; i++) arr[i] = arr[i + 1];
    arr[len - 1] = whatInsert;
  }
}

// 00010 => 10
void killFirstZeros(char* arr) {
  if (arr[0] == '-') arr++;

  int flag = 0;

  if (arr[0] == '0' && arr[1] == '\0') flag = 1;

  for (; flag == 0;) {
    if (arr[0] == '0' && arr[1] != '.')
      shiftLeftString(arr, 1, '\0');
    else
      flag = 1;
  }
}

void sum2NumArrFast(char* num1, char* num2, char* answer, int len) {
  int ten = 0;
  char temp;
  for (int i = len - 1; i > -1; i--) {
    temp = num1[i] + num2[i] - '0' + ten;
    if (temp > '9') {
      ten = 1;
      answer[i] = temp - 10;
    } else {
      ten = 0;
      answer[i] = temp;
    }
  }
}

void sum2NumArr(char* num1, char* num2, char* answer) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  int len3 = strlen(answer);
  int ten = 0;
  char temp;
  int i = len1 - 1, j = len2 - 1, k = len3 - 1;
  for (; k > -1; i--, j--, k--) {
    if (j > -1 && i > -1)
      temp = num1[i] + num2[j] - '0' + ten;
    else if (j > -1)
      temp = num2[j] + ten;
    else if (i > -1)
      temp = num1[i] + ten;
    else
      temp = '0' + ten;

    if (temp > '9') {
      ten = 1;
      answer[k] = temp - 10;
    } else {
      ten = 0;
      answer[k] = temp;
    }
  }
}

int get2inLevel(char* dst, int exp, int len) {
  memset(dst, '0', len);
  dst[len - 1] = '1';

  for (int i = 0; i < exp; i++) sum2NumArrFast(dst, dst, dst, len);
  return 0;
}
//вставить точку в строку, сдвинув левую часть
void putDot(char* arr, int number) {
  int len = strlen(arr);
  int i = len - number - 1;
  int temp1 = arr[i];
  arr[i] = '\0';
  shiftLeftString(arr, 1, temp1);
  arr[i] = '.';
}

//из decimal в char главная функция
int fromDecimalToChar(const s21_decimal src, char* dst, int lenDst) {
  if (dst == NULL) return -1;
  char dstCopy[32];
  memset(dstCopy, '0', 31);
  dstCopy[31] = '\0';
  char twoInXLevel[30];
  twoInXLevel[29] = '\0';
  for (int i = 0; i < 96; i++) {
    if (((src.bits[i / 32] >> i) & 1) == 1) {
      get2inLevel(twoInXLevel, i, 29);
      sum2NumArr(dstCopy, twoInXLevel, dstCopy);
    }
  }

  int exp = getExp(src);
  if (exp != 0) putDot(dstCopy, exp);

  if ((src.bits[3] & MINUS) == MINUS) dstCopy[0] = '-';

  killFirstZeros(dstCopy);

  int ret = 0;
  int lenDstCopy = strlen(dstCopy);
  if (lenDst < lenDstCopy)
    ret = -2;
  else
    memcpy(dst, dstCopy, lenDstCopy + 1);

  return ret;
}
