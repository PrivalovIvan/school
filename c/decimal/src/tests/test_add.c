#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_decimal.h"

START_TEST(test_add1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add24) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 52818775009509558395695966890
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add28) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 52818775015658473085500828330
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add30) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422902307433130
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add32) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422903739088895
  s21_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add34) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337592112294570
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add36) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // 79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add40) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add42) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add44) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add46) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 79228162514264337593543950331
  s21_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add48) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add50) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add52) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add54) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // 79228106389283212384222373411
  s21_decimal check = {{0x3AC4E623, 0x756BD584, 0xFFFFF41D, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add56) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // 79228162514264337543839948913
  s21_decimal check = {{0x6D692071, 0xFFFFFFF4, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add58) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 79228162514264337592894706333
  s21_decimal check = {{0xD94D529D, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add60) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add61) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add62) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add63) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add64) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add65) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add66) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add67) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add68) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add69) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add70) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add71) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add72) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add73) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add74) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add75) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add76) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add77) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add78) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add79) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add80) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add81) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add82) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add83) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add84) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add85) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -52818775009509558395695966890
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add86) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add87) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -52818775015658473085500828330
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add88) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add89) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -79228162508115422902307433130
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add90) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add91) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -79228162508115422903739088895
  s21_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add92) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add93) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337592112294570
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add94) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add95) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // -79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add96) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add97) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add98) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add99) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add100) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add101) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add102) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add103) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add104) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add105) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -79228162514264337593543950331
  s21_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add106) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add107) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add108) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add109) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add110) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add111) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add112) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add113) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add114) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add115) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add116) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // -79228106389283212384222373411
  s21_decimal check = {{0x3AC4E623, 0x756BD584, 0xFFFFF41D, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add117) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add118) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -79228162514264337543839948913
  s21_decimal check = {{0x6D692071, 0xFFFFFFF4, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add119) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add120) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -79228162514264337592894706333
  s21_decimal check = {{0xD94D529D, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add121) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add122) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add123) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add124) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add125) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add126) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add127) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add128) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add129) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add130) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add131) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add132) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555299
  s21_decimal check = {{0x66666663, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add133) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add134) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add135) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add136) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add137) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add138) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add139) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add140) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add141) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add142) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 79228162514264337593543950332
  s21_decimal check = {{0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add143) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add144) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add145) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add146) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 52818775009509558395695966889
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add147) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add148) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 52818775015658473085500828329
  s21_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add149) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add150) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422902307433129
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add151) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add152) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422903739088894
  s21_decimal check = {{0xFFFFFFFE, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add153) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add154) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337592112294569
  s21_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add155) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add156) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // 79228162514264337593517540946
  s21_decimal check = {{0xFE6D0652, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add157) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add158) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add159) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add160) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add161) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add162) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 79228162514264337593543950326
  s21_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add163) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add164) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950326
  s21_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add165) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add166) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 79228162514264337593543950330
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add167) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add168) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add169) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add170) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add171) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add172) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add173) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add174) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add175) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // 79228106389283212384222373410
  s21_decimal check = {{0x3AC4E622, 0x756BD584, 0xFFFFF41D, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add176) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add177) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // 79228162514264337543839948912
  s21_decimal check = {{0x6D692070, 0xFFFFFFF4, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add178) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add179) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 79228162514264337592894706332
  s21_decimal check = {{0xD94D529C, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add180) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add181) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add182) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add183) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add184) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add185) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add186) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add187) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add188) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add189) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add190) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add191) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555299
  s21_decimal check = {{0x66666663, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add192) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add193) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add194) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add195) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add196) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add197) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add198) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add199) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add200) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add201) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -79228162514264337593543950332
  s21_decimal check = {{0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add202) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add203) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add204) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add205) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -52818775009509558395695966889
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add206) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add207) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -52818775015658473085500828329
  s21_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xAAAAAAAA, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add208) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add209) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -79228162508115422902307433129
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add210) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add211) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -79228162508115422903739088894
  s21_decimal check = {{0xFFFFFFFE, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add212) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add213) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337592112294569
  s21_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add214) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add215) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // -79228162514264337593517540946
  s21_decimal check = {{0xFE6D0652, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add216) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add217) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add218) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add219) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add220) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add221) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -79228162514264337593543950326
  s21_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add222) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add223) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950326
  s21_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add224) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add225) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -79228162514264337593543950330
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add226) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add227) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add228) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add229) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add230) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add231) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add232) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add233) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add234) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add235) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add236) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // -79228106389283212384222373410
  s21_decimal check = {{0x3AC4E622, 0x756BD584, 0xFFFFF41D, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add237) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add238) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -79228162514264337543839948912
  s21_decimal check = {{0x6D692070, 0xFFFFFFF4, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add239) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add240) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -79228162514264337592894706332
  s21_decimal check = {{0xD94D529C, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add241) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add242) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add243) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add244) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add245) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add246) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add247) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add248) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add249) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 15845632502852867518708790067
  s21_decimal check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add250) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add251) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 15845632502852867518708790068
  s21_decimal check = {{0x33333334, 0x33333333, 0x33333333, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add252) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -2
  s21_decimal check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add253) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add254) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395032
  s21_decimal check = {{0x99999998, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add255) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add256) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add257) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add258) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add259) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add260) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add261) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add262) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 7922816251426433759354395031.0
  s21_decimal check = {{0xFFFFFFE6, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add263) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add264) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 7922816251426433759354395032.0
  s21_decimal check = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add265) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 34332203756181212957202378478
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x6EEEEEEE, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add266) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -18486571253328345438493588412
  s21_decimal check = {{0xBBBBBBBC, 0xBBBBBBBB, 0x3BBBBBBB, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add267) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 34332203750032298267397517038
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x6EEEEEEE, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add268) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -18486571247179430748688726972
  s21_decimal check = {{0xBBBBBBBC, 0x66666666, 0x3BBBBBBB, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add269) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 7922816257575348450590912238
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add270) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 7922816245277519068117877828
  s21_decimal check = {{0x44444444, 0x44444444, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add271) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 7922816257575348449159256473
  s21_decimal check = {{0x99999999, 0xEEEEEEEE, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add272) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 7922816245277519069549533593
  s21_decimal check = {{0x99999999, 0x44444444, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add273) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 7922816251426433760786050798
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add274) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 7922816251426433757922739268
  s21_decimal check = {{0x44444444, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add275) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // 7922816251426433759380804421
  s21_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add276) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // 7922816251426433759327985645.3
  s21_decimal check = {{0xF0423F45, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add277) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add278) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 7922816251426433759327985645.5
  s21_decimal check = {{0xF0423F47, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add279) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add280) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759327985646
  s21_decimal check = {{0x98069FEE, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add281) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7922816251426433759354395041
  s21_decimal check = {{0x999999A1, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add282) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 7922816251426433759354395025.1
  s21_decimal check = {{0xFFFFFFAB, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add283) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395041
  s21_decimal check = {{0x999999A1, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add284) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395025
  s21_decimal check = {{0x99999991, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add285) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 7922816251426433759354395037
  s21_decimal check = {{0x9999999D, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add286) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 7922816251426433759354395029.4
  s21_decimal check = {{0xFFFFFFD6, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add287) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add288) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add289) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add290) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add291) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add292) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add293) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add294) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add295) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // 7922760126445308550032818109.0
  s21_decimal check = {{0x4BB0FD62, 0x9636572A, 0xFFFF8926, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add296) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // 7922872376407558968675971957
  s21_decimal check = {{0x5ED4B375, 0x242DC415, 0x1999A57C, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add297) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // 7922816251426433709650393610.6
  s21_decimal check = {{0x461B446A, 0xFFFFFF8C, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add298) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // 7922816251426433809058396455
  s21_decimal check = {{0x2C307927, 0x999999A5, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add299) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 7922816251426433758705151030.8
  s21_decimal check = {{0x7D053A24, 0xFFFFFFFE, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add300) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 7922816251426433760003639035
  s21_decimal check = {{0xC04C46FB, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add301) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add302) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add303) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add304) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add305) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add306) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add307) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add308) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add309) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add310) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -15845632502852867518708790067
  s21_decimal check = {{0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add311) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 2
  s21_decimal check = {{0x2, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add312) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -15845632502852867518708790068
  s21_decimal check = {{0x33333334, 0x33333333, 0x33333333, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add313) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395032
  s21_decimal check = {{0x99999998, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add314) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add315) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add316) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add317) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add318) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add319) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add320) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add321) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -7922816251426433759354395031.0
  s21_decimal check = {{0xFFFFFFE6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add322) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add323) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -7922816251426433759354395032.0
  s21_decimal check = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add324) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add325) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 18486571253328345438493588412
  s21_decimal check = {{0xBBBBBBBC, 0xBBBBBBBB, 0x3BBBBBBB, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add326) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -34332203756181212957202378478
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x6EEEEEEE, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add327) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 18486571247179430748688726972
  s21_decimal check = {{0xBBBBBBBC, 0x66666666, 0x3BBBBBBB, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add328) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -34332203750032298267397517038
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x6EEEEEEE, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add329) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -7922816245277519068117877828
  s21_decimal check = {{0x44444444, 0x44444444, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add330) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -7922816257575348450590912238
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add331) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -7922816245277519069549533593
  s21_decimal check = {{0x99999999, 0x44444444, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add332) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -7922816257575348449159256473
  s21_decimal check = {{0x99999999, 0xEEEEEEEE, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add333) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -7922816251426433757922739268
  s21_decimal check = {{0x44444444, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add334) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -7922816251426433760786050798
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add335) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // -7922816251426433759327985645.3
  s21_decimal check = {{0xF0423F45, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add336) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // -7922816251426433759380804421
  s21_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add337) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -7922816251426433759327985645.5
  s21_decimal check = {{0xF0423F47, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add338) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add339) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -7922816251426433759327985646
  s21_decimal check = {{0x98069FEE, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add340) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add341) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -7922816251426433759354395025.1
  s21_decimal check = {{0xFFFFFFAB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add342) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -7922816251426433759354395041
  s21_decimal check = {{0x999999A1, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add343) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395025
  s21_decimal check = {{0x99999991, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add344) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395041
  s21_decimal check = {{0x999999A1, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add345) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -7922816251426433759354395029.4
  s21_decimal check = {{0xFFFFFFD6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add346) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // -7922816251426433759354395037
  s21_decimal check = {{0x9999999D, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add347) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add348) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add349) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add350) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add351) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add352) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add353) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add354) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add355) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // -7922872376407558968675971957
  s21_decimal check = {{0x5ED4B375, 0x242DC415, 0x1999A57C, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add356) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // -7922760126445308550032818109.0
  s21_decimal check = {{0x4BB0FD62, 0x9636572A, 0xFFFF8926, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add357) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // -7922816251426433809058396455
  s21_decimal check = {{0x2C307927, 0x999999A5, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add358) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -7922816251426433709650393610.6
  s21_decimal check = {{0x461B446A, 0xFFFFFF8C, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add359) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -7922816251426433760003639035
  s21_decimal check = {{0xC04C46FB, 0x99999999, 0x19999999, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add360) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -7922816251426433758705151030.8
  s21_decimal check = {{0x7D053A24, 0xFFFFFFFE, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add361) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add362) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add363) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add364) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add365) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add366) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add367) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 15845632502852867518708790067
  s21_decimal check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add368) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add369) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 15845632502852867518708790068
  s21_decimal check = {{0x33333334, 0x33333333, 0x33333333, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add370) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add371) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 15845632502852867518708790068
  s21_decimal check = {{0x33333334, 0x33333333, 0x33333333, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add372) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -1.5
  s21_decimal check = {{0xF, 0x0, 0x0, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add373) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add374) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add375) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add376) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add377) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add378) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add379) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add380) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add381) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add382) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 7922816251426433759354395031.5
  s21_decimal check = {{0xFFFFFFEB, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add383) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add384) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add385) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 34332203756181212957202378478
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x6EEEEEEE, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add386) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -18486571253328345438493588412
  s21_decimal check = {{0xBBBBBBBC, 0xBBBBBBBB, 0x3BBBBBBB, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add387) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 34332203750032298267397517038
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x6EEEEEEE, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add388) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -18486571247179430748688726972
  s21_decimal check = {{0xBBBBBBBC, 0x66666666, 0x3BBBBBBB, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add389) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 7922816257575348450590912238
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add390) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 7922816245277519068117877828.5
  s21_decimal check = {{0xAAAAAAAD, 0xAAAAAAAA, 0xFFFFFFFC, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add391) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 7922816257575348449159256474
  s21_decimal check = {{0x9999999A, 0xEEEEEEEE, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add392) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 7922816245277519069549533593.5
  s21_decimal check = {{0xFFFFFFFF, 0xAAAAAAAD, 0xFFFFFFFC, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add393) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 7922816251426433760786050798
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add394) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 7922816251426433757922739268.5
  s21_decimal check = {{0xAAAAAAAD, 0xFFFFFFFC, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add395) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // 7922816251426433759380804421
  s21_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add396) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // 7922816251426433759327985645.8
  s21_decimal check = {{0xF0423F4A, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add397) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 7922816251426433759380804421
  s21_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add398) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 7922816251426433759327985646.0
  s21_decimal check = {{0xF0423F4C, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add399) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add400) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759327985646.5
  s21_decimal check = {{0xF0423F51, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_add(decimal1, decimal2, check);
}

Suite *add_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[45m-=S21_ADD=-\033[0m");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_add1);
  tcase_add_test(tc_core, test_add2);
  tcase_add_test(tc_core, test_add3);
  tcase_add_test(tc_core, test_add4);
  tcase_add_test(tc_core, test_add5);
  tcase_add_test(tc_core, test_add6);
  tcase_add_test(tc_core, test_add7);
  tcase_add_test(tc_core, test_add8);
  tcase_add_test(tc_core, test_add9);
  tcase_add_test(tc_core, test_add10);
  tcase_add_test(tc_core, test_add11);
  tcase_add_test(tc_core, test_add12);
  tcase_add_test(tc_core, test_add13);
  tcase_add_test(tc_core, test_add14);
  tcase_add_test(tc_core, test_add15);
  tcase_add_test(tc_core, test_add16);
  tcase_add_test(tc_core, test_add17);
  tcase_add_test(tc_core, test_add18);
  tcase_add_test(tc_core, test_add19);
  tcase_add_test(tc_core, test_add20);
  tcase_add_test(tc_core, test_add21);
  tcase_add_test(tc_core, test_add22);
  tcase_add_test(tc_core, test_add23);
  tcase_add_test(tc_core, test_add24);
  tcase_add_test(tc_core, test_add25);
  tcase_add_test(tc_core, test_add26);
  tcase_add_test(tc_core, test_add27);
  tcase_add_test(tc_core, test_add28);
  tcase_add_test(tc_core, test_add29);
  tcase_add_test(tc_core, test_add30);
  tcase_add_test(tc_core, test_add31);
  tcase_add_test(tc_core, test_add32);
  tcase_add_test(tc_core, test_add33);
  tcase_add_test(tc_core, test_add34);
  tcase_add_test(tc_core, test_add35);
  tcase_add_test(tc_core, test_add36);
  tcase_add_test(tc_core, test_add37);
  tcase_add_test(tc_core, test_add38);
  tcase_add_test(tc_core, test_add39);
  tcase_add_test(tc_core, test_add40);
  tcase_add_test(tc_core, test_add41);
  tcase_add_test(tc_core, test_add42);
  tcase_add_test(tc_core, test_add43);
  tcase_add_test(tc_core, test_add44);
  tcase_add_test(tc_core, test_add45);
  tcase_add_test(tc_core, test_add46);
  tcase_add_test(tc_core, test_add47);
  tcase_add_test(tc_core, test_add48);
  tcase_add_test(tc_core, test_add49);
  tcase_add_test(tc_core, test_add50);
  tcase_add_test(tc_core, test_add51);
  tcase_add_test(tc_core, test_add52);
  tcase_add_test(tc_core, test_add53);
  tcase_add_test(tc_core, test_add54);
  tcase_add_test(tc_core, test_add55);
  tcase_add_test(tc_core, test_add56);
  tcase_add_test(tc_core, test_add57);
  tcase_add_test(tc_core, test_add58);
  tcase_add_test(tc_core, test_add59);
  tcase_add_test(tc_core, test_add60);
  tcase_add_test(tc_core, test_add61);
  tcase_add_test(tc_core, test_add62);
  tcase_add_test(tc_core, test_add63);
  tcase_add_test(tc_core, test_add64);
  tcase_add_test(tc_core, test_add65);
  tcase_add_test(tc_core, test_add66);
  tcase_add_test(tc_core, test_add67);
  tcase_add_test(tc_core, test_add68);
  tcase_add_test(tc_core, test_add69);
  tcase_add_test(tc_core, test_add70);
  tcase_add_test(tc_core, test_add71);
  tcase_add_test(tc_core, test_add72);
  tcase_add_test(tc_core, test_add73);
  tcase_add_test(tc_core, test_add74);
  tcase_add_test(tc_core, test_add75);
  tcase_add_test(tc_core, test_add76);
  tcase_add_test(tc_core, test_add77);
  tcase_add_test(tc_core, test_add78);
  tcase_add_test(tc_core, test_add79);
  tcase_add_test(tc_core, test_add80);
  tcase_add_test(tc_core, test_add81);
  tcase_add_test(tc_core, test_add82);
  tcase_add_test(tc_core, test_add83);
  tcase_add_test(tc_core, test_add84);
  tcase_add_test(tc_core, test_add85);
  tcase_add_test(tc_core, test_add86);
  tcase_add_test(tc_core, test_add87);
  tcase_add_test(tc_core, test_add88);
  tcase_add_test(tc_core, test_add89);
  tcase_add_test(tc_core, test_add90);
  tcase_add_test(tc_core, test_add91);
  tcase_add_test(tc_core, test_add92);
  tcase_add_test(tc_core, test_add93);
  tcase_add_test(tc_core, test_add94);
  tcase_add_test(tc_core, test_add95);
  tcase_add_test(tc_core, test_add96);
  tcase_add_test(tc_core, test_add97);
  tcase_add_test(tc_core, test_add98);
  tcase_add_test(tc_core, test_add99);
  tcase_add_test(tc_core, test_add100);
  tcase_add_test(tc_core, test_add101);
  tcase_add_test(tc_core, test_add102);
  tcase_add_test(tc_core, test_add103);
  tcase_add_test(tc_core, test_add104);
  tcase_add_test(tc_core, test_add105);
  tcase_add_test(tc_core, test_add106);
  tcase_add_test(tc_core, test_add107);
  tcase_add_test(tc_core, test_add108);
  tcase_add_test(tc_core, test_add109);
  tcase_add_test(tc_core, test_add110);
  tcase_add_test(tc_core, test_add111);
  tcase_add_test(tc_core, test_add112);
  tcase_add_test(tc_core, test_add113);
  tcase_add_test(tc_core, test_add114);
  tcase_add_test(tc_core, test_add115);
  tcase_add_test(tc_core, test_add116);
  tcase_add_test(tc_core, test_add117);
  tcase_add_test(tc_core, test_add118);
  tcase_add_test(tc_core, test_add119);
  tcase_add_test(tc_core, test_add120);
  tcase_add_test(tc_core, test_add121);
  tcase_add_test(tc_core, test_add122);
  tcase_add_test(tc_core, test_add123);
  tcase_add_test(tc_core, test_add124);
  tcase_add_test(tc_core, test_add125);
  tcase_add_test(tc_core, test_add126);
  tcase_add_test(tc_core, test_add127);
  tcase_add_test(tc_core, test_add128);
  tcase_add_test(tc_core, test_add129);
  tcase_add_test(tc_core, test_add130);
  tcase_add_test(tc_core, test_add131);
  tcase_add_test(tc_core, test_add132);
  tcase_add_test(tc_core, test_add133);
  tcase_add_test(tc_core, test_add134);
  tcase_add_test(tc_core, test_add135);
  tcase_add_test(tc_core, test_add136);
  tcase_add_test(tc_core, test_add137);
  tcase_add_test(tc_core, test_add138);
  tcase_add_test(tc_core, test_add139);
  tcase_add_test(tc_core, test_add140);
  tcase_add_test(tc_core, test_add141);
  tcase_add_test(tc_core, test_add142);
  tcase_add_test(tc_core, test_add143);
  tcase_add_test(tc_core, test_add144);
  tcase_add_test(tc_core, test_add145);
  tcase_add_test(tc_core, test_add146);
  tcase_add_test(tc_core, test_add147);
  tcase_add_test(tc_core, test_add148);
  tcase_add_test(tc_core, test_add149);
  tcase_add_test(tc_core, test_add150);
  tcase_add_test(tc_core, test_add151);
  tcase_add_test(tc_core, test_add152);
  tcase_add_test(tc_core, test_add153);
  tcase_add_test(tc_core, test_add154);
  tcase_add_test(tc_core, test_add155);
  tcase_add_test(tc_core, test_add156);
  tcase_add_test(tc_core, test_add157);
  tcase_add_test(tc_core, test_add158);
  tcase_add_test(tc_core, test_add159);
  tcase_add_test(tc_core, test_add160);
  tcase_add_test(tc_core, test_add161);
  tcase_add_test(tc_core, test_add162);
  tcase_add_test(tc_core, test_add163);
  tcase_add_test(tc_core, test_add164);
  tcase_add_test(tc_core, test_add165);
  tcase_add_test(tc_core, test_add166);
  tcase_add_test(tc_core, test_add167);
  tcase_add_test(tc_core, test_add168);
  tcase_add_test(tc_core, test_add169);
  tcase_add_test(tc_core, test_add170);
  tcase_add_test(tc_core, test_add171);
  tcase_add_test(tc_core, test_add172);
  tcase_add_test(tc_core, test_add173);
  tcase_add_test(tc_core, test_add174);
  tcase_add_test(tc_core, test_add175);
  tcase_add_test(tc_core, test_add176);
  tcase_add_test(tc_core, test_add177);
  tcase_add_test(tc_core, test_add178);
  tcase_add_test(tc_core, test_add179);
  tcase_add_test(tc_core, test_add180);
  tcase_add_test(tc_core, test_add181);
  tcase_add_test(tc_core, test_add182);
  tcase_add_test(tc_core, test_add183);
  tcase_add_test(tc_core, test_add184);
  tcase_add_test(tc_core, test_add185);
  tcase_add_test(tc_core, test_add186);
  tcase_add_test(tc_core, test_add187);
  tcase_add_test(tc_core, test_add188);
  tcase_add_test(tc_core, test_add189);
  tcase_add_test(tc_core, test_add190);
  tcase_add_test(tc_core, test_add191);
  tcase_add_test(tc_core, test_add192);
  tcase_add_test(tc_core, test_add193);
  tcase_add_test(tc_core, test_add194);
  tcase_add_test(tc_core, test_add195);
  tcase_add_test(tc_core, test_add196);
  tcase_add_test(tc_core, test_add197);
  tcase_add_test(tc_core, test_add198);
  tcase_add_test(tc_core, test_add199);
  tcase_add_test(tc_core, test_add200);
  tcase_add_test(tc_core, test_add201);
  tcase_add_test(tc_core, test_add202);
  tcase_add_test(tc_core, test_add203);
  tcase_add_test(tc_core, test_add204);
  tcase_add_test(tc_core, test_add205);
  tcase_add_test(tc_core, test_add206);
  tcase_add_test(tc_core, test_add207);
  tcase_add_test(tc_core, test_add208);
  tcase_add_test(tc_core, test_add209);
  tcase_add_test(tc_core, test_add210);
  tcase_add_test(tc_core, test_add211);
  tcase_add_test(tc_core, test_add212);
  tcase_add_test(tc_core, test_add213);
  tcase_add_test(tc_core, test_add214);
  tcase_add_test(tc_core, test_add215);
  tcase_add_test(tc_core, test_add216);
  tcase_add_test(tc_core, test_add217);
  tcase_add_test(tc_core, test_add218);
  tcase_add_test(tc_core, test_add219);
  tcase_add_test(tc_core, test_add220);
  tcase_add_test(tc_core, test_add221);
  tcase_add_test(tc_core, test_add222);
  tcase_add_test(tc_core, test_add223);
  tcase_add_test(tc_core, test_add224);
  tcase_add_test(tc_core, test_add225);
  tcase_add_test(tc_core, test_add226);
  tcase_add_test(tc_core, test_add227);
  tcase_add_test(tc_core, test_add228);
  tcase_add_test(tc_core, test_add229);
  tcase_add_test(tc_core, test_add230);
  tcase_add_test(tc_core, test_add231);
  tcase_add_test(tc_core, test_add232);
  tcase_add_test(tc_core, test_add233);
  tcase_add_test(tc_core, test_add234);
  tcase_add_test(tc_core, test_add235);
  tcase_add_test(tc_core, test_add236);
  tcase_add_test(tc_core, test_add237);
  tcase_add_test(tc_core, test_add238);
  tcase_add_test(tc_core, test_add239);
  tcase_add_test(tc_core, test_add240);
  tcase_add_test(tc_core, test_add241);
  tcase_add_test(tc_core, test_add242);
  tcase_add_test(tc_core, test_add243);
  tcase_add_test(tc_core, test_add244);
  tcase_add_test(tc_core, test_add245);
  tcase_add_test(tc_core, test_add246);
  tcase_add_test(tc_core, test_add247);
  tcase_add_test(tc_core, test_add248);
  tcase_add_test(tc_core, test_add249);
  tcase_add_test(tc_core, test_add250);
  tcase_add_test(tc_core, test_add251);
  tcase_add_test(tc_core, test_add252);
  tcase_add_test(tc_core, test_add253);
  tcase_add_test(tc_core, test_add254);
  tcase_add_test(tc_core, test_add255);
  tcase_add_test(tc_core, test_add256);
  tcase_add_test(tc_core, test_add257);
  tcase_add_test(tc_core, test_add258);
  tcase_add_test(tc_core, test_add259);
  tcase_add_test(tc_core, test_add260);
  tcase_add_test(tc_core, test_add261);
  tcase_add_test(tc_core, test_add262);
  tcase_add_test(tc_core, test_add263);
  tcase_add_test(tc_core, test_add264);
  tcase_add_test(tc_core, test_add265);
  tcase_add_test(tc_core, test_add266);
  tcase_add_test(tc_core, test_add267);
  tcase_add_test(tc_core, test_add268);
  tcase_add_test(tc_core, test_add269);
  tcase_add_test(tc_core, test_add270);
  tcase_add_test(tc_core, test_add271);
  tcase_add_test(tc_core, test_add272);
  tcase_add_test(tc_core, test_add273);
  tcase_add_test(tc_core, test_add274);
  tcase_add_test(tc_core, test_add275);
  tcase_add_test(tc_core, test_add276);
  tcase_add_test(tc_core, test_add277);
  tcase_add_test(tc_core, test_add278);
  tcase_add_test(tc_core, test_add279);
  tcase_add_test(tc_core, test_add280);
  tcase_add_test(tc_core, test_add281);
  tcase_add_test(tc_core, test_add282);
  tcase_add_test(tc_core, test_add283);
  tcase_add_test(tc_core, test_add284);
  tcase_add_test(tc_core, test_add285);
  tcase_add_test(tc_core, test_add286);
  tcase_add_test(tc_core, test_add287);
  tcase_add_test(tc_core, test_add288);
  tcase_add_test(tc_core, test_add289);
  tcase_add_test(tc_core, test_add290);
  tcase_add_test(tc_core, test_add291);
  tcase_add_test(tc_core, test_add292);
  tcase_add_test(tc_core, test_add293);
  tcase_add_test(tc_core, test_add294);
  tcase_add_test(tc_core, test_add295);
  tcase_add_test(tc_core, test_add296);
  tcase_add_test(tc_core, test_add297);
  tcase_add_test(tc_core, test_add298);
  tcase_add_test(tc_core, test_add299);
  tcase_add_test(tc_core, test_add300);
  tcase_add_test(tc_core, test_add301);
  tcase_add_test(tc_core, test_add302);
  tcase_add_test(tc_core, test_add303);
  tcase_add_test(tc_core, test_add304);
  tcase_add_test(tc_core, test_add305);
  tcase_add_test(tc_core, test_add306);
  tcase_add_test(tc_core, test_add307);
  tcase_add_test(tc_core, test_add308);
  tcase_add_test(tc_core, test_add309);
  tcase_add_test(tc_core, test_add310);
  tcase_add_test(tc_core, test_add311);
  tcase_add_test(tc_core, test_add312);
  tcase_add_test(tc_core, test_add313);
  tcase_add_test(tc_core, test_add314);
  tcase_add_test(tc_core, test_add315);
  tcase_add_test(tc_core, test_add316);
  tcase_add_test(tc_core, test_add317);
  tcase_add_test(tc_core, test_add318);
  tcase_add_test(tc_core, test_add319);
  tcase_add_test(tc_core, test_add320);
  tcase_add_test(tc_core, test_add321);
  tcase_add_test(tc_core, test_add322);
  tcase_add_test(tc_core, test_add323);
  tcase_add_test(tc_core, test_add324);
  tcase_add_test(tc_core, test_add325);
  tcase_add_test(tc_core, test_add326);
  tcase_add_test(tc_core, test_add327);
  tcase_add_test(tc_core, test_add328);
  tcase_add_test(tc_core, test_add329);
  tcase_add_test(tc_core, test_add330);
  tcase_add_test(tc_core, test_add331);
  tcase_add_test(tc_core, test_add332);
  tcase_add_test(tc_core, test_add333);
  tcase_add_test(tc_core, test_add334);
  tcase_add_test(tc_core, test_add335);
  tcase_add_test(tc_core, test_add336);
  tcase_add_test(tc_core, test_add337);
  tcase_add_test(tc_core, test_add338);
  tcase_add_test(tc_core, test_add339);
  tcase_add_test(tc_core, test_add340);
  tcase_add_test(tc_core, test_add341);
  tcase_add_test(tc_core, test_add342);
  tcase_add_test(tc_core, test_add343);
  tcase_add_test(tc_core, test_add344);
  tcase_add_test(tc_core, test_add345);
  tcase_add_test(tc_core, test_add346);
  tcase_add_test(tc_core, test_add347);
  tcase_add_test(tc_core, test_add348);
  tcase_add_test(tc_core, test_add349);
  tcase_add_test(tc_core, test_add350);
  tcase_add_test(tc_core, test_add351);
  tcase_add_test(tc_core, test_add352);
  tcase_add_test(tc_core, test_add353);
  tcase_add_test(tc_core, test_add354);
  tcase_add_test(tc_core, test_add355);
  tcase_add_test(tc_core, test_add356);
  tcase_add_test(tc_core, test_add357);
  tcase_add_test(tc_core, test_add358);
  tcase_add_test(tc_core, test_add359);
  tcase_add_test(tc_core, test_add360);
  tcase_add_test(tc_core, test_add361);
  tcase_add_test(tc_core, test_add362);
  tcase_add_test(tc_core, test_add363);
  tcase_add_test(tc_core, test_add364);
  tcase_add_test(tc_core, test_add365);
  tcase_add_test(tc_core, test_add366);
  tcase_add_test(tc_core, test_add367);
  tcase_add_test(tc_core, test_add368);
  tcase_add_test(tc_core, test_add369);
  tcase_add_test(tc_core, test_add370);
  tcase_add_test(tc_core, test_add371);
  tcase_add_test(tc_core, test_add372);
  tcase_add_test(tc_core, test_add373);
  tcase_add_test(tc_core, test_add374);
  tcase_add_test(tc_core, test_add375);
  tcase_add_test(tc_core, test_add376);
  tcase_add_test(tc_core, test_add377);
  tcase_add_test(tc_core, test_add378);
  tcase_add_test(tc_core, test_add379);
  tcase_add_test(tc_core, test_add380);
  tcase_add_test(tc_core, test_add381);
  tcase_add_test(tc_core, test_add382);
  tcase_add_test(tc_core, test_add383);
  tcase_add_test(tc_core, test_add384);
  tcase_add_test(tc_core, test_add385);
  tcase_add_test(tc_core, test_add386);
  tcase_add_test(tc_core, test_add387);
  tcase_add_test(tc_core, test_add388);
  tcase_add_test(tc_core, test_add389);
  tcase_add_test(tc_core, test_add390);
  tcase_add_test(tc_core, test_add391);
  tcase_add_test(tc_core, test_add392);
  tcase_add_test(tc_core, test_add393);
  tcase_add_test(tc_core, test_add394);
  tcase_add_test(tc_core, test_add395);
  tcase_add_test(tc_core, test_add396);
  tcase_add_test(tc_core, test_add397);
  tcase_add_test(tc_core, test_add398);
  tcase_add_test(tc_core, test_add399);
  tcase_add_test(tc_core, test_add400);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

void test_add_fail(s21_decimal decimal1, s21_decimal decimal2, int check) {
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, check);
}