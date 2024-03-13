#include "s21_string.h"

int s21_atoi(char *str) {
  int result = 0, minus = 0, len = 0;
  char buf[100], *pbuf = buf;
  if (str[0] == '-') str++, minus = 1;
  if (str[0] == '0') str++;
  s21_strcpy(pbuf, str);
  while (NUM(*pbuf)) len++, pbuf++;
  while (NUM(*str) and len) {
    int a = *str - '0';
    result += pow(10, --len) * a;
    str++;
  }
  if (minus) result *= -1;
  return result;
}
long int s21_atol(char *str) {
  long int result = 0;
  int minus = 0, len = 0;
  char buf[100], *pbuf = buf;
  if (str[0] == '-') str++, minus = 1;
  if (str[0] == '0') str++;
  s21_strcpy(pbuf, str);
  while (NUM(*pbuf)) len++, pbuf++;
  while (NUM(*str) and len) {
    int a = *str - '0';
    result += pow(10, --len) * a;
    str++;
  }
  if (minus) result *= -1;
  return result;
}
double s21_atof(char *str) {
  double result = 0, num2 = 0;
  int num1 = 0, len = 0, minus = 0;
  char buf[100], *pbuf = buf;
  if (str[0] == '-') str++, minus = 1;
  s21_strcpy(pbuf, str);
  num1 = s21_atoi(pbuf);
  while (*pbuf != '.') pbuf++, str++;
  str++, pbuf++;
  while (NUM(*str)) len++, str++;
  num2 = s21_atoi(pbuf) / pow(10, len);
  result = num1 + num2;
  if (minus) result *= -1;

  return result;
}

void setting_the_menu(func *menu) {
  menu->func['s'] = s21_print_s;
  menu->func['c'] = s21_print_c;
  menu->func['f'] = s21_print_f;
  menu->func['G'] = s21_print_f;
  menu->func['g'] = s21_print_f;
  menu->func['E'] = s21_print_f;
  menu->func['e'] = s21_print_f;
  menu->func['d'] = s21_print_d;
  menu->func['x'] = s21_print_x;
  menu->func['o'] = s21_print_x;
  menu->func['X'] = s21_print_x;
  menu->func['i'] = s21_print_i;
  menu->func['u'] = s21_print_u;
  menu->func['p'] = s21_print_p;
}

