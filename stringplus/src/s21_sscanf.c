#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  setlocale(LC_CTYPE, "");
  flags set = {0};
  func menu = {0};
  va_list args;
  va_start(args, format);
  char ch[200], buf[200];
  char *pbuf = buf;
  s21_strcpy(pbuf, str);
  int start = s21_strlen(buf), *count_n, count = 0;

  setting_the_menu(&menu);

  for (char *c = (char *)format; *c and *pbuf; c++) {
    while (*pbuf == *c) pbuf++, c++;
    while (*c == '%' or SPACE(*c) or NUM(*c) or s21_strchr("lhL", *c)) c++;
    if (*c == ' ')
      while (s21_isspace(*pbuf)) pbuf++;
    else if (*c == 'n')
      s21_analysis_format(&set, (char *)format);
    else
      pbuf = s21_analysis_string(pbuf, ch, LENGTH, &set);

    if (*c == '*')
      while (*c != '%') c++;
    else if (*c == 'n') {
      count_n = va_arg(args, int *);
      *count_n = start - s21_strlen(pbuf);
    } else if (menu.func[(int)*c]) {
      menu.func[(int)*c](&set, args, &count, ch);
    }
  }
  va_end(args);
  return count;
}
