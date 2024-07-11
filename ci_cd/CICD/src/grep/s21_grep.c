#include "s21_grep.h"
#define V(v, rc) v == 1 ? rc<0 : rc> 0
int main(int argc, char *argv[]) {
  flags A = {0};
  parser(argc, argv, &A);
  A.count = argc - optind;
  while (optind < argc) {
    output(argv, &A);
    optind++;
  }

  return 0;
}
int parser(int argc, char *argv[], flags *A) {
  int opt;
  while (((opt) = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, 0)) != -1) {
    if (opt == 'e') {
      A->e = 1;
      strcat(A->arr_pattern, optarg);
      strcat(A->arr_pattern, "|");
    } else if (opt == 'i')
      A->i = 1;
    else if (opt == 'v')
      A->v = 1;
    else if (opt == 'c')
      A->c = 1, A->o = 0;

    else if (opt == 'l')
      A->l = 1;
    else if (opt == 'n')
      A->n = 1;
    else if (opt == 'h')
      A->h = 1;
    else if (opt == 's')
      A->s = 1;
    else if (opt == 'f')
      A->f = 1;
    else if (opt == 'o')
      A->o = 1;
    if (A->f) {
      out_f(A);
    }
  }
  if (!A->e && !A->f) {
    if (argc > optind) {
      strcat(A->arr_pattern, argv[optind]);
    }
    optind++;
  }
  if (A->e) {
    A->arr_pattern[strlen(A->arr_pattern) - 1] = '\0';
  }
  error_count_info(argc, argv);
  return 0;
}
int error_count_info(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr,
            "grep: option requires an argument -- %s\nusage: grep "
            "[-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n[-e "
            "pattern] [-f file] [--binary-files=value] "
            "[--color=when]\n[--context[=num]] [--directories=action] "
            "[--label] [--line-buffered]\n[--null] [pattern] [file ...]\n",
            argv[optind]);
  }
  return 0;
}
int out_f(flags *A) {
  FILE *f = fopen(optarg, "r");
  if (f != NULL) {
    while ((fgets(A->str, BUFFER, f)) != NULL) {
      if (A->str[strlen(A->str) - 1] == '\n') A->str[strlen(A->str) - 1] = '\0';
      if (A->str[strlen(A->str)] != '\n') A->str[strlen(A->str)] = '\0';
      strcat(A->str_f, A->str);
      strcat(A->str_f, "|");
    }
    fclose(f);
  }
  A->str_f[strlen(A->str_f) - 1] = '\0';
  strcat(A->arr_pattern, A->str_f);
  strcat(A->arr_pattern, "|");
  A->str_f[strlen(A->str_f) - 1] = '\0';
  return 0;
}
void flag_O(pcre *compile_regex_fr_f, int rc, flags *A, int ovector[],
            char *match) {
  int startoffset = 0;
  A->countO = 0;
  while ((rc = pcre_exec(compile_regex_fr_f, NULL, A->str, strlen(A->str),
                         startoffset, 0, ovector, 30)) >= 0) {
    ++A->countO;
    for (int i = 0; i < rc; ++i) {
      int substring_start = ovector[2 * i];
      int substring_end = ovector[2 * i + 1];
      int match_length = substring_end - substring_start;
      memcpy(match, A->str + substring_start, match_length);
      match[match_length] = '\0';
      startoffset = ovector[1];
    }
  }
}

/*
-v Инвертирует смысл поиска соответствий.

-c Выводит только количество совпадающих строк.
-n Предваряет каждую строку вывода номером строки из файла ввода.

-l Выводит только совпадающие файлы.
-h Выводит совпадающие строки, не предваряя их именами файлов.

-o Печатает только совпадающие (непустые) части совпавшей строки.
*/
int output(char *argv[], flags *A) {
  char buf[10000], *match = buf;
  int err_offset, rc;
  const char *err_message;
  FILE *fp = fopen(argv[optind], "r");
  if (A->i) A->option_for_I = 'i';
  pcre *comp_regex = pcre_compile(A->arr_pattern, A->option_for_I, &err_message,
                                  &err_offset, NULL);
  A->countC = 0, A->countN = 0, A->countVC = 0;
  if (fp) {
    while (fgets(A->str, BUFFER, fp) != NULL) {
      int ovector[90];
      rc = pcre_exec(comp_regex, NULL, A->str, strlen(A->str), 0, 0, ovector,
                     90);
      A->countN++;
      if (rc > 0) A->countC++;
      if (rc < 0) A->countVC++;
      if (A->arr_pattern and !A->e and A->f) printf("%s", A->str);
      if (!A->c) {
        flag_O(comp_regex, rc, A, ovector, match);
        output_NOT_C(rc, A, argv, match);
        if (A->l) {
          pcre_free(comp_regex);
          fclose(fp);
          return 0;
        }
      }
    }
    if (A->c) {
      output_C(A, argv);
    }
    pcre_free(comp_regex);
    fclose(fp);
  } else if (A->s) {
    pcre_free(comp_regex);
  } else {
    fprintf(stderr, "grep: %s: No such file or directory\n", argv[optind]);
    pcre_free(comp_regex);
  }
  return 0;
}

int output_NOT_C(int rc, flags *A, char *argv[], char *match) {
  if (A->l) {
    printf("%s\n", argv[optind]);
    return 0;
  }
  if (!A->v) {
    if (!A->h and rc > 0 and A->count > 1) printf("%s:", argv[optind]);
    if ((A->n and rc > 0)) printf("%d:", A->countN);
    if (A->o and rc > 0) {
      while (A->countO--) printf("%s\n", match);
    }
    if (rc > 0 and !A->o and !A->l) {
      printf("%s", A->str);
      if (A->str[strlen(A->str) - 1] != '\n') printf("\n");
    }
  } else if (A->v) {
    if (!A->h and rc < 0 and A->count > 1) printf("%s:", argv[optind]);
    if ((A->n and rc < 0)) printf("%d:", A->countN);
    if (A->o and rc < 0) {
      while (A->countO--) printf("%s\n", match);
    }
    if (rc < 0) {
      printf("%s", A->str);
      if (A->str[strlen(A->str) - 1] != '\n') printf("\n");
    }
  }
  return 0;
}

int output_C(flags *A, char *argv[]) {
  if (!A->v) {
    if (!A->h and A->count > 1) printf("%s:", argv[optind]);
    if (A->c) {
      if (A->l and A->countC > 0)
        printf("1\n");
      else if (A->l and A->countC < 0)
        printf("0\n");
      else
        printf("%d\n", A->countC);
    }
    if (A->l and A->countC > 0) printf("%s\n", argv[optind]);
  } else if (A->v) {
    if (!A->h and A->count > 1) printf("%s:", argv[optind]);
    if (A->c) {
      if (A->l)
        printf("1\n");
      else
        printf("%d\n", A->countVC);
    }
    if (A->l) printf("%s\n", argv[optind]);
  }
  return 0;
}
