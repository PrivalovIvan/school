#include "tetris_test.h"

START_TEST(move_left_test_1) {
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  shapes_s sh = {0};
  shapes_s list[24];
  init_list_shape(list);
  int result = shift_left(&sh, g_info, list);

  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(move_left_test_2) {
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  shapes_s sh = {0};
  shapes_s list[24];
  init_list_shape(list);
  sh.num_shape = 15;
  sh.move_shapes = 1;
  int result = shift_left(&sh, g_info, list);

  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(move_rigth_test_1) {
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  shapes_s sh = {0};
  shapes_s list[24];
  init_list_shape(list);
  sh.move_shapes = 10;
  int result = shift_right(&sh, g_info, list);

  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(move_rigth_test_2) {
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  shapes_s sh = {0};
  shapes_s list[24];
  init_list_shape(list);
  sh.num_shape = 15;
  sh.move_shapes = 2;
  int result = shift_right(&sh, g_info, list);

  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(get_random_number_test) {
  shapes_s sh = {0};
  int result = get_random_number(0, 23, &sh);
  ck_assert_double_nonnan(result);
}
END_TEST
START_TEST(create_block_test) {
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  INIT_NEXT_FIGURE(4, 4)
  shapes_s sh = {0};
  shapes_s list[24];
  init_list_shape(list);
  int result = create_block(&sh, &g_info, list);
  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(exit_game_test) {
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  shapes_s sh = {0};
  wins win = {0};
  exit_game(g_info, &win, &sh);
}
START_TEST(shifting_block_down_test_1) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  shapes_s sh = {0};
  state_s state = {0};
  shapes_s list[24];
  init_list_shape(list);
  sh.shift_down = 23;
  result = shifting_block_down(&g_info, list, &sh, &state);
  ck_assert_int_eq(result, 1);
}
START_TEST(shifting_block_down_test_2) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  shapes_s sh = {0};
  state_s state = {0};
  shapes_s list[24];
  init_list_shape(list);
  sh.shift_down = 17;
  result = shifting_block_down(&g_info, list, &sh, &state);
  ck_assert_int_eq(result, 0);
}
START_TEST(check_line_test_1) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  wins win = {0};
  result = check_line(&g_info, &win);
  ck_assert_int_eq(result, 0);
}
START_TEST(check_line_test_2) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  INIT_NEXT_FIGURE(4, 4)
  wins win = {0};
  for (int j = 0; j < 10; j++) g_info.field[19][j] = 1;
  result = check_line(&g_info, &win);
  ck_assert_int_eq(result, 1);
}
START_TEST(turning_the_shape_test_1) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  INIT_NEXT_FIGURE(4, 4)
  shapes_s sh = {0};
  shapes_s list[24];
  init_list_shape(list);
  sh.move_shapes = 18;
  result = turning_the_shape(g_info, list, &sh);
  ck_assert_int_eq(result, 1);
}
START_TEST(turning_the_shape_test_2) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  INIT_NEXT_FIGURE(4, 4)
  shapes_s sh = {0};
  shapes_s list[24];
  init_list_shape(list);
  sh.move_shapes = 52;
  sh.num_shape = 3;
  result = turning_the_shape(g_info, list, &sh);
  ck_assert_int_eq(result, 1);
}

START_TEST(check_last_line_test_1) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  result = check_last_line(&g_info);
  ck_assert_int_eq(result, 0);
}
START_TEST(check_last_line_test_2) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  for (int i = 0; i < 10; i++) g_info.field[0][i] = 1;
  result = check_last_line(&g_info);
  ck_assert_int_eq(result, 1);
}
START_TEST(init_stats_test) {
  int result = 0;
  GameInfo_t g_info = {0};
  INIT_FIELD(HEIGHT, WIDTH)
  result = init_stats(&g_info);
  ck_assert_int_eq(result, 0);
}

Suite *tetris_test(void) {
  Suite *suite;

  suite = suite_create("tetris_test");
  TCase *tcase_core = tcase_create("tetris_test");

  tcase_add_test(tcase_core, move_left_test_1);
  tcase_add_test(tcase_core, move_left_test_2);
  tcase_add_test(tcase_core, move_rigth_test_1);
  tcase_add_test(tcase_core, move_rigth_test_2);
  tcase_add_test(tcase_core, get_random_number_test);
  tcase_add_test(tcase_core, create_block_test);
  tcase_add_test(tcase_core, exit_game_test);
  tcase_add_test(tcase_core, shifting_block_down_test_1);
  tcase_add_test(tcase_core, shifting_block_down_test_2);
  tcase_add_test(tcase_core, check_line_test_1);
  tcase_add_test(tcase_core, check_line_test_2);
  tcase_add_test(tcase_core, turning_the_shape_test_1);
  tcase_add_test(tcase_core, turning_the_shape_test_2);
  tcase_add_test(tcase_core, check_last_line_test_1);
  tcase_add_test(tcase_core, check_last_line_test_2);
  tcase_add_test(tcase_core, init_stats_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main() {
  Suite *suite = tetris_test();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
