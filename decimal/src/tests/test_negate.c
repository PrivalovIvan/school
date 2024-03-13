#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_decimal.h"

START_TEST(test_negate_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // -792281625142643375935439503.35
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // 792281625142643375935439503.35
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // -79228162514264337593543950.335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // 79228162514264337593543950.335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // -7922816251426433759354395.0335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // 7922816251426433759354395.0335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // -792281625142643375935439.50335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // 792281625142643375935439.50335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // -79228162514264337593543.950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // 79228162514264337593543.950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // -7922816251426433759354.3950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // 7922816251426433759354.3950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // -792281625142643375935.43950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // 792281625142643375935.43950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // -79228162514264337593.543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // 79228162514264337593.543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok21) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // -7922816251426433759.3543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok22) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // 7922816251426433759.3543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok23) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // -792281625142643375.93543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok24) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // 792281625142643375.93543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok25) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // -79228162514264337.593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok26) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // 79228162514264337.593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok27) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // -7922816251426433.7593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok28) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // 7922816251426433.7593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok29) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // -792281625142643.37593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok30) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 792281625142643.37593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok31) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // -79228162514264.337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok32) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // 79228162514264.337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok33) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // -7922816251426.4337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok34) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // 7922816251426.4337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok35) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // -792281625142.64337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok36) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // 792281625142.64337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok37) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // -79228162514.264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok38) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // 79228162514.264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok39) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // -7922816251.4264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok40) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // 7922816251.4264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok41) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // -792281625.14264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok42) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // 792281625.14264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok43) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // -79228162.514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok44) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // 79228162.514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok45) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // -7922816.2514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok46) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // 7922816.2514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok47) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // -792281.62514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok48) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // 792281.62514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok49) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // -79228.162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok50) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // 79228.162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok51) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // -7922.8162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok52) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // 7922.8162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok53) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // -792.28162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok54) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // 792.28162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok55) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // -79.228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok56) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // 79.228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok57) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok58) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok59) {
  // 79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok60) {
  // -79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok61) {
  // 7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.4
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok62) {
  // -7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759354395033.4
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok63) {
  // 792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // -792281625142643375935439503.34
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok64) {
  // -792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // 792281625142643375935439503.34
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok65) {
  // 79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // -79228162514264337593543950.334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok66) {
  // -79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // 79228162514264337593543950.334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok67) {
  // 7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // -7922816251426433759354395.0334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok68) {
  // -7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // 7922816251426433759354395.0334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok69) {
  // 792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // -792281625142643375935439.50334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok70) {
  // -792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // 792281625142643375935439.50334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok71) {
  // 79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // -79228162514264337593543.950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok72) {
  // -79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // 79228162514264337593543.950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok73) {
  // 7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // -7922816251426433759354.3950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok74) {
  // -7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // 7922816251426433759354.3950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok75) {
  // 792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // -792281625142643375935.43950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok76) {
  // -792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // 792281625142643375935.43950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok77) {
  // 79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // -79228162514264337593.543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok78) {
  // -79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // 79228162514264337593.543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok79) {
  // 7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // -7922816251426433759.3543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok80) {
  // -7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // 7922816251426433759.3543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok81) {
  // 792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // -792281625142643375.93543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok82) {
  // -792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // 792281625142643375.93543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok83) {
  // 79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // -79228162514264337.593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok84) {
  // -79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // 79228162514264337.593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok85) {
  // 7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // -7922816251426433.7593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok86) {
  // -7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // 7922816251426433.7593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok87) {
  // 792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // -792281625142643.37593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok88) {
  // -792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 792281625142643.37593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok89) {
  // 79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // -79228162514264.337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok90) {
  // -79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // 79228162514264.337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok91) {
  // 7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // -7922816251426.4337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok92) {
  // -7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // 7922816251426.4337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok93) {
  // 792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // -792281625142.64337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok94) {
  // -792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // 792281625142.64337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok95) {
  // 79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // -79228162514.264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok96) {
  // -79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // 79228162514.264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok97) {
  // 7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // -7922816251.4264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok98) {
  // -7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // 7922816251.4264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok99) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // -792281625.14264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok100) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // 792281625.14264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok101) {
  // 79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // -79228162.514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok102) {
  // -79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // 79228162.514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok103) {
  // 7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // -7922816.2514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok104) {
  // -7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // 7922816.2514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok105) {
  // 792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // -792281.62514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok106) {
  // -792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // 792281.62514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok107) {
  // 79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // -79228.162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok108) {
  // -79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // 79228.162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok109) {
  // 7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // -7922.8162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok110) {
  // -7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // 7922.8162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok111) {
  // 792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // -792.28162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok112) {
  // -792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // 792.28162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok113) {
  // 79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // -79.228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok114) {
  // -79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // 79.228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok115) {
  // 7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -7.9228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok116) {
  // -7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 7.9228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok117) {
  // 52818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok118) {
  // -52818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 52818775009509558395695966890
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok119) {
  // 5281877500950955839569596689.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok120) {
  // -5281877500950955839569596689.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 5281877500950955839569596689.0
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok121) {
  // 5281877500950955.8395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};
  // -5281877500950955.8395695966890
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok122) {
  // -5281877500950955.8395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};
  // 5281877500950955.8395695966890
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok123) {
  // 5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  // -5.2818775009509558395695966890
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok124) {
  // -5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  // 5.2818775009509558395695966890
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok125) {
  // 52818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -52818775009509558392832655360
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok126) {
  // -52818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 52818775009509558392832655360
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok127) {
  // 5281877500950955839283265536.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -5281877500950955839283265536.0
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok128) {
  // -5281877500950955839283265536.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 5281877500950955839283265536.0
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok129) {
  // 5281877500950955.8392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};
  // -5281877500950955.8392832655360
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok130) {
  // -5281877500950955.8392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};
  // 5281877500950955.8392832655360
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok131) {
  // 5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  // -5.2818775009509558392832655360
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok132) {
  // -5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  // 5.2818775009509558392832655360
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok133) {
  // 52818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};
  // -52818774997211729016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok134) {
  // -52818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};
  // 52818774997211729016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok135) {
  // 5281877499721172901608624401.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};
  // -5281877499721172901608624401.0
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok136) {
  // -5281877499721172901608624401.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};
  // 5281877499721172901608624401.0
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok137) {
  // 5281877499721172.9016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};
  // -5281877499721172.9016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok138) {
  // -5281877499721172.9016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};
  // 5281877499721172.9016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok139) {
  // 5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  // -5.2818774997211729016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok140) {
  // -5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  // 5.2818774997211729016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok141) {
  // 52818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};
  // -52818774997211729013222932480
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok142) {
  // -52818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};
  // 52818774997211729013222932480
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok143) {
  // 5281877499721172901322293248.0
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};
  // -5281877499721172901322293248.0
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok144) {
  // -5281877499721172901322293248.0
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};
  // 5281877499721172901322293248.0
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok145) {
  // 5281877499721172.9013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0xD0000}};
  // -5281877499721172.9013222932480
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok146) {
  // -5281877499721172.9013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x800D0000}};
  // 5281877499721172.9013222932480
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok147) {
  // 5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  // -5.2818774997211729013222932480
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok148) {
  // -5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  // 5.2818774997211729013222932480
  s21_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok149) {
  // 12297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};
  // -12297829382473034410
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok150) {
  // -12297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};
  // 12297829382473034410
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok151) {
  // 1229782938247303441.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};
  // -1229782938247303441.0
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok152) {
  // -1229782938247303441.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};
  // 1229782938247303441.0
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok153) {
  // 122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  // -122978293.82473034410
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok154) {
  // -122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  // 122978293.82473034410
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok155) {
  // 1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // -1.2297829382473034410
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok156) {
  // -1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 1.2297829382473034410
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok157) {
  // 12297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};
  // -12297829379609722880
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok158) {
  // -12297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};
  // 12297829379609722880
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok159) {
  // 1229782937960972288.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};
  // -1229782937960972288.0
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok160) {
  // -1229782937960972288.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};
  // 1229782937960972288.0
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok161) {
  // 122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  // -122978293.79609722880
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok162) {
  // -122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  // 122978293.79609722880
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok163) {
  // 1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  // -1.2297829379609722880
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok164) {
  // -1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 1.2297829379609722880
  s21_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok165) {
  // 2863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};
  // -2863311530
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok166) {
  // -2863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};
  // 2863311530
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok167) {
  // 286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  // -286331153.0
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok168) {
  // -286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  // 286331153.0
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok169) {
  // 286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  // -286331.1530
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok170) {
  // -286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  // 286331.1530
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok171) {
  // 2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  // -2.863311530
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok172) {
  // -2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  // 2.863311530
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok173) {
  // 26409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok174) {
  // -26409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok175) {
  // 2640938750475477919784798344.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};
  // -2640938750475477919784798344.5
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok176) {
  // -2640938750475477919784798344.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};
  // 2640938750475477919784798344.5
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok177) {
  // 2640938750475477.9197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};
  // -2640938750475477.9197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok178) {
  // -2640938750475477.9197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x800D0000}};
  // 2640938750475477.9197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok179) {
  // 2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  // -2.6409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok180) {
  // -2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  // 2.6409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok181) {
  // 26409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};
  // -26409387504754779196416327680
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok182) {
  // -26409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387504754779196416327680
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok183) {
  // 2640938750475477919641632768.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};
  // -2640938750475477919641632768.0
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok184) {
  // -2640938750475477919641632768.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};
  // 2640938750475477919641632768.0
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok185) {
  // 2640938750475477.9196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0xD0000}};
  // -2640938750475477.9196416327680
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok186) {
  // -2640938750475477.9196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x800D0000}};
  // 2640938750475477.9196416327680
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok187) {
  // 2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  // -2.6409387504754779196416327680
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok188) {
  // -2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  // 2.6409387504754779196416327680
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok189) {
  // 26409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok190) {
  // -26409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok191) {
  // 2640938749860586450804312200.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};
  // -2640938749860586450804312200.5
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok192) {
  // -2640938749860586450804312200.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};
  // 2640938749860586450804312200.5
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok193) {
  // 2640938749860586.4508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0xD0000}};
  // -2640938749860586.4508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok194) {
  // -2640938749860586.4508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x800D0000}};
  // 2640938749860586.4508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok195) {
  // 2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  // -2.6409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok196) {
  // -2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  // 2.6409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok197) {
  // 26409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};
  // -26409387498605864506611466240
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok198) {
  // -26409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};
  // 26409387498605864506611466240
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok199) {
  // 2640938749860586450661146624.0
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};
  // -2640938749860586450661146624.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok200) {
  // -2640938749860586450661146624.0
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};
  // 2640938749860586450661146624.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok201) {
  // 2640938749860586.4506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0xD0000}};
  // -2640938749860586.4506611466240
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok202) {
  // -2640938749860586.4506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x800D0000}};
  // 2640938749860586.4506611466240
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok203) {
  // 2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  // -2.6409387498605864506611466240
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok204) {
  // -2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  // 2.6409387498605864506611466240
  s21_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok205) {
  // 6148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok206) {
  // -6148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok207) {
  // 614891469123651720.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};
  // -614891469123651720.5
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok208) {
  // -614891469123651720.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};
  // 614891469123651720.5
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok209) {
  // 6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
  // -6148914.691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok210) {
  // -6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
  // 6148914.691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok211) {
  // 6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};
  // -6.148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok212) {
  // -6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
  // 6.148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok213) {
  // 6148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};
  // -6148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok214) {
  // -6148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 6148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok215) {
  // 614891468980486144.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};
  // -614891468980486144.0
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok216) {
  // -614891468980486144.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};
  // 614891468980486144.0
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok217) {
  // 6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};
  // -6148914.689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok218) {
  // -6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};
  // 6148914.689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok219) {
  // 6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};
  // -6.148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok220) {
  // -6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};
  // 6.148914689804861440
  s21_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok221) {
  // 1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};
  // -1431655765
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok222) {
  // -1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 1431655765
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok223) {
  // 143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};
  // -143165576.5
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok224) {
  // -143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};
  // 143165576.5
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok225) {
  // 143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};
  // -143165.5765
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok226) {
  // -143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};
  // 143165.5765
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok227) {
  // 1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -1.431655765
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok228) {
  // -1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 1.431655765
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok229) {
  // 18446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x0}};
  // -18446744078004518913
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok230) {
  // -18446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80000000}};
  // 18446744078004518913
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok231) {
  // 1844674407800451891.3
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x10000}};
  // -1844674407800451891.3
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok232) {
  // -1844674407800451891.3
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80010000}};
  // 1844674407800451891.3
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok233) {
  // 184467440780.04518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80000}};
  // -184467440780.04518913
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok234) {
  // -184467440780.04518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80080000}};
  // 184467440780.04518913
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok235) {
  // 1.8446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};
  // -1.8446744078004518913
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok236) {
  // -1.8446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};
  // 1.8446744078004518913
  s21_decimal decimal_check = {{0x1, 0x1, 0x1, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok237) {
  // 18446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x0}};
  // -18446744078004518912
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok238) {
  // -18446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80000000}};
  // 18446744078004518912
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok239) {
  // 1844674407800451891.2
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x10000}};
  // -1844674407800451891.2
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok240) {
  // -1844674407800451891.2
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80010000}};
  // 1844674407800451891.2
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok241) {
  // 18446744078.004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x90000}};
  // -18446744078.004518912
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok242) {
  // -18446744078.004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80090000}};
  // 18446744078.004518912
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok243) {
  // 1.8446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};
  // -1.8446744078004518912
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok244) {
  // -1.8446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};
  // 1.8446744078004518912
  s21_decimal decimal_check = {{0x0, 0x1, 0x1, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok245) {
  // 18446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x0}};
  // -18446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok246) {
  // -18446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80000000}};
  // 18446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok247) {
  // 1844674407370955161.7
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x10000}};
  // -1844674407370955161.7
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok248) {
  // -1844674407370955161.7
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80010000}};
  // 1844674407370955161.7
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok249) {
  // 1844674407.3709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0xA0000}};
  // -1844674407.3709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok250) {
  // -1844674407.3709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x800A0000}};
  // 1844674407.3709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok251) {
  // 1.8446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};
  // -1.8446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok252) {
  // -1.8446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};
  // 1.8446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok253) {
  // 18446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x0}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok254) {
  // -18446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80000000}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok255) {
  // 1844674407370955161.6
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};
  // -1844674407370955161.6
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok256) {
  // -1844674407370955161.6
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};
  // 1844674407370955161.6
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok257) {
  // 184467440.73709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0xB0000}};
  // -184467440.73709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok258) {
  // -184467440.73709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x800B0000}};
  // 184467440.73709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok259) {
  // 1.8446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};
  // -1.8446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok260) {
  // -1.8446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};
  // 1.8446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok261) {
  // 4294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x0}};
  // -4294967297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok262) {
  // -4294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80000000}};
  // 4294967297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok263) {
  // 429496729.7
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};
  // -429496729.7
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok264) {
  // -429496729.7
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};
  // 429496729.7
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok265) {
  // 42949672.97
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};
  // -42949672.97
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok266) {
  // -42949672.97
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};
  // 42949672.97
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok267) {
  // 429496.7297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};
  // -429496.7297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok268) {
  // -429496.7297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};
  // 429496.7297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok269) {
  // 4.294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};
  // -4.294967297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok270) {
  // -4.294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};
  // 4.294967297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok271) {
  // 42.94967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};
  // -42.94967297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok272) {
  // -42.94967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};
  // 42.94967297
  s21_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok273) {
  // 4294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x0}};
  // -4294967296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok274) {
  // -4294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80000000}};
  // 4294967296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok275) {
  // 429496729.6
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};
  // -429496729.6
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok276) {
  // -429496729.6
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};
  // 429496729.6
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok277) {
  // 42949672.96
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};
  // -42949672.96
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok278) {
  // -42949672.96
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};
  // 42949672.96
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok279) {
  // 4294967.296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};
  // -4294967.296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok280) {
  // -4294967.296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};
  // 4294967.296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok281) {
  // 4.294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};
  // -4.294967296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok282) {
  // -4.294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};
  // 4.294967296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok283) {
  // 42.94967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};
  // -42.94967296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok284) {
  // -42.94967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};
  // 42.94967296
  s21_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok285) {
  // 1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok286) {
  // -1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok287) {
  // 0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok288) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok289) {
  // 0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  // -0.0000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok290) {
  // -0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  // 0.0000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok291) {
  // 0.00000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};
  // -0.00000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok292) {
  // -0.00000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};
  // 0.00000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok293) {
  // 0.000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  // -0.000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok294) {
  // -0.000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};
  // 0.000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok295) {
  // 0.0000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok296) {
  // -0.0000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok297) {
  // 39614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x0}};
  // -39614081266355540835774234624
  s21_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok298) {
  // -39614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80000000}};
  // 39614081266355540835774234624
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok299) {
  // 3961408126635554083577423462.4
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};
  // -3961408126635554083577423462.4
  s21_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok300) {
  // -3961408126635554083577423462.4
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80010000}};
  // 3961408126635554083577423462.4
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok301) {
  // 39614081266355.540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -39614081266355.540835774234624
  s21_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok302) {
  // -39614081266355.540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 39614081266355.540835774234624
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok303) {
  // 3.9614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};
  // -3.9614081266355540835774234624
  s21_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok304) {
  // -3.9614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
  // 3.9614081266355540835774234624
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok305) {
  // 39614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x0}};
  // -39614081266355540833626750976
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok306) {
  // -39614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80000000}};
  // 39614081266355540833626750976
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok307) {
  // 3961408126635554083362675097.6
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x10000}};
  // -3961408126635554083362675097.6
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok308) {
  // -3961408126635554083362675097.6
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80010000}};
  // 3961408126635554083362675097.6
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok309) {
  // 3961408126635554.0833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0xD0000}};
  // -3961408126635554.0833626750976
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok310) {
  // -3961408126635554.0833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x800D0000}};
  // 3961408126635554.0833626750976
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok311) {
  // 3.9614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};
  // -3.9614081266355540833626750976
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok312) {
  // -3.9614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};
  // 3.9614081266355540833626750976
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok313) {
  // 39614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok314) {
  // -39614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 39614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok315) {
  // 3961408125713216879891945881.6
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x10000}};
  // -3961408125713216879891945881.6
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok316) {
  // -3961408125713216879891945881.6
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80010000}};
  // 3961408125713216879891945881.6
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok317) {
  // 39614081257132168.798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0xC0000}};
  // -39614081257132168.798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok318) {
  // -39614081257132168.798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x800C0000}};
  // 39614081257132168.798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok319) {
  // 3.9614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};
  // -3.9614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok320) {
  // -3.9614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};
  // 3.9614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok321) {
  // 39614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok322) {
  // -39614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok323) {
  // 3961408125713216879677197516.8
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x10000}};
  // -3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok324) {
  // -3961408125713216879677197516.8
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80010000}};
  // 3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok325) {
  // 396140812571321687.96771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0xB0000}};
  // -396140812571321687.96771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok326) {
  // -396140812571321687.96771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x800B0000}};
  // 396140812571321687.96771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok327) {
  // 3.9614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok328) {
  // -3.9614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok329) {
  // 9223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x0}};
  // -9223372039002259456
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok330) {
  // -9223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80000000}};
  // 9223372039002259456
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok331) {
  // 922337203900225945.6
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x10000}};
  // -922337203900225945.6
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok332) {
  // -922337203900225945.6
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80010000}};
  // 922337203900225945.6
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok333) {
  // 922337203900.2259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x70000}};
  // -922337203900.2259456
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok334) {
  // -922337203900.2259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80070000}};
  // 922337203900.2259456
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok335) {
  // 9.223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};
  // -9.223372039002259456
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok336) {
  // -9.223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};
  // 9.223372039002259456
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok337) {
  // 9223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x0}};
  // -9223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok338) {
  // -9223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000000}};
  // 9223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok339) {
  // 922337203685477580.8
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x10000}};
  // -922337203685477580.8
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok340) {
  // -922337203685477580.8
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80010000}};
  // 922337203685477580.8
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok341) {
  // 92233720368.54775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000}};
  // -92233720368.54775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok342) {
  // -92233720368.54775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80080000}};
  // 92233720368.54775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok343) {
  // 9.223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};
  // -9.223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok344) {
  // -9.223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};
  // 9.223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok345) {
  // 2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};
  // -2147483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok346) {
  // -2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 2147483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok347) {
  // 214748364.8
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};
  // -214748364.8
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok348) {
  // -214748364.8
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};
  // 214748364.8
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok349) {
  // 21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  // -21474836.48
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok350) {
  // -21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  // 21474836.48
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok351) {
  // 214748.3648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -214748.3648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok352) {
  // -214748.3648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 214748.3648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok353) {
  // 21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};
  // -21.47483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok354) {
  // -21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};
  // 21.47483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok355) {
  // 2.147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  // -2.147483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok356) {
  // -2.147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  // 2.147483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok357) {
  // 156064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x0}};
  // -156064767562212695305426944
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok358) {
  // -156064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80000000}};
  // 156064767562212695305426944
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok359) {
  // 15606476756221269530542694.4
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x10000}};
  // -15606476756221269530542694.4
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok360) {
  // -15606476756221269530542694.4
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80010000}};
  // 15606476756221269530542694.4
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok361) {
  // 1560647.67562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};
  // -1560647.67562212695305426944
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok362) {
  // -1560647.67562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};
  // 1560647.67562212695305426944
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok363) {
  // 1.56064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};
  // -1.56064767562212695305426944
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok364) {
  // -1.56064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};
  // 1.56064767562212695305426944
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok365) {
  // 156064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x0}};
  // -156064767562212695296966656
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok366) {
  // -156064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80000000}};
  // 156064767562212695296966656
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok367) {
  // 15606476756221269529696665.6
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x10000}};
  // -15606476756221269529696665.6
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok368) {
  // -15606476756221269529696665.6
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80010000}};
  // 15606476756221269529696665.6
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok369) {
  // 15606476756221269529696.6656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x40000}};
  // -15606476756221269529696.6656
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok370) {
  // -15606476756221269529696.6656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80040000}};
  // 15606476756221269529696.6656
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok371) {
  // 1.56064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};
  // -1.56064767562212695296966656
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok372) {
  // -1.56064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};
  // 1.56064767562212695296966656
  s21_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok373) {
  // 156064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x0}};
  // -156064767525876035030685696
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok374) {
  // -156064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80000000}};
  // 156064767525876035030685696
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok375) {
  // 15606476752587603503068569.6
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x10000}};
  // -15606476752587603503068569.6
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok376) {
  // -15606476752587603503068569.6
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80010000}};
  // 15606476752587603503068569.6
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok377) {
  // 1560647675258760.35030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0xB0000}};
  // -1560647675258760.35030685696
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok378) {
  // -1560647675258760.35030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x800B0000}};
  // 1560647675258760.35030685696
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok379) {
  // 1.56064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};
  // -1.56064767525876035030685696
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok380) {
  // -1.56064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};
  // 1.56064767525876035030685696
  s21_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok381) {
  // 156064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x0}};
  // -156064767525876035022225408
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok382) {
  // -156064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80000000}};
  // 156064767525876035022225408
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok383) {
  // 15606476752587603502222540.8
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x10000}};
  // -15606476752587603502222540.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok384) {
  // -15606476752587603502222540.8
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80010000}};
  // 15606476752587603502222540.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok385) {
  // 15606476.7525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x130000}};
  // -15606476.7525876035022225408
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok386) {
  // -15606476.7525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80130000}};
  // 15606476.7525876035022225408
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok387) {
  // 1.56064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};
  // -1.56064767525876035022225408
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok388) {
  // -1.56064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};
  // 1.56064767525876035022225408
  s21_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok389) {
  // 36336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x0}};
  // -36336660283201536
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok390) {
  // -36336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000000}};
  // 36336660283201536
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok391) {
  // 3633666028320153.6
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x10000}};
  // -3633666028320153.6
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok392) {
  // -3633666028320153.6
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80010000}};
  // 3633666028320153.6
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok393) {
  // 363366602.83201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};
  // -363366602.83201536
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok394) {
  // -363366602.83201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};
  // 363366602.83201536
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok395) {
  // 3.6336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -3.6336660283201536
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok396) {
  // -3.6336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 3.6336660283201536
  s21_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok397) {
  // 36336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x0}};
  // -36336660274741248
  s21_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok398) {
  // -36336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000000}};
  // 36336660274741248
  s21_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok399) {
  // 3633666027474124.8
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x10000}};
  // -3633666027474124.8
  s21_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok400) {
  // -3633666027474124.8
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80010000}};
  // 3633666027474124.8
  s21_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

