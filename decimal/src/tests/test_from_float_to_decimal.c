#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_decimal.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_from_float_to_decimal_ok1) {
  // 2.28401628E-19
  int f = 545706772;
  // 0.0000000000000000002284016
  s21_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2) {
  // -2.28401628E-19
  int f = -1601776876;
  // -0.0000000000000000002284016
  s21_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok3) {
  // 5.92141241E+23
  int f = 1727711253;
  // 592141200000000000000000
  s21_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok4) {
  // -5.92141241E+23
  int f = -419772395;
  // -592141200000000000000000
  s21_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok5) {
  // 2.1349025E-18
  int f = 572360491;
  // 0.000000000000000002134902
  s21_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok6) {
  // -2.1349025E-18
  int f = -1575123157;
  // -0.000000000000000002134902
  s21_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok7) {
  // 2.38582807E-08
  int f = 852291818;
  // 0.00000002385828
  s21_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok8) {
  // -2.38582807E-08
  int f = -1295191830;
  // -0.00000002385828
  s21_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok9) {
  // 7.91617864E+11
  int f = 1396199450;
  // 791617900000
  s21_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok10) {
  // -7.91617864E+11
  int f = -751284198;
  // -791617900000
  s21_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok11) {
  // 1.99102057E+21
  int f = 1658314220;
  // 1991021000000000000000
  s21_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok12) {
  // -1.99102057E+21
  int f = -489169428;
  // -1991021000000000000000
  s21_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok13) {
  // 9.29209423E+24
  int f = 1760949678;
  // 9292094000000000000000000
  s21_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok14) {
  // -9.29209423E+24
  int f = -386533970;
  // -9292094000000000000000000
  s21_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok15) {
  // 0.000115481133
  int f = 955395702;
  // 0.0001154811
  s21_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok16) {
  // -0.000115481133
  int f = -1192087946;
  // -0.0001154811
  s21_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok17) {
  // 8.66900895E-23
  int f = 449944209;
  // 0.0000000000000000000000866901
  s21_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok18) {
  // -8.66900895E-23
  int f = -1697539439;
  // -0.0000000000000000000000866901
  s21_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok19) {
  // 3.91406387E+11
  int f = 1387676487;
  // 391406400000
  s21_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok20) {
  // -3.91406387E+11
  int f = -759807161;
  // -391406400000
  s21_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok21) {
  // 1.54636995E-16
  int f = 624052425;
  // 0.000000000000000154637
  s21_decimal decimal_check = {{0x25C0D, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok22) {
  // -1.54636995E-16
  int f = -1523431223;
  // -0.000000000000000154637
  s21_decimal decimal_check = {{0x25C0D, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok23) {
  // 1.05583253E-13
  int f = 703447194;
  // 0.0000000000001055833
  s21_decimal decimal_check = {{0x101C59, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok24) {
  // -1.05583253E-13
  int f = -1444036454;
  // -0.0000000000001055833
  s21_decimal decimal_check = {{0x101C59, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok25) {
  // 4882.71582
  int f = 1167627706;
  // 4882.716
  s21_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok26) {
  // -4882.71582
  int f = -979855942;
  // -4882.716
  s21_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok27) {
  // 1.9929916E-26
  int f = 348479575;
  // 0.0000000000000000000000000199
  s21_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok28) {
  // -1.9929916E-26
  int f = -1799004073;
  // -0.0000000000000000000000000199
  s21_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok29) {
  // 3574.10864
  int f = 1163878845;
  // 3574.109
  s21_decimal decimal_check = {{0x36895D, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok30) {
  // -3574.10864
  int f = -983604803;
  // -3574.109
  s21_decimal decimal_check = {{0x36895D, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok31) {
  // 3.62930687E-13
  int f = 718032851;
  // 0.0000000000003629307
  s21_decimal decimal_check = {{0x3760FB, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok32) {
  // -3.62930687E-13
  int f = -1429450797;
  // -0.0000000000003629307
  s21_decimal decimal_check = {{0x3760FB, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok33) {
  // 2.1409382E-19
  int f = 545047011;
  // 0.0000000000000000002140938
  s21_decimal decimal_check = {{0x20AB0A, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok34) {
  // -2.1409382E-19
  int f = -1602436637;
  // -0.0000000000000000002140938
  s21_decimal decimal_check = {{0x20AB0A, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok35) {
  // 241.244507
  int f = 1131495064;
  // 241.2445
  s21_decimal decimal_check = {{0x24CF9D, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok36) {
  // -241.244507
  int f = -1015988584;
  // -241.2445
  s21_decimal decimal_check = {{0x24CF9D, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok37) {
  // 802580.063
  int f = 1229189441;
  // 802580.1
  s21_decimal decimal_check = {{0x7A76C9, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok38) {
  // -802580.063
  int f = -918294207;
  // -802580.1
  s21_decimal decimal_check = {{0x7A76C9, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok39) {
  // 8.38680669E+16
  int f = 1536490184;
  // 83868070000000000
  s21_decimal decimal_check = {{0xB858FC00, 0x129F590, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok40) {
  // -8.38680669E+16
  int f = -610993464;
  // -83868070000000000
  s21_decimal decimal_check = {{0xB858FC00, 0x129F590, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok41) {
  // 3.93541897E-17
  int f = 607485242;
  // 0.00000000000000003935419
  s21_decimal decimal_check = {{0x3C0CBB, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok42) {
  // -3.93541897E-17
  int f = -1539998406;
  // -0.00000000000000003935419
  s21_decimal decimal_check = {{0x3C0CBB, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok43) {
  // 1.45764168E-20
  int f = 512338845;
  // 0.00000000000000000001457642
  s21_decimal decimal_check = {{0x163DEA, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok44) {
  // -1.45764168E-20
  int f = -1635144803;
  // -0.00000000000000000001457642
  s21_decimal decimal_check = {{0x163DEA, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok45) {
  // 1.34647118E+20
  int f = 1625920341;
  // 134647100000000000000
  s21_decimal decimal_check = {{0x207FC000, 0x4C9A980F, 0x7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok46) {
  // -1.34647118E+20
  int f = -521563307;
  // -134647100000000000000
  s21_decimal decimal_check = {{0x207FC000, 0x4C9A980F, 0x7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok47) {
  // 2.20958198E-20
  int f = 516993130;
  // 0.00000000000000000002209582
  s21_decimal decimal_check = {{0x21B72E, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok48) {
  // -2.20958198E-20
  int f = -1630490518;
  // -0.00000000000000000002209582
  s21_decimal decimal_check = {{0x21B72E, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok49) {
  // 5.36623235E-09
  int f = 834167265;
  // 0.000000005366232
  s21_decimal decimal_check = {{0x51E1D8, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok50) {
  // -5.36623235E-09
  int f = -1313316383;
  // -0.000000005366232
  s21_decimal decimal_check = {{0x51E1D8, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok51) {
  // 4.71008997E+17
  int f = 1557212038;
  // 471009000000000000
  s21_decimal decimal_check = {{0xA3031000, 0x6895C30, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok52) {
  // -4.71008997E+17
  int f = -590271610;
  // -471009000000000000
  s21_decimal decimal_check = {{0xA3031000, 0x6895C30, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok53) {
  // 2.36363464E-11
  int f = 768600146;
  // 0.00000000002363635
  s21_decimal decimal_check = {{0x2410F3, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok54) {
  // -2.36363464E-11
  int f = -1378883502;
  // -0.00000000002363635
  s21_decimal decimal_check = {{0x2410F3, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok55) {
  // 0.0255207196
  int f = 1020334292;
  // 0.02552072
  s21_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok56) {
  // -0.0255207196
  int f = -1127149356;
  // -0.02552072
  s21_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok57) {
  // 3.9575282E-24
  int f = 412686710;
  // 0.0000000000000000000000039575
  s21_decimal decimal_check = {{0x9A97, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok58) {
  // -3.9575282E-24
  int f = -1734796938;
  // -0.0000000000000000000000039575
  s21_decimal decimal_check = {{0x9A97, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok59) {
  // 0.00399137754
  int f = 998427162;
  // 0.003991378
  s21_decimal decimal_check = {{0x3CE752, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok60) {
  // -0.00399137754
  int f = -1149056486;
  // -0.003991378
  s21_decimal decimal_check = {{0x3CE752, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok61) {
  // 1.95127377E-05
  int f = 933474121;
  // 0.00001951274
  s21_decimal decimal_check = {{0x1DC62A, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok62) {
  // -1.95127377E-05
  int f = -1214009527;
  // -0.00001951274
  s21_decimal decimal_check = {{0x1DC62A, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok63) {
  // 1.26745242E-20
  int f = 510618173;
  // 0.00000000000000000001267452
  s21_decimal decimal_check = {{0x1356FC, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok64) {
  // -1.26745242E-20
  int f = -1636865475;
  // -0.00000000000000000001267452
  s21_decimal decimal_check = {{0x1356FC, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok65) {
  // 0.0764362067
  int f = 1033669270;
  // 0.07643621
  s21_decimal decimal_check = {{0x74A1E5, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok66) {
  // -0.0764362067
  int f = -1113814378;
  // -0.07643621
  s21_decimal decimal_check = {{0x74A1E5, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok67) {
  // 1.19421885E-18
  int f = 565197904;
  // 0.000000000000000001194219
  s21_decimal decimal_check = {{0x1238EB, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok68) {
  // -1.19421885E-18
  int f = -1582285744;
  // -0.000000000000000001194219
  s21_decimal decimal_check = {{0x1238EB, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok69) {
  // 7.93902012E-16
  int f = 644141985;
  // 0.000000000000000793902
  s21_decimal decimal_check = {{0xC1D2E, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok70) {
  // -7.93902012E-16
  int f = -1503341663;
  // -0.000000000000000793902
  s21_decimal decimal_check = {{0xC1D2E, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok71) {
  // 5.86327048E-15
  int f = 668155680;
  // 0.00000000000000586327
  s21_decimal decimal_check = {{0x8F257, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok72) {
  // -5.86327048E-15
  int f = -1479327968;
  // -0.00000000000000586327
  s21_decimal decimal_check = {{0x8F257, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok73) {
  // 8.52215659E-11
  int f = 784033658;
  // 0.00000000008522157
  s21_decimal decimal_check = {{0x8209AD, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok74) {
  // -8.52215659E-11
  int f = -1363449990;
  // -0.00000000008522157
  s21_decimal decimal_check = {{0x8209AD, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok75) {
  // 9.61645806E-28
  int f = 311976189;
  // 0.000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok76) {
  // -9.61645806E-28
  int f = -1835507459;
  // -0.000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok77) {
  // 46282560
  int f = 1278250448;
  // 46282560
  s21_decimal decimal_check = {{0x2C23740, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok78) {
  // -46282560
  int f = -869233200;
  // -46282560
  s21_decimal decimal_check = {{0x2C23740, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok79) {
  // 1.15109615E-12
  int f = 732037276;
  // 0.000000000001151096
  s21_decimal decimal_check = {{0x119078, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok80) {
  // -1.15109615E-12
  int f = -1415446372;
  // -0.000000000001151096
  s21_decimal decimal_check = {{0x119078, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok81) {
  // 2.83794689E-11
  int f = 771334370;
  // 0.00000000002837947
  s21_decimal decimal_check = {{0x2B4DBB, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok82) {
  // -2.83794689E-11
  int f = -1376149278;
  // -0.00000000002837947
  s21_decimal decimal_check = {{0x2B4DBB, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok83) {
  // 8.43187742E-10
  int f = 812107280;
  // 0.0000000008431877
  s21_decimal decimal_check = {{0x80A905, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok84) {
  // -8.43187742E-10
  int f = -1335376368;
  // -0.0000000008431877
  s21_decimal decimal_check = {{0x80A905, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok85) {
  // 9.83161032E+17
  int f = 1566199356;
  // 983161000000000000
  s21_decimal decimal_check = {{0x72049000, 0xDA4E3B8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok86) {
  // -9.83161032E+17
  int f = -581284292;
  // -983161000000000000
  s21_decimal decimal_check = {{0x72049000, 0xDA4E3B8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok87) {
  // 5010.18115
  int f = 1167888755;
  // 5010.181
  s21_decimal decimal_check = {{0x4C7305, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok88) {
  // -5010.18115
  int f = -979594893;
  // -5010.181
  s21_decimal decimal_check = {{0x4C7305, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok89) {
  // 5.82704236E-25
  int f = 389306006;
  // 0.0000000000000000000000005827
  s21_decimal decimal_check = {{0x16C3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok90) {
  // -5.82704236E-25
  int f = -1758177642;
  // -0.0000000000000000000000005827
  s21_decimal decimal_check = {{0x16C3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok91) {
  // 5.07265574E+16
  int f = 1530148745;
  // 50726560000000000
  s21_decimal decimal_check = {{0x9D7A4000, 0xB43789, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok92) {
  // -5.07265574E+16
  int f = -617334903;
  // -50726560000000000
  s21_decimal decimal_check = {{0x9D7A4000, 0xB43789, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok93) {
  // 1.35639493E+19
  int f = 1597783252;
  // 13563950000000000000
  s21_decimal decimal_check = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok94) {
  // -1.35639493E+19
  int f = -549700396;
  // -13563950000000000000
  s21_decimal decimal_check = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok95) {
  // 1.2867606E+27
  int f = 1820658757;
  // 1286761000000000000000000000
  s21_decimal decimal_check = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok96) {
  // -1.2867606E+27
  int f = -326824891;
  // -1286761000000000000000000000
  s21_decimal decimal_check = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok97) {
  // 9.07980924E+20
  int f = 1648681745;
  // 907980900000000000000
  s21_decimal decimal_check = {{0x6B7A4000, 0x38C429DC, 0x31, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok98) {
  // -9.07980924E+20
  int f = -498801903;
  // -907980900000000000000
  s21_decimal decimal_check = {{0x6B7A4000, 0x38C429DC, 0x31, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok99) {
  // 15372566
  int f = 1265275158;
  // 15372570
  s21_decimal decimal_check = {{0xEA911A, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok100) {
  // -15372566
  int f = -882208490;
  // -15372570
  s21_decimal decimal_check = {{0xEA911A, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok101) {
  // 9.85001198E-23
  int f = 451815583;
  // 0.0000000000000000000000985001
  s21_decimal decimal_check = {{0xF07A9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok102) {
  // -9.85001198E-23
  int f = -1695668065;
  // -0.0000000000000000000000985001
  s21_decimal decimal_check = {{0xF07A9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok103) {
  // 4.58205132E-12
  int f = 748762995;
  // 0.000000000004582051
  s21_decimal decimal_check = {{0x45EAA3, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok104) {
  // -4.58205132E-12
  int f = -1398720653;
  // -0.000000000004582051
  s21_decimal decimal_check = {{0x45EAA3, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok105) {
  // 6.88863376E-12
  int f = 754081612;
  // 0.000000000006888634
  s21_decimal decimal_check = {{0x691CBA, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok106) {
  // -6.88863376E-12
  int f = -1393402036;
  // -0.000000000006888634
  s21_decimal decimal_check = {{0x691CBA, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok107) {
  // 1.94770514E+10
  int f = 1351687559;
  // 19477050000
  s21_decimal decimal_check = {{0x88EC3290, 0x4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok108) {
  // -1.94770514E+10
  int f = -795796089;
  // -19477050000
  s21_decimal decimal_check = {{0x88EC3290, 0x4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok109) {
  // 0.000745483907
  int f = 977497236;
  // 0.0007454839
  s21_decimal decimal_check = {{0x71C077, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok110) {
  // -0.000745483907
  int f = -1169986412;
  // -0.0007454839
  s21_decimal decimal_check = {{0x71C077, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok111) {
  // 7.85835969E+18
  int f = 1591352577;
  // 7858360000000000000
  s21_decimal decimal_check = {{0xDD238000, 0x6D0E80C8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok112) {
  // -7.85835969E+18
  int f = -556131071;
  // -7858360000000000000
  s21_decimal decimal_check = {{0xDD238000, 0x6D0E80C8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok113) {
  // 4.39337262E+21
  int f = 1668164171;
  // 4393373000000000000000
  s21_decimal decimal_check = {{0x883C8000, 0x2A4C5A69, 0xEE, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok114) {
  // -4.39337262E+21
  int f = -479319477;
  // -4393373000000000000000
  s21_decimal decimal_check = {{0x883C8000, 0x2A4C5A69, 0xEE, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok115) {
  // 4.8940947E+19
  int f = 1613352011;
  // 48940950000000000000
  s21_decimal decimal_check = {{0x88276000, 0xA7312EB9, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok116) {
  // -4.8940947E+19
  int f = -534131637;
  // -48940950000000000000
  s21_decimal decimal_check = {{0x88276000, 0xA7312EB9, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok117) {
  // 2.1753997E+18
  int f = 1576109204;
  // 2175400000000000000
  s21_decimal decimal_check = {{0x34628000, 0x1E3092C6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok118) {
  // -2.1753997E+18
  int f = -571374444;
  // -2175400000000000000
  s21_decimal decimal_check = {{0x34628000, 0x1E3092C6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok119) {
  // 8.42251829E+11
  int f = 1396972063;
  // 842251800000
  s21_decimal decimal_check = {{0x1A1E8DC0, 0xC4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok120) {
  // -8.42251829E+11
  int f = -750511585;
  // -842251800000
  s21_decimal decimal_check = {{0x1A1E8DC0, 0xC4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok121) {
  // 4.26393967E-07
  int f = 887417636;
  // 0.000000426394
  s21_decimal decimal_check = {{0x6819A, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok122) {
  // -4.26393967E-07
  int f = -1260066012;
  // -0.000000426394
  s21_decimal decimal_check = {{0x6819A, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok123) {
  // 1.84532337E-12
  int f = 738318948;
  // 0.000000000001845323
  s21_decimal decimal_check = {{0x1C284B, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok124) {
  // -1.84532337E-12
  int f = -1409164700;
  // -0.000000000001845323
  s21_decimal decimal_check = {{0x1C284B, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok125) {
  // 7.70974401E-20
  int f = 532023947;
  // 0.00000000000000000007709744
  s21_decimal decimal_check = {{0x75A430, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok126) {
  // -7.70974401E-20
  int f = -1615459701;
  // -0.00000000000000000007709744
  s21_decimal decimal_check = {{0x75A430, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok127) {
  // 0.0104842195
  int f = 1009501697;
  // 0.01048422
  s21_decimal decimal_check = {{0xFFF66, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok128) {
  // -0.0104842195
  int f = -1137981951;
  // -0.01048422
  s21_decimal decimal_check = {{0xFFF66, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok129) {
  // 1.98140566E-22
  int f = 460294537;
  // 0.0000000000000000000001981406
  s21_decimal decimal_check = {{0x1E3BDE, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok130) {
  // -1.98140566E-22
  int f = -1687189111;
  // -0.0000000000000000000001981406
  s21_decimal decimal_check = {{0x1E3BDE, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok131) {
  // 1.17932588E+22
  int f = 1679807510;
  // 11793260000000000000000
  s21_decimal decimal_check = {{0x6F3E0000, 0x505C1EA1, 0x27F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok132) {
  // -1.17932588E+22
  int f = -467676138;
  // -11793260000000000000000
  s21_decimal decimal_check = {{0x6F3E0000, 0x505C1EA1, 0x27F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok133) {
  // 356700.438
  int f = 1219373966;
  // 356700.4
  s21_decimal decimal_check = {{0x366D9C, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok134) {
  // -356700.438
  int f = -928109682;
  // -356700.4
  s21_decimal decimal_check = {{0x366D9C, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok135) {
  // 4.27844415E-17
  int f = 608521972;
  // 0.00000000000000004278444
  s21_decimal decimal_check = {{0x4148AC, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok136) {
  // -4.27844415E-17
  int f = -1538961676;
  // -0.00000000000000004278444
  s21_decimal decimal_check = {{0x4148AC, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok137) {
  // 12419649
  int f = 1262322241;
  // 12419650
  s21_decimal decimal_check = {{0xBD8242, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok138) {
  // -12419649
  int f = -885161407;
  // -12419650
  s21_decimal decimal_check = {{0xBD8242, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok139) {
  // 3.08497797E-21
  int f = 493426727;
  // 0.000000000000000000003084978
  s21_decimal decimal_check = {{0x2F12B2, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok140) {
  // -3.08497797E-21
  int f = -1654056921;
  // -0.000000000000000000003084978
  s21_decimal decimal_check = {{0x2F12B2, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok141) {
  // 4.18459603E+15
  int f = 1500372451;
  // 4184596000000000
  s21_decimal decimal_check = {{0x2E1BC800, 0xEDDDE, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok142) {
  // -4.18459603E+15
  int f = -647111197;
  // -4184596000000000
  s21_decimal decimal_check = {{0x2E1BC800, 0xEDDDE, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok143) {
  // 1.16865436E+26
  int f = 1791055472;
  // 116865400000000000000000000
  s21_decimal decimal_check = {{0xBAE00000, 0x7467DF7, 0x60AB36, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok144) {
  // -1.16865436E+26
  int f = -356428176;
  // -116865400000000000000000000
  s21_decimal decimal_check = {{0xBAE00000, 0x7467DF7, 0x60AB36, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok145) {
  // 2.70840103E+12
  int f = 1411229266;
  // 2708401000000
  s21_decimal decimal_check = {{0x99478E40, 0x276, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok146) {
  // -2.70840103E+12
  int f = -736254382;
  // -2708401000000
  s21_decimal decimal_check = {{0x99478E40, 0x276, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok147) {
  // 6.74712444E-21
  int f = 503244335;
  // 0.000000000000000000006747124
  s21_decimal decimal_check = {{0x66F3F4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok148) {
  // -6.74712444E-21
  int f = -1644239313;
  // -0.000000000000000000006747124
  s21_decimal decimal_check = {{0x66F3F4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok149) {
  // 5.64592297E-11
  int f = 779636593;
  // 0.00000000005645923
  s21_decimal decimal_check = {{0x562663, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok150) {
  // -5.64592297E-11
  int f = -1367847055;
  // -0.00000000005645923
  s21_decimal decimal_check = {{0x562663, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok151) {
  // 4.58151199E+10
  int f = 1361751220;
  // 45815120000
  s21_decimal decimal_check = {{0xAACB4080, 0xA, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok152) {
  // -4.58151199E+10
  int f = -785732428;
  // -45815120000
  s21_decimal decimal_check = {{0xAACB4080, 0xA, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok153) {
  // 1.48573706E-20
  int f = 512512747;
  // 0.00000000000000000001485737
  s21_decimal decimal_check = {{0x16ABA9, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok154) {
  // -1.48573706E-20
  int f = -1634970901;
  // -0.00000000000000000001485737
  s21_decimal decimal_check = {{0x16ABA9, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok155) {
  // 1.40592974E-22
  int f = 455735147;
  // 0.000000000000000000000140593
  s21_decimal decimal_check = {{0x22531, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok156) {
  // -1.40592974E-22
  int f = -1691748501;
  // -0.000000000000000000000140593
  s21_decimal decimal_check = {{0x22531, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok157) {
  // 1.83958331E+22
  int f = 1685671774;
  // 18395830000000000000000
  s21_decimal decimal_check = {{0x2A1F0000, 0x3D6CDFB7, 0x3E5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok158) {
  // -1.83958331E+22
  int f = -461811874;
  // -18395830000000000000000
  s21_decimal decimal_check = {{0x2A1F0000, 0x3D6CDFB7, 0x3E5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok159) {
  // 1.04831784E-07
  int f = 870391778;
  // 0.0000001048318
  s21_decimal decimal_check = {{0xFFEFE, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok160) {
  // -1.04831784E-07
  int f = -1277091870;
  // -0.0000001048318
  s21_decimal decimal_check = {{0xFFEFE, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok161) {
  // 3.40432057E+16
  int f = 1525802043;
  // 34043210000000000
  s21_decimal decimal_check = {{0x7F106400, 0x78F21E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok162) {
  // -3.40432057E+16
  int f = -621681605;
  // -34043210000000000
  s21_decimal decimal_check = {{0x7F106400, 0x78F21E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok163) {
  // 4.44212428E-21
  int f = 497537431;
  // 0.000000000000000000004442124
  s21_decimal decimal_check = {{0x43C80C, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok164) {
  // -4.44212428E-21
  int f = -1649946217;
  // -0.000000000000000000004442124
  s21_decimal decimal_check = {{0x43C80C, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok165) {
  // 2.77922045E-05
  int f = 938025806;
  // 0.0000277922
  s21_decimal decimal_check = {{0x43DA2, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok166) {
  // -2.77922045E-05
  int f = -1209457842;
  // -0.0000277922
  s21_decimal decimal_check = {{0x43DA2, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok167) {
  // 2.47787305E-13
  int f = 713784810;
  // 0.0000000000002477873
  s21_decimal decimal_check = {{0x25CF31, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok168) {
  // -2.47787305E-13
  int f = -1433698838;
  // -0.0000000000002477873
  s21_decimal decimal_check = {{0x25CF31, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok169) {
  // 8.1853854E-19
  int f = 561092358;
  // 0.0000000000000000008185385
  s21_decimal decimal_check = {{0x7CE629, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok170) {
  // -8.1853854E-19
  int f = -1586391290;
  // -0.0000000000000000008185385
  s21_decimal decimal_check = {{0x7CE629, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok171) {
  // 2.11021068E+24
  int f = 1742695776;
  // 2110211000000000000000000
  s21_decimal decimal_check = {{0xE22C0000, 0xC47CDAF3, 0x1BEDA, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok172) {
  // -2.11021068E+24
  int f = -404787872;
  // -2110211000000000000000000
  s21_decimal decimal_check = {{0xE22C0000, 0xC47CDAF3, 0x1BEDA, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok173) {
  // 1.82873229E+09
  int f = 1322909819;
  // 1828732000
  s21_decimal decimal_check = {{0x6D003C60, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok174) {
  // -1.82873229E+09
  int f = -824573829;
  // -1828732000
  s21_decimal decimal_check = {{0x6D003C60, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok175) {
  // 3807398.25
  int f = 1248354969;
  // 3807398
  s21_decimal decimal_check = {{0x3A18A6, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok176) {
  // -3807398.25
  int f = -899128679;
  // -3807398
  s21_decimal decimal_check = {{0x3A18A6, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok177) {
  // 807.082397
  int f = 1145685318;
  // 807.0824
  s21_decimal decimal_check = {{0x7B26A8, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok178) {
  // -807.082397
  int f = -1001798330;
  // -807.0824
  s21_decimal decimal_check = {{0x7B26A8, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok179) {
  // 1.00471938E-16
  int f = 619162666;
  // 0.0000000000000001004719
  s21_decimal decimal_check = {{0xF54AF, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok180) {
  // -1.00471938E-16
  int f = -1528320982;
  // -0.0000000000000001004719
  s21_decimal decimal_check = {{0xF54AF, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok181) {
  // 1.31486965E-18
  int f = 566364767;
  // 0.00000000000000000131487
  s21_decimal decimal_check = {{0x2019F, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok182) {
  // -1.31486965E-18
  int f = -1581118881;
  // -0.00000000000000000131487
  s21_decimal decimal_check = {{0x2019F, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok183) {
  // 8.47554286E-13
  int f = 728666297;
  // 0.0000000000008475543
  s21_decimal decimal_check = {{0x815397, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok184) {
  // -8.47554286E-13
  int f = -1418817351;
  // -0.0000000000008475543
  s21_decimal decimal_check = {{0x815397, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok185) {
  // 2.07975469E-28
  int f = 293851635;
  // 0.0000000000000000000000000002
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok186) {
  // -2.07975469E-28
  int f = -1853632013;
  // -0.0000000000000000000000000002
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok187) {
  // 2.76817269E+13
  int f = 1439263036;
  // 27681730000000
  s21_decimal decimal_check = {{0x27AEF480, 0x192D, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok188) {
  // -2.76817269E+13
  int f = -708220612;
  // -27681730000000
  s21_decimal decimal_check = {{0x27AEF480, 0x192D, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok189) {
  // 2.64643858E+12
  int f = 1410992898;
  // 2646439000000
  s21_decimal decimal_check = {{0x2C0E77C0, 0x268, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok190) {
  // -2.64643858E+12
  int f = -736490750;
  // -2646439000000
  s21_decimal decimal_check = {{0x2C0E77C0, 0x268, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok191) {
  // 7.66456801E+18
  int f = 1591000072;
  // 7664568000000000000
  s21_decimal decimal_check = {{0xC4D38000, 0x6A5E03FC, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok192) {
  // -7.66456801E+18
  int f = -556483576;
  // -7664568000000000000
  s21_decimal decimal_check = {{0xC4D38000, 0x6A5E03FC, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok193) {
  // 2.76005793E+27
  int f = 1829679376;
  // 2760058000000000000000000000
  s21_decimal decimal_check = {{0x38400000, 0xFD42C0C4, 0x8EB1103, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok194) {
  // -2.76005793E+27
  int f = -317804272;
  // -2760058000000000000000000000
  s21_decimal decimal_check = {{0x38400000, 0xFD42C0C4, 0x8EB1103, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok195) {
  // 4.72614865E-19
  int f = 554401221;
  // 0.0000000000000000004726149
  s21_decimal decimal_check = {{0x481D85, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok196) {
  // -4.72614865E-19
  int f = -1593082427;
  // -0.0000000000000000004726149
  s21_decimal decimal_check = {{0x481D85, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok197) {
  // 1.22559799E-13
  int f = 705297781;
  // 0.0000000000001225598
  s21_decimal decimal_check = {{0x12B37E, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok198) {
  // -1.22559799E-13
  int f = -1442185867;
  // -0.0000000000001225598
  s21_decimal decimal_check = {{0x12B37E, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok199) {
  // 4.67068756E+27
  int f = 1836152841;
  // 4670688000000000000000000000
  s21_decimal decimal_check = {{0x4C000000, 0xD4815AA5, 0xF1780A7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok200) {
  // -4.67068756E+27
  int f = -311330807;
  // -4670688000000000000000000000
  s21_decimal decimal_check = {{0x4C000000, 0xD4815AA5, 0xF1780A7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok201) {
  // 1.43260896E-27
  int f = 316866950;
  // 0.0000000000000000000000000014
  s21_decimal decimal_check = {{0xE, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok202) {
  // -1.43260896E-27
  int f = -1830616698;
  // -0.0000000000000000000000000014
  s21_decimal decimal_check = {{0xE, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok203) {
  // 0.00161657971
  int f = 986964842;
  // 0.00161658
  s21_decimal decimal_check = {{0x2777A, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok204) {
  // -0.00161657971
  int f = -1160518806;
  // -0.00161658
  s21_decimal decimal_check = {{0x2777A, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok205) {
  // 1.11468367E-18
  int f = 564428687;
  // 0.000000000000000001114684
  s21_decimal decimal_check = {{0x11023C, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok206) {
  // -1.11468367E-18
  int f = -1583054961;
  // -0.000000000000000001114684
  s21_decimal decimal_check = {{0x11023C, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok207) {
  // 1478.01416
  int f = 1152958580;
  // 1478.014
  s21_decimal decimal_check = {{0x168D7E, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok208) {
  // -1478.01416
  int f = -994525068;
  // -1478.014
  s21_decimal decimal_check = {{0x168D7E, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok209) {
  // 3.6517143E+09
  int f = 1331275965;
  // 3651714000
  s21_decimal decimal_check = {{0xD9A8BBD0, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok210) {
  // -3.6517143E+09
  int f = -816207683;
  // -3651714000
  s21_decimal decimal_check = {{0xD9A8BBD0, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok211) {
  // 2.08207478E+25
  int f = 1770637240;
  // 20820750000000000000000000
  s21_decimal decimal_check = {{0x13780000, 0x1E7FE2B2, 0x1138F7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok212) {
  // -2.08207478E+25
  int f = -376846408;
  // -20820750000000000000000000
  s21_decimal decimal_check = {{0x13780000, 0x1E7FE2B2, 0x1138F7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok213) {
  // 1.67284952E-06
  int f = 903906988;
  // 0.00000167285
  s21_decimal decimal_check = {{0x28D75, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok214) {
  // -1.67284952E-06
  int f = -1243576660;
  // -0.00000167285
  s21_decimal decimal_check = {{0x28D75, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok215) {
  // 1.00791645E+27
  int f = 1817210535;
  // 1007916000000000000000000000
  s21_decimal decimal_check = {{0xE3800000, 0xD819E2BC, 0x341BA83, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok216) {
  // -1.00791645E+27
  int f = -330273113;
  // -1007916000000000000000000000
  s21_decimal decimal_check = {{0xE3800000, 0xD819E2BC, 0x341BA83, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok217) {
  // 6.66145091E-18
  int f = 586531744;
  // 0.000000000000000006661451
  s21_decimal decimal_check = {{0x65A54B, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok218) {
  // -6.66145091E-18
  int f = -1560951904;
  // -0.000000000000000006661451
  s21_decimal decimal_check = {{0x65A54B, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok219) {
  // 15725.3545
  int f = 1182119275;
  // 15725.35
  s21_decimal decimal_check = {{0x17FEB7, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok220) {
  // -15725.3545
  int f = -965364373;
  // -15725.35
  s21_decimal decimal_check = {{0x17FEB7, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok221) {
  // 1.33397293
  int f = 1068154784;
  // 1.333973
  s21_decimal decimal_check = {{0x145AD5, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok222) {
  // -1.33397293
  int f = -1079328864;
  // -1.333973
  s21_decimal decimal_check = {{0x145AD5, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok223) {
  // 165025.641
  int f = 1210132585;
  // 165025.6
  s21_decimal decimal_check = {{0x192E50, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok224) {
  // -165025.641
  int f = -937351063;
  // -165025.6
  s21_decimal decimal_check = {{0x192E50, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok225) {
  // 1.2441821E+15
  int f = 1485664887;
  // 1244182000000000
  s21_decimal decimal_check = {{0xB2255C00, 0x46B93, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok226) {
  // -1.2441821E+15
  int f = -661818761;
  // -1244182000000000
  s21_decimal decimal_check = {{0xB2255C00, 0x46B93, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok227) {
  // 2.10811349E-13
  int f = 711809596;
  // 0.0000000000002108113
  s21_decimal decimal_check = {{0x202AD1, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok228) {
  // -2.10811349E-13
  int f = -1435674052;
  // -0.0000000000002108113
  s21_decimal decimal_check = {{0x202AD1, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok229) {
  // 2.40751309E+13
  int f = 1437543277;
  // 24075130000000
  s21_decimal decimal_check = {{0x6D925280, 0x15E5, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok230) {
  // -2.40751309E+13
  int f = -709940371;
  // -24075130000000
  s21_decimal decimal_check = {{0x6D925280, 0x15E5, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok231) {
  // 2.48895624E-25
  int f = 379195158;
  // 0.0000000000000000000000002489
  s21_decimal decimal_check = {{0x9B9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok232) {
  // -2.48895624E-25
  int f = -1768288490;
  // -0.0000000000000000000000002489
  s21_decimal decimal_check = {{0x9B9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok233) {
  // 1.31895402E+11
  int f = 1375055009;
  // 131895400000
  s21_decimal decimal_check = {{0xB5941640, 0x1E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok234) {
  // -1.31895402E+11
  int f = -772428639;
  // -131895400000
  s21_decimal decimal_check = {{0xB5941640, 0x1E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok235) {
  // 1.4550111E+11
  int f = 1376223787;
  // 145501100000
  s21_decimal decimal_check = {{0xE08A97E0, 0x21, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok236) {
  // -1.4550111E+11
  int f = -771259861;
  // -145501100000
  s21_decimal decimal_check = {{0xE08A97E0, 0x21, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok237) {
  // 6.25111367E-23
  int f = 446112901;
  // 0.0000000000000000000000625111
  s21_decimal decimal_check = {{0x989D7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok238) {
  // -6.25111367E-23
  int f = -1701370747;
  // -0.0000000000000000000000625111
  s21_decimal decimal_check = {{0x989D7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok239) {
  // 4.58558402E+27
  int f = 1835864499;
  // 4585584000000000000000000000
  s21_decimal decimal_check = {{0x66000000, 0xBEE8B75C, 0xED11B2E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok240) {
  // -4.58558402E+27
  int f = -311619149;
  // -4585584000000000000000000000
  s21_decimal decimal_check = {{0x66000000, 0xBEE8B75C, 0xED11B2E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok241) {
  // 3.28743145E-26
  int f = 354601253;
  // 0.0000000000000000000000000329
  s21_decimal decimal_check = {{0x149, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok242) {
  // -3.28743145E-26
  int f = -1792882395;
  // -0.0000000000000000000000000329
  s21_decimal decimal_check = {{0x149, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok243) {
  // 9.16167978E+16
  int f = 1537392255;
  // 91616800000000000
  s21_decimal decimal_check = {{0x83754000, 0x1457CFE, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok244) {
  // -9.16167978E+16
  int f = -610091393;
  // -91616800000000000
  s21_decimal decimal_check = {{0x83754000, 0x1457CFE, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok245) {
  // 0.026427852
  int f = 1020821305;
  // 0.02642785
  s21_decimal decimal_check = {{0x285361, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok246) {
  // -0.026427852
  int f = -1126662343;
  // -0.02642785
  s21_decimal decimal_check = {{0x285361, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok247) {
  // 1.24064249E-15
  int f = 649251745;
  // 0.000000000000001240642
  s21_decimal decimal_check = {{0x12EE42, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok248) {
  // -1.24064249E-15
  int f = -1498231903;
  // -0.000000000000001240642
  s21_decimal decimal_check = {{0x12EE42, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok249) {
  // 1.16119836E+15
  int f = 1485046610;
  // 1161198000000000
  s21_decimal decimal_check = {{0x7A4DCC00, 0x4201A, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok250) {
  // -1.16119836E+15
  int f = -662437038;
  // -1161198000000000
  s21_decimal decimal_check = {{0x7A4DCC00, 0x4201A, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok251) {
  // 2.50407264E-11
  int f = 769409716;
  // 0.00000000002504073
  s21_decimal decimal_check = {{0x263589, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok252) {
  // -2.50407264E-11
  int f = -1378073932;
  // -0.00000000002504073
  s21_decimal decimal_check = {{0x263589, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok253) {
  // 2.71758257E+15
  int f = 1494907400;
  // 2717583000000000
  s21_decimal decimal_check = {{0x995CD600, 0x9A7A0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok254) {
  // -2.71758257E+15
  int f = -652576248;
  // -2717583000000000
  s21_decimal decimal_check = {{0x995CD600, 0x9A7A0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok255) {
  // 9.97534673E+16
  int f = 1538339488;
  // 99753470000000000
  s21_decimal decimal_check = {{0xA0766C00, 0x1626540, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok256) {
  // -9.97534673E+16
  int f = -609144160;
  // -99753470000000000
  s21_decimal decimal_check = {{0xA0766C00, 0x1626540, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok257) {
  // 1.34486375E-15
  int f = 650236087;
  // 0.000000000000001344864
  s21_decimal decimal_check = {{0x148560, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok258) {
  // -1.34486375E-15
  int f = -1497247561;
  // -0.000000000000001344864
  s21_decimal decimal_check = {{0x148560, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok259) {
  // 1.82659161E-12
  int f = 738232563;
  // 0.000000000001826592
  s21_decimal decimal_check = {{0x1BDF20, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok260) {
  // -1.82659161E-12
  int f = -1409251085;
  // -0.000000000001826592
  s21_decimal decimal_check = {{0x1BDF20, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok261) {
  // 7.77944088
  int f = 1090056494;
  // 7.779441
  s21_decimal decimal_check = {{0x76B471, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok262) {
  // -7.77944088
  int f = -1057427154;
  // -7.779441
  s21_decimal decimal_check = {{0x76B471, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok263) {
  // 3.12144136E+16
  int f = 1524484784;
  // 31214410000000000
  s21_decimal decimal_check = {{0x2BEC6400, 0x6EE557, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok264) {
  // -3.12144136E+16
  int f = -622998864;
  // -31214410000000000
  s21_decimal decimal_check = {{0x2BEC6400, 0x6EE557, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok265) {
  // 530444320
  int f = 1308422017;
  // 530444300
  s21_decimal decimal_check = {{0x1F9DF00C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok266) {
  // -530444320
  int f = -839061631;
  // -530444300
  s21_decimal decimal_check = {{0x1F9DF00C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok267) {
  // 3.93075884E+12
  int f = 1415892191;
  // 3930759000000
  s21_decimal decimal_check = {{0x337E6FC0, 0x393, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok268) {
  // -3.93075884E+12
  int f = -731591457;
  // -3930759000000
  s21_decimal decimal_check = {{0x337E6FC0, 0x393, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok269) {
  // 7.42264215E-19
  int f = 559616998;
  // 0.0000000000000000007422642
  s21_decimal decimal_check = {{0x7142B2, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok270) {
  // -7.42264215E-19
  int f = -1587866650;
  // -0.0000000000000000007422642
  s21_decimal decimal_check = {{0x7142B2, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok271) {
  // 1.06286686E-19
  int f = 536540764;
  // 0.0000000000000000001062867
  s21_decimal decimal_check = {{0x1037D3, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok272) {
  // -1.06286686E-19
  int f = -1610942884;
  // -0.0000000000000000001062867
  s21_decimal decimal_check = {{0x1037D3, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok273) {
  // 3.94556822E+15
  int f = 1499482003;
  // 3945568000000000
  s21_decimal decimal_check = {{0x2313C000, 0xE0479, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok274) {
  // -3.94556822E+15
  int f = -648001645;
  // -3945568000000000
  s21_decimal decimal_check = {{0x2313C000, 0xE0479, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok275) {
  // 4.74276045E+09
  int f = 1334663268;
  // 4742760000
  s21_decimal decimal_check = {{0x1AB0C640, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok276) {
  // -4.74276045E+09
  int f = -812820380;
  // -4742760000
  s21_decimal decimal_check = {{0x1AB0C640, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok277) {
  // 6.8088455E-05
  int f = 948882102;
  // 0.00006808846
  s21_decimal decimal_check = {{0x67E50E, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok278) {
  // -6.8088455E-05
  int f = -1198601546;
  // -0.00006808846
  s21_decimal decimal_check = {{0x67E50E, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok279) {
  // 9.93429178E-27
  int f = 340051160;
  // 0.0000000000000000000000000099
  s21_decimal decimal_check = {{0x63, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok280) {
  // -9.93429178E-27
  int f = -1807432488;
  // -0.0000000000000000000000000099
  s21_decimal decimal_check = {{0x63, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok281) {
  // 1.2797555E-08
  int f = 844880958;
  // 0.00000001279756
  s21_decimal decimal_check = {{0x13870C, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok282) {
  // -1.2797555E-08
  int f = -1302602690;
  // -0.00000001279756
  s21_decimal decimal_check = {{0x13870C, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok283) {
  // 1.80100608
  int f = 1072072542;
  // 1.801006
  s21_decimal decimal_check = {{0x1B7B2E, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok284) {
  // -1.80100608
  int f = -1075411106;
  // -1.801006
  s21_decimal decimal_check = {{0x1B7B2E, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok285) {
  // 2.88075291E-15
  int f = 659526787;
  // 0.000000000000002880753
  s21_decimal decimal_check = {{0x2BF4F1, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok286) {
  // -2.88075291E-15
  int f = -1487956861;
  // -0.000000000000002880753
  s21_decimal decimal_check = {{0x2BF4F1, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok287) {
  // 4.98270022E+16
  int f = 1529939301;
  // 49827000000000000
  s21_decimal decimal_check = {{0x7B393000, 0xB10564, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok288) {
  // -4.98270022E+16
  int f = -617544347;
  // -49827000000000000
  s21_decimal decimal_check = {{0x7B393000, 0xB10564, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok289) {
  // 19.2353897
  int f = 1100603924;
  // 19.23539
  s21_decimal decimal_check = {{0x1D59D3, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok290) {
  // -19.2353897
  int f = -1046879724;
  // -19.23539
  s21_decimal decimal_check = {{0x1D59D3, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok291) {
  // 7.56507507E-06
  int f = 922605440;
  // 0.000007565075
  s21_decimal decimal_check = {{0x736F13, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok292) {
  // -7.56507507E-06
  int f = -1224878208;
  // -0.000007565075
  s21_decimal decimal_check = {{0x736F13, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok293) {
  // 1.72874326E-10
  int f = 792597452;
  // 0.0000000001728743
  s21_decimal decimal_check = {{0x1A60E7, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok294) {
  // -1.72874326E-10
  int f = -1354886196;
  // -0.0000000001728743
  s21_decimal decimal_check = {{0x1A60E7, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok295) {
  // 973.707092
  int f = 1148415297;
  // 973.7071
  s21_decimal decimal_check = {{0x94936F, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok296) {
  // -973.707092
  int f = -999068351;
  // -973.7071
  s21_decimal decimal_check = {{0x94936F, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok297) {
  // 5.56646213E+17
  int f = 1559704409;
  // 556646200000000000
  s21_decimal decimal_check = {{0x8923000, 0x7B99AC5, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok298) {
  // -5.56646213E+17
  int f = -587779239;
  // -556646200000000000
  s21_decimal decimal_check = {{0x8923000, 0x7B99AC5, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok299) {
  // 0.0539412126
  int f = 1029501302;
  // 0.05394121
  s21_decimal decimal_check = {{0x524EC9, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok300) {
  // -0.0539412126
  int f = -1117982346;
  // -0.05394121
  s21_decimal decimal_check = {{0x524EC9, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok301) {
  // 5.68253473E+25
  int f = 1782318321;
  // 56825350000000000000000000
  s21_decimal decimal_check = {{0x84580000, 0x6567A044, 0x2F013C, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok302) {
  // -5.68253473E+25
  int f = -365165327;
  // -56825350000000000000000000
  s21_decimal decimal_check = {{0x84580000, 0x6567A044, 0x2F013C, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok303) {
  // 1.88714903E-22
  int f = 459547759;
  // 0.0000000000000000000001887149
  s21_decimal decimal_check = {{0x1CCBAD, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok304) {
  // -1.88714903E-22
  int f = -1687935889;
  // -0.0000000000000000000001887149
  s21_decimal decimal_check = {{0x1CCBAD, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok305) {
  // 3.86104686E+21
  int f = 1666272970;
  // 3861047000000000000000
  s21_decimal decimal_check = {{0xD7A58000, 0x4ECA7DCB, 0xD1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok306) {
  // -3.86104686E+21
  int f = -481210678;
  // -3861047000000000000000
  s21_decimal decimal_check = {{0xD7A58000, 0x4ECA7DCB, 0xD1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok307) {
  // 2.58369932E-23
  int f = 435806540;
  // 0.000000000000000000000025837
  s21_decimal decimal_check = {{0x64ED, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok308) {
  // -2.58369932E-23
  int f = -1711677108;
  // -0.000000000000000000000025837
  s21_decimal decimal_check = {{0x64ED, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok309) {
  // 3.77445417E+14
  int f = 1470866542;
  // 377445400000000
  s21_decimal decimal_check = {{0xDAFD3600, 0x15748, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok310) {
  // -3.77445417E+14
  int f = -676617106;
  // -377445400000000
  s21_decimal decimal_check = {{0xDAFD3600, 0x15748, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok311) {
  // 3.96881507E-27
  int f = 329070737;
  // 0.000000000000000000000000004
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok312) {
  // -3.96881507E-27
  int f = -1818412911;
  // -0.000000000000000000000000004
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok313) {
  // 6.08972547E+16
  int f = 1532516795;
  // 60897250000000000
  s21_decimal decimal_check = {{0xEA0C5400, 0xD859B9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok314) {
  // -6.08972547E+16
  int f = -614966853;
  // -60897250000000000
  s21_decimal decimal_check = {{0xEA0C5400, 0xD859B9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok315) {
  // 4.54454516E+14
  int f = 1473161592;
  // 454454500000000
  s21_decimal decimal_check = {{0xEF0A0100, 0x19D52, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok316) {
  // -4.54454516E+14
  int f = -674322056;
  // -454454500000000
  s21_decimal decimal_check = {{0xEF0A0100, 0x19D52, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok317) {
  // 298389.375
  int f = 1217508012;
  // 298389.4
  s21_decimal decimal_check = {{0x2D87D6, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok318) {
  // -298389.375
  int f = -929975636;
  // -298389.4
  s21_decimal decimal_check = {{0x2D87D6, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok319) {
  // 7.39824756E-19
  int f = 559569812;
  // 0.0000000000000000007398248
  s21_decimal decimal_check = {{0x70E368, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok320) {
  // -7.39824756E-19
  int f = -1587913836;
  // -0.0000000000000000007398248
  s21_decimal decimal_check = {{0x70E368, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok321) {
  // 7.90202733E+27
  int f = 1842103099;
  // 7902027000000000000000000000
  s21_decimal decimal_check = {{0x18E00000, 0x59EE2CE, 0x1988674E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok322) {
  // -7.90202733E+27
  int f = -305380549;
  // -7902027000000000000000000000
  s21_decimal decimal_check = {{0x18E00000, 0x59EE2CE, 0x1988674E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok323) {
  // 8.36178333E-06
  int f = 923552150;
  // 0.000008361783
  s21_decimal decimal_check = {{0x7F9737, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok324) {
  // -8.36178333E-06
  int f = -1223931498;
  // -0.000008361783
  s21_decimal decimal_check = {{0x7F9737, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok325) {
  // 3769.21729
  int f = 1164678010;
  // 3769.217
  s21_decimal decimal_check = {{0x398381, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok326) {
  // -3769.21729
  int f = -982805638;
  // -3769.217
  s21_decimal decimal_check = {{0x398381, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok327) {
  // 1.80550409E+12
  int f = 1406283831;
  // 1805504000000
  s21_decimal decimal_check = {{0x606CB000, 0x1A4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok328) {
  // -1.80550409E+12
  int f = -741199817;
  // -1805504000000
  s21_decimal decimal_check = {{0x606CB000, 0x1A4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok329) {
  // 2.00816507E+21
  int f = 1658436039;
  // 2008165000000000000000
  s21_decimal decimal_check = {{0x2C508000, 0xDCE343C9, 0x6C, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok330) {
  // -2.00816507E+21
  int f = -489047609;
  // -2008165000000000000000
  s21_decimal decimal_check = {{0x2C508000, 0xDCE343C9, 0x6C, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok331) {
  // 42.4789772
  int f = 1110043257;
  // 42.47898
  s21_decimal decimal_check = {{0x40D15A, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok332) {
  // -42.4789772
  int f = -1037440391;
  // -42.47898
  s21_decimal decimal_check = {{0x40D15A, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok333) {
  // 1.42036498E+14
  int f = 1459695219;
  // 142036500000000
  s21_decimal decimal_check = {{0x7320AD00, 0x812E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok334) {
  // -1.42036498E+14
  int f = -687788429;
  // -142036500000000
  s21_decimal decimal_check = {{0x7320AD00, 0x812E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok335) {
  // 3.08074432E+20
  int f = 1636145954;
  // 308074400000000000000
  s21_decimal decimal_check = {{0x479A0000, 0xB364228D, 0x10, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok336) {
  // -3.08074432E+20
  int f = -511337694;
  // -308074400000000000000
  s21_decimal decimal_check = {{0x479A0000, 0xB364228D, 0x10, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok337) {
  // 2.82437522E+23
  int f = 1718565856;
  // 282437500000000000000000
  s21_decimal decimal_check = {{0xCDA60000, 0xF7B1A7FD, 0x3BCE, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok338) {
  // -2.82437522E+23
  int f = -428917792;
  // -282437500000000000000000
  s21_decimal decimal_check = {{0xCDA60000, 0xF7B1A7FD, 0x3BCE, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok339) {
  // 2.16314857E-06
  int f = 907094684;
  // 0.000002163149
  s21_decimal decimal_check = {{0x2101CD, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok340) {
  // -2.16314857E-06
  int f = -1240388964;
  // -0.000002163149
  s21_decimal decimal_check = {{0x2101CD, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok341) {
  // 3.11719901E-23
  int f = 437697806;
  // 0.000000000000000000000031172
  s21_decimal decimal_check = {{0x79C4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok342) {
  // -3.11719901E-23
  int f = -1709785842;
  // -0.000000000000000000000031172
  s21_decimal decimal_check = {{0x79C4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok343) {
  // 7.10805625E+18
  int f = 1589987783;
  // 7108056000000000000
  s21_decimal decimal_check = {{0x9B958000, 0x62A4E345, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok344) {
  // -7.10805625E+18
  int f = -557495865;
  // -7108056000000000000
  s21_decimal decimal_check = {{0x9B958000, 0x62A4E345, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok345) {
  // 1.10467782E-23
  int f = 425045247;
  // 0.0000000000000000000000110468
  s21_decimal decimal_check = {{0x1AF84, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok346) {
  // -1.10467782E-23
  int f = -1722438401;
  // -0.0000000000000000000000110468
  s21_decimal decimal_check = {{0x1AF84, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok347) {
  // 6.46864174E+21
  int f = 1672435000;
  // 6468642000000000000000
  s21_decimal decimal_check = {{0x745D0000, 0xAA70EAAA, 0x15E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok348) {
  // -6.46864174E+21
  int f = -475048648;
  // -6468642000000000000000
  s21_decimal decimal_check = {{0x745D0000, 0xAA70EAAA, 0x15E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok349) {
  // 0.00363415456
  int f = 997075711;
  // 0.003634155
  s21_decimal decimal_check = {{0x3773EB, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok350) {
  // -0.00363415456
  int f = -1150407937;
  // -0.003634155
  s21_decimal decimal_check = {{0x3773EB, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok351) {
  // 1.78366992E-08
  int f = 848901969;
  // 0.0000000178367
  s21_decimal decimal_check = {{0x2B8BF, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok352) {
  // -1.78366992E-08
  int f = -1298581679;
  // -0.0000000178367
  s21_decimal decimal_check = {{0x2B8BF, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok353) {
  // 3.28054909E-07
  int f = 883957638;
  // 0.0000003280549
  s21_decimal decimal_check = {{0x320EA5, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok354) {
  // -3.28054909E-07
  int f = -1263526010;
  // -0.0000003280549
  s21_decimal decimal_check = {{0x320EA5, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok355) {
  // 0.129331082
  int f = 1040478046;
  // 0.1293311
  s21_decimal decimal_check = {{0x13BBFF, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok356) {
  // -0.129331082
  int f = -1107005602;
  // -0.1293311
  s21_decimal decimal_check = {{0x13BBFF, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok357) {
  // 30.7339287
  int f = 1106632470;
  // 30.73393
  s21_decimal decimal_check = {{0x2EE571, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok358) {
  // -30.7339287
  int f = -1040851178;
  // -30.73393
  s21_decimal decimal_check = {{0x2EE571, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok359) {
  // 3.0781897E-18
  int f = 576921948;
  // 0.00000000000000000307819
  s21_decimal decimal_check = {{0x4B26B, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok360) {
  // -3.0781897E-18
  int f = -1570561700;
  // -0.00000000000000000307819
  s21_decimal decimal_check = {{0x4B26B, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok361) {
  // 1.41380582E+17
  int f = 1543185522;
  // 141380600000000000
  s21_decimal decimal_check = {{0x1921B000, 0x1F648E8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok362) {
  // -1.41380582E+17
  int f = -604298126;
  // -141380600000000000
  s21_decimal decimal_check = {{0x1921B000, 0x1F648E8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok363) {
  // 1.33295075E-26
  int f = 344195665;
  // 0.0000000000000000000000000133
  s21_decimal decimal_check = {{0x85, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok364) {
  // -1.33295075E-26
  int f = -1803287983;
  // -0.0000000000000000000000000133
  s21_decimal decimal_check = {{0x85, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok365) {
  // 8.498085E+16
  int f = 1536619729;
  // 84980850000000000
  s21_decimal decimal_check = {{0xF5F400, 0x12DE9A2, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok366) {
  // -8.498085E+16
  int f = -610863919;
  // -84980850000000000
  s21_decimal decimal_check = {{0xF5F400, 0x12DE9A2, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok367) {
  // 12405.1982
  int f = 1178719435;
  // 12405.2
  s21_decimal decimal_check = {{0x1E494, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok368) {
  // -12405.1982
  int f = -968764213;
  // -12405.2
  s21_decimal decimal_check = {{0x1E494, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok369) {
  // 1.70968087E-20
  int f = 513898892;
  // 0.00000000000000000001709681
  s21_decimal decimal_check = {{0x1A1671, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok370) {
  // -1.70968087E-20
  int f = -1633584756;
  // -0.00000000000000000001709681
  s21_decimal decimal_check = {{0x1A1671, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok371) {
  // 2.09692443E-16
  int f = 628212297;
  // 0.0000000000000002096924
  s21_decimal decimal_check = {{0x1FFF1C, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok372) {
  // -2.09692443E-16
  int f = -1519271351;
  // -0.0000000000000002096924
  s21_decimal decimal_check = {{0x1FFF1C, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok373) {
  // 8.02104489E+12
  int f = 1424585073;
  // 8021045000000
  s21_decimal decimal_check = {{0x8B89B740, 0x74B, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok374) {
  // -8.02104489E+12
  int f = -722898575;
  // -8021045000000
  s21_decimal decimal_check = {{0x8B89B740, 0x74B, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok375) {
  // 1.04314942E-07
  int f = 870319039;
  // 0.0000001043149
  s21_decimal decimal_check = {{0xFEACD, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok376) {
  // -1.04314942E-07
  int f = -1277164609;
  // -0.0000001043149
  s21_decimal decimal_check = {{0xFEACD, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok377) {
  // 2.64088815E+15
  int f = 1494621691;
  // 2640888000000000
  s21_decimal decimal_check = {{0xA721B000, 0x961DF, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok378) {
  // -2.64088815E+15
  int f = -652861957;
  // -2640888000000000
  s21_decimal decimal_check = {{0xA721B000, 0x961DF, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok379) {
  // 4.67902401E+25
  int f = 1780142304;
  // 46790240000000000000000000
  s21_decimal decimal_check = {{0xDD800000, 0xFE325BBC, 0x26B437, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok380) {
  // -4.67902401E+25
  int f = -367341344;
  // -46790240000000000000000000
  s21_decimal decimal_check = {{0xDD800000, 0xFE325BBC, 0x26B437, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok381) {
  // 1.73181625E-18
  int f = 570397227;
  // 0.000000000000000001731816
  s21_decimal decimal_check = {{0x1A6CE8, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok382) {
  // -1.73181625E-18
  int f = -1577086421;
  // -0.000000000000000001731816
  s21_decimal decimal_check = {{0x1A6CE8, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok383) {
  // 4.29781641E+18
  int f = 1584305061;
  // 4297816000000000000
  s21_decimal decimal_check = {{0x95FD8000, 0x3BA4E8E1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok384) {
  // -4.29781641E+18
  int f = -563178587;
  // -4297816000000000000
  s21_decimal decimal_check = {{0x95FD8000, 0x3BA4E8E1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok385) {
  // 7.99136845E+21
  int f = 1675139906;
  // 7991368000000000000000
  s21_decimal decimal_check = {{0xEFD40000, 0x368267EA, 0x1B1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok386) {
  // -7.99136845E+21
  int f = -472343742;
  // -7991368000000000000000
  s21_decimal decimal_check = {{0xEFD40000, 0x368267EA, 0x1B1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok387) {
  // 4.69790976E-25
  int f = 387015853;
  // 0.0000000000000000000000004698
  s21_decimal decimal_check = {{0x125A, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok388) {
  // -4.69790976E-25
  int f = -1760467795;
  // -0.0000000000000000000000004698
  s21_decimal decimal_check = {{0x125A, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok389) {
  // 1.23054447E+20
  int f = 1624602407;
  // 123054400000000000000
  s21_decimal decimal_check = {{0x70D40000, 0xABB90CD4, 0x6, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok390) {
  // -1.23054447E+20
  int f = -522881241;
  // -123054400000000000000
  s21_decimal decimal_check = {{0x70D40000, 0xABB90CD4, 0x6, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok391) {
  // 7.58803818E+14
  int f = 1479313458;
  // 758803800000000
  s21_decimal decimal_check = {{0xC6F40600, 0x2B220, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok392) {
  // -7.58803818E+14
  int f = -668170190;
  // -758803800000000
  s21_decimal decimal_check = {{0xC6F40600, 0x2B220, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok393) {
  // 2.37397573E+14
  int f = 1465379182;
  // 237397600000000
  s21_decimal decimal_check = {{0x6F9E5800, 0xD7E9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok394) {
  // -2.37397573E+14
  int f = -682104466;
  // -237397600000000
  s21_decimal decimal_check = {{0x6F9E5800, 0xD7E9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok395) {
  // 7.94356025E-10
  int f = 811227606;
  // 0.000000000794356
  s21_decimal decimal_check = {{0xC1EF4, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok396) {
  // -7.94356025E-10
  int f = -1336256042;
  // -0.000000000794356
  s21_decimal decimal_check = {{0xC1EF4, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok397) {
  // 2.47739942E+13
  int f = 1437876521;
  // 24773990000000
  s21_decimal decimal_check = {{0x24DFA580, 0x1688, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok398) {
  // -2.47739942E+13
  int f = -709607127;
  // -24773990000000
  s21_decimal decimal_check = {{0x24DFA580, 0x1688, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok399) {
  // 4.61453107E+17
  int f = 1556933925;
  // 461453100000000000
  s21_decimal decimal_check = {{0x4A00B800, 0x6676926, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok400) {
  // -4.61453107E+17
  int f = -590549723;
  // -461453100000000000
  s21_decimal decimal_check = {{0x4A00B800, 0x6676926, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

Suite *from_float_to_decimal_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[45m-=S21_FROM_FLOAT_TO_DECIMAL2=-\033[0m");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok3);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok4);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok5);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok6);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok7);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok8);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok9);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok10);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok11);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok12);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok13);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok14);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok15);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok16);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok17);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok18);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok19);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok20);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok21);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok22);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok23);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok24);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok25);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok26);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok27);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok28);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok29);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok30);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok31);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok32);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok33);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok34);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok35);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok36);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok37);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok38);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok39);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok40);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok41);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok42);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok43);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok44);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok45);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok46);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok47);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok48);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok49);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok50);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok51);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok52);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok53);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok54);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok55);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok56);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok57);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok58);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok59);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok60);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok61);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok62);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok63);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok64);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok65);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok66);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok67);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok68);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok69);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok70);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok71);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok72);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok73);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok74);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok75);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok76);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok77);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok78);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok79);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok80);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok81);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok82);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok83);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok84);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok85);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok86);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok87);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok88);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok89);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok90);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok91);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok92);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok93);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok94);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok95);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok96);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok97);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok98);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok99);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok100);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok101);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok102);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok103);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok104);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok105);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok106);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok107);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok108);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok109);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok110);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok111);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok112);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok113);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok114);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok115);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok116);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok117);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok118);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok119);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok120);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok121);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok122);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok123);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok124);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok125);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok126);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok127);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok128);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok129);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok130);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok131);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok132);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok133);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok134);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok135);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok136);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok137);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok138);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok139);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok140);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok141);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok142);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok143);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok144);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok145);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok146);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok147);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok148);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok149);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok150);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok151);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok152);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok153);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok154);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok155);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok156);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok157);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok158);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok159);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok160);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok161);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok162);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok163);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok164);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok165);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok166);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok167);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok168);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok169);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok170);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok171);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok172);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok173);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok174);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok175);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok176);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok177);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok178);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok179);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok180);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok181);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok182);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok183);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok184);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok185);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok186);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok187);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok188);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok189);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok190);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok191);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok192);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok193);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok194);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok195);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok196);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok197);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok198);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok199);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok200);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok201);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok202);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok203);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok204);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok205);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok206);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok207);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok208);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok209);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok210);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok211);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok212);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok213);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok214);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok215);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok216);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok217);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok218);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok219);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok220);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok221);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok222);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok223);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok224);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok225);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok226);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok227);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok228);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok229);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok230);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok231);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok232);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok233);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok234);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok235);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok236);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok237);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok238);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok239);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok240);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok241);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok242);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok243);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok244);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok245);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok246);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok247);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok248);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok249);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok250);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok251);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok252);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok253);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok254);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok255);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok256);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok257);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok258);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok259);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok260);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok261);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok262);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok263);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok264);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok265);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok266);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok267);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok268);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok269);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok270);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok271);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok272);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok273);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok274);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok275);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok276);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok277);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok278);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok279);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok280);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok281);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok282);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok283);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok284);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok285);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok286);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok287);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok288);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok289);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok290);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok291);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok292);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok293);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok294);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok295);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok296);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok297);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok298);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok299);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok300);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok301);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok302);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok303);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok304);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok305);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok306);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok307);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok308);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok309);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok310);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok311);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok312);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok313);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok314);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok315);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok316);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok317);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok318);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok319);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok320);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok321);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok322);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok323);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok324);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok325);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok326);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok327);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok328);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok329);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok330);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok331);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok332);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok333);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok334);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok335);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok336);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok337);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok338);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok339);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok340);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok341);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok342);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok343);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok344);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok345);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok346);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok347);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok348);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok349);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok350);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok351);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok352);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok353);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok354);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok355);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok356);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok357);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok358);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok359);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok360);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok361);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok362);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok363);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok364);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok365);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok366);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok367);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok368);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok369);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok370);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok371);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok372);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok373);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok374);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok375);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok376);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok377);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok378);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok379);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok380);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok381);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok382);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok383);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok384);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok385);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok386);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok387);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok388);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok389);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok390);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok391);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok392);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok393);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok394);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok395);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok396);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok397);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok398);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok399);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_from_float_to_decimal(int f, s21_decimal decimal_check) {
  s21_decimal result;

  float_cast_test cast_float;
  cast_float.int32_bytes = f;

  int code = s21_from_float_to_decimal(cast_float.f, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
