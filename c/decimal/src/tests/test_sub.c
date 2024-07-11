#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_decimal.h"

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

START_TEST(test_sub1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub24) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 52818775009509558395695966890
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 52818775015658473085500828330
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub28) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 79228162508115422902307433130
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub30) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 79228162508115422903739088895
  s21_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub32) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337592112294570
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub34) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub36) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub40) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub42) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub44) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 79228162514264337593543950331
  s21_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub46) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub48) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub50) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub52) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub54) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 79228162514264337593543949689
  s21_decimal check = {{0xFFFFFD79, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub56) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub58) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // 79228162514240090656400479551
  s21_decimal check = {{0x4AC153F, 0xFFA9DB8A, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // 18994429982494779296567793531
  s21_decimal check = {{0xB3DC177B, 0x9B738FD3, 0x3D5FD300, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub60) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub61) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub62) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub63) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub64) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub65) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub66) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub67) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub68) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub69) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub70) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub71) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub72) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub73) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub74) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub75) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub76) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub77) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub78) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub79) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub80) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub81) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub82) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub83) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub84) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub85) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub86) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -52818775009509558395695966890
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub87) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub88) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -52818775015658473085500828330
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub89) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub90) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -79228162508115422902307433130
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub91) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub92) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -79228162508115422903739088895
  s21_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub93) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub94) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -79228162514264337592112294570
  s21_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub95) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub96) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // -79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub97) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub98) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub99) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub100) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub101) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub102) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub103) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub104) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub105) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub106) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // -79228162514264337593543950331
  s21_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub107) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub108) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub109) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub110) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub111) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub112) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub113) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub114) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub115) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub116) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -79228162514264337593543949689
  s21_decimal check = {{0xFFFFFD79, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub117) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // -79228162514240090656400479551
  s21_decimal check = {{0x4AC153F, 0xFFA9DB8A, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub118) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub119) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub120) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // -18994429982494779296567793531
  s21_decimal check = {{0xB3DC177B, 0x9B738FD3, 0x3D5FD300, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub121) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub122) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub123) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub124) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub125) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub126) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub127) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub128) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub129) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub130) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub131) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555299
  s21_decimal check = {{0x66666663, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub132) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub133) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub134) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub135) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub136) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub137) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub138) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub139) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub140) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub141) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 79228162514264337593543950332
  s21_decimal check = {{0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub142) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub143) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub144) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub145) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 52818775009509558395695966889
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub146) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub147) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 52818775015658473085500828329
  s21_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub148) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub149) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 79228162508115422902307433129
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub150) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub151) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 79228162508115422903739088894
  s21_decimal check = {{0xFFFFFFFE, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub152) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub153) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337592112294569
  s21_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub154) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub155) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 79228162514264337593517540946
  s21_decimal check = {{0xFE6D0652, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub156) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub157) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub158) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub159) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub160) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub161) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 79228162514264337593543950326
  s21_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub162) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub163) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950326
  s21_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub164) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub165) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 79228162514264337593543950330
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub166) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub167) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub168) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub169) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub170) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub171) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub172) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub173) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub174) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub175) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 79228162514264337593543949688
  s21_decimal check = {{0xFFFFFD78, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub176) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub177) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub178) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // 79228162514240090656400479550
  s21_decimal check = {{0x4AC153E, 0xFFA9DB8A, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub179) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // 18994429982494779296567793530
  s21_decimal check = {{0xB3DC177A, 0x9B738FD3, 0x3D5FD300, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub180) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub181) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub182) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub183) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub184) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub185) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub186) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub187) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub188) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub189) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub190) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub191) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub192) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555299
  s21_decimal check = {{0x66666663, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub193) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub194) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub195) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub196) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub197) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub198) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub199) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub200) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub201) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub202) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -79228162514264337593543950332
  s21_decimal check = {{0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub203) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub204) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub205) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub206) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -52818775009509558395695966889
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub207) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub208) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -52818775015658473085500828329
  s21_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xAAAAAAAA, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub209) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub210) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -79228162508115422902307433129
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub211) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub212) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -79228162508115422903739088894
  s21_decimal check = {{0xFFFFFFFE, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub213) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub214) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -79228162514264337592112294569
  s21_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub215) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub216) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // -79228162514264337593517540946
  s21_decimal check = {{0xFE6D0652, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub217) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub218) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub219) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub220) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub221) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub222) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -79228162514264337593543950326
  s21_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub223) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub224) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950326
  s21_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub225) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub226) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // -79228162514264337593543950330
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub227) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub228) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub229) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub230) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub231) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub232) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub233) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub234) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub235) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub236) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -79228162514264337593543949688
  s21_decimal check = {{0xFFFFFD78, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub237) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // -79228162514240090656400479550
  s21_decimal check = {{0x4AC153E, 0xFFA9DB8A, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub238) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub239) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub240) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // -18994429982494779296567793530
  s21_decimal check = {{0xB3DC177A, 0x9B738FD3, 0x3D5FD300, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub241) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub242) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub243) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub244) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub245) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub246) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub247) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub248) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub249) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub250) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 15845632502852867518708790067
  s21_decimal check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub251) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -2
  s21_decimal check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub252) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 15845632502852867518708790068
  s21_decimal check = {{0x33333334, 0x33333333, 0x33333333, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub253) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395032
  s21_decimal check = {{0x99999998, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub254) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub255) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub256) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub257) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub258) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub259) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub260) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub261) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 7922816251426433759354395031.0
  s21_decimal check = {{0xFFFFFFE6, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub262) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub263) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 7922816251426433759354395032.0
  s21_decimal check = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub264) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub265) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -18486571253328345438493588412
  s21_decimal check = {{0xBBBBBBBC, 0xBBBBBBBB, 0x3BBBBBBB, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub266) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 34332203756181212957202378478
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x6EEEEEEE, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub267) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -18486571247179430748688726972
  s21_decimal check = {{0xBBBBBBBC, 0x66666666, 0x3BBBBBBB, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub268) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 34332203750032298267397517038
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x6EEEEEEE, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub269) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 7922816245277519068117877828
  s21_decimal check = {{0x44444444, 0x44444444, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub270) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 7922816257575348450590912238
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub271) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 7922816245277519069549533593
  s21_decimal check = {{0x99999999, 0x44444444, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub272) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 7922816257575348449159256473
  s21_decimal check = {{0x99999999, 0xEEEEEEEE, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub273) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 7922816251426433757922739268
  s21_decimal check = {{0x44444444, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub274) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 7922816251426433760786050798
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub275) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 7922816251426433759327985645.5
  s21_decimal check = {{0xF0423F47, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub276) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // 7922816251426433759380804421
  s21_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub277) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 7922816251426433759327985645.5
  s21_decimal check = {{0xF0423F47, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub278) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub279) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 7922816251426433759327985646
  s21_decimal check = {{0x98069FEE, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub280) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub281) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7922816251426433759354395025.1
  s21_decimal check = {{0xFFFFFFAB, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub282) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 7922816251426433759354395041
  s21_decimal check = {{0x999999A1, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub283) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395025
  s21_decimal check = {{0x99999991, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub284) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395041
  s21_decimal check = {{0x999999A1, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub285) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 7922816251426433759354395029.4
  s21_decimal check = {{0xFFFFFFD6, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub286) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 7922816251426433759354395037
  s21_decimal check = {{0x9999999D, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub287) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub288) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub289) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub290) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub291) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub292) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub293) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub294) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub295) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 7922816251426433759354394386.7
  s21_decimal check = {{0xFFFFE6BB, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub296) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 7922816251426433759354395679
  s21_decimal check = {{0x99999C1F, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub297) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // 7922816251450680696497865817
  s21_decimal check = {{0x94ED8459, 0x99EFBE0F, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub298) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // 7922816251402186822210924249.2
  s21_decimal check = {{0x2EB8D47C, 0xFCA29364, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub299) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // -52310916280343124537621761771
  s21_decimal check = {{0xB28A4EEB, 0xCAF2D692, 0xA9069365, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub300) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // 68156548783195992056330551837
  s21_decimal check = {{0xE5BD821D, 0xFE2609C5, 0xDC39C698, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub301) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub302) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub303) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub304) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub305) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub306) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub307) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub308) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub309) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -15845632502852867518708790067
  s21_decimal check = {{0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub310) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub311) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -15845632502852867518708790068
  s21_decimal check = {{0x33333334, 0x33333333, 0x33333333, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub312) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 2
  s21_decimal check = {{0x2, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub313) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub314) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395032
  s21_decimal check = {{0x99999998, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub315) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub316) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub317) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub318) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub319) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub320) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub321) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub322) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -7922816251426433759354395031.0
  s21_decimal check = {{0xFFFFFFE6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub323) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub324) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -7922816251426433759354395032.0
  s21_decimal check = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub325) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -34332203756181212957202378478
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x6EEEEEEE, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub326) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 18486571253328345438493588412
  s21_decimal check = {{0xBBBBBBBC, 0xBBBBBBBB, 0x3BBBBBBB, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub327) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -34332203750032298267397517038
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x6EEEEEEE, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub328) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 18486571247179430748688726972
  s21_decimal check = {{0xBBBBBBBC, 0x66666666, 0x3BBBBBBB, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub329) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -7922816257575348450590912238
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub330) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -7922816245277519068117877828
  s21_decimal check = {{0x44444444, 0x44444444, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub331) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -7922816257575348449159256473
  s21_decimal check = {{0x99999999, 0xEEEEEEEE, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub332) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -7922816245277519069549533593
  s21_decimal check = {{0x99999999, 0x44444444, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub333) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -7922816251426433760786050798
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub334) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -7922816251426433757922739268
  s21_decimal check = {{0x44444444, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub335) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -7922816251426433759380804421
  s21_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub336) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // -7922816251426433759327985645.5
  s21_decimal check = {{0xF0423F47, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub337) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub338) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -7922816251426433759327985645.5
  s21_decimal check = {{0xF0423F47, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub339) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub340) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759327985646
  s21_decimal check = {{0x98069FEE, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub341) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -7922816251426433759354395041
  s21_decimal check = {{0x999999A1, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub342) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -7922816251426433759354395025.1
  s21_decimal check = {{0xFFFFFFAB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub343) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395041
  s21_decimal check = {{0x999999A1, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub344) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395025
  s21_decimal check = {{0x99999991, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub345) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -7922816251426433759354395037
  s21_decimal check = {{0x9999999D, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub346) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // -7922816251426433759354395029.4
  s21_decimal check = {{0xFFFFFFD6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub347) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub348) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub349) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub350) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub351) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub352) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub353) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub354) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub355) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // -7922816251426433759354395679
  s21_decimal check = {{0x99999C1F, 0x99999999, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub356) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -7922816251426433759354394386.7
  s21_decimal check = {{0xFFFFE6BB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub357) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // -7922816251402186822210924249.2
  s21_decimal check = {{0x2EB8D47C, 0xFCA29364, 0xFFFFFFFF, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub358) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // -7922816251450680696497865817
  s21_decimal check = {{0x94ED8459, 0x99EFBE0F, 0x19999999, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub359) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // -68156548783195992056330551837
  s21_decimal check = {{0xE5BD821D, 0xFE2609C5, 0xDC39C698, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub360) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // 52310916280343124537621761771
  s21_decimal check = {{0xB28A4EEB, 0xCAF2D692, 0xA9069365, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub361) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub362) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub363) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub364) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub365) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub366) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 15845632502852867518708790066
  s21_decimal check = {{0x33333332, 0x33333333, 0x33333333, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub367) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub368) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 15845632502852867518708790067
  s21_decimal check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub369) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub370) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 15845632502852867518708790068
  s21_decimal check = {{0x33333334, 0x33333333, 0x33333333, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub371) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -1.5
  s21_decimal check = {{0xF, 0x0, 0x0, 0x80010000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub372) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 15845632502852867518708790068
  s21_decimal check = {{0x33333334, 0x33333333, 0x33333333, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub373) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub374) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub375) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub376) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub377) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub378) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub379) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub380) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub381) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 7922816251426433759354395031.5
  s21_decimal check = {{0xFFFFFFEB, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub382) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub383) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 7922816251426433759354395032.5
  s21_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub384) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub385) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -18486571253328345438493588412
  s21_decimal check = {{0xBBBBBBBC, 0xBBBBBBBB, 0x3BBBBBBB, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub386) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 34332203756181212957202378478
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x6EEEEEEE, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub387) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -18486571247179430748688726972
  s21_decimal check = {{0xBBBBBBBC, 0x66666666, 0x3BBBBBBB, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub388) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 34332203750032298267397517038
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x6EEEEEEE, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub389) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 7922816245277519068117877828.5
  s21_decimal check = {{0xAAAAAAAD, 0xAAAAAAAA, 0xFFFFFFFC, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub390) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 7922816257575348450590912238
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub391) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 7922816245277519069549533593.5
  s21_decimal check = {{0xFFFFFFFF, 0xAAAAAAAD, 0xFFFFFFFC, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub392) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 7922816257575348449159256474
  s21_decimal check = {{0x9999999A, 0xEEEEEEEE, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub393) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 7922816251426433757922739268.5
  s21_decimal check = {{0xAAAAAAAD, 0xFFFFFFFC, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub394) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 7922816251426433760786050798
  s21_decimal check = {{0xEEEEEEEE, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub395) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 7922816251426433759327985646.0
  s21_decimal check = {{0xF0423F4C, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub396) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // 7922816251426433759380804421
  s21_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub397) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 7922816251426433759327985646.0
  s21_decimal check = {{0xF0423F4C, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub398) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 7922816251426433759380804421
  s21_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub399) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 7922816251426433759327985646.5
  s21_decimal check = {{0xF0423F51, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub400) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759380804420
  s21_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x0}};

  test_sub(decimal1, decimal2, check);
}

Suite *sub_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[45m-=S21_SUB=-\033[0m");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_sub1);
  tcase_add_test(tc_core, test_sub2);
  tcase_add_test(tc_core, test_sub3);
  tcase_add_test(tc_core, test_sub4);
  tcase_add_test(tc_core, test_sub5);
  tcase_add_test(tc_core, test_sub6);
  tcase_add_test(tc_core, test_sub7);
  tcase_add_test(tc_core, test_sub8);
  tcase_add_test(tc_core, test_sub9);
  tcase_add_test(tc_core, test_sub10);
  tcase_add_test(tc_core, test_sub11);
  tcase_add_test(tc_core, test_sub12);
  tcase_add_test(tc_core, test_sub13);
  tcase_add_test(tc_core, test_sub14);
  tcase_add_test(tc_core, test_sub15);
  tcase_add_test(tc_core, test_sub16);
  tcase_add_test(tc_core, test_sub17);
  tcase_add_test(tc_core, test_sub18);
  tcase_add_test(tc_core, test_sub19);
  tcase_add_test(tc_core, test_sub20);
  tcase_add_test(tc_core, test_sub21);
  tcase_add_test(tc_core, test_sub22);
  tcase_add_test(tc_core, test_sub23);
  tcase_add_test(tc_core, test_sub24);
  tcase_add_test(tc_core, test_sub25);
  tcase_add_test(tc_core, test_sub26);
  tcase_add_test(tc_core, test_sub27);
  tcase_add_test(tc_core, test_sub28);
  tcase_add_test(tc_core, test_sub29);
  tcase_add_test(tc_core, test_sub30);
  tcase_add_test(tc_core, test_sub31);
  tcase_add_test(tc_core, test_sub32);
  tcase_add_test(tc_core, test_sub33);
  tcase_add_test(tc_core, test_sub34);
  tcase_add_test(tc_core, test_sub35);
  tcase_add_test(tc_core, test_sub36);
  tcase_add_test(tc_core, test_sub37);
  tcase_add_test(tc_core, test_sub38);
  tcase_add_test(tc_core, test_sub39);
  tcase_add_test(tc_core, test_sub40);
  tcase_add_test(tc_core, test_sub41);
  tcase_add_test(tc_core, test_sub42);
  tcase_add_test(tc_core, test_sub43);
  tcase_add_test(tc_core, test_sub44);
  tcase_add_test(tc_core, test_sub45);
  tcase_add_test(tc_core, test_sub46);
  tcase_add_test(tc_core, test_sub47);
  tcase_add_test(tc_core, test_sub48);
  tcase_add_test(tc_core, test_sub49);
  tcase_add_test(tc_core, test_sub50);
  tcase_add_test(tc_core, test_sub51);
  tcase_add_test(tc_core, test_sub52);
  tcase_add_test(tc_core, test_sub53);
  tcase_add_test(tc_core, test_sub54);
  tcase_add_test(tc_core, test_sub55);
  tcase_add_test(tc_core, test_sub56);
  tcase_add_test(tc_core, test_sub57);
  tcase_add_test(tc_core, test_sub58);
  tcase_add_test(tc_core, test_sub59);
  tcase_add_test(tc_core, test_sub60);
  tcase_add_test(tc_core, test_sub61);
  tcase_add_test(tc_core, test_sub62);
  tcase_add_test(tc_core, test_sub63);
  tcase_add_test(tc_core, test_sub64);
  tcase_add_test(tc_core, test_sub65);
  tcase_add_test(tc_core, test_sub66);
  tcase_add_test(tc_core, test_sub67);
  tcase_add_test(tc_core, test_sub68);
  tcase_add_test(tc_core, test_sub69);
  tcase_add_test(tc_core, test_sub70);
  tcase_add_test(tc_core, test_sub71);
  tcase_add_test(tc_core, test_sub72);
  tcase_add_test(tc_core, test_sub73);
  tcase_add_test(tc_core, test_sub74);
  tcase_add_test(tc_core, test_sub75);
  tcase_add_test(tc_core, test_sub76);
  tcase_add_test(tc_core, test_sub77);
  tcase_add_test(tc_core, test_sub78);
  tcase_add_test(tc_core, test_sub79);
  tcase_add_test(tc_core, test_sub80);
  tcase_add_test(tc_core, test_sub81);
  tcase_add_test(tc_core, test_sub82);
  tcase_add_test(tc_core, test_sub83);
  tcase_add_test(tc_core, test_sub84);
  tcase_add_test(tc_core, test_sub85);
  tcase_add_test(tc_core, test_sub86);
  tcase_add_test(tc_core, test_sub87);
  tcase_add_test(tc_core, test_sub88);
  tcase_add_test(tc_core, test_sub89);
  tcase_add_test(tc_core, test_sub90);
  tcase_add_test(tc_core, test_sub91);
  tcase_add_test(tc_core, test_sub92);
  tcase_add_test(tc_core, test_sub93);
  tcase_add_test(tc_core, test_sub94);
  tcase_add_test(tc_core, test_sub95);
  tcase_add_test(tc_core, test_sub96);
  tcase_add_test(tc_core, test_sub97);
  tcase_add_test(tc_core, test_sub98);
  tcase_add_test(tc_core, test_sub99);
  tcase_add_test(tc_core, test_sub100);
  tcase_add_test(tc_core, test_sub101);
  tcase_add_test(tc_core, test_sub102);
  tcase_add_test(tc_core, test_sub103);
  tcase_add_test(tc_core, test_sub104);
  tcase_add_test(tc_core, test_sub105);
  tcase_add_test(tc_core, test_sub106);
  tcase_add_test(tc_core, test_sub107);
  tcase_add_test(tc_core, test_sub108);
  tcase_add_test(tc_core, test_sub109);
  tcase_add_test(tc_core, test_sub110);
  tcase_add_test(tc_core, test_sub111);
  tcase_add_test(tc_core, test_sub112);
  tcase_add_test(tc_core, test_sub113);
  tcase_add_test(tc_core, test_sub114);
  tcase_add_test(tc_core, test_sub115);
  tcase_add_test(tc_core, test_sub116);
  tcase_add_test(tc_core, test_sub117);
  tcase_add_test(tc_core, test_sub118);
  tcase_add_test(tc_core, test_sub119);
  tcase_add_test(tc_core, test_sub120);
  tcase_add_test(tc_core, test_sub121);
  tcase_add_test(tc_core, test_sub122);
  tcase_add_test(tc_core, test_sub123);
  tcase_add_test(tc_core, test_sub124);
  tcase_add_test(tc_core, test_sub125);
  tcase_add_test(tc_core, test_sub126);
  tcase_add_test(tc_core, test_sub127);
  tcase_add_test(tc_core, test_sub128);
  tcase_add_test(tc_core, test_sub129);
  tcase_add_test(tc_core, test_sub130);
  tcase_add_test(tc_core, test_sub131);
  tcase_add_test(tc_core, test_sub132);
  tcase_add_test(tc_core, test_sub133);
  tcase_add_test(tc_core, test_sub134);
  tcase_add_test(tc_core, test_sub135);
  tcase_add_test(tc_core, test_sub136);
  tcase_add_test(tc_core, test_sub137);
  tcase_add_test(tc_core, test_sub138);
  tcase_add_test(tc_core, test_sub139);
  tcase_add_test(tc_core, test_sub140);
  tcase_add_test(tc_core, test_sub141);
  tcase_add_test(tc_core, test_sub142);
  tcase_add_test(tc_core, test_sub143);
  tcase_add_test(tc_core, test_sub144);
  tcase_add_test(tc_core, test_sub145);
  tcase_add_test(tc_core, test_sub146);
  tcase_add_test(tc_core, test_sub147);
  tcase_add_test(tc_core, test_sub148);
  tcase_add_test(tc_core, test_sub149);
  tcase_add_test(tc_core, test_sub150);
  tcase_add_test(tc_core, test_sub151);
  tcase_add_test(tc_core, test_sub152);
  tcase_add_test(tc_core, test_sub153);
  tcase_add_test(tc_core, test_sub154);
  tcase_add_test(tc_core, test_sub155);
  tcase_add_test(tc_core, test_sub156);
  tcase_add_test(tc_core, test_sub157);
  tcase_add_test(tc_core, test_sub158);
  tcase_add_test(tc_core, test_sub159);
  tcase_add_test(tc_core, test_sub160);
  tcase_add_test(tc_core, test_sub161);
  tcase_add_test(tc_core, test_sub162);
  tcase_add_test(tc_core, test_sub163);
  tcase_add_test(tc_core, test_sub164);
  tcase_add_test(tc_core, test_sub165);
  tcase_add_test(tc_core, test_sub166);
  tcase_add_test(tc_core, test_sub167);
  tcase_add_test(tc_core, test_sub168);
  tcase_add_test(tc_core, test_sub169);
  tcase_add_test(tc_core, test_sub170);
  tcase_add_test(tc_core, test_sub171);
  tcase_add_test(tc_core, test_sub172);
  tcase_add_test(tc_core, test_sub173);
  tcase_add_test(tc_core, test_sub174);
  tcase_add_test(tc_core, test_sub175);
  tcase_add_test(tc_core, test_sub176);
  tcase_add_test(tc_core, test_sub177);
  tcase_add_test(tc_core, test_sub178);
  tcase_add_test(tc_core, test_sub179);
  tcase_add_test(tc_core, test_sub180);
  tcase_add_test(tc_core, test_sub181);
  tcase_add_test(tc_core, test_sub182);
  tcase_add_test(tc_core, test_sub183);
  tcase_add_test(tc_core, test_sub184);
  tcase_add_test(tc_core, test_sub185);
  tcase_add_test(tc_core, test_sub186);
  tcase_add_test(tc_core, test_sub187);
  tcase_add_test(tc_core, test_sub188);
  tcase_add_test(tc_core, test_sub189);
  tcase_add_test(tc_core, test_sub190);
  tcase_add_test(tc_core, test_sub191);
  tcase_add_test(tc_core, test_sub192);
  tcase_add_test(tc_core, test_sub193);
  tcase_add_test(tc_core, test_sub194);
  tcase_add_test(tc_core, test_sub195);
  tcase_add_test(tc_core, test_sub196);
  tcase_add_test(tc_core, test_sub197);
  tcase_add_test(tc_core, test_sub198);
  tcase_add_test(tc_core, test_sub199);
  tcase_add_test(tc_core, test_sub200);
  tcase_add_test(tc_core, test_sub201);
  tcase_add_test(tc_core, test_sub202);
  tcase_add_test(tc_core, test_sub203);
  tcase_add_test(tc_core, test_sub204);
  tcase_add_test(tc_core, test_sub205);
  tcase_add_test(tc_core, test_sub206);
  tcase_add_test(tc_core, test_sub207);
  tcase_add_test(tc_core, test_sub208);
  tcase_add_test(tc_core, test_sub209);
  tcase_add_test(tc_core, test_sub210);
  tcase_add_test(tc_core, test_sub211);
  tcase_add_test(tc_core, test_sub212);
  tcase_add_test(tc_core, test_sub213);
  tcase_add_test(tc_core, test_sub214);
  tcase_add_test(tc_core, test_sub215);
  tcase_add_test(tc_core, test_sub216);
  tcase_add_test(tc_core, test_sub217);
  tcase_add_test(tc_core, test_sub218);
  tcase_add_test(tc_core, test_sub219);
  tcase_add_test(tc_core, test_sub220);
  tcase_add_test(tc_core, test_sub221);
  tcase_add_test(tc_core, test_sub222);
  tcase_add_test(tc_core, test_sub223);
  tcase_add_test(tc_core, test_sub224);
  tcase_add_test(tc_core, test_sub225);
  tcase_add_test(tc_core, test_sub226);
  tcase_add_test(tc_core, test_sub227);
  tcase_add_test(tc_core, test_sub228);
  tcase_add_test(tc_core, test_sub229);
  tcase_add_test(tc_core, test_sub230);
  tcase_add_test(tc_core, test_sub231);
  tcase_add_test(tc_core, test_sub232);
  tcase_add_test(tc_core, test_sub233);
  tcase_add_test(tc_core, test_sub234);
  tcase_add_test(tc_core, test_sub235);
  tcase_add_test(tc_core, test_sub236);
  tcase_add_test(tc_core, test_sub237);
  tcase_add_test(tc_core, test_sub238);
  tcase_add_test(tc_core, test_sub239);
  tcase_add_test(tc_core, test_sub240);
  tcase_add_test(tc_core, test_sub241);
  tcase_add_test(tc_core, test_sub242);
  tcase_add_test(tc_core, test_sub243);
  tcase_add_test(tc_core, test_sub244);
  tcase_add_test(tc_core, test_sub245);
  tcase_add_test(tc_core, test_sub246);
  tcase_add_test(tc_core, test_sub247);
  tcase_add_test(tc_core, test_sub248);
  tcase_add_test(tc_core, test_sub249);
  tcase_add_test(tc_core, test_sub250);
  tcase_add_test(tc_core, test_sub251);
  tcase_add_test(tc_core, test_sub252);
  tcase_add_test(tc_core, test_sub253);
  tcase_add_test(tc_core, test_sub254);
  tcase_add_test(tc_core, test_sub255);
  tcase_add_test(tc_core, test_sub256);
  tcase_add_test(tc_core, test_sub257);
  tcase_add_test(tc_core, test_sub258);
  tcase_add_test(tc_core, test_sub259);
  tcase_add_test(tc_core, test_sub260);
  tcase_add_test(tc_core, test_sub261);
  tcase_add_test(tc_core, test_sub262);
  tcase_add_test(tc_core, test_sub263);
  tcase_add_test(tc_core, test_sub264);
  tcase_add_test(tc_core, test_sub265);
  tcase_add_test(tc_core, test_sub266);
  tcase_add_test(tc_core, test_sub267);
  tcase_add_test(tc_core, test_sub268);
  tcase_add_test(tc_core, test_sub269);
  tcase_add_test(tc_core, test_sub270);
  tcase_add_test(tc_core, test_sub271);
  tcase_add_test(tc_core, test_sub272);
  tcase_add_test(tc_core, test_sub273);
  tcase_add_test(tc_core, test_sub274);
  tcase_add_test(tc_core, test_sub275);
  tcase_add_test(tc_core, test_sub276);
  tcase_add_test(tc_core, test_sub277);
  tcase_add_test(tc_core, test_sub278);
  tcase_add_test(tc_core, test_sub279);
  tcase_add_test(tc_core, test_sub280);
  tcase_add_test(tc_core, test_sub281);
  tcase_add_test(tc_core, test_sub282);
  tcase_add_test(tc_core, test_sub283);
  tcase_add_test(tc_core, test_sub284);
  tcase_add_test(tc_core, test_sub285);
  tcase_add_test(tc_core, test_sub286);
  tcase_add_test(tc_core, test_sub287);
  tcase_add_test(tc_core, test_sub288);
  tcase_add_test(tc_core, test_sub289);
  tcase_add_test(tc_core, test_sub290);
  tcase_add_test(tc_core, test_sub291);
  tcase_add_test(tc_core, test_sub292);
  tcase_add_test(tc_core, test_sub293);
  tcase_add_test(tc_core, test_sub294);
  tcase_add_test(tc_core, test_sub295);
  tcase_add_test(tc_core, test_sub296);
  tcase_add_test(tc_core, test_sub297);
  tcase_add_test(tc_core, test_sub298);
  tcase_add_test(tc_core, test_sub299);
  tcase_add_test(tc_core, test_sub300);
  tcase_add_test(tc_core, test_sub301);
  tcase_add_test(tc_core, test_sub302);
  tcase_add_test(tc_core, test_sub303);
  tcase_add_test(tc_core, test_sub304);
  tcase_add_test(tc_core, test_sub305);
  tcase_add_test(tc_core, test_sub306);
  tcase_add_test(tc_core, test_sub307);
  tcase_add_test(tc_core, test_sub308);
  tcase_add_test(tc_core, test_sub309);
  tcase_add_test(tc_core, test_sub310);
  tcase_add_test(tc_core, test_sub311);
  tcase_add_test(tc_core, test_sub312);
  tcase_add_test(tc_core, test_sub313);
  tcase_add_test(tc_core, test_sub314);
  tcase_add_test(tc_core, test_sub315);
  tcase_add_test(tc_core, test_sub316);
  tcase_add_test(tc_core, test_sub317);
  tcase_add_test(tc_core, test_sub318);
  tcase_add_test(tc_core, test_sub319);
  tcase_add_test(tc_core, test_sub320);
  tcase_add_test(tc_core, test_sub321);
  tcase_add_test(tc_core, test_sub322);
  tcase_add_test(tc_core, test_sub323);
  tcase_add_test(tc_core, test_sub324);
  tcase_add_test(tc_core, test_sub325);
  tcase_add_test(tc_core, test_sub326);
  tcase_add_test(tc_core, test_sub327);
  tcase_add_test(tc_core, test_sub328);
  tcase_add_test(tc_core, test_sub329);
  tcase_add_test(tc_core, test_sub330);
  tcase_add_test(tc_core, test_sub331);
  tcase_add_test(tc_core, test_sub332);
  tcase_add_test(tc_core, test_sub333);
  tcase_add_test(tc_core, test_sub334);
  tcase_add_test(tc_core, test_sub335);
  tcase_add_test(tc_core, test_sub336);
  tcase_add_test(tc_core, test_sub337);
  tcase_add_test(tc_core, test_sub338);
  tcase_add_test(tc_core, test_sub339);
  tcase_add_test(tc_core, test_sub340);
  tcase_add_test(tc_core, test_sub341);
  tcase_add_test(tc_core, test_sub342);
  tcase_add_test(tc_core, test_sub343);
  tcase_add_test(tc_core, test_sub344);
  tcase_add_test(tc_core, test_sub345);
  tcase_add_test(tc_core, test_sub346);
  tcase_add_test(tc_core, test_sub347);
  tcase_add_test(tc_core, test_sub348);
  tcase_add_test(tc_core, test_sub349);
  tcase_add_test(tc_core, test_sub350);
  tcase_add_test(tc_core, test_sub351);
  tcase_add_test(tc_core, test_sub352);
  tcase_add_test(tc_core, test_sub353);
  tcase_add_test(tc_core, test_sub354);
  tcase_add_test(tc_core, test_sub355);
  tcase_add_test(tc_core, test_sub356);
  tcase_add_test(tc_core, test_sub357);
  tcase_add_test(tc_core, test_sub358);
  tcase_add_test(tc_core, test_sub359);
  tcase_add_test(tc_core, test_sub360);
  tcase_add_test(tc_core, test_sub361);
  tcase_add_test(tc_core, test_sub362);
  tcase_add_test(tc_core, test_sub363);
  tcase_add_test(tc_core, test_sub364);
  tcase_add_test(tc_core, test_sub365);
  tcase_add_test(tc_core, test_sub366);
  tcase_add_test(tc_core, test_sub367);
  tcase_add_test(tc_core, test_sub368);
  tcase_add_test(tc_core, test_sub369);
  tcase_add_test(tc_core, test_sub370);
  tcase_add_test(tc_core, test_sub371);
  tcase_add_test(tc_core, test_sub372);
  tcase_add_test(tc_core, test_sub373);
  tcase_add_test(tc_core, test_sub374);
  tcase_add_test(tc_core, test_sub375);
  tcase_add_test(tc_core, test_sub376);
  tcase_add_test(tc_core, test_sub377);
  tcase_add_test(tc_core, test_sub378);
  tcase_add_test(tc_core, test_sub379);
  tcase_add_test(tc_core, test_sub380);
  tcase_add_test(tc_core, test_sub381);
  tcase_add_test(tc_core, test_sub382);
  tcase_add_test(tc_core, test_sub383);
  tcase_add_test(tc_core, test_sub384);
  tcase_add_test(tc_core, test_sub385);
  tcase_add_test(tc_core, test_sub386);
  tcase_add_test(tc_core, test_sub387);
  tcase_add_test(tc_core, test_sub388);
  tcase_add_test(tc_core, test_sub389);
  tcase_add_test(tc_core, test_sub390);
  tcase_add_test(tc_core, test_sub391);
  tcase_add_test(tc_core, test_sub392);
  tcase_add_test(tc_core, test_sub393);
  tcase_add_test(tc_core, test_sub394);
  tcase_add_test(tc_core, test_sub395);
  tcase_add_test(tc_core, test_sub396);
  tcase_add_test(tc_core, test_sub397);
  tcase_add_test(tc_core, test_sub398);
  tcase_add_test(tc_core, test_sub399);
  tcase_add_test(tc_core, test_sub400);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_sub(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);
#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  s21_print_decimal_bits(decimal1);
  s21_print_decimal_string(decimal1);
  s21_print_decimal_bits(decimal2);
  s21_print_decimal_string(decimal2);
  printf("\ncheck:\n");
  s21_print_decimal_bits(check);
  s21_print_decimal_string(check);
  printf("\nres:\n");
  s21_print_decimal_bits(result);
  s21_print_decimal_string(result);
  printf("---------------------------------\n");
#endif
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

void test_sub_fail(s21_decimal decimal1, s21_decimal decimal2, int check) {
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_eq(code, check);
}