int s21_analysis_format(flags *set, char *format) {
  char num_length[50] = {0};
  int i = 0;
  set->h = 0, set->l = 0, set->L = 0, set->x = 0, set->o = 0, set->c = 0;
  static char *buf = 0;
  if (buf == 0) buf = format;
  if (*buf == '%') {
    buf++;
    while (*buf) {
      if (*buf == 'l')
        set->l = 1;
      else if (*buf == 'c')
        set->c = 1;
      else if (*buf == 'o')
        set->o = 1;
      else if (*buf == 'h')
        set->h = 1;
      else if (*buf == 'L')
        set->L = 1;
      else if (*buf == 'x' or *buf == 'X')
        set->x = 1;
      if (NUM(*buf)) num_length[i++] = *buf++;
      if (*buf != '%')
        buf++;
      else
        break;
    }
  } else
    while (*buf != ' ' and SPACE(*buf)) buf++;
  num_length[i++] = '\0';
  set->length = s21_atoi(num_length);
  return set->length;
}
char *s21_analysis_string(char *str, char *ch, int length, flags *set) {
  if (set->c) {
    *ch++ = *str++;
    if (length > 0)
      while (*str and *str != ' ' and (length)-- > 1) str++;
  } else if (length > 0) {
    while (*str and *str != ' ' and length-- > 0) *ch++ = *str++;
  } else {
    while (*str and *str != ' ') *ch++ = *str++;
    while (*str == ' ') str++;
  }
  *ch = '\0';
  return str;
}
long int s21_octal_and_hex_number_system(char *s, flags *set) {
  long int hexLength = 0, system = 0, minus = 0, stop = 0, result = 0;
  if (s[0] == '-') {
    minus = 1;
    s++;
  }
  if (set->o)
    system = 8;
  else if (set->x) {
    system = 16;
    if (s[0] == '0' and (s[1] == 'x' or s[1] == 'X')) stop = 2;
  } else if (s[1] == 'x' or s[1] == 'X') {
    system = 16, stop = 2;
  } else if (s[0] == '0') {
    system = 8, stop = 1;
  }
  while (s[hexLength] != '\0') {
    hexLength++;
  }
  if (system) {
    int power = 0;
    for (int i = hexLength - 1; i >= stop; i--) {
      int digitValue;
      if (s[i] >= '0' and s[i] <= '7' and system == 8) {
        digitValue = s[i] - '0';
      } else if (NUM(s[i]) and system == 16) {
        digitValue = s[i] - '0';
      } else if (HEX_X(s[i]) and system == 16) {
        digitValue = s[i] - 'A' + 10;
      } else if (HEX_x(s[i]) and system == 16) {
        digitValue = s[i] - 'a' + 10;
      } else {
        result = 0, power = 0;
        continue;
      }
      result += digitValue * pow(system, power);
      power++;
    }
  }
  set->x = 0, set->o = 0;
  return minus == 1 ? result = result * -1 : result;
}
s21_size_t s21_mbstowcs(wchar_t *dest, const char *src, s21_size_t n) {
  s21_size_t len = 0;
  len = s21_strlen(src);
  if (n == 0) {
    return len;
  }
  s21_size_t bytes = mbsrtowcs(dest, &src, n, s21_NULL);

  if (bytes == (s21_size_t)-1) {
    return (s21_size_t)-1;
  } else if (bytes == (s21_size_t)-2) {
    dest[n - 1] = L'\0';
  }

  return len;
}
int s21_parse_pointer(const char *str, void **ptr) {
  char *endptr = 0;
  unsigned long int val = 0;
  val = strtoul(str, &endptr, 16);
  if (str == endptr) {
    return -1;
  }
  *ptr = (void *)val;
  return 0;
}
void s21_print_f(flags *set, va_list args, int *count, char *ch) {
  set->num_db = va_arg(args, float *);
  if (set->L == 1)
    *(long double *)set->num_db = s21_atof(ch);
  else
    *set->num_db = s21_atof(ch);
  *count = *count + 1;
}
void s21_print_s(flags *set, va_list args, int *count, char *ch) {
  if (set->l) {
    set->chL = va_arg(args, wchar_t *);
    s21_mbstowcs(set->chL, ch, sizeof(ch));
  } else {
    set->ch = va_arg(args, char *);
    s21_strcpy(set->ch, ch);
  }
  *count = *count + 1;
}
void s21_print_c(flags *set, va_list args, int *count, char *ch) {
  if (set->l) {
    set->chL = va_arg(args, wchar_t *);
    s21_mbstowcs(set->chL, ch, sizeof(ch));
  } else {
    set->simbol = va_arg(args, char *);
    *set->simbol = *ch;
  }
  *count = *count + 1;
}
void s21_print_d(flags *set, va_list args, int *count, char *ch) {
  set->num_d = va_arg(args, int *);
  if (s21_atoi(ch) == 0)
    *set->num_db = *set->num_d;
  else if (set->h)
    *(short *)set->num_d = s21_atoi(ch);
  else if (set->l)
    *(long int *)set->num_d = s21_atol(ch);
  else
    *set->num_d = s21_atoi(ch);
  *count = *count + 1;
}
void s21_print_x(flags *set, va_list args, int *count, char *ch) {
  set->num_i = va_arg(args, int *);
  if (set->h)
    *(unsigned short *)set->num_i = s21_octal_and_hex_number_system(ch, set);
  else if (set->l)
    *(unsigned long int *)set->num_i = s21_octal_and_hex_number_system(ch, set);
  else
    *(unsigned int *)set->num_i = s21_octal_and_hex_number_system(ch, set);
  *count = *count + 1;
}
void s21_print_i(flags *set, va_list args, int *count, char *ch) {
  set->num_i = va_arg(args, int *);
  if (set->h)
    *(short *)set->num_i = s21_octal_and_hex_number_system(ch, set);
  else if (set->l)
    *(long int *)set->num_i = s21_octal_and_hex_number_system(ch, set);
  else
    *set->num_i = s21_octal_and_hex_number_system(ch, set);
  *count = *count + 1;
}
void s21_print_u(flags *set, va_list args, int *count, char *ch) {
  set->u_num = va_arg(args, unsigned int *);
  if (set->h)
    *(unsigned short *)set->u_num = s21_atoi(ch);
  else if (set->l)
    *(unsigned long int *)set->u_num = s21_atoi(ch);
  else
    *(unsigned int *)set->u_num = s21_atoi(ch);
  *count = *count + 1;
}

void s21_print_p(flags *set, va_list args, int *count, char *ch) {
  set->p = va_arg(args, void *);
  s21_parse_pointer(ch, set->p);
  *count = *count + 1;
}
