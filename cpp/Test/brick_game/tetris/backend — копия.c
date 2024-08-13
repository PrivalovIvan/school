#include "inc/backend.h"
#include "inc/frontend.h"
// STATE START

int init_stats(GameInfo_t *g_info) {
  read_hi_score(g_info);
  g_info->score = 0;
  g_info->level = 1;
  g_info->speed = 1;
  return 0;
}

// STATE SPAWN

int get_random_number(int min, int max, shapes_s *sh) {
  int number_random = 0;
  struct timespec spec;
  clock_gettime(0, &spec);
  srand(spec.tv_nsec);
  number_random = min + rand() % (max - min + 1);
  if (number_random > 23 or number_random == sh->temp)
    get_random_number(min, max, sh);
  sh->temp = number_random;
  return number_random;
}

int create_block(shapes_s *sh, GameInfo_t *g_info, shapes_s *list) {
  int result = 1;
  if (sh->skip)
    sh->num_shape = get_random_number(0, 23, sh), sh->skip = 0;
  else
    sh->num_shape = sh->next;
  sh->move_shapes = WIDTH / 2 - list[sh->num_shape].right / 2;
  sh->shift_down = 0;
  add_figure_in_place(g_info, list, sh);
  sh->next = get_random_number(0, 23, sh);
  clean_info add_figure_in_next(g_info, list, sh);
  return result;
}

void add_figure_in_next(GameInfo_t *g_info, shapes_s *list, shapes_s *sh) {
  for (int i = 0; i < 4; i++)
    g_info->next[list[sh->next].figure[i][0]][list[sh->next].figure[i][1]] = 1;
}

void add_figure_in_place(GameInfo_t *g_info, shapes_s *list, shapes_s *sh) {
  for (int i = 0; i < 4; i++)
    g_info->field[Y_P(i) + sh->shift_down][X_P(i) + sh->move_shapes] = 1;
}

void exit_game(GameInfo_t g_info) {
  for (int j = 0; j < 20; j++) {
    for (int k = 0; k < 10; k++) {
      g_info.field[j][k] = 1;
    }
  }
  for (int j = 0; j < 20; j++) {
    for (int k = 0; k < 10; k++) {
      g_info.field[j][k] = 0;
    }
  }
}

// SHIFTING

int shifting_block_down(GameInfo_t *g_info, shapes_s *list, shapes_s *sh,
                        state_s *state) {
  int result = 0;
  if (sh->shift_down + list[sh->num_shape].down < 19) {
    if (check_next_rows(*g_info, list, *sh, 0))
      *state = ATTACHING;
    else {
      remove_block(g_info, list, sh);
      *state = MOVING;
    }
    sh->shift_down++;
  } else if (sh->shift_down + list[sh->num_shape].down == 19)
    sh->shift_down = 0, *state = SPAWN,
    sh->move_shapes = (WIDTH - list[sh->num_shape].right) / 2, sh->shift_down++;
  else
    result = 1;
  return result;
}

// Проверка следющей строки
int check_next_rows(GameInfo_t g_info, shapes_s *list, shapes_s sh, int x) {
  int del = 0;
  if (g_info.field[CHECK_Y_0(x) + sh.shift_down + x][CHECK_X_0(x)] == 1 or
      g_info.field[CHECK_Y_1(x) + sh.shift_down + x][CHECK_X_1(x)] == 1 or
      g_info.field[CHECK_Y_2(x) + sh.shift_down + x][CHECK_X_2(x)] == 1 or
      g_info.field[CHECK_Y_3(x) + sh.shift_down + x][CHECK_X_3(x)] == 1) {
    del = 1;
  }
  return del;
}

// ATTACHING

int check_last_line(GameInfo_t *g_info) {
  int temp = 0;
  for (int i = 0; i < 10; i++) {
    if (g_info->field[0][i] == 1) {
      temp = 1;
    }
  }
  return temp;
}

int check_line(GameInfo_t *g_info) {
  int line = 0, line_qty = 0, i = 0, end = 0;
  for (i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (g_info->field[i][j] == 1)
        line = 1;
      else {
        line = 0;
        break;
      }
    }

    if (line) {
      line_qty++;
      for (int k = 0; k < 10; k++)
        g_info->field[i][k] = 0, line = 0;
      for (int a = i; a > 1; a--) {
        for (int b = 0; b < 10; b++) {
          if (g_info->field[a - 1][b] == 1)
            g_info->field[a][b] = 1;
          if (g_info->field[a - 1][b] == 0)
            g_info->field[a][b] = 0;
        }
      }
      if (line_qty == 1)
        g_info->score = g_info->score + 100;
      else if (line_qty == 2)
        g_info->score = g_info->score + 200;
      else if (line_qty == 3)
        g_info->score = g_info->score + 400;
      else if (line_qty == 4)
        g_info->score = g_info->score + 800;
      end = 1;
    }
  }
  level_up(g_info);
  return end;
}

// MOVING

int shift_left(shapes_s *sh, GameInfo_t g_info, shapes_s *list) {
  int ok = 0;
  if (sh->move_shapes) {
    for (int i = 0; i < 4; i++) {
      if (g_info
              .field[list[sh->num_shape].figure[i][0] + sh->shift_down]
                    [list[sh->num_shape].figure[i][1] + sh->move_shapes - 1] ==
          0) {
        ok = 1;
      } else {
        ok = 0;
        break;
      }
    }
  }
  if (ok)
    sh->move_shapes--;
  return ok;
}

