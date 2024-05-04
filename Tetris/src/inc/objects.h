#ifndef OBJECTS_H
#define OBJECTS_H

#include <ncurses.h>

/**
 * @brief Структура для игровых окон
 *
 */
typedef struct {
  WINDOW *win_game;
  WINDOW *win_data;
} wins;

/**
 * @brief Структура для данных о фигурах
 *
 */
typedef struct shapes_s {
  int id;
  int down, right;
  int p1, p2, p3, p4;
  int figure[4][2];
  int shift_down, move_shapes, num_shape;
  int run;
  int next, skip, delay, speed, temp;
} shapes_s;

#endif