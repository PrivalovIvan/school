#include "s21_matrix_test.h"

START_TEST(s21_determinant_1) {
  matrix_t matrix = {0};
  double result;
  s21_create_matrix(5, 5, &matrix);
  matrix_full(-1, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), 0);
  s21_remove_matrix(&matrix);
}

END_TEST

START_TEST(s21_determinant_2) {
  matrix_t matrix = {0};
  double result;
  s21_create_matrix(6, 4, &matrix);
  matrix_full(-1.676675645, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), CALC_ERROR);
  s21_remove_matrix(&matrix);
}

END_TEST

START_TEST(s21_determinant_3) {
  matrix_t matrix = {0};
  double result;
  s21_create_matrix(0, 4, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
}

END_TEST

START_TEST(s21_determinant_4) {
  matrix_t matrix = {0};
  double result = 0;
  s21_create_matrix(2, 2, &matrix);
  matrix_full(5, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
}

END_TEST

START_TEST(s21_determinant_5) {
  double result = 0;
  matrix_t matrix = {0};
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 9;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[0][3] = 4;

  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 4;
  matrix.matrix[1][3] = 4;

  matrix.matrix[2][0] = 4;
  matrix.matrix[2][1] = 4;
  matrix.matrix[2][2] = 9;
  matrix.matrix[2][3] = 9;

  matrix.matrix[3][0] = 1;
  matrix.matrix[3][1] = 1;
  matrix.matrix[3][2] = 5;
  matrix.matrix[3][3] = 1;
  s21_determinant(&matrix, &result);
  ck_assert_int_eq(result, -578);
  s21_remove_matrix(&matrix);
}

END_TEST

START_TEST(s21_determinant_6) {
  double result = 0;
  matrix_t matrix = {0};
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[0][3] = 4;

  matrix.matrix[1][0] = 5;
  matrix.matrix[1][1] = 6;
  matrix.matrix[1][2] = 7;
  matrix.matrix[1][3] = 8;

  matrix.matrix[2][0] = 9;
  matrix.matrix[2][1] = 10;
  matrix.matrix[2][2] = 11;
  matrix.matrix[2][3] = 12;

  matrix.matrix[3][0] = 13;
  matrix.matrix[3][1] = 14;
  matrix.matrix[3][2] = 15;
  matrix.matrix[3][3] = 16;
  s21_determinant(&matrix, &result);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&matrix);
}

END_TEST

START_TEST(s21_determinant_7) {
  matrix_t matrix = {0};
  double value = -14351145.1125;
  double res;

  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1234.25;
  matrix.matrix[0][1] = -234.4;
  matrix.matrix[0][2] = 624;
  matrix.matrix[1][0] = 43;
  matrix.matrix[1][1] = 45;
  matrix.matrix[1][2] = 1;
  matrix.matrix[2][0] = 0;
  matrix.matrix[2][1] = -560;
  matrix.matrix[2][2] = -0.25;

  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_8) {
  matrix_t matrix = {0};
  double value = 1563370.85615;
  double res;

  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 1234.25;
  matrix.matrix[0][1] = -234.4;
  matrix.matrix[0][2] = 624;
  matrix.matrix[0][3] = 624;

  matrix.matrix[1][0] = 43;
  matrix.matrix[1][1] = 45;
  matrix.matrix[1][2] = 1;
  matrix.matrix[1][3] = 1;

  matrix.matrix[2][0] = 0;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -0.25;
  matrix.matrix[2][3] = -0.45;

  matrix.matrix[3][0] = 30;
  matrix.matrix[3][1] = 2.303;
  matrix.matrix[3][2] = 23;
  matrix.matrix[3][3] = 2;

  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_9) {
  matrix_t matrix = {0};
  double value = -82677054.89092243;
  double res;

  s21_create_matrix(5, 5, &matrix);
  matrix.matrix[0][0] = 1234.25;
  matrix.matrix[0][1] = -234.4;
  matrix.matrix[0][2] = 624;
  matrix.matrix[0][3] = 624;
  matrix.matrix[0][4] = 23;

  matrix.matrix[1][0] = 43;
  matrix.matrix[1][1] = 45;
  matrix.matrix[1][2] = 1;
  matrix.matrix[1][3] = 1;
  matrix.matrix[1][4] = 14.3;

  matrix.matrix[2][0] = 0;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -0.25;
  matrix.matrix[2][3] = -0.45;
  matrix.matrix[2][4] = 3.15;

  matrix.matrix[3][0] = 30;
  matrix.matrix[3][1] = 2.303;
  matrix.matrix[3][2] = 23;
  matrix.matrix[3][3] = 2;
  matrix.matrix[3][4] = 25.5;

  matrix.matrix[4][0] = 14.04;
  matrix.matrix[4][1] = 42.07;
  matrix.matrix[4][2] = -9.3;
  matrix.matrix[4][3] = -25;
  matrix.matrix[4][4] = -2.5;

  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *s21_determinant_test(void) {
  Suite *s = suite_create(COLOR("s21_determinant_test"));
  TCase *tc = tcase_create("s21_determinant_test");
  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);
  tcase_add_test(tc, s21_determinant_9);
  suite_add_tcase(s, tc);
  return s;
}