int shift_right(shapes_s *sh, GameInfo_t g_info, shapes_s *list) {
  int ok2 = 0;
  if (sh->move_shapes + list[sh->num_shape].right < 10) {
    for (int i = 0; i < 4; i++) {
      if (g_info
              .field[list[sh->num_shape].figure[i][0] + sh->shift_down]
                    [list[sh->num_shape].figure[i][1] + sh->move_shapes + 1] ==
          0)
        ok2 = 1;
      else {
        ok2 = 0;
        break;
      }
    }
  }
  if (ok2)
    sh->move_shapes++;
  return ok2;
}

int turning_the_shape(GameInfo_t g_info, shapes_s *list, shapes_s *sh) {
  int x = 1;
  int result = 0;
  if (list[sh->num_shape].id == list[sh->num_shape + 1].id) {
    if (sh->move_shapes + list[sh->num_shape + 1].right > 9)
      sh->move_shapes = 9 - list[sh->num_shape + 1].right + 1;
    if (list[sh->num_shape + 1].down + sh->shift_down + 1 < 19)
      if ((checking_on_the_right_for_turn(g_info, list, *sh, x)) and
          (checking_on_the_down_for_turn(g_info, list, *sh, x)))
        sh->num_shape++, result = 1;
  } else if (list[sh->num_shape].id != list[sh->num_shape + 1].id) {
    if (sh->move_shapes + list[list[sh->num_shape].id].right > 9)
      sh->move_shapes = 9 - list[list[sh->num_shape].id].right + 1;
    if (sh->num_shape == 23)
      x = -3;
    if (list[sh->num_shape + x].down + sh->shift_down + 1 < 19)
      if (checking_on_the_right_for_turn(g_info, list, *sh, x) and
          checking_on_the_down_for_turn(g_info, list, *sh, x))
        sh->num_shape = list[sh->num_shape].id, result = 1;
  }
  return result;
}

// SUBFUNCTION

int checking_on_the_right_for_turn(GameInfo_t g_info, shapes_s *list,
                                   shapes_s sh, int x) {
  int result = 0;
  if ((g_info.field[list[sh.num_shape + x].figure[0][0] + sh.shift_down + 1]
                   [list[sh.num_shape + x].figure[0][1] + sh.move_shapes] ==
       0) and
      (g_info.field[list[sh.num_shape + x].figure[1][0] + sh.shift_down + 1]
                   [list[sh.num_shape + x].figure[1][1] + sh.move_shapes] ==
       0) and
      (g_info.field[list[sh.num_shape + x].figure[2][0] + sh.shift_down + 1]
                   [list[sh.num_shape + x].figure[2][1] + sh.move_shapes] ==
       0) and
      (g_info.field[list[sh.num_shape + x].figure[3][0] + sh.shift_down + 1]
                   [list[sh.num_shape + x].figure[3][1] + sh.move_shapes] == 0))
    result = 1;
  return result;
}
int checking_on_the_down_for_turn(GameInfo_t g_info, shapes_s *list,
                                  shapes_s sh, int x) {
  int result = 0;
  if ((g_info.field[list[sh.num_shape + x].p1 + sh.shift_down + 1]
                   [sh.move_shapes] == 0) and
      (g_info.field[list[sh.num_shape + x].p2 + sh.shift_down + 1]
                   [sh.move_shapes] == 0) and
      (g_info.field[list[sh.num_shape + x].p3 + sh.shift_down + 1]
                   [sh.move_shapes] == 0) and
      (g_info.field[list[sh.num_shape + x].p4 + sh.shift_down + 1]
                   [sh.move_shapes] == 0))
    result = 1;
  return result;
}
void clean_memory_matrix(GameInfo_t *g_info) {
  for (int i = 0; i < 21; i++) {
    free(g_info->field[i]);
  }
  for (int i = 0; i < 4; i++) {
    free(g_info->next[i]);
  }
  free(g_info->field);
  free(g_info->next);
}

void remove_block(GameInfo_t *g_info, shapes_s *list, shapes_s *sh) {
  for (int i = 0; i < 4; i++)
    g_info->field[list[sh->num_shape].figure[i][0] + sh->shift_down]
                 [list[sh->num_shape].figure[i][1] + sh->move_shapes] = 0;
}

void pause_game(wins *win) {
  mvwaddch(win->win_data, 20, 4, '-'), mvwaddch(win->win_data, 20, 5, '>');
  wrefresh(win->win_data);
  wtimeout(win->win_game, -1);
  if (wgetch(win->win_game) == 'p') {
    wtimeout(win->win_game, 30);
    mvwaddch(win->win_data, 20, 4, ' '), mvwaddch(win->win_data, 20, 5, ' ');
  }
}

void speed_game(GameInfo_t *g_info) { g_info->speed = g_info->level * 1.5; }

void level_up(GameInfo_t *g_info) {
  g_info->level = g_info->score / 600 + 1;
  if (g_info->level > 10)
    g_info->level = 10;
}

void write_hi_score(GameInfo_t g_info) {
  FILE *fp = fopen("hi_score/record.txt", "w");
  if (fp) {
    char str[10];
    sprintf(str, "%d", g_info.score);

    int n = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < n; i++)
      putc(str[i], fp);
    fclose(fp);
  }
}

void read_hi_score(GameInfo_t *g_info) {
  FILE *fr = fopen("hi_score/record.txt", "r");
  if (fr) {
    char line[100];
    while ((fgets(line, 99, fr)))
      ;
    g_info->high_score = atoi(line);
    fclose(fr);
  }
}

void clear_field(GameInfo_t *g_info) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      g_info->field[i][j] = 0;
    }
  }
}
