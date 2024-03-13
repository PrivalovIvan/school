#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_decimal.h"

START_TEST(test_from_decimal_to_float_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok5) {
  // 20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok6) {
  // -20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok7) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  int check = 1814288138;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok8) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  int check = -333195510;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok9) {
  // 2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x10000}};
  int check = 1826166407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok10) {
  // -2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80010000}};
  int check = -321317241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok11) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  int check = 1786974831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok12) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  int check = -360508817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok13) {
  // 209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x20000}};
  int check = 1798155167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok14) {
  // -209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80020000}};
  int check = -349328481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok15) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  int check = 1758574359;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok16) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  int check = -388909289;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok17) {
  // 20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x30000}};
  int check = 1770713011;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok18) {
  // -20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80030000}};
  int check = -376770637;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok19) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  int check = 1730659756;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok20) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  int check = -416823892;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok21) {
  // 2099546306628004946228914.6839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x40000}};
  int check = 1742621777;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok22) {
  // -2099546306628004946228914.6839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80040000}};
  int check = -404861871;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok23) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  int check = 1703294909;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok24) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  int check = -444188739;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok25) {
  // 209954630662800494622891.46839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x50000}};
  int check = 1714542247;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok26) {
  // -209954630662800494622891.46839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80050000}};
  int check = -432941401;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok27) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  int check = 1675018133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok28) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  int check = -472465515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok29) {
  // 20995463066280049462289.146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x60000}};
  int check = 1687045459;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok30) {
  // -20995463066280049462289.146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80060000}};
  int check = -460438189;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok31) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  int check = 1647037559;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok32) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  int check = -500446089;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok33) {
  // 2099546306628004946228.9146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x70000}};
  int check = 1659085342;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok34) {
  // -2099546306628004946228.9146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80070000}};
  int check = -488398306;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok35) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  int check = 1619619935;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok36) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  int check = -527863713;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok37) {
  // 209954630662800494622.89146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000}};
  int check = 1630935883;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok38) {
  // -209954630662800494622.89146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80080000}};
  int check = -516547765;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok39) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  int check = 1591469823;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok40) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  int check = -556013825;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok41) {
  // 20995463066280049462.289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x90000}};
  int check = 1603383151;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok42) {
  // -20995463066280049462.289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80090000}};
  int check = -544100497;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok43) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  int check = 1563421695;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok44) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  int check = -584061953;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok45) {
  // 2099546306628004946.2289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xA0000}};
  int check = 1575557298;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok46) {
  // -2099546306628004946.2289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800A0000}};
  int check = -571926350;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok47) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  int check = 1535950028;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok48) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  int check = -611533620;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok49) {
  // 209954630662800494.62289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xB0000}};
  int check = 1547336232;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok50) {
  // -209954630662800494.62289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800B0000}};
  int check = -600147416;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok51) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  int check = 1507929619;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok52) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  int check = -639554029;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok53) {
  // 20995463066280049.462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xC0000}};
  int check = 1519726214;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok54) {
  // -20995463066280049.462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800C0000}};
  int check = -627757434;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok55) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  int check = 1479812316;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok56) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  int check = -667671332;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok57) {
  // 2099546306628004.9462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xD0000}};
  int check = 1492037847;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok58) {
  // -2099546306628004.9462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800D0000}};
  int check = -655445801;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok59) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  int check = 1452285309;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok60) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  int check = -695198339;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok61) {
  // 209954630662800.49462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xE0000}};
  int check = 1463743455;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok62) {
  // -209954630662800.49462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800E0000}};
  int check = -683740193;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok63) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  int check = 1424397717;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok64) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  int check = -723085931;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok65) {
  // 20995463066280.049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xF0000}};
  int check = 1436074777;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok66) {
  // -20995463066280.049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800F0000}};
  int check = -711408871;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok67) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  int check = 1396209578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok68) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  int check = -751274070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok69) {
  // 2099546306628.0049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x100000}};
  int check = 1408527195;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok70) {
  // -2099546306628.0049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80100000}};
  int check = -738956453;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok71) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  int check = 1368625903;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok72) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  int check = -778857745;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok73) {
  // 209954630662.80049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x110000}};
  int check = 1380157718;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok74) {
  // -209954630662.80049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80110000}};
  int check = -767325930;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok75) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  int check = 1340874314;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok76) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  int check = -806609334;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok77) {
  // 20995463066.280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x120000}};
  int check = 1352428971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok78) {
  // -20995463066.280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80120000}};
  int check = -795054677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok79) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 1312613640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok80) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -834870008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok81) {
  // 2099546306.6280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x130000}};
  int check = 1325025554;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok82) {
  // -2099546306.6280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80130000}};
  int check = -822458094;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok83) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 1284971936;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok84) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -862511712;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok85) {
  // 209954630.66280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x140000}};
  int check = 1296579188;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok86) {
  // -209954630.66280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80140000}};
  int check = -850904460;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok87) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 1257359617;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok88) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -890124031;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok89) {
  // 20995463.066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x150000}};
  int check = 1268788932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok90) {
  // -20995463.066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80150000}};
  int check = -878694716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok91) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 1229024666;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok92) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -918458982;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok93) {
  // 2099546.3066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x160000}};
  int check = 1241523561;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok94) {
  // -2099546.3066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80160000}};
  int check = -905960087;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok95) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 1201323541;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok96) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -946160107;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok97) {
  // 209954.63066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x170000}};
  int check = 1213008040;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok98) {
  // -209954.63066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80170000}};
  int check = -934475608;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok99) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 1173853832;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok100) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -973629816;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok101) {
  // 20995.463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x180000}};
  int check = 1185154797;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok102) {
  // -20995.463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80180000}};
  int check = -962328851;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok103) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 1145442822;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok104) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -1002040826;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok105) {
  // 2099.5463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x190000}};
  int check = 1157839038;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok106) {
  // -2099.5463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80190000}};
  int check = -989644610;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok107) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 1117680850;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok108) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -1029802798;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok109) {
  // 209.95463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1A0000}};
  int check = 1129444451;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok110) {
  // -209.95463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801A0000}};
  int check = -1018039197;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok111) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 1090357174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok112) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -1057126474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok113) {
  // 20.995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1B0000}};
  int check = 1101526709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok114) {
  // -20.995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801B0000}};
  int check = -1045956939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok115) {
  // 79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok116) {
  // -79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok117) {
  // 7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok118) {
  // -7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok119) {
  // 20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok120) {
  // -20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok121) {
  // 792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  int check = 1814288138;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok122) {
  // -792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  int check = -333195510;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok123) {
  // 2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x10000}};
  int check = 1826166407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok124) {
  // -2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80010000}};
  int check = -321317241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok125) {
  // 79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  int check = 1786974831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok126) {
  // -79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  int check = -360508817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok127) {
  // 209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x20000}};
  int check = 1798155167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok128) {
  // -209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80020000}};
  int check = -349328481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok129) {
  // 7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  int check = 1758574359;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok130) {
  // -7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  int check = -388909289;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok131) {
  // 20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x30000}};
  int check = 1770713011;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok132) {
  // -20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80030000}};
  int check = -376770637;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok133) {
  // 792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  int check = 1730659756;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok134) {
  // -792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  int check = -416823892;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok135) {
  // 2099546306628004946228914.6839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x40000}};
  int check = 1742621777;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok136) {
  // -2099546306628004946228914.6839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80040000}};
  int check = -404861871;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok137) {
  // 79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  int check = 1703294909;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok138) {
  // -79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  int check = -444188739;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok139) {
  // 209954630662800494622891.46839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x50000}};
  int check = 1714542247;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok140) {
  // -209954630662800494622891.46839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80050000}};
  int check = -432941401;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok141) {
  // 7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  int check = 1675018133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok142) {
  // -7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  int check = -472465515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok143) {
  // 20995463066280049462289.146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x60000}};
  int check = 1687045459;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok144) {
  // -20995463066280049462289.146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80060000}};
  int check = -460438189;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok145) {
  // 792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  int check = 1647037559;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok146) {
  // -792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  int check = -500446089;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok147) {
  // 2099546306628004946228.9146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x70000}};
  int check = 1659085342;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok148) {
  // -2099546306628004946228.9146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80070000}};
  int check = -488398306;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok149) {
  // 79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  int check = 1619619935;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok150) {
  // -79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  int check = -527863713;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok151) {
  // 209954630662800494622.89146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000}};
  int check = 1630935883;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok152) {
  // -209954630662800494622.89146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80080000}};
  int check = -516547765;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok153) {
  // 7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  int check = 1591469823;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok154) {
  // -7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  int check = -556013825;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok155) {
  // 20995463066280049462.289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x90000}};
  int check = 1603383151;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok156) {
  // -20995463066280049462.289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80090000}};
  int check = -544100497;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok157) {
  // 792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  int check = 1563421695;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok158) {
  // -792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  int check = -584061953;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok159) {
  // 2099546306628004946.2289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xA0000}};
  int check = 1575557298;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok160) {
  // -2099546306628004946.2289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800A0000}};
  int check = -571926350;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok161) {
  // 79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  int check = 1535950028;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok162) {
  // -79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  int check = -611533620;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok163) {
  // 209954630662800494.62289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xB0000}};
  int check = 1547336232;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok164) {
  // -209954630662800494.62289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800B0000}};
  int check = -600147416;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok165) {
  // 7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  int check = 1507929619;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok166) {
  // -7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  int check = -639554029;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok167) {
  // 20995463066280049.462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xC0000}};
  int check = 1519726214;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok168) {
  // -20995463066280049.462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800C0000}};
  int check = -627757434;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok169) {
  // 792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  int check = 1479812316;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok170) {
  // -792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  int check = -667671332;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok171) {
  // 2099546306628004.9462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xD0000}};
  int check = 1492037847;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok172) {
  // -2099546306628004.9462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800D0000}};
  int check = -655445801;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok173) {
  // 79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  int check = 1452285309;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok174) {
  // -79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  int check = -695198339;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok175) {
  // 209954630662800.49462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xE0000}};
  int check = 1463743455;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok176) {
  // -209954630662800.49462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800E0000}};
  int check = -683740193;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok177) {
  // 7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  int check = 1424397717;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok178) {
  // -7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  int check = -723085931;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok179) {
  // 20995463066280.049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xF0000}};
  int check = 1436074777;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok180) {
  // -20995463066280.049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800F0000}};
  int check = -711408871;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok181) {
  // 792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  int check = 1396209578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok182) {
  // -792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  int check = -751274070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok183) {
  // 2099546306628.0049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x100000}};
  int check = 1408527195;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok184) {
  // -2099546306628.0049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80100000}};
  int check = -738956453;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok185) {
  // 79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  int check = 1368625903;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok186) {
  // -79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  int check = -778857745;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok187) {
  // 209954630662.80049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x110000}};
  int check = 1380157718;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok188) {
  // -209954630662.80049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80110000}};
  int check = -767325930;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok189) {
  // 7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  int check = 1340874314;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok190) {
  // -7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  int check = -806609334;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok191) {
  // 20995463066.280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x120000}};
  int check = 1352428971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok192) {
  // -20995463066.280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80120000}};
  int check = -795054677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok193) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 1312613640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok194) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -834870008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok195) {
  // 2099546306.6280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x130000}};
  int check = 1325025554;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok196) {
  // -2099546306.6280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80130000}};
  int check = -822458094;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok197) {
  // 79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 1284971936;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok198) {
  // -79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -862511712;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok199) {
  // 209954630.66280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x140000}};
  int check = 1296579188;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok200) {
  // -209954630.66280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80140000}};
  int check = -850904460;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok201) {
  // 7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 1257359617;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok202) {
  // -7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -890124031;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok203) {
  // 20995463.066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x150000}};
  int check = 1268788932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok204) {
  // -20995463.066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80150000}};
  int check = -878694716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok205) {
  // 792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 1229024666;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok206) {
  // -792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -918458982;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok207) {
  // 2099546.3066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x160000}};
  int check = 1241523561;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok208) {
  // -2099546.3066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80160000}};
  int check = -905960087;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok209) {
  // 79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 1201323541;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok210) {
  // -79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -946160107;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok211) {
  // 209954.63066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x170000}};
  int check = 1213008040;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok212) {
  // -209954.63066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80170000}};
  int check = -934475608;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok213) {
  // 7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 1173853832;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok214) {
  // -7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -973629816;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok215) {
  // 20995.463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x180000}};
  int check = 1185154797;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok216) {
  // -20995.463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80180000}};
  int check = -962328851;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok217) {
  // 792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 1145442822;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok218) {
  // -792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -1002040826;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok219) {
  // 2099.5463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x190000}};
  int check = 1157839038;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok220) {
  // -2099.5463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80190000}};
  int check = -989644610;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok221) {
  // 79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 1117680850;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok222) {
  // -79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -1029802798;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok223) {
  // 209.95463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1A0000}};
  int check = 1129444451;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok224) {
  // -209.95463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801A0000}};
  int check = -1018039197;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok225) {
  // 7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 1090357174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok226) {
  // -7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -1057126474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok227) {
  // 20.995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1B0000}};
  int check = 1101526709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok228) {
  // -20.995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801B0000}};
  int check = -1045956939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok229) {
  // 52818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1865067179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok230) {
  // -52818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = -282416469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok231) {
  // 5281877500950955839569596689.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 1837664393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok232) {
  // -5281877500950955839569596689.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = -309819255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok233) {
  // 13996975377520032974859431226
  s21_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x0}};
  int check = 1848961051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok234) {
  // -13996975377520032974859431226
  s21_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x80000000}};
  int check = -298522597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok235) {
  // 528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 1308351499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok236) {
  // -528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -839132149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok237) {
  // 1399697537.7520032974859431226
  s21_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x130000}};
  int check = 1319557985;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok238) {
  // -1399697537.7520032974859431226
  s21_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x80130000}};
  int check = -827925663;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok239) {
  // 5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 1084818724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok240) {
  // -5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -1062664924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok241) {
  // 13.996975377520032974859431226
  s21_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x1B0000}};
  int check = 1096807324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok242) {
  // -13.996975377520032974859431226
  s21_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x801B0000}};
  int check = -1050676324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok243) {
  // 52818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1865067179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok244) {
  // -52818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = -282416469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok245) {
  // 5281877500950955839283265536.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 1837664393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok246) {
  // -5281877500950955839283265536.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = -309819255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok247) {
  // 13996975377520032974100653670
  s21_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x0}};
  int check = 1848961051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok248) {
  // -13996975377520032974100653670
  s21_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x80000000}};
  int check = -298522597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok249) {
  // 528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 1308351499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok250) {
  // -528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -839132149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok251) {
  // 1399697537.7520032974100653670
  s21_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x130000}};
  int check = 1319557985;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok252) {
  // -1399697537.7520032974100653670
  s21_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x80130000}};
  int check = -827925663;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok253) {
  // 5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 1084818724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok254) {
  // -5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -1062664924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok255) {
  // 13.996975377520032974100653670
  s21_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x1B0000}};
  int check = 1096807324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok256) {
  // -13.996975377520032974100653670
  s21_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x801B0000}};
  int check = -1050676324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok257) {
  // 52818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};
  int check = 1865067179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok258) {
  // -52818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};
  int check = -282416469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok259) {
  // 5281877499721172901608624401.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};
  int check = 1837664393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok260) {
  // -5281877499721172901608624401.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};
  int check = -309819255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok261) {
  // 13996975374261108189262854663
  s21_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x0}};
  int check = 1848961051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok262) {
  // -13996975374261108189262854663
  s21_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x80000000}};
  int check = -298522597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok263) {
  // 528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 1308351499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok264) {
  // -528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -839132149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok265) {
  // 1399697537.4261108189262854663
  s21_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x130000}};
  int check = 1319557985;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok266) {
  // -1399697537.4261108189262854663
  s21_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x80130000}};
  int check = -827925663;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok267) {
  // 5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 1084818724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok268) {
  // -5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -1062664924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok269) {
  // 13.996975374261108189262854663
  s21_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x1B0000}};
  int check = 1096807324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok270) {
  // -13.996975374261108189262854663
  s21_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x801B0000}};
  int check = -1050676324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok271) {
  // 52818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};
  int check = 1865067179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok272) {
  // -52818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};
  int check = -282416469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok273) {
  // 5281877499721172901322293248.0
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};
  int check = 1837664393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok274) {
  // -5281877499721172901322293248.0
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};
  int check = -309819255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok275) {
  // 13996975374261108188504077107
  s21_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x0}};
  int check = 1848961051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok276) {
  // -13996975374261108188504077107
  s21_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x80000000}};
  int check = -298522597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok277) {
  // 528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 1308351499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok278) {
  // -528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -839132149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok279) {
  // 1399697537.4261108188504077107
  s21_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x130000}};
  int check = 1319557985;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok280) {
  // -1399697537.4261108188504077107
  s21_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x80130000}};
  int check = -827925663;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok281) {
  // 5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 1084818724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok282) {
  // -5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -1062664924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok283) {
  // 13.996975374261108188504077107
  s21_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x1B0000}};
  int check = 1096807324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok284) {
  // -13.996975374261108188504077107
  s21_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x801B0000}};
  int check = -1050676324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok285) {
  // 12297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};
  int check = 1596631723;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok286) {
  // -12297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};
  int check = -550851925;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok287) {
  // 32589247863553541186.50
  s21_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x20000}};
  int check = 1608655394;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok288) {
  // -32589247863553541186.50
  s21_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x80020000}};
  int check = -538828254;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok289) {
  // 1229782938247303441.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};
  int check = 1569228937;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok290) {
  // -1229782938247303441.0
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};
  int check = -578254711;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok291) {
  // 3258924786355354118.650
  s21_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x30000}};
  int check = 1580525595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok292) {
  // -3258924786355354118.650
  s21_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x80030000}};
  int check = -566958053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok293) {
  // 122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 1290440703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok294) {
  // -122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -857042945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok295) {
  // 325892478.6355354118650
  s21_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0xD0000}};
  int check = 1302029772;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok296) {
  // -325892478.6355354118650
  s21_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x800D0000}};
  int check = -845453876;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok297) {
  // 1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1067280775;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok298) {
  // -1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1080202873;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok299) {
  // 3.258924786355354118650
  s21_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x150000}};
  int check = 1079022137;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok300) {
  // -3.258924786355354118650
  s21_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x80150000}};
  int check = -1068461511;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok301) {
  // 12297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};
  int check = 1596631723;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok302) {
  // -12297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};
  int check = -550851925;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok303) {
  // 32589247855965765632.00
  s21_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x20000}};
  int check = 1608655394;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok304) {
  // -32589247855965765632.00
  s21_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x80020000}};
  int check = -538828254;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok305) {
  // 1229782937960972288.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};
  int check = 1569228937;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok306) {
  // -1229782937960972288.0
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};
  int check = -578254711;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok307) {
  // 3258924785596576563.200
  s21_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x30000}};
  int check = 1580525595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok308) {
  // -3258924785596576563.200
  s21_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x80030000}};
  int check = -566958053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok309) {
  // 122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 1290440703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok310) {
  // -122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -857042945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok311) {
  // 325892478.5596576563200
  s21_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0xD0000}};
  int check = 1302029772;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok312) {
  // -325892478.5596576563200
  s21_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x800D0000}};
  int check = -845453876;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok313) {
  // 1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1067280775;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok314) {
  // -1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1080202873;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok315) {
  // 3.258924785596576563200
  s21_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x150000}};
  int check = 1079022137;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok316) {
  // -3.258924785596576563200
  s21_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x80150000}};
  int check = -1068461511;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok317) {
  // 2863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};
  int check = 1328196267;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok318) {
  // -2863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};
  int check = -819287381;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok319) {
  // 7587775554.50
  s21_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x20000}};
  int check = 1340219938;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok320) {
  // -7587775554.50
  s21_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x80020000}};
  int check = -807263710;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok321) {
  // 286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  int check = 1300793481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok322) {
  // -286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  int check = -846690167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok323) {
  // 758777555.450
  s21_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x30000}};
  int check = 1312090139;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok324) {
  // -758777555.450
  s21_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x80030000}};
  int check = -835393509;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok325) {
  // 286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  int check = 1217122149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok326) {
  // -286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  int check = -930361499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok327) {
  // 758777.555450
  s21_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x60000}};
  int check = 1228488601;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok328) {
  // -758777.555450
  s21_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x80060000}};
  int check = -918995047;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok329) {
  // 2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  int check = 1077362815;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok330) {
  // -2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  int check = -1070120833;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok331) {
  // 7.58777555450
  s21_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0xB0000}};
  int check = 1089654543;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok332) {
  // -7.58777555450
  s21_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x800B0000}};
  int check = -1057829105;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok333) {
  // 26409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  int check = 1856678571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok334) {
  // -26409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  int check = -290805077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok335) {
  // 2640938750475477919784798344.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};
  int check = 1829275785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok336) {
  // -2640938750475477919784798344.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};
  int check = -318207863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok337) {
  // 6998487688760016487429715612.9
  s21_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x10000}};
  int check = 1840572443;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok338) {
  // -6998487688760016487429715612.9
  s21_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x80010000}};
  int check = -306911205;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok339) {
  // 264093875.04754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x140000}};
  int check = 1299962891;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok340) {
  // -264093875.04754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80140000}};
  int check = -847520757;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok341) {
  // 699848768.87600164874297156129
  s21_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x140000}};
  int check = 1311169377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok342) {
  // -699848768.87600164874297156129
  s21_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x80140000}};
  int check = -836314271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok343) {
  // 2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 1076430116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok344) {
  // -2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -1071053532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok345) {
  // 6.9984876887600164874297156129
  s21_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x1C0000}};
  int check = 1088418716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok346) {
  // -6.9984876887600164874297156129
  s21_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x801C0000}};
  int check = -1059064932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok347) {
  // 26409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};
  int check = 1856678571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok348) {
  // -26409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};
  int check = -290805077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok349) {
  // 69984876887600164870503268352
  s21_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x0}};
  int check = 1868702242;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok350) {
  // -69984876887600164870503268352
  s21_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x80000000}};
  int check = -278781406;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok351) {
  // 2640938750475477919641632768.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};
  int check = 1829275785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok352) {
  // -2640938750475477919641632768.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};
  int check = -318207863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok353) {
  // 6998487688760016487050326835.2
  s21_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x10000}};
  int check = 1840572443;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok354) {
  // -6998487688760016487050326835.2
  s21_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x80010000}};
  int check = -306911205;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok355) {
  // 264093875.04754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x140000}};
  int check = 1299962891;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok356) {
  // -264093875.04754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80140000}};
  int check = -847520757;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok357) {
  // 699848768.87600164870503268352
  s21_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x140000}};
  int check = 1311169377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok358) {
  // -699848768.87600164870503268352
  s21_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x80140000}};
  int check = -836314271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok359) {
  // 2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 1076430116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok360) {
  // -2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -1071053532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok361) {
  // 6.9984876887600164870503268352
  s21_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x1C0000}};
  int check = 1088418716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok362) {
  // -6.9984876887600164870503268352
  s21_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x801C0000}};
  int check = -1059064932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok363) {
  // 26409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};
  int check = 1856678571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok364) {
  // -26409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  int check = -290805077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok365) {
  // 69984876871305540946314273313
  s21_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x0}};
  int check = 1868702242;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok366) {
  // -69984876871305540946314273313
  s21_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x80000000}};
  int check = -278781406;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok367) {
  // 2640938749860586450804312200.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};
  int check = 1829275785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok368) {
  // -2640938749860586450804312200.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};
  int check = -318207863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok369) {
  // 6998487687130554094631427331.3
  s21_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x10000}};
  int check = 1840572443;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok370) {
  // -6998487687130554094631427331.3
  s21_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x80010000}};
  int check = -306911205;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok371) {
  // 264093874.98605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x140000}};
  int check = 1299962891;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok372) {
  // -264093874.98605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80140000}};
  int check = -847520757;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok373) {
  // 699848768.71305540946314273313
  s21_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x140000}};
  int check = 1311169377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok374) {
  // -699848768.71305540946314273313
  s21_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x80140000}};
  int check = -836314271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok375) {
  // 2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  int check = 1076430116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok376) {
  // -2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  int check = -1071053532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok377) {
  // 6.9984876871305540946314273313
  s21_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x1C0000}};
  int check = 1088418716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok378) {
  // -6.9984876871305540946314273313
  s21_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x801C0000}};
  int check = -1059064932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok379) {
  // 26409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};
  int check = 1856678571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok380) {
  // -26409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};
  int check = -290805077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok381) {
  // 69984876871305540942520385536
  s21_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x0}};
  int check = 1868702242;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok382) {
  // -69984876871305540942520385536
  s21_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x80000000}};
  int check = -278781406;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok383) {
  // 2640938749860586450661146624.0
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};
  int check = 1829275785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok384) {
  // -2640938749860586450661146624.0
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};
  int check = -318207863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok385) {
  // 6998487687130554094252038553.6
  s21_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x10000}};
  int check = 1840572443;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok386) {
  // -6998487687130554094252038553.6
  s21_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x80010000}};
  int check = -306911205;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok387) {
  // 264093874.98605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x140000}};
  int check = 1299962891;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok388) {
  // -264093874.98605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80140000}};
  int check = -847520757;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok389) {
  // 699848768.71305540942520385536
  s21_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x140000}};
  int check = 1311169377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok390) {
  // -699848768.71305540942520385536
  s21_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x80140000}};
  int check = -836314271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok391) {
  // 2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  int check = 1076430116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok392) {
  // -2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  int check = -1071053532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok393) {
  // 6.9984876871305540942520385536
  s21_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x1C0000}};
  int check = 1088418716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok394) {
  // -6.9984876871305540942520385536
  s21_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x801C0000}};
  int check = -1059064932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok395) {
  // 6148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};
  int check = 1588243115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok396) {
  // -6148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  int check = -559240533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok397) {
  // 16294623931776770593.25
  s21_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x20000}};
  int check = 1600266786;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok398) {
  // -16294623931776770593.25
  s21_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x80020000}};
  int check = -547216862;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok399) {
  // 614891469123651720.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};
  int check = 1560840329;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok400) {
  // -614891469123651720.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};
  int check = -586643319;

  test_from_decimal_to_float(decimal, check);
}
Suite *from_decimal_to_float_suite1(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[45m-=S21_FROM_DECIMAL_TO_FLOAT=-\033[0m");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok3);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok4);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok5);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok6);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok7);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok8);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok9);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok10);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok11);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok12);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok13);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok14);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok15);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok16);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok17);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok18);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok19);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok20);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok21);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok22);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok23);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok24);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok25);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok26);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok27);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok28);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok29);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok30);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok31);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok32);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok33);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok34);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok35);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok36);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok37);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok38);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok39);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok40);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok41);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok42);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok43);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok44);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok45);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok46);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok47);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok48);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok49);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok50);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok51);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok52);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok53);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok54);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok55);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok56);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok57);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok58);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok59);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok60);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok61);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok62);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok63);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok64);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok65);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok66);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok67);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok68);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok69);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok70);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok71);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok72);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok73);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok74);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok75);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok76);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok77);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok78);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok79);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok80);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok81);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok82);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok83);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok84);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok85);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok86);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok87);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok88);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok89);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok90);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok91);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok92);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok93);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok94);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok95);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok96);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok97);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok98);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok99);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok100);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok101);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok102);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok103);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok104);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok105);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok106);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok107);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok108);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok109);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok110);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok111);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok112);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok113);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok114);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok115);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok116);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok117);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok118);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok119);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok120);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok121);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok122);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok123);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok124);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok125);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok126);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok127);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok128);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok129);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok130);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok131);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok132);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok133);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok134);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok135);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok136);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok137);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok138);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok139);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok140);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok141);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok142);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok143);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok144);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok145);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok146);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok147);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok148);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok149);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok150);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok151);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok152);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok153);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok154);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok155);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok156);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok157);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok158);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok159);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok160);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok161);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok162);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok163);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok164);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok165);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok166);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok167);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok168);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok169);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok170);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok171);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok172);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok173);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok174);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok175);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok176);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok177);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok178);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok179);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok180);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok181);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok182);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok183);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok184);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok185);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok186);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok187);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok188);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok189);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok190);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok191);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok192);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok193);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok194);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok195);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok196);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok197);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok198);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok199);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok200);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok201);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok202);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok203);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok204);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok205);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok206);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok207);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok208);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok209);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok210);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok211);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok212);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok213);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok214);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok215);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok216);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok217);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok218);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok219);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok220);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok221);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok222);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok223);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok224);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok225);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok226);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok227);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok228);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok229);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok230);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok231);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok232);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok233);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok234);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok235);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok236);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok237);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok238);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok239);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok240);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok241);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok242);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok243);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok244);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok245);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok246);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok247);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok248);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok249);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok250);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok251);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok252);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok253);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok254);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok255);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok256);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok257);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok258);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok259);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok260);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok261);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok262);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok263);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok264);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok265);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok266);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok267);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok268);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok269);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok270);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok271);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok272);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok273);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok274);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok275);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok276);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok277);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok278);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok279);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok280);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok281);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok282);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok283);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok284);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok285);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok286);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok287);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok288);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok289);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok290);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok291);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok292);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok293);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok294);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok295);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok296);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok297);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok298);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok299);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok300);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok301);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok302);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok303);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok304);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok305);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok306);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok307);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok308);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok309);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok310);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok311);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok312);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok313);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok314);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok315);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok316);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok317);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok318);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok319);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok320);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok321);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok322);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok323);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok324);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok325);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok326);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok327);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok328);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok329);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok330);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok331);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok332);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok333);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok334);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok335);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok336);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok337);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok338);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok339);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok340);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok341);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok342);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok343);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok344);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok345);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok346);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok347);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok348);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok349);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok350);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok351);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok352);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok353);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok354);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok355);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok356);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok357);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok358);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok359);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok360);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok361);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok362);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok363);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok364);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok365);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok366);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok367);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok368);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok369);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok370);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok371);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok372);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok373);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok374);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok375);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok376);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok377);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok378);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok379);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok380);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok381);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok382);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok383);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok384);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok385);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok386);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok387);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok388);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok389);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok390);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok391);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok392);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok393);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok394);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok395);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok396);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok397);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok398);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok399);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_from_decimal_to_float(s21_decimal decimal, int check) {
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  float_cast_test cast_result;
  cast_result.f = result;

  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
}
