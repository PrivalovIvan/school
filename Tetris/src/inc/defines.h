#ifndef DEFINES_H
#define DEFINES_H

#define SPACE 32
#define ENTER 10
#define PAUSE 'p'
#define EXIT 'x'
#define BASE_SPEED 45
#define HEIGHT 20
#define WIDTH 10
#define msleep(ms) usleep(ms * 1000)
#define WIN_Y_0 getmaxy(stdscr) / 2 - 11
#define WIN_X_0 getmaxx(stdscr) / 2 - 12
#define SHIFT_D(x) x
#define SHIFT_R(x) x
#define CHECK_Y_0(x) \
  list[sh.num_shape + x].figure[0][0] + list[sh.num_shape + x].p1
#define CHECK_X_0(x) list[sh.num_shape + x].figure[0][1] + sh.move_shapes

#define CHECK_Y_1(x) \
  list[sh.num_shape + x].figure[1][0] + list[sh.num_shape + x].p2
#define CHECK_X_1(x) list[sh.num_shape + x].figure[1][1] + sh.move_shapes

#define CHECK_Y_2(x) \
  list[sh.num_shape + x].figure[2][0] + list[sh.num_shape + x].p3
#define CHECK_X_2(x) list[sh.num_shape + x].figure[2][1] + sh.move_shapes

#define CHECK_Y_3(x) \
  list[sh.num_shape + x].figure[3][0] + list[sh.num_shape + x].p4
#define CHECK_X_3(x) list[sh.num_shape + x].figure[3][1] + sh.move_shapes

#define Y_P(i) list[sh->num_shape].figure[i][0]
#define X_P(i) list[sh->num_shape].figure[i][1]

/**
 * @brief инициализация поля для игры
 *
 */
#define INIT_FIELD(y, x)                           \
  g_info.field = (int **)calloc(y, sizeof(int *)); \
  for (int i = 0; i < y; i++) g_info.field[i] = (int *)calloc(x, sizeof(int));
/**
 * @brief инициализация поля для отрисовки слудующей фигуры в окне с данными для
 * игры
 *
 */
#define INIT_NEXT_FIGURE(y, x)                    \
  g_info.next = (int **)calloc(y, sizeof(int *)); \
  for (int i = 0; i < y; i++) g_info.next[i] = (int *)calloc(x, sizeof(int));

/**
 * @brief инициализация окна с игрой
 *
 */
#define INIT_WIN_GAME(y, x, name)        \
  name = newwin(y, x, WIN_Y_0, WIN_X_0); \
  cbreak();                              \
  nodelay(win.win_game, 1);              \
  curs_set(0);                           \
  noecho();

/**
 * @brief инициализация окна с данными об игре
 *
 */
#define INIT_WIN_DATA(y, x, name) name = newwin(y, x, WIN_Y_0, WIN_X_0 + 11);

#define PRINT_START1                        \
  {                                         \
    mvwprintw(win.win_game, 5, 3, "press"); \
    mvwprintw(win.win_game, 6, 3, "ENTER"); \
    mvwprintw(win.win_game, 7, 6, "to");    \
    mvwprintw(win.win_game, 8, 3, "start"); \
    mvwprintw(win.win_game, 16, 6, "to");   \
    mvwprintw(win.win_game, 17, 4, "exit"); \
    mvwprintw(win.win_game, 18, 5, "'x'");  \
    box(win.win_game, 0, 0);                \
    wrefresh(win.win_game);                 \
  }

#define clean_game             \
  for (int i = 0; i < 21; i++) \
    for (int j = 0; j < 10; j++) p->g_info->field[i][j] = 0;
#define clean_info            \
  for (int i = 0; i < 4; i++) \
    for (int j = 0; j < 4; j++) g_info->next[i][j] = 0;

#endif