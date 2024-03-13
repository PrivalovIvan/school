#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_decimal.h"

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests all data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_mul1) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul2) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul3) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul4) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul5) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul6) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul7) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul8) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul9) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul10) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul11) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul12) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul13) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul14) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul15) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul16) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul17) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 52818775009509558395695964249
  s21_decimal decimal_check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul18) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -52818775009509558395695964249
  s21_decimal decimal_check = {
      {0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul19) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul20) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul21) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 13204693752377389598923991722
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul22) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -13204693752377389598923991722
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul23) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 13204693752377389598923991720
  s21_decimal decimal_check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul24) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -13204693752377389598923991720
  s21_decimal decimal_check = {
      {0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul25) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 13204693752377389598923991725
  s21_decimal decimal_check = {{0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul26) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -13204693752377389598923991725
  s21_decimal decimal_check = {
      {0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul27) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387504754779197847983448
  s21_decimal decimal_check = {{0x55555558, 0x55555555, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul28) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387504754779197847983448
  s21_decimal decimal_check = {
      {0x55555558, 0x55555555, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul29) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul30) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul31) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387504754779197847983442
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul32) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387504754779197847983442
  s21_decimal decimal_check = {
      {0x55555552, 0x55555555, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul33) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul34) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul35) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul36) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul37) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // 20923672451288935879452631411
  s21_decimal decimal_check = {{0xADCFA173, 0x67336914, 0x439BA7FC, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul38) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // -20923672451288935879452631411
  s21_decimal decimal_check = {
      {0xADCFA173, 0x67336914, 0x439BA7FC, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul39) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul40) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul41) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // 66023468761886.947994619958612
  s21_decimal decimal_check = {{0x55555554, 0x55555555, 0xD5555555, 0xF0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul42) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -66023468761886.947994619958612
  s21_decimal decimal_check = {
      {0x55555554, 0x55555555, 0xD5555555, 0x800F0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul43) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // 13204693752377.389598923991722
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0xF0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul44) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // -13204693752377.389598923991722
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x800F0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul45) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul46) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul47) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul48) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul49) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 2.6409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul50) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -2.6409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul51) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 26.409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x1B0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul52) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -26.409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x801B0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul53) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul54) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul55) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul56) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul57) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul58) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul59) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul60) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul61) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul62) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul63) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul64) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul65) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul66) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul67) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul68) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul69) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul70) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul71) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul72) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul73) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul74) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul75) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -52818775009509558395695964249
  s21_decimal decimal_check = {
      {0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul76) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 52818775009509558395695964249
  s21_decimal decimal_check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul77) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul78) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul79) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -13204693752377389598923991722
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul80) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 13204693752377389598923991722
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul81) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -13204693752377389598923991720
  s21_decimal decimal_check = {
      {0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul82) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 13204693752377389598923991720
  s21_decimal decimal_check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul83) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -13204693752377389598923991725
  s21_decimal decimal_check = {
      {0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul84) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 13204693752377389598923991725
  s21_decimal decimal_check = {{0xAAAAAAAD, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul85) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -26409387504754779197847983448
  s21_decimal decimal_check = {
      {0x55555558, 0x55555555, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul86) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387504754779197847983448
  s21_decimal decimal_check = {{0x55555558, 0x55555555, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul87) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul88) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul89) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -26409387504754779197847983442
  s21_decimal decimal_check = {
      {0x55555552, 0x55555555, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul90) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387504754779197847983442
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul91) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul92) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul93) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul94) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul95) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // -20923672451288935879452631411
  s21_decimal decimal_check = {
      {0xADCFA173, 0x67336914, 0x439BA7FC, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul96) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // 20923672451288935879452631411
  s21_decimal decimal_check = {{0xADCFA173, 0x67336914, 0x439BA7FC, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul97) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul98) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul99) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // -66023468761886.947994619958612
  s21_decimal decimal_check = {
      {0x55555554, 0x55555555, 0xD5555555, 0x800F0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul100) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // 66023468761886.947994619958612
  s21_decimal decimal_check = {{0x55555554, 0x55555555, 0xD5555555, 0xF0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul101) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // -13204693752377.389598923991722
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x800F0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul102) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // 13204693752377.389598923991722
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0xF0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul103) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul104) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul105) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul106) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul107) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -2.6409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul108) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 2.6409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul109) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -26.409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x801B0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul110) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 26.409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x1B0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul111) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul112) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul113) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul114) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul115) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul116) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul117) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul118) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul119) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul120) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul121) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul122) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul123) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul124) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul125) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul126) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul127) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul128) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul129) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul130) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul131) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul132) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul133) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 52818774997211729016086241369
  s21_decimal decimal_check = {{0xAAAAA059, 0x0, 0xAAAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul134) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -52818774997211729016086241369
  s21_decimal decimal_check = {{0xAAAAA059, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul135) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul136) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul137) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 13204693749302932254021561002
  s21_decimal decimal_check = {{0x2AAAAAAA, 0x80000000, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul138) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -13204693749302932254021561002
  s21_decimal decimal_check = {
      {0x2AAAAAAA, 0x80000000, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul139) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 13204693749302932254021561000
  s21_decimal decimal_check = {{0x2AAAAAA8, 0x80000000, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul140) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -13204693749302932254021561000
  s21_decimal decimal_check = {
      {0x2AAAAAA8, 0x80000000, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul141) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 13204693749302932254021561005
  s21_decimal decimal_check = {{0x2AAAAAAD, 0x80000000, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul142) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -13204693749302932254021561005
  s21_decimal decimal_check = {
      {0x2AAAAAAD, 0x80000000, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul143) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387498605864508043122008
  s21_decimal decimal_check = {{0x55555558, 0x0, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul144) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387498605864508043122008
  s21_decimal decimal_check = {{0x55555558, 0x0, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul145) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul146) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul147) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387498605864508043122002
  s21_decimal decimal_check = {{0x55555552, 0x0, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul148) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387498605864508043122002
  s21_decimal decimal_check = {{0x55555552, 0x0, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul149) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul150) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul151) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul152) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul153) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // 20923672446417263756150562907
  s21_decimal decimal_check = {{0x8A37E05B, 0x2397C118, 0x439BA7FC, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul154) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // -20923672446417263756150562907
  s21_decimal decimal_check = {
      {0x8A37E05B, 0x2397C118, 0x439BA7FC, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul155) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul156) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul157) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // 66023468746514.661270107805012
  s21_decimal decimal_check = {{0xD5555554, 0x80000000, 0xD5555554, 0xF0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul158) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -66023468746514.661270107805012
  s21_decimal decimal_check = {
      {0xD5555554, 0x80000000, 0xD5555554, 0x800F0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul159) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // 13204693749302.932254021561002
  s21_decimal decimal_check = {{0x2AAAAAAA, 0x80000000, 0x2AAAAAAA, 0xF0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul160) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // -13204693749302.932254021561002
  s21_decimal decimal_check = {
      {0x2AAAAAAA, 0x80000000, 0x2AAAAAAA, 0x800F0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul161) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul162) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul163) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul164) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul165) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 2.6409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul166) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -2.6409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul167) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 26.409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x1B0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul168) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -26.409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x801B0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul169) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul170) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul171) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul172) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul173) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul174) {
  // 26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul175) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul176) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul177) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul178) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul179) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul180) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul181) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul182) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul183) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul184) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul185) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul186) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul187) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul188) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul189) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul190) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul191) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -52818774997211729016086241369
  s21_decimal decimal_check = {{0xAAAAA059, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul192) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 52818774997211729016086241369
  s21_decimal decimal_check = {{0xAAAAA059, 0x0, 0xAAAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul193) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul194) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul195) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -13204693749302932254021561002
  s21_decimal decimal_check = {
      {0x2AAAAAAA, 0x80000000, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul196) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 13204693749302932254021561002
  s21_decimal decimal_check = {{0x2AAAAAAA, 0x80000000, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul197) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -13204693749302932254021561000
  s21_decimal decimal_check = {
      {0x2AAAAAA8, 0x80000000, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul198) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 13204693749302932254021561000
  s21_decimal decimal_check = {{0x2AAAAAA8, 0x80000000, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul199) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -13204693749302932254021561005
  s21_decimal decimal_check = {
      {0x2AAAAAAD, 0x80000000, 0x2AAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul200) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 13204693749302932254021561005
  s21_decimal decimal_check = {{0x2AAAAAAD, 0x80000000, 0x2AAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul201) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -26409387498605864508043122008
  s21_decimal decimal_check = {{0x55555558, 0x0, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul202) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387498605864508043122008
  s21_decimal decimal_check = {{0x55555558, 0x0, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul203) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul204) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul205) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -26409387498605864508043122002
  s21_decimal decimal_check = {{0x55555552, 0x0, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul206) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387498605864508043122002
  s21_decimal decimal_check = {{0x55555552, 0x0, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul207) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul208) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul209) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul210) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul211) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // -20923672446417263756150562907
  s21_decimal decimal_check = {
      {0x8A37E05B, 0x2397C118, 0x439BA7FC, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul212) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // 20923672446417263756150562907
  s21_decimal decimal_check = {{0x8A37E05B, 0x2397C118, 0x439BA7FC, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul213) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul214) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul215) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // -66023468746514.661270107805012
  s21_decimal decimal_check = {
      {0xD5555554, 0x80000000, 0xD5555554, 0x800F0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul216) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // 66023468746514.661270107805012
  s21_decimal decimal_check = {{0xD5555554, 0x80000000, 0xD5555554, 0xF0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul217) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // -13204693749302.932254021561002
  s21_decimal decimal_check = {
      {0x2AAAAAAA, 0x80000000, 0x2AAAAAAA, 0x800F0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul218) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // 13204693749302.932254021561002
  s21_decimal decimal_check = {{0x2AAAAAAA, 0x80000000, 0x2AAAAAAA, 0xF0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul219) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul220) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul221) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul222) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul223) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -2.6409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul224) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 2.6409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul225) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -26.409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x801B0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul226) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 26.409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x1B0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul227) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul228) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul229) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul230) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul231) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul232) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul233) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul234) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul235) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul236) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul237) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul238) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul239) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul240) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul241) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 8803129166201954835059936825
  s21_decimal decimal_check = {{0x38E38E39, 0x55555555, 0x1C71C71C, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul242) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -8803129166201954835059936825
  s21_decimal decimal_check = {
      {0x38E38E39, 0x55555555, 0x1C71C71C, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul243) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 162389070814544768680495185.58
  s21_decimal decimal_check = {{0x9C3D3FDE, 0xD33DA3EB, 0x34788254, 0x20000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul244) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // -162389070814544768680495185.58
  s21_decimal decimal_check = {
      {0x9C3D3FDE, 0xD33DA3EB, 0x34788254, 0x80020000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul245) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 162389070776735616809194041.03
  s21_decimal decimal_check = {{0xFD781E47, 0x9EC52196, 0x34788254, 0x20000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul246) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -162389070776735616809194041.03
  s21_decimal decimal_check = {
      {0xFD781E47, 0x9EC52196, 0x34788254, 0x80020000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul247) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 162389067710850691399003335
  s21_decimal decimal_check = {{0xFF79ACC7, 0xFFFFFFFF, 0x865338, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul248) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -162389067710850691399003335
  s21_decimal decimal_check = {{0xFF79ACC7, 0xFFFFFFFF, 0x865338, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul249) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 12297829382473034409.999999385
  s21_decimal decimal_check = {{0x82EE2199, 0xAAAAAAAA, 0x27BC86AA, 0x90000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul250) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -12297829382473034409.999999385
  s21_decimal decimal_check = {
      {0x82EE2199, 0xAAAAAAAA, 0x27BC86AA, 0x80090000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul251) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul252) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul253) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 3074457345618258602.5
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x1, 0x10000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul254) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -3074457345618258602.5
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x1, 0x80010000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul255) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 3074457345618258602.4999999994
  s21_decimal decimal_check = {{0x475359FA, 0xAAAAAAAA, 0x635750AA, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul256) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -3074457345618258602.4999999994
  s21_decimal decimal_check = {
      {0x475359FA, 0xAAAAAAAA, 0x635750AA, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul257) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 3074457345618258602.5000000006
  s21_decimal decimal_check = {{0x47535A06, 0xAAAAAAAA, 0x635750AA, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul258) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -3074457345618258602.5000000006
  s21_decimal decimal_check = {
      {0x47535A06, 0xAAAAAAAA, 0x635750AA, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul259) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 6148914691236517205.0000000006
  s21_decimal decimal_check = {{0x8EA6B406, 0x55555554, 0xC6AEA155, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul260) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -6148914691236517205.0000000006
  s21_decimal decimal_check = {
      {0x8EA6B406, 0x55555554, 0xC6AEA155, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul261) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 49191317529892137640
  s21_decimal decimal_check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul262) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -49191317529892137640
  s21_decimal decimal_check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul263) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 6148914691236517204.9999999994
  s21_decimal decimal_check = {{0x8EA6B3FA, 0x55555554, 0xC6AEA155, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul264) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -6148914691236517204.9999999994
  s21_decimal decimal_check = {
      {0x8EA6B3FA, 0x55555554, 0xC6AEA155, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul265) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul266) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul267) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 48716721244363430604.148555673
  s21_decimal decimal_check = {{0xD4B7BF99, 0x79B8EBC2, 0x9D6986FE, 0x90000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul268) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -48716721244363430604.148555673
  s21_decimal decimal_check = {
      {0xD4B7BF99, 0x79B8EBC2, 0x9D6986FE, 0x80090000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul269) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // 4871672124436343060.4148555676
  s21_decimal decimal_check = {{0xD4B7BF9C, 0x79B8EBC2, 0x9D6986FE, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul270) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // -4871672124436343060.4148555676
  s21_decimal decimal_check = {
      {0xD4B7BF9C, 0x79B8EBC2, 0x9D6986FE, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul271) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul272) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul273) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // 15372.2867280912930125
  s21_decimal decimal_check = {{0x5555554D, 0x55555555, 0x8, 0x100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul274) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -15372.2867280912930125
  s21_decimal decimal_check = {{0x5555554D, 0x55555555, 0x8, 0x80100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul275) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // 3074.4573456182586025
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x1, 0x100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul276) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // -3074.4573456182586025
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x1, 0x80100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul277) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul278) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul279) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul280) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul281) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.0000000006148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul282) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -0.0000000006148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul283) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 0.0000000061489146912365172050
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x3, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul284) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -0.0000000061489146912365172050
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x3, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul285) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul286) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul287) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul288) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul289) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // -43385638798924061271577.476380
  s21_decimal decimal_check = {{0x588A3D1C, 0x5F33F93, 0x8C2FC260, 0x80060000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul290) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 43385638798924061271577.476380
  s21_decimal decimal_check = {{0x588A3D1C, 0x5F33F93, 0x8C2FC260, 0x60000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul291) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul292) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul293) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul294) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul295) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul296) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul297) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul298) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul299) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -8803129166201954835059936825
  s21_decimal decimal_check = {
      {0x38E38E39, 0x55555555, 0x1C71C71C, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul300) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 8803129166201954835059936825
  s21_decimal decimal_check = {{0x38E38E39, 0x55555555, 0x1C71C71C, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul301) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -162389070814544768680495185.58
  s21_decimal decimal_check = {
      {0x9C3D3FDE, 0xD33DA3EB, 0x34788254, 0x80020000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul302) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // 162389070814544768680495185.58
  s21_decimal decimal_check = {{0x9C3D3FDE, 0xD33DA3EB, 0x34788254, 0x20000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul303) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -162389070776735616809194041.03
  s21_decimal decimal_check = {
      {0xFD781E47, 0x9EC52196, 0x34788254, 0x80020000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul304) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 162389070776735616809194041.03
  s21_decimal decimal_check = {{0xFD781E47, 0x9EC52196, 0x34788254, 0x20000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul305) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -162389067710850691399003335
  s21_decimal decimal_check = {{0xFF79ACC7, 0xFFFFFFFF, 0x865338, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul306) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 162389067710850691399003335
  s21_decimal decimal_check = {{0xFF79ACC7, 0xFFFFFFFF, 0x865338, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul307) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -12297829382473034409.999999385
  s21_decimal decimal_check = {
      {0x82EE2199, 0xAAAAAAAA, 0x27BC86AA, 0x80090000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul308) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 12297829382473034409.999999385
  s21_decimal decimal_check = {{0x82EE2199, 0xAAAAAAAA, 0x27BC86AA, 0x90000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul309) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul310) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul311) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -3074457345618258602.5
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x1, 0x80010000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul312) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 3074457345618258602.5
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x1, 0x10000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul313) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -3074457345618258602.4999999994
  s21_decimal decimal_check = {
      {0x475359FA, 0xAAAAAAAA, 0x635750AA, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul314) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 3074457345618258602.4999999994
  s21_decimal decimal_check = {{0x475359FA, 0xAAAAAAAA, 0x635750AA, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul315) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -3074457345618258602.5000000006
  s21_decimal decimal_check = {
      {0x47535A06, 0xAAAAAAAA, 0x635750AA, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul316) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 3074457345618258602.5000000006
  s21_decimal decimal_check = {{0x47535A06, 0xAAAAAAAA, 0x635750AA, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul317) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -6148914691236517205.0000000006
  s21_decimal decimal_check = {
      {0x8EA6B406, 0x55555554, 0xC6AEA155, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul318) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 6148914691236517205.0000000006
  s21_decimal decimal_check = {{0x8EA6B406, 0x55555554, 0xC6AEA155, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul319) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -49191317529892137640
  s21_decimal decimal_check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul320) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 49191317529892137640
  s21_decimal decimal_check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul321) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -6148914691236517204.9999999994
  s21_decimal decimal_check = {
      {0x8EA6B3FA, 0x55555554, 0xC6AEA155, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul322) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 6148914691236517204.9999999994
  s21_decimal decimal_check = {{0x8EA6B3FA, 0x55555554, 0xC6AEA155, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul323) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul324) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul325) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -48716721244363430604.148555673
  s21_decimal decimal_check = {
      {0xD4B7BF99, 0x79B8EBC2, 0x9D6986FE, 0x80090000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul326) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 48716721244363430604.148555673
  s21_decimal decimal_check = {{0xD4B7BF99, 0x79B8EBC2, 0x9D6986FE, 0x90000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul327) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // -4871672124436343060.4148555676
  s21_decimal decimal_check = {
      {0xD4B7BF9C, 0x79B8EBC2, 0x9D6986FE, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul328) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // 4871672124436343060.4148555676
  s21_decimal decimal_check = {{0xD4B7BF9C, 0x79B8EBC2, 0x9D6986FE, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul329) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul330) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul331) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // -15372.2867280912930125
  s21_decimal decimal_check = {{0x5555554D, 0x55555555, 0x8, 0x80100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul332) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // 15372.2867280912930125
  s21_decimal decimal_check = {{0x5555554D, 0x55555555, 0x8, 0x100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul333) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // -3074.4573456182586025
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x1, 0x80100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul334) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // 3074.4573456182586025
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x1, 0x100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul335) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul336) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul337) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul338) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul339) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -0.0000000006148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul340) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 0.0000000006148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul341) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -0.0000000061489146912365172050
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x3, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul342) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 0.0000000061489146912365172050
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x3, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul343) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul344) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul345) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul346) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul347) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // 43385638798924061271577.476380
  s21_decimal decimal_check = {{0x588A3D1C, 0x5F33F93, 0x8C2FC260, 0x60000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul348) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -43385638798924061271577.476380
  s21_decimal decimal_check = {{0x588A3D1C, 0x5F33F93, 0x8C2FC260, 0x80060000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul349) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul350) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul351) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul352) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul353) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul354) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul355) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul356) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul357) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 8803129164152316605602201600
  s21_decimal decimal_check = {{0x0, 0x38E38E39, 0x1C71C71C, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul358) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -8803129164152316605602201600
  s21_decimal decimal_check = {{0x0, 0x38E38E39, 0x1C71C71C, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul359) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 162389070776735616809194041.03
  s21_decimal decimal_check = {{0xFD781E47, 0x9EC52196, 0x34788254, 0x20000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul360) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // -162389070776735616809194041.03
  s21_decimal decimal_check = {
      {0xFD781E47, 0x9EC52196, 0x34788254, 0x80020000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul361) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 162389070738926464946696025.64
  s21_decimal decimal_check = {{0x932B7F04, 0x6A4C9F42, 0x34788254, 0x20000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul362) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -162389070738926464946696025.64
  s21_decimal decimal_check = {
      {0x932B7F04, 0x6A4C9F42, 0x34788254, 0x80020000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul363) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 162389067673041540250337280
  s21_decimal decimal_check = {{0x0, 0xFF79ACC7, 0x865338, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul364) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -162389067673041540250337280
  s21_decimal decimal_check = {{0x0, 0xFF79ACC7, 0x865338, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul365) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 12297829379609722879.999999385
  s21_decimal decimal_check = {{0xFFFFFD99, 0x82EE23FF, 0x27BC86AA, 0x90000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul366) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -12297829379609722879.999999385
  s21_decimal decimal_check = {
      {0xFFFFFD99, 0x82EE23FF, 0x27BC86AA, 0x80090000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul367) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 6148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul368) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul369) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 3074457344902430720.0
  s21_decimal decimal_check = {{0x0, 0xAAAAAAA9, 0x1, 0x10000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul370) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -3074457344902430720.0
  s21_decimal decimal_check = {{0x0, 0xAAAAAAA9, 0x1, 0x80010000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul371) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 3074457344902430719.9999999994
  s21_decimal decimal_check = {{0xFFFFFFFA, 0x475359FF, 0x635750AA, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul372) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -3074457344902430719.9999999994
  s21_decimal decimal_check = {
      {0xFFFFFFFA, 0x475359FF, 0x635750AA, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul373) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 3074457344902430720.0000000006
  s21_decimal decimal_check = {{0x6, 0x47535A00, 0x635750AA, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul374) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -3074457344902430720.0000000006
  s21_decimal decimal_check = {{0x6, 0x47535A00, 0x635750AA, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul375) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 6148914689804861440.0000000006
  s21_decimal decimal_check = {{0x6, 0x8EA6B400, 0xC6AEA154, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul376) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -6148914689804861440.0000000006
  s21_decimal decimal_check = {{0x6, 0x8EA6B400, 0xC6AEA154, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul377) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 49191317518438891520
  s21_decimal decimal_check = {{0x0, 0xAAAAAAA8, 0x2, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul378) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -49191317518438891520
  s21_decimal decimal_check = {{0x0, 0xAAAAAAA8, 0x2, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul379) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 6148914689804861439.9999999994
  s21_decimal decimal_check = {{0xFFFFFFFA, 0x8EA6B3FF, 0xC6AEA154, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul380) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -6148914689804861439.9999999994
  s21_decimal decimal_check = {
      {0xFFFFFFFA, 0x8EA6B3FF, 0xC6AEA154, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul381) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul382) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul383) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 48716721233020685042.758212308
  s21_decimal decimal_check = {{0xF8685AD4, 0xDC4F64C4, 0x9D6986FD, 0x90000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul384) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -48716721233020685042.758212308
  s21_decimal decimal_check = {
      {0xF8685AD4, 0xDC4F64C4, 0x9D6986FD, 0x80090000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul385) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // 4871672123302068504.2758212311
  s21_decimal decimal_check = {{0xF8685AD7, 0xDC4F64C4, 0x9D6986FD, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul386) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // -4871672123302068504.2758212311
  s21_decimal decimal_check = {
      {0xF8685AD7, 0xDC4F64C4, 0x9D6986FD, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul387) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul388) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul389) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // 15372.2867245121536000
  s21_decimal decimal_check = {{0x0, 0x5555554D, 0x8, 0x100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul390) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -15372.2867245121536000
  s21_decimal decimal_check = {{0x0, 0x5555554D, 0x8, 0x80100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul391) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // 3074.4573449024307200
  s21_decimal decimal_check = {{0x0, 0xAAAAAAA9, 0x1, 0x100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul392) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // -3074.4573449024307200
  s21_decimal decimal_check = {{0x0, 0xAAAAAAA9, 0x1, 0x80100000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul393) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul394) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul395) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul396) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul397) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.0000000006148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul398) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -0.0000000006148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul399) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 0.0000000061489146898048614400
  s21_decimal decimal_check = {{0x0, 0x55555552, 0x3, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul400) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -0.0000000061489146898048614400
  s21_decimal decimal_check = {{0x0, 0x55555552, 0x3, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

Suite *mul_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[45m-=S21_MUL=-\033[0m");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_mul1);
  tcase_add_test(tc_core, test_mul2);
  tcase_add_test(tc_core, test_mul3);
  tcase_add_test(tc_core, test_mul4);
  tcase_add_test(tc_core, test_mul5);
  tcase_add_test(tc_core, test_mul6);
  tcase_add_test(tc_core, test_mul7);
  tcase_add_test(tc_core, test_mul8);
  tcase_add_test(tc_core, test_mul9);
  tcase_add_test(tc_core, test_mul10);
  tcase_add_test(tc_core, test_mul11);
  tcase_add_test(tc_core, test_mul12);
  tcase_add_test(tc_core, test_mul13);
  tcase_add_test(tc_core, test_mul14);
  tcase_add_test(tc_core, test_mul15);
  tcase_add_test(tc_core, test_mul16);
  tcase_add_test(tc_core, test_mul17);
  tcase_add_test(tc_core, test_mul18);
  tcase_add_test(tc_core, test_mul19);
  tcase_add_test(tc_core, test_mul20);
  tcase_add_test(tc_core, test_mul21);
  tcase_add_test(tc_core, test_mul22);
  tcase_add_test(tc_core, test_mul23);
  tcase_add_test(tc_core, test_mul24);
  tcase_add_test(tc_core, test_mul25);
  tcase_add_test(tc_core, test_mul26);
  tcase_add_test(tc_core, test_mul27);
  tcase_add_test(tc_core, test_mul28);
  tcase_add_test(tc_core, test_mul29);
  tcase_add_test(tc_core, test_mul30);
  tcase_add_test(tc_core, test_mul31);
  tcase_add_test(tc_core, test_mul32);
  tcase_add_test(tc_core, test_mul33);
  tcase_add_test(tc_core, test_mul34);
  tcase_add_test(tc_core, test_mul35);
  tcase_add_test(tc_core, test_mul36);
  tcase_add_test(tc_core, test_mul37);
  tcase_add_test(tc_core, test_mul38);
  tcase_add_test(tc_core, test_mul39);
  tcase_add_test(tc_core, test_mul40);
  tcase_add_test(tc_core, test_mul41);
  tcase_add_test(tc_core, test_mul42);
  tcase_add_test(tc_core, test_mul43);
  tcase_add_test(tc_core, test_mul44);
  tcase_add_test(tc_core, test_mul45);
  tcase_add_test(tc_core, test_mul46);
  tcase_add_test(tc_core, test_mul47);
  tcase_add_test(tc_core, test_mul48);
  tcase_add_test(tc_core, test_mul49);
  tcase_add_test(tc_core, test_mul50);
  tcase_add_test(tc_core, test_mul51);
  tcase_add_test(tc_core, test_mul52);
  tcase_add_test(tc_core, test_mul53);
  tcase_add_test(tc_core, test_mul54);
  tcase_add_test(tc_core, test_mul55);
  tcase_add_test(tc_core, test_mul56);
  tcase_add_test(tc_core, test_mul57);
  tcase_add_test(tc_core, test_mul58);
  tcase_add_test(tc_core, test_mul59);
  tcase_add_test(tc_core, test_mul60);
  tcase_add_test(tc_core, test_mul61);
  tcase_add_test(tc_core, test_mul62);
  tcase_add_test(tc_core, test_mul63);
  tcase_add_test(tc_core, test_mul64);
  tcase_add_test(tc_core, test_mul65);
  tcase_add_test(tc_core, test_mul66);
  tcase_add_test(tc_core, test_mul67);
  tcase_add_test(tc_core, test_mul68);
  tcase_add_test(tc_core, test_mul69);
  tcase_add_test(tc_core, test_mul70);
  tcase_add_test(tc_core, test_mul71);
  tcase_add_test(tc_core, test_mul72);
  tcase_add_test(tc_core, test_mul73);
  tcase_add_test(tc_core, test_mul74);
  tcase_add_test(tc_core, test_mul75);
  tcase_add_test(tc_core, test_mul76);
  tcase_add_test(tc_core, test_mul77);
  tcase_add_test(tc_core, test_mul78);
  tcase_add_test(tc_core, test_mul79);
  tcase_add_test(tc_core, test_mul80);
  tcase_add_test(tc_core, test_mul81);
  tcase_add_test(tc_core, test_mul82);
  tcase_add_test(tc_core, test_mul83);
  tcase_add_test(tc_core, test_mul84);
  tcase_add_test(tc_core, test_mul85);
  tcase_add_test(tc_core, test_mul86);
  tcase_add_test(tc_core, test_mul87);
  tcase_add_test(tc_core, test_mul88);
  tcase_add_test(tc_core, test_mul89);
  tcase_add_test(tc_core, test_mul90);
  tcase_add_test(tc_core, test_mul91);
  tcase_add_test(tc_core, test_mul92);
  tcase_add_test(tc_core, test_mul93);
  tcase_add_test(tc_core, test_mul94);
  tcase_add_test(tc_core, test_mul95);
  tcase_add_test(tc_core, test_mul96);
  tcase_add_test(tc_core, test_mul97);
  tcase_add_test(tc_core, test_mul98);
  tcase_add_test(tc_core, test_mul99);
  tcase_add_test(tc_core, test_mul100);
  tcase_add_test(tc_core, test_mul101);
  tcase_add_test(tc_core, test_mul102);
  tcase_add_test(tc_core, test_mul103);
  tcase_add_test(tc_core, test_mul104);
  tcase_add_test(tc_core, test_mul105);
  tcase_add_test(tc_core, test_mul106);
  tcase_add_test(tc_core, test_mul107);
  tcase_add_test(tc_core, test_mul108);
  tcase_add_test(tc_core, test_mul109);
  tcase_add_test(tc_core, test_mul110);
  tcase_add_test(tc_core, test_mul111);
  tcase_add_test(tc_core, test_mul112);
  tcase_add_test(tc_core, test_mul113);
  tcase_add_test(tc_core, test_mul114);
  tcase_add_test(tc_core, test_mul115);
  tcase_add_test(tc_core, test_mul116);
  tcase_add_test(tc_core, test_mul117);
  tcase_add_test(tc_core, test_mul118);
  tcase_add_test(tc_core, test_mul119);
  tcase_add_test(tc_core, test_mul120);
  tcase_add_test(tc_core, test_mul121);
  tcase_add_test(tc_core, test_mul122);
  tcase_add_test(tc_core, test_mul123);
  tcase_add_test(tc_core, test_mul124);
  tcase_add_test(tc_core, test_mul125);
  tcase_add_test(tc_core, test_mul126);
  tcase_add_test(tc_core, test_mul127);
  tcase_add_test(tc_core, test_mul128);
  tcase_add_test(tc_core, test_mul129);
  tcase_add_test(tc_core, test_mul130);
  tcase_add_test(tc_core, test_mul131);
  tcase_add_test(tc_core, test_mul132);
  tcase_add_test(tc_core, test_mul133);
  tcase_add_test(tc_core, test_mul134);
  tcase_add_test(tc_core, test_mul135);
  tcase_add_test(tc_core, test_mul136);
  tcase_add_test(tc_core, test_mul137);
  tcase_add_test(tc_core, test_mul138);
  tcase_add_test(tc_core, test_mul139);
  tcase_add_test(tc_core, test_mul140);
  tcase_add_test(tc_core, test_mul141);
  tcase_add_test(tc_core, test_mul142);
  tcase_add_test(tc_core, test_mul143);
  tcase_add_test(tc_core, test_mul144);
  tcase_add_test(tc_core, test_mul145);
  tcase_add_test(tc_core, test_mul146);
  tcase_add_test(tc_core, test_mul147);
  tcase_add_test(tc_core, test_mul148);
  tcase_add_test(tc_core, test_mul149);
  tcase_add_test(tc_core, test_mul150);
  tcase_add_test(tc_core, test_mul151);
  tcase_add_test(tc_core, test_mul152);
  tcase_add_test(tc_core, test_mul153);
  tcase_add_test(tc_core, test_mul154);
  tcase_add_test(tc_core, test_mul155);
  tcase_add_test(tc_core, test_mul156);
  tcase_add_test(tc_core, test_mul157);
  tcase_add_test(tc_core, test_mul158);
  tcase_add_test(tc_core, test_mul159);
  tcase_add_test(tc_core, test_mul160);
  tcase_add_test(tc_core, test_mul161);
  tcase_add_test(tc_core, test_mul162);
  tcase_add_test(tc_core, test_mul163);
  tcase_add_test(tc_core, test_mul164);
  tcase_add_test(tc_core, test_mul165);
  tcase_add_test(tc_core, test_mul166);
  tcase_add_test(tc_core, test_mul167);
  tcase_add_test(tc_core, test_mul168);
  tcase_add_test(tc_core, test_mul169);
  tcase_add_test(tc_core, test_mul170);
  tcase_add_test(tc_core, test_mul171);
  tcase_add_test(tc_core, test_mul172);
  tcase_add_test(tc_core, test_mul173);
  tcase_add_test(tc_core, test_mul174);
  tcase_add_test(tc_core, test_mul175);
  tcase_add_test(tc_core, test_mul176);
  tcase_add_test(tc_core, test_mul177);
  tcase_add_test(tc_core, test_mul178);
  tcase_add_test(tc_core, test_mul179);
  tcase_add_test(tc_core, test_mul180);
  tcase_add_test(tc_core, test_mul181);
  tcase_add_test(tc_core, test_mul182);
  tcase_add_test(tc_core, test_mul183);
  tcase_add_test(tc_core, test_mul184);
  tcase_add_test(tc_core, test_mul185);
  tcase_add_test(tc_core, test_mul186);
  tcase_add_test(tc_core, test_mul187);
  tcase_add_test(tc_core, test_mul188);
  tcase_add_test(tc_core, test_mul189);
  tcase_add_test(tc_core, test_mul190);
  tcase_add_test(tc_core, test_mul191);
  tcase_add_test(tc_core, test_mul192);
  tcase_add_test(tc_core, test_mul193);
  tcase_add_test(tc_core, test_mul194);
  tcase_add_test(tc_core, test_mul195);
  tcase_add_test(tc_core, test_mul196);
  tcase_add_test(tc_core, test_mul197);
  tcase_add_test(tc_core, test_mul198);
  tcase_add_test(tc_core, test_mul199);
  tcase_add_test(tc_core, test_mul200);
  tcase_add_test(tc_core, test_mul201);
  tcase_add_test(tc_core, test_mul202);
  tcase_add_test(tc_core, test_mul203);
  tcase_add_test(tc_core, test_mul204);
  tcase_add_test(tc_core, test_mul205);
  tcase_add_test(tc_core, test_mul206);
  tcase_add_test(tc_core, test_mul207);
  tcase_add_test(tc_core, test_mul208);
  tcase_add_test(tc_core, test_mul209);
  tcase_add_test(tc_core, test_mul210);
  tcase_add_test(tc_core, test_mul211);
  tcase_add_test(tc_core, test_mul212);
  tcase_add_test(tc_core, test_mul213);
  tcase_add_test(tc_core, test_mul214);
  tcase_add_test(tc_core, test_mul215);
  tcase_add_test(tc_core, test_mul216);
  tcase_add_test(tc_core, test_mul217);
  tcase_add_test(tc_core, test_mul218);
  tcase_add_test(tc_core, test_mul219);
  tcase_add_test(tc_core, test_mul220);
  tcase_add_test(tc_core, test_mul221);
  tcase_add_test(tc_core, test_mul222);
  tcase_add_test(tc_core, test_mul223);
  tcase_add_test(tc_core, test_mul224);
  tcase_add_test(tc_core, test_mul225);
  tcase_add_test(tc_core, test_mul226);
  tcase_add_test(tc_core, test_mul227);
  tcase_add_test(tc_core, test_mul228);
  tcase_add_test(tc_core, test_mul229);
  tcase_add_test(tc_core, test_mul230);
  tcase_add_test(tc_core, test_mul231);
  tcase_add_test(tc_core, test_mul232);
  tcase_add_test(tc_core, test_mul233);
  tcase_add_test(tc_core, test_mul234);
  tcase_add_test(tc_core, test_mul235);
  tcase_add_test(tc_core, test_mul236);
  tcase_add_test(tc_core, test_mul237);
  tcase_add_test(tc_core, test_mul238);
  tcase_add_test(tc_core, test_mul239);
  tcase_add_test(tc_core, test_mul240);
  tcase_add_test(tc_core, test_mul241);
  tcase_add_test(tc_core, test_mul242);
  tcase_add_test(tc_core, test_mul243);
  tcase_add_test(tc_core, test_mul244);
  tcase_add_test(tc_core, test_mul245);
  tcase_add_test(tc_core, test_mul246);
  tcase_add_test(tc_core, test_mul247);
  tcase_add_test(tc_core, test_mul248);
  tcase_add_test(tc_core, test_mul249);
  tcase_add_test(tc_core, test_mul250);
  tcase_add_test(tc_core, test_mul251);
  tcase_add_test(tc_core, test_mul252);
  tcase_add_test(tc_core, test_mul253);
  tcase_add_test(tc_core, test_mul254);
  tcase_add_test(tc_core, test_mul255);
  tcase_add_test(tc_core, test_mul256);
  tcase_add_test(tc_core, test_mul257);
  tcase_add_test(tc_core, test_mul258);
  tcase_add_test(tc_core, test_mul259);
  tcase_add_test(tc_core, test_mul260);
  tcase_add_test(tc_core, test_mul261);
  tcase_add_test(tc_core, test_mul262);
  tcase_add_test(tc_core, test_mul263);
  tcase_add_test(tc_core, test_mul264);
  tcase_add_test(tc_core, test_mul265);
  tcase_add_test(tc_core, test_mul266);
  tcase_add_test(tc_core, test_mul267);
  tcase_add_test(tc_core, test_mul268);
  tcase_add_test(tc_core, test_mul269);
  tcase_add_test(tc_core, test_mul270);
  tcase_add_test(tc_core, test_mul271);
  tcase_add_test(tc_core, test_mul272);
  tcase_add_test(tc_core, test_mul273);
  tcase_add_test(tc_core, test_mul274);
  tcase_add_test(tc_core, test_mul275);
  tcase_add_test(tc_core, test_mul276);
  tcase_add_test(tc_core, test_mul277);
  tcase_add_test(tc_core, test_mul278);
  tcase_add_test(tc_core, test_mul279);
  tcase_add_test(tc_core, test_mul280);
  tcase_add_test(tc_core, test_mul281);
  tcase_add_test(tc_core, test_mul282);
  tcase_add_test(tc_core, test_mul283);
  tcase_add_test(tc_core, test_mul284);
  tcase_add_test(tc_core, test_mul285);
  tcase_add_test(tc_core, test_mul286);
  tcase_add_test(tc_core, test_mul287);
  tcase_add_test(tc_core, test_mul288);
  tcase_add_test(tc_core, test_mul289);
  tcase_add_test(tc_core, test_mul290);
  tcase_add_test(tc_core, test_mul291);
  tcase_add_test(tc_core, test_mul292);
  tcase_add_test(tc_core, test_mul293);
  tcase_add_test(tc_core, test_mul294);
  tcase_add_test(tc_core, test_mul295);
  tcase_add_test(tc_core, test_mul296);
  tcase_add_test(tc_core, test_mul297);
  tcase_add_test(tc_core, test_mul298);
  tcase_add_test(tc_core, test_mul299);
  tcase_add_test(tc_core, test_mul300);
  tcase_add_test(tc_core, test_mul301);
  tcase_add_test(tc_core, test_mul302);
  tcase_add_test(tc_core, test_mul303);
  tcase_add_test(tc_core, test_mul304);
  tcase_add_test(tc_core, test_mul305);
  tcase_add_test(tc_core, test_mul306);
  tcase_add_test(tc_core, test_mul307);
  tcase_add_test(tc_core, test_mul308);
  tcase_add_test(tc_core, test_mul309);
  tcase_add_test(tc_core, test_mul310);
  tcase_add_test(tc_core, test_mul311);
  tcase_add_test(tc_core, test_mul312);
  tcase_add_test(tc_core, test_mul313);
  tcase_add_test(tc_core, test_mul314);
  tcase_add_test(tc_core, test_mul315);
  tcase_add_test(tc_core, test_mul316);
  tcase_add_test(tc_core, test_mul317);
  tcase_add_test(tc_core, test_mul318);
  tcase_add_test(tc_core, test_mul319);
  tcase_add_test(tc_core, test_mul320);
  tcase_add_test(tc_core, test_mul321);
  tcase_add_test(tc_core, test_mul322);
  tcase_add_test(tc_core, test_mul323);
  tcase_add_test(tc_core, test_mul324);
  tcase_add_test(tc_core, test_mul325);
  tcase_add_test(tc_core, test_mul326);
  tcase_add_test(tc_core, test_mul327);
  tcase_add_test(tc_core, test_mul328);
  tcase_add_test(tc_core, test_mul329);
  tcase_add_test(tc_core, test_mul330);
  tcase_add_test(tc_core, test_mul331);
  tcase_add_test(tc_core, test_mul332);
  tcase_add_test(tc_core, test_mul333);
  tcase_add_test(tc_core, test_mul334);
  tcase_add_test(tc_core, test_mul335);
  tcase_add_test(tc_core, test_mul336);
  tcase_add_test(tc_core, test_mul337);
  tcase_add_test(tc_core, test_mul338);
  tcase_add_test(tc_core, test_mul339);
  tcase_add_test(tc_core, test_mul340);
  tcase_add_test(tc_core, test_mul341);
  tcase_add_test(tc_core, test_mul342);
  tcase_add_test(tc_core, test_mul343);
  tcase_add_test(tc_core, test_mul344);
  tcase_add_test(tc_core, test_mul345);
  tcase_add_test(tc_core, test_mul346);
  tcase_add_test(tc_core, test_mul347);
  tcase_add_test(tc_core, test_mul348);
  tcase_add_test(tc_core, test_mul349);
  tcase_add_test(tc_core, test_mul350);
  tcase_add_test(tc_core, test_mul351);
  tcase_add_test(tc_core, test_mul352);
  tcase_add_test(tc_core, test_mul353);
  tcase_add_test(tc_core, test_mul354);
  tcase_add_test(tc_core, test_mul355);
  tcase_add_test(tc_core, test_mul356);
  tcase_add_test(tc_core, test_mul357);
  tcase_add_test(tc_core, test_mul358);
  tcase_add_test(tc_core, test_mul359);
  tcase_add_test(tc_core, test_mul360);
  tcase_add_test(tc_core, test_mul361);
  tcase_add_test(tc_core, test_mul362);
  tcase_add_test(tc_core, test_mul363);
  tcase_add_test(tc_core, test_mul364);
  tcase_add_test(tc_core, test_mul365);
  tcase_add_test(tc_core, test_mul366);
  tcase_add_test(tc_core, test_mul367);
  tcase_add_test(tc_core, test_mul368);
  tcase_add_test(tc_core, test_mul369);
  tcase_add_test(tc_core, test_mul370);
  tcase_add_test(tc_core, test_mul371);
  tcase_add_test(tc_core, test_mul372);
  tcase_add_test(tc_core, test_mul373);
  tcase_add_test(tc_core, test_mul374);
  tcase_add_test(tc_core, test_mul375);
  tcase_add_test(tc_core, test_mul376);
  tcase_add_test(tc_core, test_mul377);
  tcase_add_test(tc_core, test_mul378);
  tcase_add_test(tc_core, test_mul379);
  tcase_add_test(tc_core, test_mul380);
  tcase_add_test(tc_core, test_mul381);
  tcase_add_test(tc_core, test_mul382);
  tcase_add_test(tc_core, test_mul383);
  tcase_add_test(tc_core, test_mul384);
  tcase_add_test(tc_core, test_mul385);
  tcase_add_test(tc_core, test_mul386);
  tcase_add_test(tc_core, test_mul387);
  tcase_add_test(tc_core, test_mul388);
  tcase_add_test(tc_core, test_mul389);
  tcase_add_test(tc_core, test_mul390);
  tcase_add_test(tc_core, test_mul391);
  tcase_add_test(tc_core, test_mul392);
  tcase_add_test(tc_core, test_mul393);
  tcase_add_test(tc_core, test_mul394);
  tcase_add_test(tc_core, test_mul395);
  tcase_add_test(tc_core, test_mul396);
  tcase_add_test(tc_core, test_mul397);
  tcase_add_test(tc_core, test_mul398);
  tcase_add_test(tc_core, test_mul399);
  tcase_add_test(tc_core, test_mul400);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_mul_fail1(s21_decimal decimal1, s21_decimal decimal2,
                    int code_check) {
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, code_check);
}

void test_mul(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}