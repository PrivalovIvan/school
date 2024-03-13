#include "s21_matrix_test.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t matrixA = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(7, 4, &matrixA);
  s21_create_matrix(4, 3, &matrixB);
  matrix_full(9, &matrixA);
  matrix_full(6, &matrixB);
  ck_assert_int_eq(s21_mult_matrix(&matrixA, &matrixB, &result), OK);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t matrixA = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(4, 3, &matrixA);
  matrix_full(1, &matrixA);
  s21_create_matrix(-3, 5, &matrixB);
  matrix_full(6, &matrixB);
  ck_assert_int_eq(s21_mult_matrix(&matrixA, &matrixB, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t matrixA = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(2, 8, &matrixA);
  s21_create_matrix(4, 5, &matrixB);
  matrix_full(2, &matrixA);
  matrix_full(5, &matrixB);
  ck_assert_int_eq(s21_mult_matrix(&matrixA, &matrixB, &result), CALC_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t matrixA = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(4, 6, &matrixA);
  s21_create_matrix(3, 4, &matrixB);
  matrix_full(-5, &matrixA);
  matrix_full(6, &matrixB);
  ck_assert_int_eq(s21_mult_matrix(&matrixA, &matrixB, &result), CALC_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test1) {
  matrix_t matrix_a = {0}, matrix_b = {0}, result = {0};
  ck_assert_int_eq(s21_create_matrix(3, 2, &matrix_a), OK);
  ck_assert_int_eq(s21_create_matrix(2, 3, &matrix_b), OK);

  matrix_a.matrix[0][0] = 1.0;
  matrix_a.matrix[0][1] = 4.0;
  matrix_a.matrix[1][0] = 2.0;
  matrix_a.matrix[1][1] = 5.0;
  matrix_a.matrix[2][0] = 3.0;
  matrix_a.matrix[2][1] = 6.0;

  matrix_b.matrix[0][0] = 1.0;
  matrix_b.matrix[0][1] = -1.0;
  matrix_b.matrix[0][2] = 1.0;
  matrix_b.matrix[1][0] = 2.0;
  matrix_b.matrix[1][1] = 3.0;
  matrix_b.matrix[1][2] = 4.0;

  ck_assert_int_eq(s21_mult_matrix(&matrix_a, &matrix_b, &result), OK);
  ck_assert_double_eq(result.matrix[0][0], 9.0);
  ck_assert_double_eq(result.matrix[0][1], 11.0);
  ck_assert_double_eq(result.matrix[0][2], 17.0);
  ck_assert_double_eq(result.matrix[1][0], 12.0);
  ck_assert_double_eq(result.matrix[1][1], 13.0);
  ck_assert_double_eq(result.matrix[1][2], 22.0);
  ck_assert_double_eq(result.matrix[2][0], 15.0);
  ck_assert_double_eq(result.matrix[2][1], 15.0);
  ck_assert_double_eq(result.matrix[2][2], 27.0);

  s21_remove_matrix(&matrix_a);
  s21_remove_matrix(&matrix_b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test2) {
  matrix_t matrix_a = {0}, matrix_b = {0}, result = {0};
  ck_assert_int_eq(s21_create_matrix(3, 2, &matrix_a), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &matrix_b), OK);

  matrix_a.matrix[0][0] = 1.0;
  matrix_a.matrix[0][1] = 4.0;
  matrix_a.matrix[1][0] = 2.0;
  matrix_a.matrix[1][1] = 5.0;
  matrix_a.matrix[2][0] = 3.0;
  matrix_a.matrix[2][1] = 6.0;

  matrix_b.matrix[0][0] = 1.0;
  matrix_b.matrix[0][1] = -1.0;
  matrix_b.matrix[0][2] = 1.0;
  matrix_b.matrix[1][0] = 2.0;
  matrix_b.matrix[1][1] = 3.0;
  matrix_b.matrix[1][2] = 4.0;

  ck_assert_int_eq(s21_mult_matrix(&matrix_a, &matrix_b, &result), CALC_ERROR);

  s21_remove_matrix(&matrix_a);
  s21_remove_matrix(&matrix_b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test3) {
  matrix_t matrix_a = {0}, matrix_b = {0}, result = {0};
  ck_assert_int_eq(s21_create_matrix(3, 1, &matrix_a), OK);
  ck_assert_int_eq(s21_create_matrix(1, 3, &matrix_b), OK);

  matrix_a.matrix[0][0] = 4.0;
  matrix_a.matrix[1][0] = 5.0;
  matrix_a.matrix[2][0] = 6.0;

  matrix_b.matrix[0][0] = 1.0;
  matrix_b.matrix[0][1] = 2.0;
  matrix_b.matrix[0][2] = 3.0;

  ck_assert_int_eq(s21_mult_matrix(&matrix_a, &matrix_b, &result), OK);

  ck_assert_double_eq(result.matrix[0][0], 4.0);
  ck_assert_double_eq(result.matrix[0][1], 8.0);
  ck_assert_double_eq(result.matrix[0][2], 12.0);
  ck_assert_double_eq(result.matrix[1][0], 5.0);
  ck_assert_double_eq(result.matrix[1][1], 10.0);
  ck_assert_double_eq(result.matrix[1][2], 15.0);
  ck_assert_double_eq(result.matrix[2][0], 6.0);
  ck_assert_double_eq(result.matrix[2][1], 12.0);
  ck_assert_double_eq(result.matrix[2][2], 18.0);

  s21_remove_matrix(&matrix_a);
  s21_remove_matrix(&matrix_b);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_matrix_test(void) {
  Suite *s = suite_create(COLOR("s21_mult_matrix_test"));
  TCase *tc = tcase_create("s21_mult_matrix_test");
  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);
  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);

  suite_add_tcase(s, tc);
  return s;
}