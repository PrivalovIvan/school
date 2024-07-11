#include "s21_string.h"

#define SPECS "cdipneEgGfFsuoxX%"
#define FLAGS " -+#0"
#define PREC_ARGS "Llh"
#define isd(d) ((d) >= '0' && (d) <= '9')
#define chtod(ch) ((ch) - '0')
#define dtoch(d) ((char)((d) + '0'))
#define up_hextoch(d) ((char)((d) + 55))
#define down_hextoch(d) ((char)((d) + 87))
#define max(a, b) ((a) > (b) ? (a) : (b))

// INFO (minimal realizasion):
//	- Specs: c, d, f, s, u, %
//	- Flags: -, +, (пробел)
//	- Width: (число)
//	- Precision: .(число)
//	- Length: h, l

typedef unsigned int u_int;
typedef unsigned long int ul_int;
typedef unsigned short uh_int;
typedef long int l_int;
typedef short h_int;
typedef long double l_dbl;

typedef struct {
  bool plus;
  bool minus;
  bool space;
  bool hash;
  bool zero;
  bool dot;
  bool upper_case;
  bool g;

  int e;
  int exp;
  int sign;
  int err;

  u_int width;
  u_int prec;

  char length;
  char base;
} format_flags;

void *xmalloc(s21_size_t size, int *err) {
  void *temp;
  temp = malloc(size);
  if (!temp) *err = -1;
  return temp;
}

void set_base(const char *format, format_flags *f) {
  if (*format == 'o') {
    f->base = 8;
  } else if (*format == 'x' || *format == 'X') {
    f->base = 16;
    if (*format == 'X') f->upper_case = true;
  }
}

const char *get_flags(const char *format, format_flags *f) {
  char *ptr = s21_NULL;
  while ((ptr = s21_strchr(FLAGS, *format)) != NULL) {
    if (*ptr == '+')
      f->plus = true;
    else if (*ptr == '-')
      f->minus = true;
    else if (*ptr == '#')
      f->hash = true;
    else if (*ptr == ' ')
      f->space = true;
    else if (*ptr == '0')
      f->zero = true;

    format++;
  }

  if (f->plus) f->space = false;

  if (f->minus) f->zero = false;

  return format;
}

const char *get_value(const char *format, u_int *width, va_list *args) {
  *width = 0;
  if (*format == '*') {
    *width = va_arg(*args, u_int);
    format++;
  }
  while (isd(*format)) {
    *width *= 10;
    *width += chtod(*format);
    format++;
  }

  return format;
}

const char *get_length(const char *format, char *length) {
  char *ptr = s21_NULL;
  if ((ptr = s21_strchr(PREC_ARGS, *format)) != s21_NULL) {
    *length = *ptr;
    format++;
  }
  return format;
}

const char *set_format(const char *format, format_flags *f, va_list *args) {
  format = get_flags(format, f);
  format = get_value(format, &f->width, args);
  if (*format == '.') {
    f->dot = true;
    format++;
    format = get_value(format, &f->prec, args);
  }
  format = get_length(format, &f->length);

  return format;
}

s21_size_t get_size_dec(format_flags *f, l_int num) {
  s21_size_t size = 0;
  l_int num_copy = num;

  while (num_copy != 0) {
    num_copy /= 10;
    size++;
  }

  if (num == 0 && (f->prec || f->width || f->space)) {
    size++;
  }

  // max size that could be format without flags
  s21_size_t temp = (s21_size_t)max(f->prec, f->width);

  if (f->space || f->plus || num < 0) {
    f->sign = 1;
    if (temp > size) {
      size = temp;

      if (f->width <= f->prec)
        size++;
      else if (f->width == 1)
        size++;

    } else
      size++;
  } else {
    if (temp > size) size = temp;
  }

  if (num == 0 && !f->prec && !f->width && !f->space && !f->dot) size++;

  return size;
}

