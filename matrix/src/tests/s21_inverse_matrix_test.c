#include "s21_matrix_test.h"

START_TEST(s21_inverse_matrix_1) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 8;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 8;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 8;
  matrix.matrix[2][0] = 2;
  matrix.matrix[2][1] = -8;
  matrix.matrix[2][2] = -2;
  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(6, 8, &matrix);
  matrix_full(5, &matrix);
  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), CALC_ERROR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(0, 0, &matrix);
  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(2, 2, &matrix);
  matrix_full(7, &matrix);
  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;

  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = -38.0;
  B.matrix[1][1] = 41.0;
  B.matrix[1][2] = -34.0;
  B.matrix[2][0] = 27.0;
  B.matrix[2][1] = -29.0;
  B.matrix[2][2] = 24.0;

  s21_inverse_matrix(&A, &result);
  int res = s21_eq_matrix(&B, &result);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_inverse_matrix(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 1.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = -5.0 / 23.0;
  X.matrix[1][1] = -121.0 / 23.0;
  X.matrix[1][2] = 2.0 / 23.0;
  X.matrix[1][3] = 1.0 / 23.0;
  X.matrix[2][0] = -18.0 / 23.0;
  X.matrix[2][1] = -379.0 / 46.0;
  X.matrix[2][2] = 19.0 / 46.0;
  X.matrix[2][3] = -25.0 / 46.0;
  X.matrix[3][0] = 53.0 / 69.0;
  X.matrix[3][1] = 1061.0 / 138.0;
  X.matrix[3][2] = -47.0 / 138.0;
  X.matrix[3][3] = 19.0 / 46.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test3) {
  int res;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  res = s21_inverse_matrix(&A, &Z);

  ck_assert_int_eq(Z.matrix[0][0] == (1.0 / A.matrix[0][0]), 1);
  ck_assert_int_eq(res, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

Suite *s21_inverse_matrix_test(void) {
  Suite *s = suite_create(COLOR("s21_inverse_matrix_test"));
  TCase *tc = tcase_create("s21_inverse_matrix_test");
  tcase_add_test(tc, s21_inverse_matrix_1);
  tcase_add_test(tc, s21_inverse_matrix_2);
  tcase_add_test(tc, s21_inverse_matrix_3);
  tcase_add_test(tc, s21_inverse_matrix_4);
  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);

  suite_add_tcase(s, tc);
  return s;
}