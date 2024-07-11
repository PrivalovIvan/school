#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <pcre.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10000

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int E;
  int T;
  int count;
  char str[BUFFER];
  char str_v[BUFFER];
} flags;

int output(char *argv[], flags *A);
int parser(int argc, char *argv[], flags *A);
int count_files_in_argv(char *argv[], int argc, flags *A);
void print_nb(int count);

#endif