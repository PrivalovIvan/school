#include "../../inc/frontend.h"

void panel_data(wins* win, GameInfo_t* g_info) {
  mvwprintw(win->win_data, 1, 3, "hi-score");
  mvwprintw(win->win_data, 2, 4, "%.7d", g_info->high_score);
  mvwprintw(win->win_data, 4, 6, "score");
  mvwprintw(win->win_data, 5, 4, "%.7d", g_info->score);
  mvwprintw(win->win_data, 7, 7, "next");
  mvwprintw(win->win_data, 14, 6, "level");
  mvwprintw(win->win_data, 15, 9, "%.2d", g_info->level);
  mvwprintw(win->win_data, 17, 6, "speed");
  mvwprintw(win->win_data, 18, 9, "%.2d", g_info->speed);
  mvwprintw(win->win_data, 20, 6, "pause");

  box(win->win_data, 0, 0);
  wrefresh(win->win_data);
}
void print_next_figure(wins* win, GameInfo_t* g_info) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (g_info->next[i][j] == 1)
        mvwaddch(win->win_data, i + 9, j + 5, '0');
      else
        mvwaddch(win->win_data, i + 9, j + 5, ' ');
    }
    wrefresh(win->win_data);
  }
}

void panel_game(wins* win, GameInfo_t* g_info) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (g_info->field[i][j] == 1)
        mvwaddch(win->win_game, i + 1, j + 1, '0');
      else if (g_info->field[i][j] == 0)
        mvwaddch(win->win_game, i + 1, j + 1, ' ');
    }
    box(win->win_game, 0, 0), wrefresh(win->win_game);
  }
}

GameInfo_t updateCurrentState(GameInfo_t* g_info, wins* win) {
  print_next_figure(win, g_info);
  panel_game(win, g_info);
  panel_data(win, g_info);
  return *g_info;
}