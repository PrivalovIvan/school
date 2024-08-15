#ifndef FSM_M_H
#define FSM_M_H

#include "backend.h"

/**
 * @brief события для fsm
 *
 */
typedef enum state_s {
  START,
  SPAWN,
  MOVING,
  SHIFTING,
  ATTACHING,
  GAME_OVER,
  NONE
} state_s;

/**
 * @brief Сигналы для fsm
 *
 */
typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  No_sig,
  Action
} UserAction_t;

/**
 * @brief Структура указателей на структуры
 *
 */
typedef struct {
  // Signals
  UserAction_t *action;
  // State;
  state_s *state;
  wins *win;
  shapes_s *sh;
  shapes_s *list;
  GameInfo_t *g_info;
} params_t;

/**
 * @brief Функция создает сигнал
 *
 * @param sig указатель на на перечисление сигналов
 * @param state указатель на перечисление событий
 * @param win указатель на структуру с окнами игры
 * @param g_info указатель на структуру с данными игры
 * @param list указатель на список фигур
 * @param sh указатель на структуру с данными фигур
 */
void sigact(UserAction_t sig, state_s *state, GameInfo_t *g_info,
            shapes_s *list, shapes_s *sh);

/**
 * @brief Get the signal object
 *
 * @param user_input
 * @return UserAction_t
 */
UserAction_t get_signal(int user_input);

/**
 * @brief старт игры
 *
 * @param p Набор структур
 */

void start(params_t *p);
/**
 * @brief пауза
 *
 * @param p Набор структур
 */
void pause_in_game(params_t *p);
/**
 * @brief выход из игры
 *
 * @param p Набор структур
 */
void exit_app(params_t *p);
/**
 * @brief создание блока
 *
 * @param p Набор структур
 */
void spawn(params_t *p);
/**
 * @brief сдвиг фигуры влево
 *
 * @param p Набор структур
 */
void move_left(params_t *p);
/**
 * @brief сдвиг фигуры вправо
 *
 * @param p Набор структур
 */
void move_rigth(params_t *p);
/**
 * @brief падение фигуры
 *
 * @param p Набор структур
 */
void move_down(params_t *p);
/**
 * @brief поворот фигуры
 *
 * @param p Набор структур
 */
void rotate(params_t *p);
/**
 * @brief сдвиг фигуры вниз
 *
 * @param p Набор структур
 */
void shifting(params_t *p);
/**
 * @brief при соприкосновении проверяет целые линии
 *
 * @param p Набор структур
 */
void attaching(params_t *p);
#endif
