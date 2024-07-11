#include "test_me.h"

START_TEST(_base) {
  char y[200] = {0}, y2[200] = {0};
  char x[200] = {0}, x2[200] = {0};
  char b[200] = {0}, b2[200] = {0};
  char a = 0, a2 = 0;
  float f = 0, f2 = 0;
  unsigned int ox16_x = 0, o8_o = 0;
  unsigned int ox16_x_2 = 0, o8_o_2 = 0;
  int s = 0, o8 = 0, ox16 = 0, inum = 0;
  int s2 = 0, o8_2 = 0, ox16_2 = 0, inum2 = 0;
  char str[] = "hello 15 ,world ! 20.3 -0x1235 -15112 0156  fA56d 01234 gh";
  char format[] = "%s %d %s %s %f %i %u %i %x %o %1c";
  sscanf(str, format, x, &s, y, b, &f, &ox16, &inum, &o8, &ox16_x, &o8_o, &a);
  s21_sscanf(str, format, x2, &s2, y2, b2, &f2, &ox16_2, &inum2, &o8_2,
             &ox16_x_2, &o8_o_2, &a2);
  ck_assert_str_eq(x, x2);              // hello               %s
  ck_assert_int_eq(s, s2);              // 15                  %d
  ck_assert_str_eq(y, y2);              // ,world              %s
  ck_assert_str_eq(b, b2);              // !                   %s
  ck_assert_float_eq(f, f2);            // 20.3                %f,e,E,g,G
  ck_assert_int_eq(ox16, ox16_2);       // 0x1235              %i
  ck_assert_uint_eq(inum, inum2);       // -15112              %u
  ck_assert_int_eq(o8, o8_2);           // 0156                %i
  ck_assert_uint_eq(ox16_x, ox16_x_2);  // fA56d               %x
  ck_assert_int_eq(o8_o, o8_o_2);       // 1235                %o
  ck_assert_int_eq(a, a2);              // gh                  %c
}
END_TEST
START_TEST(_h) {
  short d, d2;
  short i, i2;
  unsigned short o, o2;
  unsigned short u, u2;
  unsigned short x, x2;
  unsigned short X, X2;

  char str[] = "50000 0x1235 04562 064532 e456 FE456";
  char format[] = "%hd %hi %ho %hu %hx %hX";

  sscanf(str, format, &d, &i, &o, &u, &x, &X);
  s21_sscanf(str, format, &d2, &i2, &o2, &u2, &x2, &X2);
  ck_assert_int_eq(d, d2);  // 50000       %hd
  ck_assert_int_eq(i, i2);  // 0x1235      %hi
  ck_assert_int_eq(o, o2);  // 04562       %ho
  ck_assert_int_eq(u, u2);  // 45fA32      %hu
  ck_assert_int_eq(X, X2);  // FE456       %hX
  ck_assert_int_eq(x, x2);  // fe456       %hx
}
END_TEST
START_TEST(_l) {
  long d, d2;
  long i, i2;
  unsigned long o, o2;
  unsigned long u, u2;
  unsigned long x, x2;
  unsigned long X, X2;

  char str[] = "99999999999 0x999999 04562 0632 fab99999 FEABF456";
  char format[] = "%ld %li %lo %lu %lx %lX";

  sscanf(str, format, &d, &i, &o, &u, &x, &X);
  s21_sscanf(str, format, &d2, &i2, &o2, &u2, &x2, &X2);
  ck_assert_int_eq(d, d2);  // 99999999999    %ld
  ck_assert_int_eq(i, i2);  // 0x999999       %li
  ck_assert_int_eq(o, o2);  // 04562          %lo
  ck_assert_int_eq(u, u2);  // 0632           %lu
  ck_assert_int_eq(X, X2);  // fab99999       %lX
  ck_assert_int_eq(x, x2);  // FEABF456       %lx
}
END_TEST
START_TEST(_L) {
  long double d, d2;

  char str2[] = "20.345631";
  char format2[] = "%Lf";

  sscanf(str2, format2, &d);
  s21_sscanf(str2, format2, &d2);
  ck_assert_double_eq(d, d2);  // 20.345631       %Lf
}
END_TEST
START_TEST(_char42) {
  char a[20];
  char a2[20];
  char str[] = "Hello, world !";
  char format[] = "%*s%*s%s";
  sscanf(str, format, a);
  s21_sscanf(str, format, a2);

  ck_assert_str_eq(a, a2);
}
END_TEST
START_TEST(_n) {
  char format[] = "%s %n %s %n %Lf %n %s";
  char str[] = "Hello, world! 20.315684 a";
  char a[20], a2[20];
  char c[20], c2[20];
  char d[20], d2[20];
  int b1, b1_2;
  int b2, b2_2;
  int b3, b3_2;
  long double f, f2;
  int res1 = s21_sscanf(str, format, a, &b1, c, &b2, &f, &b3, d);
  int res2 = sscanf(str, format, a2, &b1_2, c2, &b2_2, &f2, &b3_2, d2);

  ck_assert_str_eq(a, a2);
  ck_assert_str_eq(c, c2);
  ck_assert_str_eq(d, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(b1, b1_2);
  ck_assert_int_eq(b2, b2_2);
  ck_assert_int_eq(b3, b3_2);
  ck_assert_double_eq(f, f2);
}
END_TEST
START_TEST(_c_part_1) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);

  char format2[] = "%c";
  char str2[] = "\t\n\n   \n  \ta";
  char c12, c22;
  int16_t res12 = s21_sscanf(str2, format2, &c12);
  int16_t res22 = sscanf(str2, format2, &c22);
  ck_assert_int_eq(res12, res22);
  ck_assert_int_eq(c12, c22);

  char format5[] = "%c %c \t%c";
  char str5[] = "\t\n\n  1    2 3 \n  \t";
  char c115, c125, c135, c215, c225, c235;
  int16_t res15 = s21_sscanf(str5, format5, &c115, &c125, &c135);
  int16_t res25 = sscanf(str5, format5, &c215, &c225, &c235);
  ck_assert_int_eq(res15, res25);
  ck_assert_int_eq(c115, c215);
  ck_assert_int_eq(c125, c225);
  ck_assert_int_eq(c135, c235);
}
END_TEST
START_TEST(_c_part_2) {
  char format4[] = "%c%c%c";
  char str4[] = "\t\n\n  123 \n  \t";
  char c114, c124, c134, c214, c224, c234;
  int16_t res14 = s21_sscanf(str4, format4, &c114, &c124, &c134);
  int16_t res24 = sscanf(str4, format4, &c214, &c224, &c234);
  ck_assert_int_eq(res14, res24);
  ck_assert_int_eq(c114, c214);
  ck_assert_int_eq(c124, c224);
  ck_assert_int_eq(c134, c234);
}
END_TEST
START_TEST(_c_part_3) {
  char format6[] = "%c %c \t%c";
  char str6[] = "\t\n\n  123 \n  \t";
  char c116, c126, c136, c216, c226, c236;
  int16_t res16 = s21_sscanf(str6, format6, &c116, &c126, &c136);
  int16_t res26 = sscanf(str6, format6, &c216, &c226, &c236);
  ck_assert_int_eq(res16, res26);
  ck_assert_int_eq(c116, c216);
  ck_assert_int_eq(c126, c226);
  ck_assert_int_eq(c136, c236);
}
END_TEST
START_TEST(_c_part_4) {
  char format7[] = "%c %*c \t%c";
  char str7[] = "\t\n\n  123 \n  \t";
  char c117, c127, c217, c227;
  int16_t res17 = s21_sscanf(str7, format7, &c117, &c127);
  int16_t res27 = sscanf(str7, format7, &c217, &c227);
  ck_assert_int_eq(res17, res27);
  ck_assert_int_eq(c117, c217);
  ck_assert_int_eq(c127, c227);
}
END_TEST
START_TEST(_percent) {
  int a, a2, res, res2;
  char b[20], b2[20];
  char format[] = "Sale %d%% for %s";
  char str[] = "Sale 50% for you";
  res = s21_sscanf(str, format, &a, b);
  res2 = sscanf(str, format, &a2, b2);
  ck_assert_int_eq(res, res2);
  ck_assert_int_eq(a, a2);
  ck_assert_str_eq(b, b2);
}
END_TEST
START_TEST(_pointer) {
  void **s;
  void **s2;
  char str[] = "0xd468d61234";
  char fmt[] = "%p";
  sscanf(str, fmt, &s);
  s21_sscanf(str, fmt, &s2);

  ck_assert_ptr_eq(s, s2);
}
END_TEST

Suite *test_s21_sscanf(void) {
  Suite *suite = suite_create("\033[43m-=S21_SSCANF=-\033[0m");
  TCase *tcase_core = tcase_create("s21_sscanf");

  tcase_add_test(tcase_core, _base);
  tcase_add_test(tcase_core, _h);
  tcase_add_test(tcase_core, _l);
  tcase_add_test(tcase_core, _L);
  tcase_add_test(tcase_core, _char42);
  tcase_add_test(tcase_core, _c_part_1);
  tcase_add_test(tcase_core, _c_part_2);
  tcase_add_test(tcase_core, _c_part_3);
  tcase_add_test(tcase_core, _c_part_4);
  tcase_add_test(tcase_core, _n);
  tcase_add_test(tcase_core, _percent);
  tcase_add_test(tcase_core, _pointer);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
