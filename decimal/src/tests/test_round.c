#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_decimal.h"

START_TEST(test_round_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok21) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok22) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok23) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643376
  s21_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok24) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  s21_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok25) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264338
  s21_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok26) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  s21_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok27) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426434
  s21_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok28) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  s21_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok29) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok30) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok31) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok32) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok33) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok34) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok35) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625143
  s21_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok36) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  s21_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok37) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok38) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok39) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok40) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok41) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok42) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok43) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228163
  s21_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok44) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228163
  s21_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok45) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  s21_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok46) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922816
  s21_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok47) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792282
  s21_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok48) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792282
  s21_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok49) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  s21_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok50) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79228
  s21_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok51) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7923
  s21_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok52) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7923
  s21_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok53) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  s21_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok54) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -792
  s21_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok55) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok56) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok57) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok58) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok59) {
  // 79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok60) {
  // -79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok61) {
  // 7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok62) {
  // -7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  s21_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok63) {
  // 792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok64) {
  // -792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok65) {
  // 79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok66) {
  // -79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok67) {
  // 7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok68) {
  // -7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok69) {
  // 792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok70) {
  // -792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok71) {
  // 79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok72) {
  // -79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok73) {
  // 7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok74) {
  // -7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok75) {
  // 792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok76) {
  // -792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok77) {
  // 79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok78) {
  // -79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok79) {
  // 7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok80) {
  // -7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok81) {
  // 792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643376
  s21_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok82) {
  // -792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  s21_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok83) {
  // 79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264338
  s21_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok84) {
  // -79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  s21_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok85) {
  // 7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426434
  s21_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok86) {
  // -7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  s21_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok87) {
  // 792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok88) {
  // -792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok89) {
  // 79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok90) {
  // -79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok91) {
  // 7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok92) {
  // -7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok93) {
  // 792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625143
  s21_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok94) {
  // -792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  s21_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok95) {
  // 79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok96) {
  // -79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok97) {
  // 7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok98) {
  // -7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok99) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok100) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok101) {
  // 79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228163
  s21_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok102) {
  // -79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228163
  s21_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok103) {
  // 7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  s21_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok104) {
  // -7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922816
  s21_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok105) {
  // 792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792282
  s21_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok106) {
  // -792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792282
  s21_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok107) {
  // 79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  s21_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok108) {
  // -79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79228
  s21_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok109) {
  // 7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7923
  s21_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok110) {
  // -7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7923
  s21_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok111) {
  // 792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  s21_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok112) {
  // -792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -792
  s21_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok113) {
  // 79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok114) {
  // -79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok115) {
  // 7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok116) {
  // -7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok117) {
  // 52818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok118) {
  // -52818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -52818775009509558395695966890
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok119) {
  // 5281877500950955839569596689.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 5281877500950955839569596689
  s21_decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok120) {
  // -5281877500950955839569596689.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -5281877500950955839569596689
  s21_decimal decimal_check = {
      {0x11111111, 0x11111111, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok121) {
  // 5281877500950955.8395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};
  // 5281877500950956
  s21_decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok122) {
  // -5281877500950955.8395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};
  // -5281877500950956
  s21_decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok123) {
  // 5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  // 5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok124) {
  // -5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  // -5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok125) {
  // 52818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 52818775009509558392832655360
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok126) {
  // -52818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -52818775009509558392832655360
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok127) {
  // 5281877500950955839283265536.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 5281877500950955839283265536
  s21_decimal decimal_check = {{0x0, 0x11111111, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok128) {
  // -5281877500950955839283265536.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -5281877500950955839283265536
  s21_decimal decimal_check = {{0x0, 0x11111111, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok129) {
  // 5281877500950955.8392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};
  // 5281877500950956
  s21_decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok130) {
  // -5281877500950955.8392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};
  // -5281877500950956
  s21_decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok131) {
  // 5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  // 5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok132) {
  // -5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  // -5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok133) {
  // 52818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};
  // 52818774997211729016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok134) {
  // -52818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};
  // -52818774997211729016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok135) {
  // 5281877499721172901608624401.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};
  // 5281877499721172901608624401
  s21_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok136) {
  // -5281877499721172901608624401.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};
  // -5281877499721172901608624401
  s21_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok137) {
  // 5281877499721172.9016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};
  // 5281877499721173
  s21_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok138) {
  // -5281877499721172.9016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};
  // -5281877499721173
  s21_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok139) {
  // 5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  // 5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok140) {
  // -5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  // -5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok141) {
  // 52818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};
  // 52818774997211729013222932480
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok142) {
  // -52818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};
  // -52818774997211729013222932480
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok143) {
  // 5281877499721172901322293248.0
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};
  // 5281877499721172901322293248
  s21_decimal decimal_check = {{0x0, 0x0, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok144) {
  // -5281877499721172901322293248.0
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};
  // -5281877499721172901322293248
  s21_decimal decimal_check = {{0x0, 0x0, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok145) {
  // 5281877499721172.9013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0xD0000}};
  // 5281877499721173
  s21_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok146) {
  // -5281877499721172.9013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x800D0000}};
  // -5281877499721173
  s21_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok147) {
  // 5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  // 5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok148) {
  // -5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  // -5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok149) {
  // 12297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};
  // 12297829382473034410
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok150) {
  // -12297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};
  // -12297829382473034410
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok151) {
  // 1229782938247303441.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};
  // 1229782938247303441
  s21_decimal decimal_check = {{0x11111111, 0x11111111, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok152) {
  // -1229782938247303441.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};
  // -1229782938247303441
  s21_decimal decimal_check = {{0x11111111, 0x11111111, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok153) {
  // 122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  // 122978294
  s21_decimal decimal_check = {{0x7547FF6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok154) {
  // -122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  // -122978294
  s21_decimal decimal_check = {{0x7547FF6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok155) {
  // 1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok156) {
  // -1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok157) {
  // 12297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};
  // 12297829379609722880
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok158) {
  // -12297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};
  // -12297829379609722880
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok159) {
  // 1229782937960972288.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};
  // 1229782937960972288
  s21_decimal decimal_check = {{0x0, 0x11111111, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok160) {
  // -1229782937960972288.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};
  // -1229782937960972288
  s21_decimal decimal_check = {{0x0, 0x11111111, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok161) {
  // 122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  // 122978294
  s21_decimal decimal_check = {{0x7547FF6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok162) {
  // -122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  // -122978294
  s21_decimal decimal_check = {{0x7547FF6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok163) {
  // 1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok164) {
  // -1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok165) {
  // 2863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};
  // 2863311530
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok166) {
  // -2863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};
  // -2863311530
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok167) {
  // 286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  // 286331153
  s21_decimal decimal_check = {{0x11111111, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok168) {
  // -286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  // -286331153
  s21_decimal decimal_check = {{0x11111111, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok169) {
  // 286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  // 286331
  s21_decimal decimal_check = {{0x45E7B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok170) {
  // -286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  // -286331
  s21_decimal decimal_check = {{0x45E7B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok171) {
  // 2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok172) {
  // -2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok173) {
  // 26409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok174) {
  // -26409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok175) {
  // 2640938750475477919784798344.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};
  // 2640938750475477919784798344
  s21_decimal decimal_check = {{0x88888888, 0x88888888, 0x8888888, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok176) {
  // -2640938750475477919784798344.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};
  // -2640938750475477919784798344
  s21_decimal decimal_check = {{0x88888888, 0x88888888, 0x8888888, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok177) {
  // 2640938750475477.9197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};
  // 2640938750475478
  s21_decimal decimal_check = {{0x78187CD6, 0x961EB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok178) {
  // -2640938750475477.9197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x800D0000}};
  // -2640938750475478
  s21_decimal decimal_check = {{0x78187CD6, 0x961EB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok179) {
  // 2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok180) {
  // -2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok181) {
  // 26409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779196416327680
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok182) {
  // -26409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779196416327680
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok183) {
  // 2640938750475477919641632768.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};
  // 2640938750475477919641632768
  s21_decimal decimal_check = {{0x80000000, 0x88888888, 0x8888888, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok184) {
  // -2640938750475477919641632768.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};
  // -2640938750475477919641632768
  s21_decimal decimal_check = {{0x80000000, 0x88888888, 0x8888888, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok185) {
  // 2640938750475477.9196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0xD0000}};
  // 2640938750475478
  s21_decimal decimal_check = {{0x78187CD6, 0x961EB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok186) {
  // -2640938750475477.9196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x800D0000}};
  // -2640938750475478
  s21_decimal decimal_check = {{0x78187CD6, 0x961EB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok187) {
  // 2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok188) {
  // -2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok189) {
  // 26409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok190) {
  // -26409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok191) {
  // 2640938749860586450804312200.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};
  // 2640938749860586450804312200
  s21_decimal decimal_check = {{0x8888888, 0x80000000, 0x8888888, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok192) {
  // -2640938749860586450804312200.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};
  // -2640938749860586450804312200
  s21_decimal decimal_check = {{0x8888888, 0x80000000, 0x8888888, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok193) {
  // 2640938749860586.4508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0xD0000}};
  // 2640938749860586
  s21_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok194) {
  // -2640938749860586.4508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x800D0000}};
  // -2640938749860586
  s21_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok195) {
  // 2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok196) {
  // -2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok197) {
  // 26409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};
  // 26409387498605864506611466240
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok198) {
  // -26409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};
  // -26409387498605864506611466240
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok199) {
  // 2640938749860586450661146624.0
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};
  // 2640938749860586450661146624
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x8888888, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok200) {
  // -2640938749860586450661146624.0
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};
  // -2640938749860586450661146624
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x8888888, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok201) {
  // 2640938749860586.4506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0xD0000}};
  // 2640938749860586
  s21_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok202) {
  // -2640938749860586.4506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x800D0000}};
  // -2640938749860586
  s21_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok203) {
  // 2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok204) {
  // -2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok205) {
  // 6148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok206) {
  // -6148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok207) {
  // 614891469123651720.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};
  // 614891469123651720
  s21_decimal decimal_check = {{0x88888888, 0x8888888, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok208) {
  // -614891469123651720.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};
  // -614891469123651720
  s21_decimal decimal_check = {{0x88888888, 0x8888888, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok209) {
  // 6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
  // 6148915
  s21_decimal decimal_check = {{0x5DD333, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok210) {
  // -6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
  // -6148915
  s21_decimal decimal_check = {{0x5DD333, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok211) {
  // 6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};
  // 6
  s21_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok212) {
  // -6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
  // -6
  s21_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok213) {
  // 6148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};
  // 6148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok214) {
  // -6148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -6148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok215) {
  // 614891468980486144.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};
  // 614891468980486144
  s21_decimal decimal_check = {{0x80000000, 0x8888888, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok216) {
  // -614891468980486144.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};
  // -614891468980486144
  s21_decimal decimal_check = {{0x80000000, 0x8888888, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok217) {
  // 6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};
  // 6148915
  s21_decimal decimal_check = {{0x5DD333, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok218) {
  // -6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};
  // -6148915
  s21_decimal decimal_check = {{0x5DD333, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok219) {
  // 6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};
  // 6
  s21_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok220) {
  // -6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};
  // -6
  s21_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok221) {
  // 1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};
  // 1431655765
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok222) {
  // -1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -1431655765
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok223) {
  // 143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};
  // 143165576
  s21_decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok224) {
  // -143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};
  // -143165576
  s21_decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok225) {
  // 143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};
  // 143166
  s21_decimal decimal_check = {{0x22F3E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok226) {
  // -143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};
  // -143166
  s21_decimal decimal_check = {{0x22F3E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok227) {
  // 1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok228) {
  // -1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok229) {
  // 18446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x0}};
  // 18446744078004518913
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok230) {
  // -18446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80000000}};
  // -18446744078004518913
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok231) {
  // 1844674407800451891.3
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x10000}};
  // 1844674407800451891
  s21_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok232) {
  // -1844674407800451891.3
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80010000}};
  // -1844674407800451891
  s21_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok233) {
  // 184467440780.04518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80000}};
  // 184467440780
  s21_decimal decimal_check = {{0xF31DC48C, 0x2A, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok234) {
  // -184467440780.04518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80080000}};
  // -184467440780
  s21_decimal decimal_check = {{0xF31DC48C, 0x2A, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok235) {
  // 1.8446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok236) {
  // -1.8446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok237) {
  // 18446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x0}};
  // 18446744078004518912
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok238) {
  // -18446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80000000}};
  // -18446744078004518912
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok239) {
  // 1844674407800451891.2
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x10000}};
  // 1844674407800451891
  s21_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok240) {
  // -1844674407800451891.2
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80010000}};
  // -1844674407800451891
  s21_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok241) {
  // 18446744078.004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x90000}};
  // 18446744078
  s21_decimal decimal_check = {{0x4B82FA0E, 0x4, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok242) {
  // -18446744078.004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80090000}};
  // -18446744078
  s21_decimal decimal_check = {{0x4B82FA0E, 0x4, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok243) {
  // 1.8446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok244) {
  // -1.8446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok245) {
  // 18446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x0}};
  // 18446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok246) {
  // -18446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80000000}};
  // -18446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok247) {
  // 1844674407370955161.7
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x10000}};
  // 1844674407370955162
  s21_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok248) {
  // -1844674407370955161.7
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80010000}};
  // -1844674407370955162
  s21_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok249) {
  // 1844674407.3709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0xA0000}};
  // 1844674407
  s21_decimal decimal_check = {{0x6DF37F67, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok250) {
  // -1844674407.3709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x800A0000}};
  // -1844674407
  s21_decimal decimal_check = {{0x6DF37F67, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok251) {
  // 1.8446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok252) {
  // -1.8446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok253) {
  // 18446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x0}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok254) {
  // -18446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80000000}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok255) {
  // 1844674407370955161.6
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};
  // 1844674407370955162
  s21_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok256) {
  // -1844674407370955161.6
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};
  // -1844674407370955162
  s21_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok257) {
  // 184467440.73709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0xB0000}};
  // 184467441
  s21_decimal decimal_check = {{0xAFEBFF1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok258) {
  // -184467440.73709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x800B0000}};
  // -184467441
  s21_decimal decimal_check = {{0xAFEBFF1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok259) {
  // 1.8446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok260) {
  // -1.8446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok261) {
  // 4294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x0}};
  // 4294967297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok262) {
  // -4294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80000000}};
  // -4294967297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok263) {
  // 429496729.7
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};
  // 429496730
  s21_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok264) {
  // -429496729.7
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};
  // -429496730
  s21_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok265) {
  // 42949672.97
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};
  // 42949673
  s21_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok266) {
  // -42949672.97
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};
  // -42949673
  s21_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok267) {
  // 429496.7297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};
  // 429497
  s21_decimal decimal_check = {{0x68DB9, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok268) {
  // -429496.7297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};
  // -429497
  s21_decimal decimal_check = {{0x68DB9, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok269) {
  // 4.294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};
  // 4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok270) {
  // -4.294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok271) {
  // 42.94967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};
  // 43
  s21_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok272) {
  // -42.94967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};
  // -43
  s21_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok273) {
  // 4294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x0}};
  // 4294967296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok274) {
  // -4294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80000000}};
  // -4294967296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok275) {
  // 429496729.6
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};
  // 429496730
  s21_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok276) {
  // -429496729.6
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};
  // -429496730
  s21_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok277) {
  // 42949672.96
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};
  // 42949673
  s21_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok278) {
  // -42949672.96
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};
  // -42949673
  s21_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok279) {
  // 4294967.296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};
  // 4294967
  s21_decimal decimal_check = {{0x418937, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok280) {
  // -4294967.296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};
  // -4294967
  s21_decimal decimal_check = {{0x418937, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok281) {
  // 4.294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};
  // 4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok282) {
  // -4.294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok283) {
  // 42.94967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};
  // 43
  s21_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok284) {
  // -42.94967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};
  // -43
  s21_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok285) {
  // 1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok286) {
  // -1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok287) {
  // 0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok288) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok289) {
  // 0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok290) {
  // -0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok291) {
  // 0.00000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok292) {
  // -0.00000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok293) {
  // 0.000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok294) {
  // -0.000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok295) {
  // 0.0000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok296) {
  // -0.0000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok297) {
  // 39614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x0}};
  // 39614081266355540835774234624
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok298) {
  // -39614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80000000}};
  // -39614081266355540835774234624
  s21_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok299) {
  // 3961408126635554083577423462.4
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};
  // 3961408126635554083577423462
  s21_decimal decimal_check = {{0xA6666666, 0xD9999999, 0xCCCCCCC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok300) {
  // -3961408126635554083577423462.4
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80010000}};
  // -3961408126635554083577423462
  s21_decimal decimal_check = {{0xA6666666, 0xD9999999, 0xCCCCCCC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok301) {
  // 39614081266355.540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 39614081266356
  s21_decimal decimal_check = {{0x5F3DF2B4, 0x2407, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok302) {
  // -39614081266355.540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -39614081266356
  s21_decimal decimal_check = {{0x5F3DF2B4, 0x2407, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok303) {
  // 3.9614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};
  // 4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok304) {
  // -3.9614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok305) {
  // 39614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x0}};
  // 39614081266355540833626750976
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok306) {
  // -39614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80000000}};
  // -39614081266355540833626750976
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok307) {
  // 3961408126635554083362675097.6
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x10000}};
  // 3961408126635554083362675098
  s21_decimal decimal_check = {{0x9999999A, 0xD9999999, 0xCCCCCCC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok308) {
  // -3961408126635554083362675097.6
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80010000}};
  // -3961408126635554083362675098
  s21_decimal decimal_check = {{0x9999999A, 0xD9999999, 0xCCCCCCC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok309) {
  // 3961408126635554.0833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0xD0000}};
  // 3961408126635554
  s21_decimal decimal_check = {{0x3432CE22, 0xE12E1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok310) {
  // -3961408126635554.0833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x800D0000}};
  // -3961408126635554
  s21_decimal decimal_check = {{0x3432CE22, 0xE12E1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok311) {
  // 3.9614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};
  // 4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok312) {
  // -3.9614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok313) {
  // 39614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok314) {
  // -39614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -39614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok315) {
  // 3961408125713216879891945881.6
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x10000}};
  // 3961408125713216879891945882
  s21_decimal decimal_check = {{0xD999999A, 0xCCCCCCCC, 0xCCCCCCC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok316) {
  // -3961408125713216879891945881.6
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80010000}};
  // -3961408125713216879891945882
  s21_decimal decimal_check = {{0xD999999A, 0xCCCCCCCC, 0xCCCCCCC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok317) {
  // 39614081257132168.798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0xC0000}};
  // 39614081257132169
  s21_decimal decimal_check = {{0x96F5089, 0x8CBCCC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok318) {
  // -39614081257132168.798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x800C0000}};
  // -39614081257132169
  s21_decimal decimal_check = {{0x96F5089, 0x8CBCCC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok319) {
  // 3.9614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};
  // 4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok320) {
  // -3.9614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok321) {
  // 39614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok322) {
  // -39614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok323) {
  // 3961408125713216879677197516.8
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x10000}};
  // 3961408125713216879677197517
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok324) {
  // -3961408125713216879677197516.8
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80010000}};
  // -3961408125713216879677197517
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok325) {
  // 396140812571321687.96771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0xB0000}};
  // 396140812571321688
  s21_decimal decimal_check = {{0x5E592558, 0x57F5FF8, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok326) {
  // -396140812571321687.96771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x800B0000}};
  // -396140812571321688
  s21_decimal decimal_check = {{0x5E592558, 0x57F5FF8, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok327) {
  // 3.9614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok328) {
  // -3.9614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok329) {
  // 9223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x0}};
  // 9223372039002259456
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok330) {
  // -9223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80000000}};
  // -9223372039002259456
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok331) {
  // 922337203900225945.6
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x10000}};
  // 922337203900225946
  s21_decimal decimal_check = {{0xD999999A, 0xCCCCCCC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok332) {
  // -922337203900225945.6
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80010000}};
  // -922337203900225946
  s21_decimal decimal_check = {{0xD999999A, 0xCCCCCCC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok333) {
  // 922337203900.2259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x70000}};
  // 922337203900
  s21_decimal decimal_check = {{0xBF94D6BC, 0xD6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok334) {
  // -922337203900.2259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80070000}};
  // -922337203900
  s21_decimal decimal_check = {{0xBF94D6BC, 0xD6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok335) {
  // 9.223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};
  // 9
  s21_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok336) {
  // -9.223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};
  // -9
  s21_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok337) {
  // 9223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x0}};
  // 9223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok338) {
  // -9223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000000}};
  // -9223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok339) {
  // 922337203685477580.8
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x10000}};
  // 922337203685477581
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok340) {
  // -922337203685477580.8
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80010000}};
  // -922337203685477581
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok341) {
  // 92233720368.54775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000}};
  // 92233720369
  s21_decimal decimal_check = {{0x798EE231, 0x15, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok342) {
  // -92233720368.54775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80080000}};
  // -92233720369
  s21_decimal decimal_check = {{0x798EE231, 0x15, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok343) {
  // 9.223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};
  // 9
  s21_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok344) {
  // -9.223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};
  // -9
  s21_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok345) {
  // 2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};
  // 2147483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok346) {
  // -2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -2147483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok347) {
  // 214748364.8
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};
  // 214748365
  s21_decimal decimal_check = {{0xCCCCCCD, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok348) {
  // -214748364.8
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};
  // -214748365
  s21_decimal decimal_check = {{0xCCCCCCD, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok349) {
  // 21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  // 21474836
  s21_decimal decimal_check = {{0x147AE14, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok350) {
  // -21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  // -21474836
  s21_decimal decimal_check = {{0x147AE14, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok351) {
  // 214748.3648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 214748
  s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok352) {
  // -214748.3648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -214748
  s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok353) {
  // 21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};
  // 21
  s21_decimal decimal_check = {{0x15, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok354) {
  // -21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};
  // -21
  s21_decimal decimal_check = {{0x15, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok355) {
  // 2.147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok356) {
  // -2.147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok357) {
  // 156064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x0}};
  // 156064767562212695305426944
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok358) {
  // -156064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80000000}};
  // -156064767562212695305426944
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok359) {
  // 15606476756221269530542694.4
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x10000}};
  // 15606476756221269530542694
  s21_decimal decimal_check = {{0x99A68266, 0xCCD9B599, 0xCE8CC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok360) {
  // -15606476756221269530542694.4
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80010000}};
  // -15606476756221269530542694
  s21_decimal decimal_check = {{0x99A68266, 0xCCD9B599, 0xCE8CC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok361) {
  // 1560647.67562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};
  // 1560648
  s21_decimal decimal_check = {{0x17D048, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok362) {
  // -1560647.67562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};
  // -1560648
  s21_decimal decimal_check = {{0x17D048, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok363) {
  // 1.56064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok364) {
  // -1.56064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok365) {
  // 156064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x0}};
  // 156064767562212695296966656
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok366) {
  // -156064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80000000}};
  // -156064767562212695296966656
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok367) {
  // 15606476756221269529696665.6
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x10000}};
  // 15606476756221269529696666
  s21_decimal decimal_check = {{0x9999999A, 0xCCD9B599, 0xCE8CC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok368) {
  // -15606476756221269529696665.6
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80010000}};
  // -15606476756221269529696666
  s21_decimal decimal_check = {{0x9999999A, 0xCCD9B599, 0xCE8CC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok369) {
  // 15606476756221269529696.6656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x40000}};
  // 15606476756221269529697
  s21_decimal decimal_check = {{0x27525461, 0x75F7320, 0x34E, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok370) {
  // -15606476756221269529696.6656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80040000}};
  // -15606476756221269529697
  s21_decimal decimal_check = {{0x27525461, 0x75F7320, 0x34E, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok371) {
  // 1.56064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok372) {
  // -1.56064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok373) {
  // 156064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x0}};
  // 156064767525876035030685696
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok374) {
  // -156064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80000000}};
  // -156064767525876035030685696
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok375) {
  // 15606476752587603503068569.6
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x10000}};
  // 15606476752587603503068570
  s21_decimal decimal_check = {{0xCCD9B59A, 0xCCCCCCCC, 0xCE8CC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok376) {
  // -15606476752587603503068569.6
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80010000}};
  // -15606476752587603503068570
  s21_decimal decimal_check = {{0xCCD9B59A, 0xCCCCCCCC, 0xCE8CC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok377) {
  // 1560647675258760.35030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0xB0000}};
  // 1560647675258760
  s21_decimal decimal_check = {{0x9A4DA788, 0x58B66, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok378) {
  // -1560647675258760.35030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x800B0000}};
  // -1560647675258760
  s21_decimal decimal_check = {{0x9A4DA788, 0x58B66, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok379) {
  // 1.56064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok380) {
  // -1.56064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok381) {
  // 156064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x0}};
  // 156064767525876035022225408
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok382) {
  // -156064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80000000}};
  // -156064767525876035022225408
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok383) {
  // 15606476752587603502222540.8
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x10000}};
  // 15606476752587603502222541
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCE8CC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok384) {
  // -15606476752587603502222540.8
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80010000}};
  // -15606476752587603502222541
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCE8CC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok385) {
  // 15606476.7525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x130000}};
  // 15606477
  s21_decimal decimal_check = {{0xEE22CD, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok386) {
  // -15606476.7525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80130000}};
  // -15606477
  s21_decimal decimal_check = {{0xEE22CD, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok387) {
  // 1.56064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok388) {
  // -1.56064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok389) {
  // 36336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x0}};
  // 36336660283201536
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok390) {
  // -36336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000000}};
  // -36336660283201536
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok391) {
  // 3633666028320153.6
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x10000}};
  // 3633666028320154
  s21_decimal decimal_check = {{0xCCD9B59A, 0xCE8CC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok392) {
  // -3633666028320153.6
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80010000}};
  // -3633666028320154
  s21_decimal decimal_check = {{0xCCD9B59A, 0xCE8CC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok393) {
  // 363366602.83201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};
  // 363366603
  s21_decimal decimal_check = {{0x15A888CB, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok394) {
  // -363366602.83201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};
  // -363366603
  s21_decimal decimal_check = {{0x15A888CB, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok395) {
  // 3.6336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok396) {
  // -3.6336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok397) {
  // 36336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x0}};
  // 36336660274741248
  s21_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok398) {
  // -36336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000000}};
  // -36336660274741248
  s21_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok399) {
  // 3633666027474124.8
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x10000}};
  // 3633666027474125
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCE8CC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok400) {
  // -3633666027474124.8
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80010000}};
  // -3633666027474125
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCE8CC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

Suite *round_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[45m-=S21_ROUND=-\033[0m");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_round_ok1);
  tcase_add_test(tc_core, test_round_ok2);
  tcase_add_test(tc_core, test_round_ok3);
  tcase_add_test(tc_core, test_round_ok4);
  tcase_add_test(tc_core, test_round_ok5);
  tcase_add_test(tc_core, test_round_ok6);
  tcase_add_test(tc_core, test_round_ok7);
  tcase_add_test(tc_core, test_round_ok8);
  tcase_add_test(tc_core, test_round_ok9);
  tcase_add_test(tc_core, test_round_ok10);
  tcase_add_test(tc_core, test_round_ok11);
  tcase_add_test(tc_core, test_round_ok12);
  tcase_add_test(tc_core, test_round_ok13);
  tcase_add_test(tc_core, test_round_ok14);
  tcase_add_test(tc_core, test_round_ok15);
  tcase_add_test(tc_core, test_round_ok16);
  tcase_add_test(tc_core, test_round_ok17);
  tcase_add_test(tc_core, test_round_ok18);
  tcase_add_test(tc_core, test_round_ok19);
  tcase_add_test(tc_core, test_round_ok20);
  tcase_add_test(tc_core, test_round_ok21);
  tcase_add_test(tc_core, test_round_ok22);
  tcase_add_test(tc_core, test_round_ok23);
  tcase_add_test(tc_core, test_round_ok24);
  tcase_add_test(tc_core, test_round_ok25);
  tcase_add_test(tc_core, test_round_ok26);
  tcase_add_test(tc_core, test_round_ok27);
  tcase_add_test(tc_core, test_round_ok28);
  tcase_add_test(tc_core, test_round_ok29);
  tcase_add_test(tc_core, test_round_ok30);
  tcase_add_test(tc_core, test_round_ok31);
  tcase_add_test(tc_core, test_round_ok32);
  tcase_add_test(tc_core, test_round_ok33);
  tcase_add_test(tc_core, test_round_ok34);
  tcase_add_test(tc_core, test_round_ok35);
  tcase_add_test(tc_core, test_round_ok36);
  tcase_add_test(tc_core, test_round_ok37);
  tcase_add_test(tc_core, test_round_ok38);
  tcase_add_test(tc_core, test_round_ok39);
  tcase_add_test(tc_core, test_round_ok40);
  tcase_add_test(tc_core, test_round_ok41);
  tcase_add_test(tc_core, test_round_ok42);
  tcase_add_test(tc_core, test_round_ok43);
  tcase_add_test(tc_core, test_round_ok44);
  tcase_add_test(tc_core, test_round_ok45);
  tcase_add_test(tc_core, test_round_ok46);
  tcase_add_test(tc_core, test_round_ok47);
  tcase_add_test(tc_core, test_round_ok48);
  tcase_add_test(tc_core, test_round_ok49);
  tcase_add_test(tc_core, test_round_ok50);
  tcase_add_test(tc_core, test_round_ok51);
  tcase_add_test(tc_core, test_round_ok52);
  tcase_add_test(tc_core, test_round_ok53);
  tcase_add_test(tc_core, test_round_ok54);
  tcase_add_test(tc_core, test_round_ok55);
  tcase_add_test(tc_core, test_round_ok56);
  tcase_add_test(tc_core, test_round_ok57);
  tcase_add_test(tc_core, test_round_ok58);
  tcase_add_test(tc_core, test_round_ok59);
  tcase_add_test(tc_core, test_round_ok60);
  tcase_add_test(tc_core, test_round_ok61);
  tcase_add_test(tc_core, test_round_ok62);
  tcase_add_test(tc_core, test_round_ok63);
  tcase_add_test(tc_core, test_round_ok64);
  tcase_add_test(tc_core, test_round_ok65);
  tcase_add_test(tc_core, test_round_ok66);
  tcase_add_test(tc_core, test_round_ok67);
  tcase_add_test(tc_core, test_round_ok68);
  tcase_add_test(tc_core, test_round_ok69);
  tcase_add_test(tc_core, test_round_ok70);
  tcase_add_test(tc_core, test_round_ok71);
  tcase_add_test(tc_core, test_round_ok72);
  tcase_add_test(tc_core, test_round_ok73);
  tcase_add_test(tc_core, test_round_ok74);
  tcase_add_test(tc_core, test_round_ok75);
  tcase_add_test(tc_core, test_round_ok76);
  tcase_add_test(tc_core, test_round_ok77);
  tcase_add_test(tc_core, test_round_ok78);
  tcase_add_test(tc_core, test_round_ok79);
  tcase_add_test(tc_core, test_round_ok80);
  tcase_add_test(tc_core, test_round_ok81);
  tcase_add_test(tc_core, test_round_ok82);
  tcase_add_test(tc_core, test_round_ok83);
  tcase_add_test(tc_core, test_round_ok84);
  tcase_add_test(tc_core, test_round_ok85);
  tcase_add_test(tc_core, test_round_ok86);
  tcase_add_test(tc_core, test_round_ok87);
  tcase_add_test(tc_core, test_round_ok88);
  tcase_add_test(tc_core, test_round_ok89);
  tcase_add_test(tc_core, test_round_ok90);
  tcase_add_test(tc_core, test_round_ok91);
  tcase_add_test(tc_core, test_round_ok92);
  tcase_add_test(tc_core, test_round_ok93);
  tcase_add_test(tc_core, test_round_ok94);
  tcase_add_test(tc_core, test_round_ok95);
  tcase_add_test(tc_core, test_round_ok96);
  tcase_add_test(tc_core, test_round_ok97);
  tcase_add_test(tc_core, test_round_ok98);
  tcase_add_test(tc_core, test_round_ok99);
  tcase_add_test(tc_core, test_round_ok100);
  tcase_add_test(tc_core, test_round_ok101);
  tcase_add_test(tc_core, test_round_ok102);
  tcase_add_test(tc_core, test_round_ok103);
  tcase_add_test(tc_core, test_round_ok104);
  tcase_add_test(tc_core, test_round_ok105);
  tcase_add_test(tc_core, test_round_ok106);
  tcase_add_test(tc_core, test_round_ok107);
  tcase_add_test(tc_core, test_round_ok108);
  tcase_add_test(tc_core, test_round_ok109);
  tcase_add_test(tc_core, test_round_ok110);
  tcase_add_test(tc_core, test_round_ok111);
  tcase_add_test(tc_core, test_round_ok112);
  tcase_add_test(tc_core, test_round_ok113);
  tcase_add_test(tc_core, test_round_ok114);
  tcase_add_test(tc_core, test_round_ok115);
  tcase_add_test(tc_core, test_round_ok116);
  tcase_add_test(tc_core, test_round_ok117);
  tcase_add_test(tc_core, test_round_ok118);
  tcase_add_test(tc_core, test_round_ok119);
  tcase_add_test(tc_core, test_round_ok120);
  tcase_add_test(tc_core, test_round_ok121);
  tcase_add_test(tc_core, test_round_ok122);
  tcase_add_test(tc_core, test_round_ok123);
  tcase_add_test(tc_core, test_round_ok124);
  tcase_add_test(tc_core, test_round_ok125);
  tcase_add_test(tc_core, test_round_ok126);
  tcase_add_test(tc_core, test_round_ok127);
  tcase_add_test(tc_core, test_round_ok128);
  tcase_add_test(tc_core, test_round_ok129);
  tcase_add_test(tc_core, test_round_ok130);
  tcase_add_test(tc_core, test_round_ok131);
  tcase_add_test(tc_core, test_round_ok132);
  tcase_add_test(tc_core, test_round_ok133);
  tcase_add_test(tc_core, test_round_ok134);
  tcase_add_test(tc_core, test_round_ok135);
  tcase_add_test(tc_core, test_round_ok136);
  tcase_add_test(tc_core, test_round_ok137);
  tcase_add_test(tc_core, test_round_ok138);
  tcase_add_test(tc_core, test_round_ok139);
  tcase_add_test(tc_core, test_round_ok140);
  tcase_add_test(tc_core, test_round_ok141);
  tcase_add_test(tc_core, test_round_ok142);
  tcase_add_test(tc_core, test_round_ok143);
  tcase_add_test(tc_core, test_round_ok144);
  tcase_add_test(tc_core, test_round_ok145);
  tcase_add_test(tc_core, test_round_ok146);
  tcase_add_test(tc_core, test_round_ok147);
  tcase_add_test(tc_core, test_round_ok148);
  tcase_add_test(tc_core, test_round_ok149);
  tcase_add_test(tc_core, test_round_ok150);
  tcase_add_test(tc_core, test_round_ok151);
  tcase_add_test(tc_core, test_round_ok152);
  tcase_add_test(tc_core, test_round_ok153);
  tcase_add_test(tc_core, test_round_ok154);
  tcase_add_test(tc_core, test_round_ok155);
  tcase_add_test(tc_core, test_round_ok156);
  tcase_add_test(tc_core, test_round_ok157);
  tcase_add_test(tc_core, test_round_ok158);
  tcase_add_test(tc_core, test_round_ok159);
  tcase_add_test(tc_core, test_round_ok160);
  tcase_add_test(tc_core, test_round_ok161);
  tcase_add_test(tc_core, test_round_ok162);
  tcase_add_test(tc_core, test_round_ok163);
  tcase_add_test(tc_core, test_round_ok164);
  tcase_add_test(tc_core, test_round_ok165);
  tcase_add_test(tc_core, test_round_ok166);
  tcase_add_test(tc_core, test_round_ok167);
  tcase_add_test(tc_core, test_round_ok168);
  tcase_add_test(tc_core, test_round_ok169);
  tcase_add_test(tc_core, test_round_ok170);
  tcase_add_test(tc_core, test_round_ok171);
  tcase_add_test(tc_core, test_round_ok172);
  tcase_add_test(tc_core, test_round_ok173);
  tcase_add_test(tc_core, test_round_ok174);
  tcase_add_test(tc_core, test_round_ok175);
  tcase_add_test(tc_core, test_round_ok176);
  tcase_add_test(tc_core, test_round_ok177);
  tcase_add_test(tc_core, test_round_ok178);
  tcase_add_test(tc_core, test_round_ok179);
  tcase_add_test(tc_core, test_round_ok180);
  tcase_add_test(tc_core, test_round_ok181);
  tcase_add_test(tc_core, test_round_ok182);
  tcase_add_test(tc_core, test_round_ok183);
  tcase_add_test(tc_core, test_round_ok184);
  tcase_add_test(tc_core, test_round_ok185);
  tcase_add_test(tc_core, test_round_ok186);
  tcase_add_test(tc_core, test_round_ok187);
  tcase_add_test(tc_core, test_round_ok188);
  tcase_add_test(tc_core, test_round_ok189);
  tcase_add_test(tc_core, test_round_ok190);
  tcase_add_test(tc_core, test_round_ok191);
  tcase_add_test(tc_core, test_round_ok192);
  tcase_add_test(tc_core, test_round_ok193);
  tcase_add_test(tc_core, test_round_ok194);
  tcase_add_test(tc_core, test_round_ok195);
  tcase_add_test(tc_core, test_round_ok196);
  tcase_add_test(tc_core, test_round_ok197);
  tcase_add_test(tc_core, test_round_ok198);
  tcase_add_test(tc_core, test_round_ok199);
  tcase_add_test(tc_core, test_round_ok200);
  tcase_add_test(tc_core, test_round_ok201);
  tcase_add_test(tc_core, test_round_ok202);
  tcase_add_test(tc_core, test_round_ok203);
  tcase_add_test(tc_core, test_round_ok204);
  tcase_add_test(tc_core, test_round_ok205);
  tcase_add_test(tc_core, test_round_ok206);
  tcase_add_test(tc_core, test_round_ok207);
  tcase_add_test(tc_core, test_round_ok208);
  tcase_add_test(tc_core, test_round_ok209);
  tcase_add_test(tc_core, test_round_ok210);
  tcase_add_test(tc_core, test_round_ok211);
  tcase_add_test(tc_core, test_round_ok212);
  tcase_add_test(tc_core, test_round_ok213);
  tcase_add_test(tc_core, test_round_ok214);
  tcase_add_test(tc_core, test_round_ok215);
  tcase_add_test(tc_core, test_round_ok216);
  tcase_add_test(tc_core, test_round_ok217);
  tcase_add_test(tc_core, test_round_ok218);
  tcase_add_test(tc_core, test_round_ok219);
  tcase_add_test(tc_core, test_round_ok220);
  tcase_add_test(tc_core, test_round_ok221);
  tcase_add_test(tc_core, test_round_ok222);
  tcase_add_test(tc_core, test_round_ok223);
  tcase_add_test(tc_core, test_round_ok224);
  tcase_add_test(tc_core, test_round_ok225);
  tcase_add_test(tc_core, test_round_ok226);
  tcase_add_test(tc_core, test_round_ok227);
  tcase_add_test(tc_core, test_round_ok228);
  tcase_add_test(tc_core, test_round_ok229);
  tcase_add_test(tc_core, test_round_ok230);
  tcase_add_test(tc_core, test_round_ok231);
  tcase_add_test(tc_core, test_round_ok232);
  tcase_add_test(tc_core, test_round_ok233);
  tcase_add_test(tc_core, test_round_ok234);
  tcase_add_test(tc_core, test_round_ok235);
  tcase_add_test(tc_core, test_round_ok236);
  tcase_add_test(tc_core, test_round_ok237);
  tcase_add_test(tc_core, test_round_ok238);
  tcase_add_test(tc_core, test_round_ok239);
  tcase_add_test(tc_core, test_round_ok240);
  tcase_add_test(tc_core, test_round_ok241);
  tcase_add_test(tc_core, test_round_ok242);
  tcase_add_test(tc_core, test_round_ok243);
  tcase_add_test(tc_core, test_round_ok244);
  tcase_add_test(tc_core, test_round_ok245);
  tcase_add_test(tc_core, test_round_ok246);
  tcase_add_test(tc_core, test_round_ok247);
  tcase_add_test(tc_core, test_round_ok248);
  tcase_add_test(tc_core, test_round_ok249);
  tcase_add_test(tc_core, test_round_ok250);
  tcase_add_test(tc_core, test_round_ok251);
  tcase_add_test(tc_core, test_round_ok252);
  tcase_add_test(tc_core, test_round_ok253);
  tcase_add_test(tc_core, test_round_ok254);
  tcase_add_test(tc_core, test_round_ok255);
  tcase_add_test(tc_core, test_round_ok256);
  tcase_add_test(tc_core, test_round_ok257);
  tcase_add_test(tc_core, test_round_ok258);
  tcase_add_test(tc_core, test_round_ok259);
  tcase_add_test(tc_core, test_round_ok260);
  tcase_add_test(tc_core, test_round_ok261);
  tcase_add_test(tc_core, test_round_ok262);
  tcase_add_test(tc_core, test_round_ok263);
  tcase_add_test(tc_core, test_round_ok264);
  tcase_add_test(tc_core, test_round_ok265);
  tcase_add_test(tc_core, test_round_ok266);
  tcase_add_test(tc_core, test_round_ok267);
  tcase_add_test(tc_core, test_round_ok268);
  tcase_add_test(tc_core, test_round_ok269);
  tcase_add_test(tc_core, test_round_ok270);
  tcase_add_test(tc_core, test_round_ok271);
  tcase_add_test(tc_core, test_round_ok272);
  tcase_add_test(tc_core, test_round_ok273);
  tcase_add_test(tc_core, test_round_ok274);
  tcase_add_test(tc_core, test_round_ok275);
  tcase_add_test(tc_core, test_round_ok276);
  tcase_add_test(tc_core, test_round_ok277);
  tcase_add_test(tc_core, test_round_ok278);
  tcase_add_test(tc_core, test_round_ok279);
  tcase_add_test(tc_core, test_round_ok280);
  tcase_add_test(tc_core, test_round_ok281);
  tcase_add_test(tc_core, test_round_ok282);
  tcase_add_test(tc_core, test_round_ok283);
  tcase_add_test(tc_core, test_round_ok284);
  tcase_add_test(tc_core, test_round_ok285);
  tcase_add_test(tc_core, test_round_ok286);
  tcase_add_test(tc_core, test_round_ok287);
  tcase_add_test(tc_core, test_round_ok288);
  tcase_add_test(tc_core, test_round_ok289);
  tcase_add_test(tc_core, test_round_ok290);
  tcase_add_test(tc_core, test_round_ok291);
  tcase_add_test(tc_core, test_round_ok292);
  tcase_add_test(tc_core, test_round_ok293);
  tcase_add_test(tc_core, test_round_ok294);
  tcase_add_test(tc_core, test_round_ok295);
  tcase_add_test(tc_core, test_round_ok296);
  tcase_add_test(tc_core, test_round_ok297);
  tcase_add_test(tc_core, test_round_ok298);
  tcase_add_test(tc_core, test_round_ok299);
  tcase_add_test(tc_core, test_round_ok300);
  tcase_add_test(tc_core, test_round_ok301);
  tcase_add_test(tc_core, test_round_ok302);
  tcase_add_test(tc_core, test_round_ok303);
  tcase_add_test(tc_core, test_round_ok304);
  tcase_add_test(tc_core, test_round_ok305);
  tcase_add_test(tc_core, test_round_ok306);
  tcase_add_test(tc_core, test_round_ok307);
  tcase_add_test(tc_core, test_round_ok308);
  tcase_add_test(tc_core, test_round_ok309);
  tcase_add_test(tc_core, test_round_ok310);
  tcase_add_test(tc_core, test_round_ok311);
  tcase_add_test(tc_core, test_round_ok312);
  tcase_add_test(tc_core, test_round_ok313);
  tcase_add_test(tc_core, test_round_ok314);
  tcase_add_test(tc_core, test_round_ok315);
  tcase_add_test(tc_core, test_round_ok316);
  tcase_add_test(tc_core, test_round_ok317);
  tcase_add_test(tc_core, test_round_ok318);
  tcase_add_test(tc_core, test_round_ok319);
  tcase_add_test(tc_core, test_round_ok320);
  tcase_add_test(tc_core, test_round_ok321);
  tcase_add_test(tc_core, test_round_ok322);
  tcase_add_test(tc_core, test_round_ok323);
  tcase_add_test(tc_core, test_round_ok324);
  tcase_add_test(tc_core, test_round_ok325);
  tcase_add_test(tc_core, test_round_ok326);
  tcase_add_test(tc_core, test_round_ok327);
  tcase_add_test(tc_core, test_round_ok328);
  tcase_add_test(tc_core, test_round_ok329);
  tcase_add_test(tc_core, test_round_ok330);
  tcase_add_test(tc_core, test_round_ok331);
  tcase_add_test(tc_core, test_round_ok332);
  tcase_add_test(tc_core, test_round_ok333);
  tcase_add_test(tc_core, test_round_ok334);
  tcase_add_test(tc_core, test_round_ok335);
  tcase_add_test(tc_core, test_round_ok336);
  tcase_add_test(tc_core, test_round_ok337);
  tcase_add_test(tc_core, test_round_ok338);
  tcase_add_test(tc_core, test_round_ok339);
  tcase_add_test(tc_core, test_round_ok340);
  tcase_add_test(tc_core, test_round_ok341);
  tcase_add_test(tc_core, test_round_ok342);
  tcase_add_test(tc_core, test_round_ok343);
  tcase_add_test(tc_core, test_round_ok344);
  tcase_add_test(tc_core, test_round_ok345);
  tcase_add_test(tc_core, test_round_ok346);
  tcase_add_test(tc_core, test_round_ok347);
  tcase_add_test(tc_core, test_round_ok348);
  tcase_add_test(tc_core, test_round_ok349);
  tcase_add_test(tc_core, test_round_ok350);
  tcase_add_test(tc_core, test_round_ok351);
  tcase_add_test(tc_core, test_round_ok352);
  tcase_add_test(tc_core, test_round_ok353);
  tcase_add_test(tc_core, test_round_ok354);
  tcase_add_test(tc_core, test_round_ok355);
  tcase_add_test(tc_core, test_round_ok356);
  tcase_add_test(tc_core, test_round_ok357);
  tcase_add_test(tc_core, test_round_ok358);
  tcase_add_test(tc_core, test_round_ok359);
  tcase_add_test(tc_core, test_round_ok360);
  tcase_add_test(tc_core, test_round_ok361);
  tcase_add_test(tc_core, test_round_ok362);
  tcase_add_test(tc_core, test_round_ok363);
  tcase_add_test(tc_core, test_round_ok364);
  tcase_add_test(tc_core, test_round_ok365);
  tcase_add_test(tc_core, test_round_ok366);
  tcase_add_test(tc_core, test_round_ok367);
  tcase_add_test(tc_core, test_round_ok368);
  tcase_add_test(tc_core, test_round_ok369);
  tcase_add_test(tc_core, test_round_ok370);
  tcase_add_test(tc_core, test_round_ok371);
  tcase_add_test(tc_core, test_round_ok372);
  tcase_add_test(tc_core, test_round_ok373);
  tcase_add_test(tc_core, test_round_ok374);
  tcase_add_test(tc_core, test_round_ok375);
  tcase_add_test(tc_core, test_round_ok376);
  tcase_add_test(tc_core, test_round_ok377);
  tcase_add_test(tc_core, test_round_ok378);
  tcase_add_test(tc_core, test_round_ok379);
  tcase_add_test(tc_core, test_round_ok380);
  tcase_add_test(tc_core, test_round_ok381);
  tcase_add_test(tc_core, test_round_ok382);
  tcase_add_test(tc_core, test_round_ok383);
  tcase_add_test(tc_core, test_round_ok384);
  tcase_add_test(tc_core, test_round_ok385);
  tcase_add_test(tc_core, test_round_ok386);
  tcase_add_test(tc_core, test_round_ok387);
  tcase_add_test(tc_core, test_round_ok388);
  tcase_add_test(tc_core, test_round_ok389);
  tcase_add_test(tc_core, test_round_ok390);
  tcase_add_test(tc_core, test_round_ok391);
  tcase_add_test(tc_core, test_round_ok392);
  tcase_add_test(tc_core, test_round_ok393);
  tcase_add_test(tc_core, test_round_ok394);
  tcase_add_test(tc_core, test_round_ok395);
  tcase_add_test(tc_core, test_round_ok396);
  tcase_add_test(tc_core, test_round_ok397);
  tcase_add_test(tc_core, test_round_ok398);
  tcase_add_test(tc_core, test_round_ok399);
  tcase_add_test(tc_core, test_round_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_round(s21_decimal decimal, s21_decimal decimal_check) {
  s21_decimal result;

  int code = s21_round(decimal, &result);
  int sign_check = test_decimal_get_sign(decimal_check);
  int sign_result = test_decimal_get_sign(result);

  ck_assert_int_eq(code, TEST_OTHER_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}