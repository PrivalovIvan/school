#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define PI 3.14159265358979323846264338327950288L
#define E 2.71828182845904
#define S21_DBL_MAX 1.7976931348623157e+308
#define eps 1e-10
#define inf 1.0 / 0.0
#define infm -1.0 / 0.0
#define nan 0.0 / 0.0

long double s21_factorial(int n);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_sin(double x);
long double s21_pow(double base, double exp);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
int s21_abs(int x);
#endif
