#include "s21_cat.h"

int main(int argc, char *argv[]) {
  flags A = {0};

  parser(argc, argv, &A);
  while (optind < argc) {
    output(argv, &A);
    optind++;
  }
  return 0;
}

int parser(int argc, char *argv[], flags *A) {
  const struct option long_options[] = {
      {"number-nonblank", no_argument, &A->b, 1},
      {"number", no_argument, &A->n, 1},
      {"squeeze-blank", no_argument, &A->s, 1},
      {NULL, 0, NULL, 0}};

  int opt;
  while (((opt) = getopt_long(argc, argv, "nbestETv", long_options, 0)) != -1) {
    switch (opt) {
      case 'n':
        A->n = 1;
        break;
      case 'b':
        A->b = 1;
        break;
      case 'e':
        A->e = 1;
        break;
      case 's':
        A->s = 1;
        break;
      case 't':
        A->t = 1;
        break;
      case 'E':
        A->E = 1;
        break;
      case 'T':
        A->T = 1;
        break;
      case 'v':
        A->v = 1;
        break;
      default:
        break;
    }
  }
  return 0;
}

int output(char *argv[], flags *A) {
  FILE *fp = fopen(argv[optind], "r");
  if (fp) {
    int temp = '\n', count = 1, c, temp2 = 0;
    while ((c = fgetc(fp)) != EOF) {
      if (A->s && temp == '\n' && c == '\n' && temp2) continue;
      if (temp == '\n' && c == '\n')
        temp2 = 1;
      else
        temp2 = 0;
      if ((A->b && A->n && temp == '\n' && c != '\n') ||
          (A->b && temp == '\n' && c != '\n')) {
        print_nb(count);
        count++;
      } else if (A->n && !(A->b) && temp == '\n') {
        print_nb(count);
        count++;
      }
      if ((A->v || A->e || A->t) && c >= 0 && c <= 31 && c != '\n' && c != '\t')
        printf("^%c", c + 64);
      else if (((A->v || A->e || A->t)) && c == 127)
        printf("^?");
      else if ((A->e || A->E) && c == '\n')
        printf("$\n");
      else if ((A->t || A->T) && c == 9)
        printf("^I");
      else
        printf("%c", c);
      temp = c;
    }
    printf("%s", A->str_v);
    fclose(fp);
  }
  return 0;
}

void print_nb(int count) {
  if (count <= 9)
    printf("     %d\t", count);
  else if (count <= 99)
    printf("    %d\t", count);
  else if (count <= 999)
    printf("   %d\t", count);
}