int get_str_dec(format_flags *f, l_int num, char *str_dec, s21_size_t size) {
  bool num_neg = num < 0 ? true : false;

  l_int num_copy = num;

  int i = 0;

  if ((num_copy == 0 && (f->prec || f->width || f->space)) ||
      (num_copy == 0 && !f->prec && !f->width && !f->space && !f->dot)) {
    if ((!f->width || !f->dot || f->prec) &&
        (!f->space || f->width || !f->dot || f->prec)) {
      str_dec[i] = dtoch(num_copy);
      i++;
    }
    size--;
  }

  while (num_copy && size) {
    int temp = num_copy % f->base;
    str_dec[i] = dtoch(temp < 0 ? -temp : temp);
    num_copy /= f->base;
    i++;
    size--;
  }

  if ((int)f->prec - i > 0 && f->prec) {
    f->prec -= i;
    f->zero = true;
  }

  if (size == 1 && f->zero && f->sign) {
    f->zero = false;
  }

  while (f->zero && str_dec && (size - f->sign > 0)) {
    if ((size == 1 && f->sign) || !(f->minus ? f->prec : 1)) break;
    str_dec[i] = '0';
    i++;
    size--;
    f->prec--;
  }

  // sign
  if (f->space && !num_neg && size) {
    str_dec[i] = ' ';
    i++;
    size--;
  }

  if (num_neg && size) {
    str_dec[i] = '-';
    i++;
    size--;
  }

  if (f->plus && !num_neg && size) {
    str_dec[i] = '+';
    i++;
    size--;
  }

  // free amount of space in str
  if (size > 0 && !f->minus) {
    while ((size) > 0) {
      str_dec[i] = ' ';
      i++;
      size--;
    }
  }

  return i;
}

char *print_dec(char *str, format_flags *f, va_list *args) {
  l_int num = 0;

  // error: '0' flag ignored with precision and ‘%d’ gnu_printf format
  if (f->dot && f->zero) {
    f->zero = false;
  }

  if (f->length == 'l')
    num = (l_int)va_arg(*args, l_int);
  else if (f->length == 'h')
    num = (short)va_arg(*args, int);
  else
    num = (int)va_arg(*args, int);

  s21_size_t size = get_size_dec(f, num);

  char *str_dec = xmalloc(size, &f->err);

  if (str_dec && size) {
    int ofset = get_str_dec(f, num, str_dec, size);
    for (char *temp = str_dec + ofset - 1; temp - str_dec >= 0; temp--) {
      *str = *temp;
      str++;
    }
    while (ofset < (int)f->width) {
      *str = ' ';
      str++;
      ofset++;
    }
  }

  if (str_dec) free(str_dec);

  return str;
}

s21_size_t get_size_unsign(format_flags *f, ul_int num) {
  s21_size_t size = 0;
  ul_int num_copy = num;

  // INFO:

  // When used with the o, x, or X formats, the # flag prefixes any nonzero
  // output value with 0, 0x, or 0X, respectively. For o conversion, it
  // increases the precision, if necessary, to force the first digit of the
  // result to be a zero. If the value and precision are both 0, a single 0 is
  // printed.

  // Default precision is 1. If precision is 0, or if the period (.) appears
  // without a number following it, the precision is set to 0. When precision is
  // 0, conversion of the value zero results in no characters.

  if (!num_copy && ((f->hash && f->base == 8 && f->prec == 0) ||
                    (f->prec == 0 && f->width == 0 && !f->dot))) {
    size = 1;
  }

  while (num_copy != 0) {
    num_copy /= f->base;
    size++;
  }

  // max size that could be format without flags
  s21_size_t temp = (s21_size_t)max(f->prec, f->width);

  if (num && f->hash && f->base == 8) size += 1;

  if (num && f->hash && f->base == 16) {
    if (f->width > f->prec) {
      if (size + 2 > f->width)
        size = size + 2;
      else
        size = f->width;
    } else {
      if (size > f->prec)
        size = size + 2;
      else
        size = f->prec + 2;
    }
  } else {
    if (temp && temp >= size) size = temp;
  }

  return size;
}

