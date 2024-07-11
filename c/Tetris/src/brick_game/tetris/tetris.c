#include "../../inc/backend.h"

void game_loop() {
  GameInfo_t g_info = {0};
  INIT_FIELD(21, 10);
  INIT_NEXT_FIGURE(4, 4);

  initscr();
  wins win = {0};
  INIT_WIN_GAME(22, 12, win.win_game)
  INIT_WIN_DATA(22, 12, win.win_data)
  system("mkdir hi_score");

  shapes_s list[24];
  shapes_s sh = {0};

  state_s state = START;

  sh.run = 1;
  sh.skip = 1;

  int signal = Start;
  while (sh.run) {
    if (g_info.high_score < g_info.score) {
      write_hi_score(g_info);
      read_hi_score(&g_info);
    }
    speed_game(&g_info);
    wtimeout(win.win_game, BASE_SPEED - g_info.speed);

    init_list_shape(list);

    if (state == START) PRINT_START1

    if (state == GAME_OVER) exit_game(g_info, &win, &sh), sh.run = FALSE;

    sigact(get_signal(signal), &state, &win, &g_info, list, &sh);

    if (state == START or state == MOVING) signal = wgetch(win.win_game);

    if (state == MOVING and signal == -1) state = SHIFTING;
  }

  delwin(win.win_data), delwin(win.win_game), endwin();
  clean_memory_matrix(&g_info);
}
int main() {
  game_loop();
  return 0;
}
