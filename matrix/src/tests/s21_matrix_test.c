#include "s21_matrix_test.h"

int run_suite(Suite *suite) {
  int failed;
  SRunner *sr = srunner_create(suite);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);

  srunner_free(sr);
  return failed;
}

int main(void) {
  Suite *suites[] = {
      s21_create_mat(),
      s21_eq_matrix_test(),
      s21_sum_matrix_test(),
      s21_sub_matrix_test(),
      s21_mult_number_test(),
      s21_mult_matrix_test(),
      s21_transpose_test(),
      s21_determinant_test(),
      s21_calc_complements_test(),
      s21_inverse_matrix_test(),
  };
  int failed = 0, length = sizeof(suites) / sizeof(suites[0]);

  for (int i = 0; i < length; i++) {
    failed += run_suite(suites[i]);
  }

  return failed != 0;
}