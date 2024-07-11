#include "test_decimal.h"

int test_decimal_get_sign(s21_decimal value) {
  test_decimal_bytes decimal_bytes;
  decimal_bytes.d = value;
  return decimal_bytes.parts.sign;
}

int s21_random_int(int min, int max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int test_decimal_is_full_equal(s21_decimal value_1, s21_decimal value_2) {
  union {
    struct s21_decimal d;
    struct {
      uint32_t part0;
      uint32_t part1;
      uint32_t part2;
      uint32_t part3;
    } parts;
  } decimal_bytes1;

  union {
    struct s21_decimal d;
    struct {
      uint32_t part0;
      uint32_t part1;
      uint32_t part2;
      uint32_t part3;
    } parts;
  } decimal_bytes2;

  decimal_bytes1.d = value_1;
  decimal_bytes2.d = value_2;

  return decimal_bytes1.parts.part0 == decimal_bytes2.parts.part0 &&
         decimal_bytes1.parts.part1 == decimal_bytes2.parts.part1 &&
         decimal_bytes1.parts.part2 == decimal_bytes2.parts.part2 &&
         decimal_bytes1.parts.part3 == decimal_bytes2.parts.part3;
}
static int run_test_suite(Suite *test_suite) {
  int number_failed = 0;
  SRunner *sr = NULL;

  sr = srunner_create(test_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed);
}

int main(void) {
  int number_failed = 0;
  Suite *suite_array[] = {add_suite1(),
                          sub_suite1(),
                          mul_suite1(),
                          div_suite1(),

                          is_equal_suite1(),
                          is_greater_suite1(),
                          is_greater_or_equal_suite1(),
                          is_less_suite1(),
                          is_less_or_equal_suite1(),
                          is_not_equal_suite1(),

                          from_decimal_to_float_suite1(),
                          from_decimal_to_int_suite1(),
                          from_float_to_decimal_suite1(),
                          from_int_to_decimal_suite(),
                          floor_suite1(),
                          negate_suite1(),
                          round_suite1(),
                          truncate_suite1(),
                          NULL};

  for (size_t i = 0; suite_array[i]; ++i) {
    number_failed += run_test_suite(suite_array[i]);
  }
  printf("Auxiliary functions\n");
  printf("========= FAILED: %d =========\n", number_failed);

  return (number_failed ? EXIT_FAILURE : EXIT_SUCCESS);
}
