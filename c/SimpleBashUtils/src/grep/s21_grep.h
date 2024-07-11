#ifndef S21_GREP_H
#define S21_GREP_H
#include <getopt.h>
#include <iso646.h>
#include <pcre.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10000

typedef struct {
  int e, i, v, c, l, n, h, s, o, f;
  int option_for_I;
  int count;
  int countO;
  int countC;
  int countVC;
  int countN;
  char str[BUFFER];
  char str_f[BUFFER];
  char arr_pattern[BUFFER];
} flags;

int error_count_info(int argc, char *argv[]);
int parser(int argc, char *argv[], flags *A);
int output(char *argv[], flags *A);
void flag_O(pcre *compile_regex_fr_f, int rc, flags *A, int ovector[],
            char *match);
int out_f(flags *A);
int output_NOT_C(int rc, flags *A, char *argv[], char *match);
int output_C(flags *A, char *argv[]);
#endif