int get_str_unsign(format_flags *f, ul_int num, char *str_unsign,
                   s21_size_t size) {
  ul_int num_copy = num;

  int i = 0;
  // zero value

  int zero_flag = 0;

  if (!f->dot && f->prec == 0) {
    f->prec = 1;
    zero_flag = 1;
  }

  if (num == 0 && ((!f->width && !f->dot && !f->prec) ||
                   (f->hash && f->base == 8 && f->prec == 0) || f->prec)) {
    str_unsign[i] = dtoch(num);
    i++;
    size--;
  }

  // non zero value
  while (num_copy && size) {
    int temp = num_copy % f->base;
    if (temp < 10)
      str_unsign[i] = dtoch(temp);
    else {
      if (f->upper_case)
        str_unsign[i] = up_hextoch(temp);
      else
        str_unsign[i] = down_hextoch(temp);
    }
    num_copy /= f->base;
    i++;
    size--;
  }

  if ((int)f->prec - i > 0 && f->prec) {
    f->prec -= i;
    f->zero = true;
  }

  while (f->zero && size && (zero_flag ? 1 : f->prec)) {
    if ((num && ((f->base == 8 && f->hash && size == 1) ||
                 (f->base == 16 && f->hash && size == 2))) ||
        !(f->minus ? f->prec : 1))
      break;
    str_unsign[i] = '0';
    i++;
    size--;
    f->prec--;
  }

  if (num && f->base == 8 && f->hash) {
    str_unsign[i] = '0';
    i++;
    size--;
  }

  if (num && f->base == 16 && f->hash) {
    if (f->upper_case)
      str_unsign[i] = 'X';
    else
      str_unsign[i] = 'x';
    i++;
    size--;
    str_unsign[i] = '0';
    i++;
    size--;
  }

  // free amount of space in str
  if (size > 0 && !f->minus) {
    while ((size) > 0) {
      str_unsign[i] = ' ';
      i++;
      size--;
    }
  }

  return i;
}

char *print_unsign(char *str, format_flags *f, va_list *args) {
  ul_int num = 0;

  // error: '0' flag ignored with precision and ‘%d’ gnu_printf format
  if (f->dot && f->zero) {
    f->zero = false;
  }

  if (f->length == 'l')
    num = (ul_int)va_arg(*args, ul_int);
  else if (f->length == 'h')
    num = (uh_int)va_arg(*args, u_int);
  else
    num = (u_int)va_arg(*args, u_int);

  s21_size_t size = get_size_unsign(f, num);

  char *str_unsign = xmalloc(size, &f->err);

  if (str_unsign && size) {
    int ofset = get_str_unsign(f, num, str_unsign, size);
    for (char *temp = str_unsign + ofset - 1; temp - str_unsign >= 0; temp--) {
      *str = *temp;
      str++;
    }
    while (ofset < (int)f->width) {
      *str = ' ';
      str++;
      ofset++;
    }
  }

  if (str_unsign) free(str_unsign);

  return str;
}

char *print_char(char *str, format_flags *f, va_list *args) {
  int ch = va_arg(*args, int);
  int w = f->width;

  while ((w - 1) > 0 && !f->minus) {
    if (f->zero)
      *str = '0';
    else
      *str = ' ';
    str++;
    w--;
  }

  *str = (char)ch;
  str++;

  while ((w - 1) > 0 && f->minus) {
    *str = ' ';
    str++;
    w--;
  }

  return str;
}

char *print_str(char *str, format_flags *f, va_list *args) {
  char *ptr = str;
  char *src = va_arg(*args, char *);

  if (src) {
    int temp = f->width;
    int i = 0;

    if ((s21_size_t)f->width < s21_strlen(src))  // change
      f->width = s21_strlen(src);

    int blank = f->width - s21_strlen(src);

    if (f->prec == 0 && !f->dot)
      f->prec = f->width;
    else if ((int)f->prec < temp)
      blank = temp - f->prec;

    while (blank && !f->minus) {
      if (f->zero)
        *str = '0';
      else
        *str = ' ';
      str++;
      blank--;
    }

    while (*src) {
      if (!f->prec) break;
      *str = *src;
      str++;
      src++;
      i++;
      f->prec--;
    }

    while (blank && f->minus) {
      *str = ' ';
      str++;
      blank--;
    }
  } else {
    int temp = f->width;
    int blank = 0;

    if (f->prec == 0 && !f->dot) {
      if (f->width > 6) blank = temp - 6;
      f->prec = f->width;
    } else if ((int)f->prec < temp) {
      if (f->prec < 6)
        blank = temp;
      else
        blank = temp - f->prec;
    }

    while (blank && !f->minus) {
      *str = ' ';
      str++;
      blank--;
    }

    int flag = 1;

    if (f->width == 0 && f->prec < 6 && f->dot) flag = 0;

    if (f->width <= f->prec && !(!f->prec && !f->width && f->dot) && flag) {
      str = s21_strncpy(str, "(null)", 6);
      str += 6;
    }

    while (blank && f->minus) {
      *str = ' ';
      str++;
      blank--;
    }
  }

  if (ptr) ptr = str;

  return ptr;
}