Suite *negate_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[45m-=S21_NEGATE2=-\033[0m");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_negate_ok1);
  tcase_add_test(tc_core, test_negate_ok2);
  tcase_add_test(tc_core, test_negate_ok3);
  tcase_add_test(tc_core, test_negate_ok4);
  tcase_add_test(tc_core, test_negate_ok5);
  tcase_add_test(tc_core, test_negate_ok6);
  tcase_add_test(tc_core, test_negate_ok7);
  tcase_add_test(tc_core, test_negate_ok8);
  tcase_add_test(tc_core, test_negate_ok9);
  tcase_add_test(tc_core, test_negate_ok10);
  tcase_add_test(tc_core, test_negate_ok11);
  tcase_add_test(tc_core, test_negate_ok12);
  tcase_add_test(tc_core, test_negate_ok13);
  tcase_add_test(tc_core, test_negate_ok14);
  tcase_add_test(tc_core, test_negate_ok15);
  tcase_add_test(tc_core, test_negate_ok16);
  tcase_add_test(tc_core, test_negate_ok17);
  tcase_add_test(tc_core, test_negate_ok18);
  tcase_add_test(tc_core, test_negate_ok19);
  tcase_add_test(tc_core, test_negate_ok20);
  tcase_add_test(tc_core, test_negate_ok21);
  tcase_add_test(tc_core, test_negate_ok22);
  tcase_add_test(tc_core, test_negate_ok23);
  tcase_add_test(tc_core, test_negate_ok24);
  tcase_add_test(tc_core, test_negate_ok25);
  tcase_add_test(tc_core, test_negate_ok26);
  tcase_add_test(tc_core, test_negate_ok27);
  tcase_add_test(tc_core, test_negate_ok28);
  tcase_add_test(tc_core, test_negate_ok29);
  tcase_add_test(tc_core, test_negate_ok30);
  tcase_add_test(tc_core, test_negate_ok31);
  tcase_add_test(tc_core, test_negate_ok32);
  tcase_add_test(tc_core, test_negate_ok33);
  tcase_add_test(tc_core, test_negate_ok34);
  tcase_add_test(tc_core, test_negate_ok35);
  tcase_add_test(tc_core, test_negate_ok36);
  tcase_add_test(tc_core, test_negate_ok37);
  tcase_add_test(tc_core, test_negate_ok38);
  tcase_add_test(tc_core, test_negate_ok39);
  tcase_add_test(tc_core, test_negate_ok40);
  tcase_add_test(tc_core, test_negate_ok41);
  tcase_add_test(tc_core, test_negate_ok42);
  tcase_add_test(tc_core, test_negate_ok43);
  tcase_add_test(tc_core, test_negate_ok44);
  tcase_add_test(tc_core, test_negate_ok45);
  tcase_add_test(tc_core, test_negate_ok46);
  tcase_add_test(tc_core, test_negate_ok47);
  tcase_add_test(tc_core, test_negate_ok48);
  tcase_add_test(tc_core, test_negate_ok49);
  tcase_add_test(tc_core, test_negate_ok50);
  tcase_add_test(tc_core, test_negate_ok51);
  tcase_add_test(tc_core, test_negate_ok52);
  tcase_add_test(tc_core, test_negate_ok53);
  tcase_add_test(tc_core, test_negate_ok54);
  tcase_add_test(tc_core, test_negate_ok55);
  tcase_add_test(tc_core, test_negate_ok56);
  tcase_add_test(tc_core, test_negate_ok57);
  tcase_add_test(tc_core, test_negate_ok58);
  tcase_add_test(tc_core, test_negate_ok59);
  tcase_add_test(tc_core, test_negate_ok60);
  tcase_add_test(tc_core, test_negate_ok61);
  tcase_add_test(tc_core, test_negate_ok62);
  tcase_add_test(tc_core, test_negate_ok63);
  tcase_add_test(tc_core, test_negate_ok64);
  tcase_add_test(tc_core, test_negate_ok65);
  tcase_add_test(tc_core, test_negate_ok66);
  tcase_add_test(tc_core, test_negate_ok67);
  tcase_add_test(tc_core, test_negate_ok68);
  tcase_add_test(tc_core, test_negate_ok69);
  tcase_add_test(tc_core, test_negate_ok70);
  tcase_add_test(tc_core, test_negate_ok71);
  tcase_add_test(tc_core, test_negate_ok72);
  tcase_add_test(tc_core, test_negate_ok73);
  tcase_add_test(tc_core, test_negate_ok74);
  tcase_add_test(tc_core, test_negate_ok75);
  tcase_add_test(tc_core, test_negate_ok76);
  tcase_add_test(tc_core, test_negate_ok77);
  tcase_add_test(tc_core, test_negate_ok78);
  tcase_add_test(tc_core, test_negate_ok79);
  tcase_add_test(tc_core, test_negate_ok80);
  tcase_add_test(tc_core, test_negate_ok81);
  tcase_add_test(tc_core, test_negate_ok82);
  tcase_add_test(tc_core, test_negate_ok83);
  tcase_add_test(tc_core, test_negate_ok84);
  tcase_add_test(tc_core, test_negate_ok85);
  tcase_add_test(tc_core, test_negate_ok86);
  tcase_add_test(tc_core, test_negate_ok87);
  tcase_add_test(tc_core, test_negate_ok88);
  tcase_add_test(tc_core, test_negate_ok89);
  tcase_add_test(tc_core, test_negate_ok90);
  tcase_add_test(tc_core, test_negate_ok91);
  tcase_add_test(tc_core, test_negate_ok92);
  tcase_add_test(tc_core, test_negate_ok93);
  tcase_add_test(tc_core, test_negate_ok94);
  tcase_add_test(tc_core, test_negate_ok95);
  tcase_add_test(tc_core, test_negate_ok96);
  tcase_add_test(tc_core, test_negate_ok97);
  tcase_add_test(tc_core, test_negate_ok98);
  tcase_add_test(tc_core, test_negate_ok99);
  tcase_add_test(tc_core, test_negate_ok100);
  tcase_add_test(tc_core, test_negate_ok101);
  tcase_add_test(tc_core, test_negate_ok102);
  tcase_add_test(tc_core, test_negate_ok103);
  tcase_add_test(tc_core, test_negate_ok104);
  tcase_add_test(tc_core, test_negate_ok105);
  tcase_add_test(tc_core, test_negate_ok106);
  tcase_add_test(tc_core, test_negate_ok107);
  tcase_add_test(tc_core, test_negate_ok108);
  tcase_add_test(tc_core, test_negate_ok109);
  tcase_add_test(tc_core, test_negate_ok110);
  tcase_add_test(tc_core, test_negate_ok111);
  tcase_add_test(tc_core, test_negate_ok112);
  tcase_add_test(tc_core, test_negate_ok113);
  tcase_add_test(tc_core, test_negate_ok114);
  tcase_add_test(tc_core, test_negate_ok115);
  tcase_add_test(tc_core, test_negate_ok116);
  tcase_add_test(tc_core, test_negate_ok117);
  tcase_add_test(tc_core, test_negate_ok118);
  tcase_add_test(tc_core, test_negate_ok119);
  tcase_add_test(tc_core, test_negate_ok120);
  tcase_add_test(tc_core, test_negate_ok121);
  tcase_add_test(tc_core, test_negate_ok122);
  tcase_add_test(tc_core, test_negate_ok123);
  tcase_add_test(tc_core, test_negate_ok124);
  tcase_add_test(tc_core, test_negate_ok125);
  tcase_add_test(tc_core, test_negate_ok126);
  tcase_add_test(tc_core, test_negate_ok127);
  tcase_add_test(tc_core, test_negate_ok128);
  tcase_add_test(tc_core, test_negate_ok129);
  tcase_add_test(tc_core, test_negate_ok130);
  tcase_add_test(tc_core, test_negate_ok131);
  tcase_add_test(tc_core, test_negate_ok132);
  tcase_add_test(tc_core, test_negate_ok133);
  tcase_add_test(tc_core, test_negate_ok134);
  tcase_add_test(tc_core, test_negate_ok135);
  tcase_add_test(tc_core, test_negate_ok136);
  tcase_add_test(tc_core, test_negate_ok137);
  tcase_add_test(tc_core, test_negate_ok138);
  tcase_add_test(tc_core, test_negate_ok139);
  tcase_add_test(tc_core, test_negate_ok140);
  tcase_add_test(tc_core, test_negate_ok141);
  tcase_add_test(tc_core, test_negate_ok142);
  tcase_add_test(tc_core, test_negate_ok143);
  tcase_add_test(tc_core, test_negate_ok144);
  tcase_add_test(tc_core, test_negate_ok145);
  tcase_add_test(tc_core, test_negate_ok146);
  tcase_add_test(tc_core, test_negate_ok147);
  tcase_add_test(tc_core, test_negate_ok148);
  tcase_add_test(tc_core, test_negate_ok149);
  tcase_add_test(tc_core, test_negate_ok150);
  tcase_add_test(tc_core, test_negate_ok151);
  tcase_add_test(tc_core, test_negate_ok152);
  tcase_add_test(tc_core, test_negate_ok153);
  tcase_add_test(tc_core, test_negate_ok154);
  tcase_add_test(tc_core, test_negate_ok155);
  tcase_add_test(tc_core, test_negate_ok156);
  tcase_add_test(tc_core, test_negate_ok157);
  tcase_add_test(tc_core, test_negate_ok158);
  tcase_add_test(tc_core, test_negate_ok159);
  tcase_add_test(tc_core, test_negate_ok160);
  tcase_add_test(tc_core, test_negate_ok161);
  tcase_add_test(tc_core, test_negate_ok162);
  tcase_add_test(tc_core, test_negate_ok163);
  tcase_add_test(tc_core, test_negate_ok164);
  tcase_add_test(tc_core, test_negate_ok165);
  tcase_add_test(tc_core, test_negate_ok166);
  tcase_add_test(tc_core, test_negate_ok167);
  tcase_add_test(tc_core, test_negate_ok168);
  tcase_add_test(tc_core, test_negate_ok169);
  tcase_add_test(tc_core, test_negate_ok170);
  tcase_add_test(tc_core, test_negate_ok171);
  tcase_add_test(tc_core, test_negate_ok172);
  tcase_add_test(tc_core, test_negate_ok173);
  tcase_add_test(tc_core, test_negate_ok174);
  tcase_add_test(tc_core, test_negate_ok175);
  tcase_add_test(tc_core, test_negate_ok176);
  tcase_add_test(tc_core, test_negate_ok177);
  tcase_add_test(tc_core, test_negate_ok178);
  tcase_add_test(tc_core, test_negate_ok179);
  tcase_add_test(tc_core, test_negate_ok180);
  tcase_add_test(tc_core, test_negate_ok181);
  tcase_add_test(tc_core, test_negate_ok182);
  tcase_add_test(tc_core, test_negate_ok183);
  tcase_add_test(tc_core, test_negate_ok184);
  tcase_add_test(tc_core, test_negate_ok185);
  tcase_add_test(tc_core, test_negate_ok186);
  tcase_add_test(tc_core, test_negate_ok187);
  tcase_add_test(tc_core, test_negate_ok188);
  tcase_add_test(tc_core, test_negate_ok189);
  tcase_add_test(tc_core, test_negate_ok190);
  tcase_add_test(tc_core, test_negate_ok191);
  tcase_add_test(tc_core, test_negate_ok192);
  tcase_add_test(tc_core, test_negate_ok193);
  tcase_add_test(tc_core, test_negate_ok194);
  tcase_add_test(tc_core, test_negate_ok195);
  tcase_add_test(tc_core, test_negate_ok196);
  tcase_add_test(tc_core, test_negate_ok197);
  tcase_add_test(tc_core, test_negate_ok198);
  tcase_add_test(tc_core, test_negate_ok199);
  tcase_add_test(tc_core, test_negate_ok200);
  tcase_add_test(tc_core, test_negate_ok201);
  tcase_add_test(tc_core, test_negate_ok202);
  tcase_add_test(tc_core, test_negate_ok203);
  tcase_add_test(tc_core, test_negate_ok204);
  tcase_add_test(tc_core, test_negate_ok205);
  tcase_add_test(tc_core, test_negate_ok206);
  tcase_add_test(tc_core, test_negate_ok207);
  tcase_add_test(tc_core, test_negate_ok208);
  tcase_add_test(tc_core, test_negate_ok209);
  tcase_add_test(tc_core, test_negate_ok210);
  tcase_add_test(tc_core, test_negate_ok211);
  tcase_add_test(tc_core, test_negate_ok212);
  tcase_add_test(tc_core, test_negate_ok213);
  tcase_add_test(tc_core, test_negate_ok214);
  tcase_add_test(tc_core, test_negate_ok215);
  tcase_add_test(tc_core, test_negate_ok216);
  tcase_add_test(tc_core, test_negate_ok217);
  tcase_add_test(tc_core, test_negate_ok218);
  tcase_add_test(tc_core, test_negate_ok219);
  tcase_add_test(tc_core, test_negate_ok220);
  tcase_add_test(tc_core, test_negate_ok221);
  tcase_add_test(tc_core, test_negate_ok222);
  tcase_add_test(tc_core, test_negate_ok223);
  tcase_add_test(tc_core, test_negate_ok224);
  tcase_add_test(tc_core, test_negate_ok225);
  tcase_add_test(tc_core, test_negate_ok226);
  tcase_add_test(tc_core, test_negate_ok227);
  tcase_add_test(tc_core, test_negate_ok228);
  tcase_add_test(tc_core, test_negate_ok229);
  tcase_add_test(tc_core, test_negate_ok230);
  tcase_add_test(tc_core, test_negate_ok231);
  tcase_add_test(tc_core, test_negate_ok232);
  tcase_add_test(tc_core, test_negate_ok233);
  tcase_add_test(tc_core, test_negate_ok234);
  tcase_add_test(tc_core, test_negate_ok235);
  tcase_add_test(tc_core, test_negate_ok236);
  tcase_add_test(tc_core, test_negate_ok237);
  tcase_add_test(tc_core, test_negate_ok238);
  tcase_add_test(tc_core, test_negate_ok239);
  tcase_add_test(tc_core, test_negate_ok240);
  tcase_add_test(tc_core, test_negate_ok241);
  tcase_add_test(tc_core, test_negate_ok242);
  tcase_add_test(tc_core, test_negate_ok243);
  tcase_add_test(tc_core, test_negate_ok244);
  tcase_add_test(tc_core, test_negate_ok245);
  tcase_add_test(tc_core, test_negate_ok246);
  tcase_add_test(tc_core, test_negate_ok247);
  tcase_add_test(tc_core, test_negate_ok248);
  tcase_add_test(tc_core, test_negate_ok249);
  tcase_add_test(tc_core, test_negate_ok250);
  tcase_add_test(tc_core, test_negate_ok251);
  tcase_add_test(tc_core, test_negate_ok252);
  tcase_add_test(tc_core, test_negate_ok253);
  tcase_add_test(tc_core, test_negate_ok254);
  tcase_add_test(tc_core, test_negate_ok255);
  tcase_add_test(tc_core, test_negate_ok256);
  tcase_add_test(tc_core, test_negate_ok257);
  tcase_add_test(tc_core, test_negate_ok258);
  tcase_add_test(tc_core, test_negate_ok259);
  tcase_add_test(tc_core, test_negate_ok260);
  tcase_add_test(tc_core, test_negate_ok261);
  tcase_add_test(tc_core, test_negate_ok262);
  tcase_add_test(tc_core, test_negate_ok263);
  tcase_add_test(tc_core, test_negate_ok264);
  tcase_add_test(tc_core, test_negate_ok265);
  tcase_add_test(tc_core, test_negate_ok266);
  tcase_add_test(tc_core, test_negate_ok267);
  tcase_add_test(tc_core, test_negate_ok268);
  tcase_add_test(tc_core, test_negate_ok269);
  tcase_add_test(tc_core, test_negate_ok270);
  tcase_add_test(tc_core, test_negate_ok271);
  tcase_add_test(tc_core, test_negate_ok272);
  tcase_add_test(tc_core, test_negate_ok273);
  tcase_add_test(tc_core, test_negate_ok274);
  tcase_add_test(tc_core, test_negate_ok275);
  tcase_add_test(tc_core, test_negate_ok276);
  tcase_add_test(tc_core, test_negate_ok277);
  tcase_add_test(tc_core, test_negate_ok278);
  tcase_add_test(tc_core, test_negate_ok279);
  tcase_add_test(tc_core, test_negate_ok280);
  tcase_add_test(tc_core, test_negate_ok281);
  tcase_add_test(tc_core, test_negate_ok282);
  tcase_add_test(tc_core, test_negate_ok283);
  tcase_add_test(tc_core, test_negate_ok284);
  tcase_add_test(tc_core, test_negate_ok285);
  tcase_add_test(tc_core, test_negate_ok286);
  tcase_add_test(tc_core, test_negate_ok287);
  tcase_add_test(tc_core, test_negate_ok288);
  tcase_add_test(tc_core, test_negate_ok289);
  tcase_add_test(tc_core, test_negate_ok290);
  tcase_add_test(tc_core, test_negate_ok291);
  tcase_add_test(tc_core, test_negate_ok292);
  tcase_add_test(tc_core, test_negate_ok293);
  tcase_add_test(tc_core, test_negate_ok294);
  tcase_add_test(tc_core, test_negate_ok295);
  tcase_add_test(tc_core, test_negate_ok296);
  tcase_add_test(tc_core, test_negate_ok297);
  tcase_add_test(tc_core, test_negate_ok298);
  tcase_add_test(tc_core, test_negate_ok299);
  tcase_add_test(tc_core, test_negate_ok300);
  tcase_add_test(tc_core, test_negate_ok301);
  tcase_add_test(tc_core, test_negate_ok302);
  tcase_add_test(tc_core, test_negate_ok303);
  tcase_add_test(tc_core, test_negate_ok304);
  tcase_add_test(tc_core, test_negate_ok305);
  tcase_add_test(tc_core, test_negate_ok306);
  tcase_add_test(tc_core, test_negate_ok307);
  tcase_add_test(tc_core, test_negate_ok308);
  tcase_add_test(tc_core, test_negate_ok309);
  tcase_add_test(tc_core, test_negate_ok310);
  tcase_add_test(tc_core, test_negate_ok311);
  tcase_add_test(tc_core, test_negate_ok312);
  tcase_add_test(tc_core, test_negate_ok313);
  tcase_add_test(tc_core, test_negate_ok314);
  tcase_add_test(tc_core, test_negate_ok315);
  tcase_add_test(tc_core, test_negate_ok316);
  tcase_add_test(tc_core, test_negate_ok317);
  tcase_add_test(tc_core, test_negate_ok318);
  tcase_add_test(tc_core, test_negate_ok319);
  tcase_add_test(tc_core, test_negate_ok320);
  tcase_add_test(tc_core, test_negate_ok321);
  tcase_add_test(tc_core, test_negate_ok322);
  tcase_add_test(tc_core, test_negate_ok323);
  tcase_add_test(tc_core, test_negate_ok324);
  tcase_add_test(tc_core, test_negate_ok325);
  tcase_add_test(tc_core, test_negate_ok326);
  tcase_add_test(tc_core, test_negate_ok327);
  tcase_add_test(tc_core, test_negate_ok328);
  tcase_add_test(tc_core, test_negate_ok329);
  tcase_add_test(tc_core, test_negate_ok330);
  tcase_add_test(tc_core, test_negate_ok331);
  tcase_add_test(tc_core, test_negate_ok332);
  tcase_add_test(tc_core, test_negate_ok333);
  tcase_add_test(tc_core, test_negate_ok334);
  tcase_add_test(tc_core, test_negate_ok335);
  tcase_add_test(tc_core, test_negate_ok336);
  tcase_add_test(tc_core, test_negate_ok337);
  tcase_add_test(tc_core, test_negate_ok338);
  tcase_add_test(tc_core, test_negate_ok339);
  tcase_add_test(tc_core, test_negate_ok340);
  tcase_add_test(tc_core, test_negate_ok341);
  tcase_add_test(tc_core, test_negate_ok342);
  tcase_add_test(tc_core, test_negate_ok343);
  tcase_add_test(tc_core, test_negate_ok344);
  tcase_add_test(tc_core, test_negate_ok345);
  tcase_add_test(tc_core, test_negate_ok346);
  tcase_add_test(tc_core, test_negate_ok347);
  tcase_add_test(tc_core, test_negate_ok348);
  tcase_add_test(tc_core, test_negate_ok349);
  tcase_add_test(tc_core, test_negate_ok350);
  tcase_add_test(tc_core, test_negate_ok351);
  tcase_add_test(tc_core, test_negate_ok352);
  tcase_add_test(tc_core, test_negate_ok353);
  tcase_add_test(tc_core, test_negate_ok354);
  tcase_add_test(tc_core, test_negate_ok355);
  tcase_add_test(tc_core, test_negate_ok356);
  tcase_add_test(tc_core, test_negate_ok357);
  tcase_add_test(tc_core, test_negate_ok358);
  tcase_add_test(tc_core, test_negate_ok359);
  tcase_add_test(tc_core, test_negate_ok360);
  tcase_add_test(tc_core, test_negate_ok361);
  tcase_add_test(tc_core, test_negate_ok362);
  tcase_add_test(tc_core, test_negate_ok363);
  tcase_add_test(tc_core, test_negate_ok364);
  tcase_add_test(tc_core, test_negate_ok365);
  tcase_add_test(tc_core, test_negate_ok366);
  tcase_add_test(tc_core, test_negate_ok367);
  tcase_add_test(tc_core, test_negate_ok368);
  tcase_add_test(tc_core, test_negate_ok369);
  tcase_add_test(tc_core, test_negate_ok370);
  tcase_add_test(tc_core, test_negate_ok371);
  tcase_add_test(tc_core, test_negate_ok372);
  tcase_add_test(tc_core, test_negate_ok373);
  tcase_add_test(tc_core, test_negate_ok374);
  tcase_add_test(tc_core, test_negate_ok375);
  tcase_add_test(tc_core, test_negate_ok376);
  tcase_add_test(tc_core, test_negate_ok377);
  tcase_add_test(tc_core, test_negate_ok378);
  tcase_add_test(tc_core, test_negate_ok379);
  tcase_add_test(tc_core, test_negate_ok380);
  tcase_add_test(tc_core, test_negate_ok381);
  tcase_add_test(tc_core, test_negate_ok382);
  tcase_add_test(tc_core, test_negate_ok383);
  tcase_add_test(tc_core, test_negate_ok384);
  tcase_add_test(tc_core, test_negate_ok385);
  tcase_add_test(tc_core, test_negate_ok386);
  tcase_add_test(tc_core, test_negate_ok387);
  tcase_add_test(tc_core, test_negate_ok388);
  tcase_add_test(tc_core, test_negate_ok389);
  tcase_add_test(tc_core, test_negate_ok390);
  tcase_add_test(tc_core, test_negate_ok391);
  tcase_add_test(tc_core, test_negate_ok392);
  tcase_add_test(tc_core, test_negate_ok393);
  tcase_add_test(tc_core, test_negate_ok394);
  tcase_add_test(tc_core, test_negate_ok395);
  tcase_add_test(tc_core, test_negate_ok396);
  tcase_add_test(tc_core, test_negate_ok397);
  tcase_add_test(tc_core, test_negate_ok398);
  tcase_add_test(tc_core, test_negate_ok399);
  tcase_add_test(tc_core, test_negate_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_negate(s21_decimal decimal, s21_decimal decimal_check) {
  s21_decimal result;

  int code = s21_negate(decimal, &result);
  int sign_check = test_decimal_get_sign(decimal_check);
  int sign_result = test_decimal_get_sign(result);

  ck_assert_int_eq(code, TEST_OTHER_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}