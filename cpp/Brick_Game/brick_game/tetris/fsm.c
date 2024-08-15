#include "inc/backend.h"

typedef void (*action)(params_t *prms);

action fsm_table[6][9] = {
    {start, NULL, exit_app, NULL, NULL, NULL, NULL, NULL},
    {spawn, spawn, spawn, spawn, spawn, spawn, spawn, spawn},
    {NULL, pause_in_game, exit_app, move_left, move_rigth, rotate, move_down,
     NULL},
    {shifting, shifting, shifting, shifting, shifting, shifting, shifting,
     shifting},
    {attaching, attaching, attaching, attaching, attaching, attaching,
     attaching, attaching},
    {exit_app, exit_app, exit_app, exit_app, exit_app, exit_app, exit_app,
     exit_app}};

void sigact(UserAction_t sig, state_s *state, GameInfo_t *g_info,
            shapes_s *list, shapes_s *sh) {
  params_t prms;
  prms.state = state;
  prms.g_info = g_info;
  prms.sh = sh;
  prms.list = list;
  action act = fsm_table[*state][sig];

  if (act)
    act(&prms);
}

UserAction_t get_signal(int user_input) {
  UserAction_t rc = No_sig;
  // if (user_input == ENTER)
  //     rc = Start;
  // else if (user_input == PAUSE)
  //     rc = Pause;
  // else if (user_input == 68 or user_input == KEY_LEFT)
  //     rc = Left;
  // else if (user_input == 67 or user_input == KEY_RIGHT)
  //     rc = Right;
  // else if (user_input == SPACE)
  //     rc = Up;
  // else if (user_input == 66 or user_input == KEY_DOWN)
  //     rc = Down;
  // else if (user_input == EXIT)
  //     rc = Terminate;
  if (user_input == Start)
    rc = Start;
  else if (user_input == Pause)
    rc = Pause;
  else if (user_input == Left)
    rc = Left;
  else if (user_input == Right)
    rc = Right;
  else if (user_input == Up)
    rc = Up;
  else if (user_input == Down)
    rc = Down;
  else if (user_input == Terminate)
    rc = Terminate;
  return rc;
}

void start(params_t *p) {
  init_stats(p->g_info);
  *p->state = SPAWN;
}
void pause_in_game(params_t *p) { pause_game(p->win); }
void spawn(params_t *p) {
  create_block(p->sh, p->g_info, p->list);
  *p->state = MOVING;
}
void move_left(params_t *p) {
  remove_block(p->g_info, p->list, p->sh);
  shift_left(p->sh, *p->g_info, p->list);
  add_figure_in_place(p->g_info, p->list, p->sh);
  *p->state = SHIFTING;
}
void move_rigth(params_t *p) {
  remove_block(p->g_info, p->list, p->sh);
  shift_right(p->sh, *p->g_info, p->list);
  add_figure_in_place(p->g_info, p->list, p->sh);
  *p->state = SHIFTING;
}
void rotate(params_t *p) {
  remove_block(p->g_info, p->list, p->sh);
  turning_the_shape(*p->g_info, p->list, p->sh);
  add_figure_in_place(p->g_info, p->list, p->sh);
  *p->state = SHIFTING;
}
void move_down(params_t *p) {
  while ((p->sh->shift_down + p->list[p->sh->num_shape].down + 1 < 19) and
         !(check_next_rows(*p->g_info, p->list, *p->sh, 0))) {
    remove_block(p->g_info, p->list, p->sh);
    p->sh->shift_down++;
    add_figure_in_place(p->g_info, p->list, p->sh);
  }
  *p->state = ATTACHING;
}
void shifting(params_t *p) {
  if (p->sh->shift_down + p->list[p->sh->num_shape].down + 1 == 19) {
    if (p->sh->delay++ == 5)
      p->sh->delay = 0, *p->state = ATTACHING;
    else
      *p->state = MOVING;
  } else {
    if (check_next_rows(*p->g_info, p->list, *p->sh, 0))
      *p->state = ATTACHING;
    else
      *p->state = MOVING;
    remove_block(p->g_info, p->list, p->sh);
    if (p->sh->delay++ == 5)
      p->sh->shift_down++, p->sh->delay = 0;
    add_figure_in_place(p->g_info, p->list, p->sh);
  }
}
void attaching(params_t *p) {
  check_line(p->g_info);
  // check_line(p->g_info, p->list, *p->sh);
  *p->state = SPAWN;
  if (check_last_line(p->g_info)) {
    *p->state = GAME_OVER;
    clear_field(p->g_info);
  }
}
void exit_app(params_t *p) { clear_field(p->g_info); clean_memory_matrix(p->g_info); }
