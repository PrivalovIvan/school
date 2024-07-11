#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_decimal.h"

START_TEST(test_from_decimal_to_int_ok1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok2) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok3) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok4) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok5) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok6) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok7) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok8) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok9) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok10) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok11) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok12) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok13) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok14) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok15) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok16) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok17) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok18) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok19) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok20) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok21) {
  // 79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok22) {
  // -79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok23) {
  // 7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok24) {
  // -7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok25) {
  // 792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok26) {
  // -792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok27) {
  // 79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok28) {
  // -79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok29) {
  // 7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok30) {
  // -7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok31) {
  // 792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok32) {
  // -792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok33) {
  // 79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok34) {
  // -79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok35) {
  // 7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok36) {
  // -7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok37) {
  // 528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok38) {
  // -528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok39) {
  // 5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok40) {
  // -5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok41) {
  // 528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok42) {
  // -528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok43) {
  // 5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok44) {
  // -5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok45) {
  // 528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok46) {
  // -528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok47) {
  // 5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok48) {
  // -5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok49) {
  // 528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok50) {
  // -528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok51) {
  // 5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok52) {
  // -5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok53) {
  // 122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok54) {
  // -122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok55) {
  // 1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok56) {
  // -1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok57) {
  // 122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok58) {
  // -122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok59) {
  // 1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok60) {
  // -1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok61) {
  // 286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  int check = 286331153;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok62) {
  // -286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  int check = -286331153;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok63) {
  // 286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  int check = 286331;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok64) {
  // -286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  int check = -286331;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok65) {
  // 2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok66) {
  // -2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok67) {
  // 264093875.04754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok68) {
  // -264093875.04754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok69) {
  // 2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok70) {
  // -2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok71) {
  // 264093875.04754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok72) {
  // -264093875.04754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok73) {
  // 2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok74) {
  // -2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok75) {
  // 264093874.98605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok76) {
  // -264093874.98605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok77) {
  // 2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok78) {
  // -2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok79) {
  // 264093874.98605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok80) {
  // -264093874.98605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok81) {
  // 2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok82) {
  // -2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok83) {
  // 6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok84) {
  // -6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok85) {
  // 6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};
  int check = 6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok86) {
  // -6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
  int check = -6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok87) {
  // 6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok88) {
  // -6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok89) {
  // 6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};
  int check = 6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok90) {
  // -6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};
  int check = -6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok91) {
  // 1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 1431655765;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok92) {
  // -1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = -1431655765;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok93) {
  // 143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};
  int check = 143165576;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok94) {
  // -143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};
  int check = -143165576;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok95) {
  // 143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};
  int check = 143165;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok96) {
  // -143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};
  int check = -143165;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok97) {
  // 1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok98) {
  // -1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok99) {
  // 184467440.78004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0xB0000}};
  int check = 184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok100) {
  // -184467440.78004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x800B0000}};
  int check = -184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok101) {
  // 1.8446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok102) {
  // -1.8446744078004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok103) {
  // 18446744.078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0xC0000}};
  int check = 18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok104) {
  // -18446744.078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x800C0000}};
  int check = -18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok105) {
  // 1.8446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok106) {
  // -1.8446744078004518912
  s21_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok107) {
  // 1844674.4073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0xD0000}};
  int check = 1844674;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok108) {
  // -1844674.4073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x800D0000}};
  int check = -1844674;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok109) {
  // 1.8446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok110) {
  // -1.8446744073709551617
  s21_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok111) {
  // 184467.44073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0xE0000}};
  int check = 184467;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok112) {
  // -184467.44073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x800E0000}};
  int check = -184467;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok113) {
  // 1.8446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok114) {
  // -1.8446744073709551616
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok115) {
  // 429496729.7
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok116) {
  // -429496729.7
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok117) {
  // 42949672.97
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok118) {
  // -42949672.97
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok119) {
  // 429496.7297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};
  int check = 429496;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok120) {
  // -429496.7297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};
  int check = -429496;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok121) {
  // 4.294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok122) {
  // -4.294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok123) {
  // 42.94967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok124) {
  // -42.94967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok125) {
  // 429496729.6
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok126) {
  // -429496729.6
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok127) {
  // 42949672.96
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok128) {
  // -42949672.96
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok129) {
  // 4294967.296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};
  int check = 4294967;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok130) {
  // -4294967.296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};
  int check = -4294967;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok131) {
  // 4.294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok132) {
  // -4.294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok133) {
  // 42.94967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok134) {
  // -42.94967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok135) {
  // 1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok136) {
  // -1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok137) {
  // 0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok138) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok139) {
  // 0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok140) {
  // -0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok141) {
  // 0.00000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok142) {
  // -0.00000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok143) {
  // 0.000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok144) {
  // -0.000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok145) {
  // 0.0000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok146) {
  // -0.0000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok147) {
  // 396140812.66355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x140000}};
  int check = 396140812;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok148) {
  // -396140812.66355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80140000}};
  int check = -396140812;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok149) {
  // 3.9614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok150) {
  // -3.9614081266355540835774234624
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok151) {
  // 39614081.266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x150000}};
  int check = 39614081;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok152) {
  // -39614081.266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80150000}};
  int check = -39614081;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok153) {
  // 3.9614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok154) {
  // -3.9614081266355540833626750976
  s21_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok155) {
  // 3961408.1257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x160000}};
  int check = 3961408;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok156) {
  // -3961408.1257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80160000}};
  int check = -3961408;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok157) {
  // 3.9614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok158) {
  // -3.9614081257132168798919458816
  s21_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok159) {
  // 396140.81257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x170000}};
  int check = 396140;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok160) {
  // -396140.81257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80170000}};
  int check = -396140;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok161) {
  // 3.9614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok162) {
  // -3.9614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok163) {
  // 922337203.9002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0xA0000}};
  int check = 922337203;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok164) {
  // -922337203.9002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x800A0000}};
  int check = -922337203;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok165) {
  // 9.223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok166) {
  // -9.223372039002259456
  s21_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok167) {
  // 92233720.36854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0xB0000}};
  int check = 92233720;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok168) {
  // -92233720.36854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x800B0000}};
  int check = -92233720;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok169) {
  // 9.223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok170) {
  // -9.223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok171) {
  // -2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok172) {
  // 214748364.8
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};
  int check = 214748364;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok173) {
  // -214748364.8
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};
  int check = -214748364;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok174) {
  // 21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok175) {
  // -21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok176) {
  // 214748.3648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};
  int check = 214748;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok177) {
  // -214748.3648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};
  int check = -214748;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok178) {
  // 21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};
  int check = 21;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok179) {
  // -21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};
  int check = -21;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok180) {
  // 2.147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok181) {
  // -2.147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok182) {
  // 1560647.67562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};
  int check = 1560647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok183) {
  // -1560647.67562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};
  int check = -1560647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok184) {
  // 1.56064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok185) {
  // -1.56064767562212695305426944
  s21_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok186) {
  // 15606476.7562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x130000}};
  int check = 15606476;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok187) {
  // -15606476.7562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80130000}};
  int check = -15606476;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok188) {
  // 1.56064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok189) {
  // -1.56064767562212695296966656
  s21_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok190) {
  // 156064.767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x150000}};
  int check = 156064;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok191) {
  // -156064.767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80150000}};
  int check = -156064;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok192) {
  // 1.56064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok193) {
  // -1.56064767525876035030685696
  s21_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok194) {
  // 15606.4767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x160000}};
  int check = 15606;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok195) {
  // -15606.4767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x80160000}};
  int check = -15606;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok196) {
  // 1.56064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok197) {
  // -1.56064767525876035022225408
  s21_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok198) {
  // 363366602.83201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};
  int check = 363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok199) {
  // -363366602.83201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};
  int check = -363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok200) {
  // 3.6336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok201) {
  // -3.6336660283201536
  s21_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80100000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok202) {
  // 3633666.0274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0xA0000}};
  int check = 3633666;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok203) {
  // -3633666.0274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x800A0000}};
  int check = -3633666;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok204) {
  // 363366602.74741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000}};
  int check = 363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok205) {
  // -363366602.74741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80080000}};
  int check = -363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok206) {
  // 36.336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0xF0000}};
  int check = 36;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok207) {
  // -36.336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x800F0000}};
  int check = -36;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok208) {
  // 3.6336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x100000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok209) {
  // -3.6336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80100000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok210) {
  // 8460288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x0}};
  int check = 8460288;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok211) {
  // -8460288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80000000}};
  int check = -8460288;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok212) {
  // 846028.8
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x10000}};
  int check = 846028;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok213) {
  // -846028.8
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80010000}};
  int check = -846028;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok214) {
  // 84602.88
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x20000}};
  int check = 84602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok215) {
  // -84602.88
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80020000}};
  int check = -84602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok216) {
  // 8460.288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x30000}};
  int check = 8460;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok217) {
  // -8460.288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80030000}};
  int check = -8460;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok218) {
  // 84.60288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x50000}};
  int check = 84;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok219) {
  // -84.60288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80050000}};
  int check = -84;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok220) {
  // 8.460288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x60000}};
  int check = 8;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok221) {
  // -8.460288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80060000}};
  int check = -8;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok222) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok223) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok224) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok225) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok226) {
  // 79228162.514264337589248983040
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok227) {
  // -79228162.514264337589248983040
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok228) {
  // 7.9228162514264337589248983040
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok229) {
  // -7.9228162514264337589248983040
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok230) {
  // 7922816.2495817593524129366015
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok231) {
  // -7922816.2495817593524129366015
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok232) {
  // 7.9228162495817593524129366015
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok233) {
  // -7.9228162495817593524129366015
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok234) {
  // 792281.62495817593519834398720
  s21_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok235) {
  // -792281.62495817593519834398720
  s21_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok236) {
  // 7.9228162495817593519834398720
  s21_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok237) {
  // -7.9228162495817593519834398720
  s21_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok238) {
  // 184467440.73709551615
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0xB0000}};
  int check = 184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok239) {
  // -184467440.73709551615
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x800B0000}};
  int check = -184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok240) {
  // 184.46744073709551615
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x110000}};
  int check = 184;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok241) {
  // -184.46744073709551615
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80110000}};
  int check = -184;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok242) {
  // 1.8446744073709551615
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok243) {
  // -1.8446744073709551615
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok244) {
  // 18446744.069414584320
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0xC0000}};
  int check = 18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok245) {
  // -18446744.069414584320
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x800C0000}};
  int check = -18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok246) {
  // 184.46744069414584320
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x110000}};
  int check = 184;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok247) {
  // -184.46744069414584320
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80110000}};
  int check = -184;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok248) {
  // 1.8446744069414584320
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok249) {
  // -1.8446744069414584320
  s21_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok250) {
  // 429496729.5
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok251) {
  // -429496729.5
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok252) {
  // 42949672.95
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok253) {
  // -42949672.95
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok254) {
  // 42949.67295
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x50000}};
  int check = 42949;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok255) {
  // -42949.67295
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80050000}};
  int check = -42949;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok256) {
  // 42.94967295
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok257) {
  // -42.94967295
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok258) {
  // 4.294967295
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok259) {
  // -4.294967295
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok260) {
  // 1.0
  s21_decimal decimal = {{0xA, 0x0, 0x0, 0x10000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok261) {
  // -1.0
  s21_decimal decimal = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok262) {
  // 1.00
  s21_decimal decimal = {{0x64, 0x0, 0x0, 0x20000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok263) {
  // -1.00
  s21_decimal decimal = {{0x64, 0x0, 0x0, 0x80020000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok264) {
  // 1.000
  s21_decimal decimal = {{0x3E8, 0x0, 0x0, 0x30000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok265) {
  // -1.000
  s21_decimal decimal = {{0x3E8, 0x0, 0x0, 0x80030000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok266) {
  // 1.0000000000
  s21_decimal decimal = {{0x540BE400, 0x2, 0x0, 0xA0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok267) {
  // -1.0000000000
  s21_decimal decimal = {{0x540BE400, 0x2, 0x0, 0x800A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok268) {
  // 1.0000000000000000
  s21_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x100000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok269) {
  // -1.0000000000000000
  s21_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x80100000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok270) {
  // 1.00000000000000000000000
  s21_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x170000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok271) {
  // -1.00000000000000000000000
  s21_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x80170000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok272) {
  // 1.000000000000000000000000000
  s21_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok273) {
  // -1.000000000000000000000000000
  s21_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok274) {
  // 1.0000000000000000000000000000
  s21_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok275) {
  // -1.0000000000000000000000000000
  s21_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok276) {
  // 1.1
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok277) {
  // -1.1
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok278) {
  // 12.12
  s21_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};
  int check = 12;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok279) {
  // -12.12
  s21_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};
  int check = -12;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok280) {
  // 123.123
  s21_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};
  int check = 123;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok281) {
  // -123.123
  s21_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};
  int check = -123;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok282) {
  // 1234.1234
  s21_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};
  int check = 1234;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok283) {
  // -1234.1234
  s21_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};
  int check = -1234;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok284) {
  // 12345.12345
  s21_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};
  int check = 12345;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok285) {
  // -12345.12345
  s21_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};
  int check = -12345;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok286) {
  // 123456.123456
  s21_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};
  int check = 123456;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok287) {
  // -123456.123456
  s21_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};
  int check = -123456;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok288) {
  // 1234567.1234567
  s21_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};
  int check = 1234567;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok289) {
  // -1234567.1234567
  s21_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};
  int check = -1234567;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok290) {
  // 1234567890.1234567890
  s21_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};
  int check = 1234567890;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok291) {
  // -1234567890.1234567890
  s21_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};
  int check = -1234567890;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok292) {
  // 99
  s21_decimal decimal = {{0x63, 0x0, 0x0, 0x0}};
  int check = 99;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok293) {
  // -99
  s21_decimal decimal = {{0x63, 0x0, 0x0, 0x80000000}};
  int check = -99;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok294) {
  // 9.9
  s21_decimal decimal = {{0x63, 0x0, 0x0, 0x10000}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok295) {
  // -9.9
  s21_decimal decimal = {{0x63, 0x0, 0x0, 0x80010000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok296) {
  // 99.99
  s21_decimal decimal = {{0x270F, 0x0, 0x0, 0x20000}};
  int check = 99;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok297) {
  // -99.99
  s21_decimal decimal = {{0x270F, 0x0, 0x0, 0x80020000}};
  int check = -99;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok298) {
  // 999.999
  s21_decimal decimal = {{0xF423F, 0x0, 0x0, 0x30000}};
  int check = 999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok299) {
  // -999.999
  s21_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80030000}};
  int check = -999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok300) {
  // 9999.9999
  s21_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x40000}};
  int check = 9999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok301) {
  // -9999.9999
  s21_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80040000}};
  int check = -9999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok302) {
  // 99999.99999
  s21_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x50000}};
  int check = 99999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok303) {
  // -99999.99999
  s21_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x80050000}};
  int check = -99999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok304) {
  // 999999.999999
  s21_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x60000}};
  int check = 999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok305) {
  // -999999.999999
  s21_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x80060000}};
  int check = -999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok306) {
  // 9999999.9999999
  s21_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x70000}};
  int check = 9999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok307) {
  // -9999999.9999999
  s21_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x80070000}};
  int check = -9999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok308) {
  // 99999999.99999999
  s21_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80000}};
  int check = 99999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok309) {
  // -99999999.99999999
  s21_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80080000}};
  int check = -99999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok310) {
  // 999999999.999999999
  s21_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x90000}};
  int check = 999999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok311) {
  // -999999999.999999999
  s21_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x80090000}};
  int check = -999999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok312) {
  // 9
  s21_decimal decimal = {{0x9, 0x0, 0x0, 0x0}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok313) {
  // -9
  s21_decimal decimal = {{0x9, 0x0, 0x0, 0x80000000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok314) {
  // 0.9
  s21_decimal decimal = {{0x9, 0x0, 0x0, 0x10000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok315) {
  // -0.9
  s21_decimal decimal = {{0x9, 0x0, 0x0, 0x80010000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok316) {
  // 0.99
  s21_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok317) {
  // -0.99
  s21_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok318) {
  // 0.999
  s21_decimal decimal = {{0x3E7, 0x0, 0x0, 0x30000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok319) {
  // -0.999
  s21_decimal decimal = {{0x3E7, 0x0, 0x0, 0x80030000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok320) {
  // 0.9999
  s21_decimal decimal = {{0x270F, 0x0, 0x0, 0x40000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok321) {
  // -0.9999
  s21_decimal decimal = {{0x270F, 0x0, 0x0, 0x80040000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok322) {
  // 0.99999
  s21_decimal decimal = {{0x1869F, 0x0, 0x0, 0x50000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok323) {
  // -0.99999
  s21_decimal decimal = {{0x1869F, 0x0, 0x0, 0x80050000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok324) {
  // 0.999999
  s21_decimal decimal = {{0xF423F, 0x0, 0x0, 0x60000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok325) {
  // -0.999999
  s21_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80060000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok326) {
  // 0.9999999
  s21_decimal decimal = {{0x98967F, 0x0, 0x0, 0x70000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok327) {
  // -0.9999999
  s21_decimal decimal = {{0x98967F, 0x0, 0x0, 0x80070000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok328) {
  // 0.99999999
  s21_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok329) {
  // -0.99999999
  s21_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok330) {
  // 0.999999999
  s21_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok331) {
  // -0.999999999
  s21_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok332) {
  // 0.9999999999
  s21_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0xA0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok333) {
  // -0.9999999999
  s21_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x800A0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok334) {
  // 0.99999999999999999999
  s21_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok335) {
  // -0.99999999999999999999
  s21_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok336) {
  // -0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok337) {
  // 0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok338) {
  // -0.0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x80010000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok339) {
  // 0.0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x10000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok340) {
  // -0.00
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x80020000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok341) {
  // 0.00
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x20000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok342) {
  // -0.00000000000000
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok343) {
  // 0.00000000000000
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok344) {
  // -0.000000000000000000000000000
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x801B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok345) {
  // 0.000000000000000000000000000
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x1B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok346) {
  // -0.0000000000000000000000000000
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok347) {
  // 0.0000000000000000000000000000
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok348) {
  // 2147483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};
  int check = 2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok349) {
  // -2147483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80000000}};
  int check = -2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok350) {
  // 2147483646.00
  s21_decimal decimal = {{0xFFFFFF38, 0x31, 0x0, 0x20000}};
  int check = 2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok351) {
  // -2147483646.00
  s21_decimal decimal = {{0xFFFFFF38, 0x31, 0x0, 0x80020000}};
  int check = -2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok352) {
  // 2147483646.99
  s21_decimal decimal = {{0xFFFFFF9B, 0x31, 0x0, 0x20000}};
  int check = 2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok353) {
  // -2147483646.99
  s21_decimal decimal = {{0xFFFFFF9B, 0x31, 0x0, 0x80020000}};
  int check = -2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok354) {
  // 2147483646.999999999999999999
  s21_decimal decimal = {{0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x120000}};
  int check = 2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok355) {
  // -2147483646.999999999999999999
  s21_decimal decimal = {{0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x80120000}};
  int check = -2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok356) {
  // 21474836.46
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok357) {
  // -21474836.46
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok358) {
  // 214.7483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x70000}};
  int check = 214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok359) {
  // -214.7483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80070000}};
  int check = -214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok360) {
  // 2.147483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok361) {
  // -2.147483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok362) {
  // 0.2147483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0xA0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok363) {
  // -0.2147483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x800A0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok364) {
  // 0.0000000000000000002147483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok365) {
  // -0.0000000000000000002147483646
  s21_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok366) {
  // 2147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  int check = 2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok367) {
  // -2147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};
  int check = -2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok368) {
  // 2147483647.00
  s21_decimal decimal = {{0xFFFFFF9C, 0x31, 0x0, 0x20000}};
  int check = 2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok369) {
  // -2147483647.00
  s21_decimal decimal = {{0xFFFFFF9C, 0x31, 0x0, 0x80020000}};
  int check = -2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok370) {
  // 2147483647.99
  s21_decimal decimal = {{0xFFFFFFFF, 0x31, 0x0, 0x20000}};
  int check = 2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok371) {
  // -2147483647.99
  s21_decimal decimal = {{0xFFFFFFFF, 0x31, 0x0, 0x80020000}};
  int check = -2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok372) {
  // 2147483647.999999999999999999
  s21_decimal decimal = {{0xFFFFFFFF, 0xD3B1FFFF, 0x6F05B59, 0x120000}};
  int check = 2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok373) {
  // -2147483647.999999999999999999
  s21_decimal decimal = {{0xFFFFFFFF, 0xD3B1FFFF, 0x6F05B59, 0x80120000}};
  int check = -2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok374) {
  // 21474836.47
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok375) {
  // -21474836.47
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok376) {
  // 214.7483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x70000}};
  int check = 214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok377) {
  // -214.7483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80070000}};
  int check = -214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok378) {
  // 2.147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok379) {
  // -2.147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok380) {
  // 0.2147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0xA0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok381) {
  // -0.2147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x800A0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok382) {
  // 0.0000000000000000002147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok383) {
  // -0.0000000000000000002147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok384) {
  // -2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok385) {
  // -2147483648.00
  s21_decimal decimal = {{0x0, 0x32, 0x0, 0x80020000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok386) {
  // -2147483648.99
  s21_decimal decimal = {{0x63, 0x32, 0x0, 0x80020000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok387) {
  // -2147483648.999999999999999999
  s21_decimal decimal = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x80120000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok388) {
  // 21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok389) {
  // -21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok390) {
  // 214.7483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x70000}};
  int check = 214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok391) {
  // -214.7483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80070000}};
  int check = -214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok392) {
  // 2.147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok393) {
  // -2.147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok394) {
  // 0.2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0xA0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok395) {
  // -0.2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x800A0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok396) {
  // 0.0000000000000000002147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok397) {
  // -0.0000000000000000002147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok398) {
  // -202378.6784
  s21_decimal decimal = {{0x78A08920, 0x0, 0x0, 0x80040000}};
  int check = -202378;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok399) {
  // 202378.6784
  s21_decimal decimal = {{0x78A08920, 0x0, 0x0, 0x40000}};
  int check = 202378;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok400) {
  // 1157199323
  s21_decimal decimal = {{0x44F975DB, 0x0, 0x0, 0x0}};
  int check = 1157199323;

  test_from_decimal_to_int(decimal, check);
}

Suite *from_decimal_to_int_suite1(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[45m-=S21_FROM_DECIMAL_TO_INT=-\033[0m");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_int_ok1);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok2);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok3);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok4);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok5);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok6);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok7);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok8);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok9);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok10);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok11);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok12);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok13);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok14);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok15);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok16);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok17);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok18);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok19);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok20);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok21);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok22);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok23);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok24);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok25);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok26);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok27);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok28);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok29);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok30);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok31);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok32);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok33);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok34);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok35);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok36);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok37);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok38);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok39);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok40);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok41);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok42);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok43);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok44);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok45);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok46);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok47);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok48);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok49);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok50);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok51);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok52);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok53);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok54);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok55);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok56);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok57);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok58);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok59);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok60);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok61);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok62);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok63);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok64);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok65);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok66);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok67);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok68);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok69);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok70);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok71);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok72);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok73);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok74);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok75);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok76);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok77);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok78);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok79);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok80);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok81);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok82);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok83);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok84);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok85);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok86);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok87);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok88);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok89);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok90);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok91);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok92);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok93);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok94);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok95);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok96);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok97);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok98);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok99);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok100);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok101);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok102);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok103);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok104);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok105);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok106);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok107);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok108);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok109);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok110);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok111);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok112);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok113);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok114);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok115);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok116);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok117);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok118);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok119);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok120);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok121);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok122);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok123);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok124);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok125);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok126);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok127);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok128);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok129);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok130);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok131);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok132);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok133);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok134);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok135);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok136);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok137);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok138);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok139);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok140);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok141);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok142);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok143);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok144);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok145);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok146);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok147);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok148);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok149);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok150);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok151);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok152);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok153);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok154);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok155);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok156);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok157);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok158);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok159);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok160);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok161);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok162);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok163);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok164);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok165);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok166);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok167);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok168);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok169);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok170);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok171);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok172);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok173);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok174);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok175);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok176);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok177);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok178);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok179);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok180);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok181);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok182);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok183);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok184);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok185);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok186);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok187);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok188);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok189);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok190);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok191);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok192);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok193);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok194);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok195);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok196);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok197);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok198);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok199);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok200);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok201);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok202);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok203);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok204);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok205);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok206);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok207);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok208);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok209);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok210);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok211);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok212);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok213);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok214);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok215);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok216);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok217);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok218);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok219);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok220);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok221);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok222);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok223);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok224);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok225);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok226);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok227);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok228);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok229);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok230);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok231);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok232);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok233);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok234);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok235);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok236);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok237);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok238);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok239);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok240);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok241);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok242);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok243);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok244);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok245);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok246);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok247);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok248);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok249);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok250);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok251);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok252);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok253);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok254);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok255);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok256);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok257);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok258);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok259);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok260);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok261);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok262);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok263);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok264);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok265);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok266);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok267);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok268);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok269);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok270);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok271);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok272);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok273);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok274);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok275);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok276);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok277);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok278);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok279);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok280);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok281);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok282);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok283);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok284);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok285);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok286);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok287);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok288);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok289);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok290);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok291);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok292);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok293);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok294);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok295);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok296);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok297);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok298);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok299);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok300);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok301);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok302);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok303);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok304);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok305);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok306);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok307);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok308);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok309);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok310);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok311);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok312);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok313);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok314);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok315);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok316);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok317);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok318);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok319);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok320);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok321);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok322);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok323);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok324);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok325);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok326);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok327);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok328);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok329);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok330);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok331);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok332);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok333);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok334);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok335);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok336);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok337);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok338);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok339);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok340);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok341);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok342);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok343);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok344);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok345);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok346);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok347);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok348);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok349);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok350);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok351);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok352);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok353);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok354);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok355);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok356);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok357);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok358);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok359);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok360);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok361);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok362);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok363);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok364);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok365);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok366);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok367);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok368);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok369);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok370);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok371);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok372);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok373);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok374);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok375);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok376);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok377);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok378);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok379);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok380);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok381);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok382);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok383);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok384);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok385);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok386);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok387);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok388);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok389);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok390);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok391);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok392);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok393);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok394);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok395);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok396);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok397);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok398);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok399);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_from_decimal_to_int(s21_decimal decimal, int check) {
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
}
