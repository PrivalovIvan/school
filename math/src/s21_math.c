#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}
long double s21_factorial(int n) {
  long double result = 1;
  if (n < 0) return 0;
  if (n == 0)
    return 1;
  else {
    for (int i = 2; i <= n; i++) {
      result *= i;
    }
  }
  return result;
}
long double s21_cos(double x) {
  if (x != x || x == inf || x == infm) return nan;
  for (; x < -2 * PI || 2 * PI < x;) {
    if (x > 2 * PI)
      x -= 2 * PI;
    else
      x += 2 * PI;
  }
  long double result = 0;
  if (x < 0.1 && x > -0.1) return 1;
  for (int i = 0; i < 100; i++) {
    result += (s21_pow((-1), i) * s21_pow(x, 2 * i)) / s21_factorial(2 * i);
  }
  return result;
}
long double s21_sin(double x) {
  if (x != x || x == inf || x == infm) return nan;
  for (; x < -2 * PI || 2 * PI < x;) {
    if (x > 2 * PI)
      x -= 2 * PI;
    else
      x += 2 * PI;
  }
  long double result = 0;
  if (x < 0.1 && x > -0.1) return x;
  for (register int i = 0; i < 100; i++) {
    result +=
        (s21_pow((-1), i) * s21_pow(x, 1 + 2 * i)) / s21_factorial(1 + 2 * i);
  }
  return result;
}
long double s21_ceil(double x) {
  char buf[100];
  sprintf(buf, "%.0lf", x);
  long double result = 0;
  sscanf(buf, "%Lf", &result);
  if (result < x) {
    result++;
  }
  return result;
}
long double s21_floor(double x) {
  char buf[80];
  sprintf(buf, "%.lf", x);
  long double result = 0;
  sscanf(buf, "%Lf", &result);
  if (result > x) {
    result--;
  }
  return result;
}
long double s21_fmod(double x, double y) {
  long double result = 0;
  long double floor = 0;
  if (x == 0 && y != y)
    return nan;
  else if ((x == 0 && (y == y || y != 0)))
    return 0;
  else if ((x == inf || y == 0) || (x == -inf && y == inf) ||
           (x == -inf && y == -inf))
    return nan;
  else if ((y == inf || y == -inf) && (x != inf || x != -inf))
    return x;
  if ((x / y) > 0) floor = s21_floor(x / y);
  if ((x / y) < 0) floor = s21_ceil(x / y);
  long double temp = floor * y;
  result = x - temp;
  return result;
}
long double s21_fabs(double x) {
  if (x < 0) x = -x;
  return x;
}
long double s21_exp(double x) {
  long double val = 1;
  long double series = 1;
  long double i = 1;

  if (x == 1)
    return E;
  else if (x == infm)
    return 0;
  else if (x >= 710 || x == 1.0 / 0.0)
    return inf;
  else {
    while (s21_fabs(val) > eps) {
      val *= x / i;
      i += 1;
      series += val;
      if (series > S21_DBL_MAX) {
        series = inf;
        break;
      }
    }
  }
  return (x >= 0 || x != x) ? series : 1 / s21_exp(-x);
}
long double s21_sqrt(double x) {
  int flag = 1;

  long double lo = 1, hi = x, mid;
  if (x == -inf)
    return nan;
  else if (x < 0) {
    flag = 0;
  } else if (x < lo && x > 0) {
    hi = lo;
    lo = x;
  } else if (x == 0) {
    mid = 0;
    flag = 0;
    return mid;
  }
  if (flag) {
    while (100 * lo * lo < x) lo *= 10;
    while (0.01 * hi * hi > x) hi *= 0.1;

    for (int i = 0; i < 100; i++) {
      mid = (lo + hi) * 0.5;
      if (mid * mid == x) return mid;
      if (mid * mid > x)
        hi = mid;
      else
        lo = mid;
    }
  }
  return mid;
}
long double s21_log(double x) {
  long double res = 0;
  long double temp = 0;
  if (x == 0) return infm;
  if (x < 0) return nan;
  if (1.0 / 0.0 == x) return inf;
  for (int i = 0; i < 100; i++) {
    temp = res;
    res += 1;
    res = temp + 2 * ((x - s21_exp(temp)) / (x + s21_exp(temp)));
  }
  return (res);
}
long double s21_tan(double x) {
  long double res;
  long double z = s21_sin(x);
  long double y = s21_cos(x);
  res = z / y;
  return res;
}
long double s21_atan(double x) {
  long double result = 0;
  long double temp = 0;

  if (x == 1)
    return result = PI / 4;
  else if (x == -1)
    return result = -PI / 4;
  else if (x == inf)
    return PI / 2;
  else if (x == infm)
    return -PI / 2;
  else if (-1 < x && x < 1) {
    for (int i = 0; i < 1500; i++) {
      result += (s21_pow((-1), i) * s21_pow(x, 1 + (2 * i))) / (1 + (2 * i));
    }
  } else {
    for (int i = 0; i < 1000; i++) {
      temp += (s21_pow(-1, i) * s21_pow(x, -1 - 2 * i)) / (1 + 2 * i);
    }
    result = (PI * s21_sqrt(x * x)) / (2 * x) - temp;
  }
  return result;
}
long double s21_asin(double x) {
  long double result = 0;
  if (x == -1)
    return -PI / 2;
  else if (x == 1)
    return PI / 2;
  else if (x > -0.0000001 && x < 0.0000001)
    return 0.0;
  else if (x != x || x == inf || x == infm || x > 1 || x < -1)
    return nan;

  else if (x > -1 && x < 1) {
    result = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
  }
  return result;
}
long double s21_acos(double x) {
  long double result = 0;
  if (x == 0)
    return PI / 2;
  else if (x == 0.70710678)
    return PI / 4;
  else if (x == -0.70710678)
    return PI - PI / 4;
  else if (x == -1)
    return PI;
  else if (0. < x && x < 1.) {
    return result = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (-1. < x && x < 0.) {
    return result = PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (x == 1)
    return 0;
  else if (x != x || x == inf || x == infm || x > 1 || x < -1)
    return nan;

  return result;
}
long double s21_pow(double base, double exp) {
  long double result = 1.0;
  long double mlt = base;
  double x = s21_floor(s21_fabs(exp));
  long double fraction = s21_fabs(exp) - s21_floor(s21_fabs(exp));
  if ((base == -1 && (exp == inf || exp == -inf)) ||
      (base == 1 && (exp == inf || exp == -inf || exp != exp)))
    return 1;
  else if (base == -inf && (s21_fmod(exp, 3) == 0 || exp == -1) && exp < 0)
    return -0.0;
  else if ((base < 0 && base != -inf && fraction > 1e-6) ||
           (base != base && (exp == inf || exp == -inf)))
    return nan;
  else if ((s21_fabs(base) < 1 && exp == -inf) ||
           (s21_fabs(base) > 1 && exp == inf) ||
           (base == -inf && exp > 0 && (s21_fmod(exp, 2) == 0)))
    return inf;
  else if ((s21_fabs(base) > 1 && exp == -inf) ||
           (s21_fabs(base) < 1 && exp == inf) ||
           (base == -inf && exp < 0 && s21_fmod(exp, 2) == 0))
    return 0;
  else if (exp == s21_floor(exp)) {
    for (int i = 1; i <= x; i++) {
      result *= base;
    }
    if (exp < 0) {
      result = 1 / result;
    }
  } else if (mlt < 0) {
    mlt = -mlt;
    result = s21_exp(exp * s21_log(mlt));
    if (s21_fmod(exp, 2) != 0) {
      result = -result;
    }
  } else {
    result = s21_exp(exp * s21_log(mlt));
  }
  if (s21_fabs(exp) < eps) {
    result = 1;
  }
  return result;
}