char *print_ptr(char *str, format_flags *f, va_list *args) {
  f->base = 16;
  f->hash = true;
  f->upper_case = false;

  ul_int num = (ul_int)va_arg(*args, ul_int);

  if (num) {
    s21_size_t size = get_size_unsign(f, num);
    char *str_unsign = xmalloc(size, &f->err);

    if (str_unsign && size) {
      int ofset = get_str_unsign(f, num, str_unsign, size);
      for (char *temp = str_unsign + ofset - 1; temp - str_unsign >= 0;
           temp--) {
        *str = *temp;
        str++;
      }
      while (ofset < (int)f->width) {
        *str = ' ';
        str++;
        ofset++;
      }
    }

    if (str_unsign) free(str_unsign);

  } else {
    int temp = f->width;
    int blank = 0;

    if (f->prec == 0 && !f->dot) {
      if (f->width > 5) blank = temp - 5;
      f->prec = f->width;
    }

    while (blank && !f->minus) {
      *str = ' ';
      str++;
      blank--;
    }

    str = s21_strncpy(str, "(nil)", 5);
    str += 5;

    while (blank && f->minus) {
      *str = ' ';
      str++;
      blank--;
    }
  }

  return str;
}

void set_double_specs(format_flags *f, char ch) {
  if (ch == 'g' || ch == 'G')
    f->g = true;
  else if (ch == 'e' || ch == 'E')
    f->e = 1;
  if (ch == 'G' || ch == 'E' || ch == 'F') f->upper_case = true;
}

s21_size_t get_size_double(format_flags *f, l_dbl num, l_dbl *intPart,
                           l_dbl *floatPart) {
  s21_size_t size = 0;

  if (num < 0) f->sign = true;

  l_dbl val = fabsl(num);

  if (val < 1) {
    *intPart = 0.0;
    *floatPart = val;
    size = 1;
  } else if (isinf(num) || isnan(num)) {
    size = 3;
  } else {
    *intPart = (l_dbl)trunc(val);
    *floatPart = val - *intPart;
    size += (unsigned int)log10l(*intPart) + 1;
  }

  if ((f->dot && f->prec == 0) || isinf(num) || isnan(num))
    ;
  else if (f->prec != 0) {
    size += f->prec + 1;
  } else if (!f->g) {
    f->prec = 6;
    size += f->prec + 1;
  }

  if (!(isinf(num) || isnan(num))) {
    l_dbl val_copy = *floatPart;
    l_dbl one = 1.0;

    for (int j = 0; j < (int)f->prec; j++) {
      val_copy *= 10.0;
      one /= 10.0;
    }

    l_dbl tmp = val_copy;
    val_copy = roundl(val_copy);

    if ((int)(val_copy - trunc(tmp)) == 1) {
      l_dbl intPart_copy = *intPart;
      if (*floatPart + one >= 1) {
        *intPart += 1.0;
      }
      if ((int)log10(*intPart) > (int)log10(intPart_copy)) size += 1;
    }
  }

  if (f->sign || f->plus || f->space) size++;

  if (f->hash && f->prec == 0) size++;

  if (size < f->width && !f->e) size = f->width;

  return size;
}

int is_nan_or_inf(char *str_double, l_dbl num, format_flags *f,
                  s21_size_t size) {
  int i = 0;

  if (isinf(num)) {
    s21_memcpy(str_double, "fni", 3);
    i += 3;
    size -= 3;
  }
  if (isnan(num)) {
    s21_memcpy(str_double, "nan", 3);
    i += 3;
    size -= 3;
  }

  if (f->sign) {
    str_double[i] = '-';
    f->plus = false;
    f->space = false;
    i++;
    size--;
  }

  if (f->plus) {
    str_double[i] = '+';
    i++;
    size--;
  }

  if (f->space) {
    str_double[i] = ' ';
    i++;
    size--;
  }

  if (size > 0 && !f->minus) {
    while ((size) > 0) {
      str_double[i] = ' ';
      i++;
      size--;
    }
  }

  return i;
}

int set_int_part(l_dbl intPart, format_flags *f, char *str_double,
                 s21_size_t *size, int i) {
  if (intPart < 0) intPart = fabsl(intPart);

  if ((int)intPart == 0) {
    str_double[i] = '0';
    *size -= 1;
    i++;
  }

  while (*size && intPart >= 1) {
    str_double[i] = dtoch((int)fmod(intPart, 10.0));
    intPart /= 10.0;
    *size -= 1;
    i++;
  }

  while (f->zero && str_double && (*size - f->sign > 0)) {
    if ((*size == 1 && (f->sign || f->plus || f->space)) ||
        !(f->minus ? f->prec : 1))
      break;
    str_double[i] = '0';
    i++;
    *size -= 1;
  }

  // sign
  if (f->space && !f->sign && *size) {
    str_double[i] = ' ';
    i++;
    *size -= 1;
  }

  if (f->sign && *size) {
    str_double[i] = '-';
    i++;
    *size -= 1;
  }

  if (f->plus && !f->sign && *size) {
    str_double[i] = '+';
    i++;
    *size -= 1;
  }

  if (*size > 0 && !f->minus && f->width != 0) {
    while ((*size) > 0) {
      str_double[i] = ' ';
      i++;
      *size -= 1;
    }
  }

  return i;
}

int set_float_part(l_dbl floatPart, format_flags *f, char *str_double,
                   s21_size_t *size, int i) {
  l_dbl val_copy = floatPart;
  u_int prec = f->prec;

  for (int j = 0; j < (int)f->prec; j++) val_copy *= 10.0;

  val_copy = round(val_copy);
  while (prec) {
    str_double[i] = dtoch((int)fmod(val_copy, 10.0));
    val_copy /= 10.0;
    *size -= 1;
    i++;
    prec--;
  }

  return i;
}

int print_e(int exp, s21_size_t *size, char *str_double, format_flags *f) {
  int i = 0;
  int tmp = exp;

  if (!exp) {
    str_double[i] = '0';
    *size -= 1;
    i++;
  } else {
    while (exp) {
      str_double[i] = dtoch(exp % 10);
      exp /= 10;
      *size -= 1;
      i++;
    }
  }

  if (tmp < 10) {
    str_double[i] = '0';
    i++;
    *size -= 1;
  }

  if (f->e == 2)
    str_double[i] = '+';
  else
    str_double[i] = '-';

  i++;
  *size -= 1;

  if (f->upper_case)
    str_double[i] = 'E';
  else
    str_double[i] = 'e';

  i++;
  *size -= 1;

  return i;
}

int get_str_double(format_flags *f, l_dbl num, l_dbl intPart, l_dbl floatPart,
                   char *str_double, s21_size_t size) {
  int i = 0;
  if (isnan(num) || isinf(num)) i = is_nan_or_inf(str_double, num, f, size);

  if (!i) {
    if (f->e) i = print_e(f->exp, &size, str_double, f);
    i = set_float_part(floatPart, f, str_double, &size, i);
    if (!(f->dot && f->prec == 0) || f->hash) {
      str_double[i] = '.';
      size--;
      i++;
    }
    if (f->prec == 0) intPart = roundl(num);

    i = set_int_part(intPart, f, str_double, &size, i);
  }

  return i;
}

char *print_double(char *str, format_flags *f, va_list *args) {
  l_dbl num = 0;

  if (f->length == 'L')
    num = va_arg(*args, l_dbl);
  else
    num = va_arg(*args, double);

  l_dbl intPart = 0;
  l_dbl floatPart = 0;

  s21_size_t size = get_size_double(f, num, &intPart, &floatPart);
  char *str_double = xmalloc(size, &f->err);

  if (str_double && size) {
    int ofset = get_str_double(f, num, intPart, floatPart, str_double, size);
    for (char *temp = str_double + ofset - 1; temp - str_double >= 0; temp--) {
      *str = *temp;
      str++;
    }
    while (ofset < (int)f->width) {
      *str = ' ';
      str++;
      ofset++;
    }
  }

  if (str_double) free(str_double);

  return str;
}

int norm(l_dbl *num, format_flags *f) {
  int e = 0;

  if (fabsl(*num) >= 1) {
    while (fabsl(*num) >= 9.999999) {
      *num /= 10;
      e++;
    }
    f->e = 2;
  } else {
    while (fabsl(*num) <= 0.999999) {
      if (*num == 0) {
        f->e = 2;
        break;
      }
      *num *= 10;
      e++;
      f->e = 1;
    }
  }

  return e;
}

void cutter(l_dbl num, format_flags *f) {
  format_flags f_copy = *f;

  int e = norm(&num, &f_copy);

  if (!f->dot && f->prec == 0) f->prec = 6;

  if ((f_copy.e == 1 && e <= 4) || (f_copy.e == 2 && e < (int)f->prec) ||
      !num) {
    if ((int)f->prec >= e + 1) f->prec -= e + 1;
    f->e = 0;
    if (f->prec == 0) f->dot = 1;
  } else {
    if (f->prec != 0) f->prec -= 1;
    f->e = 1;
  }
}

char *print_e_g(char *str, format_flags *f, va_list *args) {
  l_dbl num = 0;

  if (f->length == 'L')
    num = va_arg(*args, l_dbl);
  else
    num = va_arg(*args, double);

  if (isnan(num) || isinf(num)) {
    f->e = 0;
    f->g = 0;
  }

  s21_size_t size = 0;

  if (f->g) cutter(num, f);

  if (f->e) {
    f->exp = norm(&num, f);
    if (f->exp < 100)
      size += 4;
    else
      size += 5;
  }

  l_dbl intPart = 0;
  l_dbl floatPart = 0;

  s21_size_t num_part_size = get_size_double(f, num, &intPart, &floatPart);
  size += num_part_size;

  if (size < f->width) size = f->width;

  char *str_double = xmalloc(size, &f->err);

  if (str_double && size) {
    int ofset = get_str_double(f, num, intPart, floatPart, str_double, size);
    if (f->g && !f->e && f->prec != 0) {
      int i = 0;
      while (str_double[i] == '0') {
        str_double[i] = '!';
        i++;
        if (!f->minus && f->width != 0) {
          *str = ' ';
          str++;
        }
      }
      if (str_double[i] == '.') str_double[i] = '!';
    }
    if (f->e && f->g && f->prec && !f->hash) {
      int i = 0;
      if (f->exp < 100)
        i = 4;
      else
        i = 5;
      while (str_double[i] == '0') {
        str_double[i] = '!';
        i++;
        if (!f->minus && f->width != 0 && f->prec < f->width) {
          *str = ' ';
          str++;
        }
      }
      if (str_double[i] == '.') str_double[i] = '!';
    }

    for (char *temp = str_double + ofset - 1; temp - str_double >= 0; temp--) {
      if (*temp != '!') {
        *str = *temp;
        str++;
      } else if (f->minus) {
        ofset--;
      }
    }
    while (ofset < (int)f->width) {
      *str = ' ';
      str++;
      ofset++;
    }
  }

  if (str_double) free(str_double);

  return str;
}

char *s_print(char *start_ptr, char *str, const char *format, format_flags *f,
              va_list *args) {
  f->base = 10;

  if (*format == 'd' || *format == 'i') {
    str = print_dec(str, f, args);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
             *format == 'X') {
    set_base(format, f);
    str = print_unsign(str, f, args);
  } else if (*format == 'c') {
    str = print_char(str, f, args);
  } else if (*format == 's') {
    str = print_str(str, f, args);
  } else if (*format == 'p') {
    str = print_ptr(str, f, args);
  } else if (*format == 'n') {
    int *n = va_arg(*args, int *);
    *n = (int)(str - start_ptr);
  } else if (*format == 'f' || *format == 'F') {
    set_double_specs(f, *format);
    str = print_double(str, f, args);
  } else if (*format == 'e' || *format == 'E' || *format == 'g' ||
             *format == 'G') {
    set_double_specs(f, *format);
    str = print_e_g(str, f, args);
  }

  return str;
}

int s21_sprintf(char *restrict str, const char *restrict format, ...) {
  char *start_ptr = str;

  // Realization:
  // start parsing from %-sign, copy format to str otherwise

  va_list args;
  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      format++;
      if (*format == '%') {
        *str = *format;
        str++;
        format++;
        continue;
      }
      format_flags f = {0};
      format = set_format(format, &f, &args);
      while (!s21_strchr(SPECS, *format)) format++;
      str = s_print(start_ptr, str, format, &f, &args);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }

  // nul terminator
  *str = '\0';

  va_end(args);

  return (str - start_ptr);
}
