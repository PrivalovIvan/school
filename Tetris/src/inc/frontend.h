#ifndef FRONTEND_H
#define FRONTEND_H

#include "objects.h"
/**
 * @brief Структура хранит данные об игре
 * о ее событиях на игровом поле, счете,уровне,скорости.
 *
 */
typedef struct GameInfo_t {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

// FRONTEND

/**
 * @brief Отрисовывает информационную панель с данными об игре
 *
 * @param win Структура, откуда выбирается информационное окно
 * @param g_info для отображения данных об игре:
 * <br>-счет
 * <br>-рекорд
 * <br>-уровень
 * <br>-скорость
 */
void panel_data(wins *win, GameInfo_t *g_info);

/**
 * @brief Отрисовывает только игровое поле
 *
 * @param win Структура, откуда выбирается игровое окно
 * @param g_info Здесь находится само игровое поле
 */
void panel_game(wins *win, GameInfo_t *g_info);
// Отрисовка окон

/**
 * @brief Отрисовка всей игры со всеми окнами
 */
GameInfo_t updateCurrentState(GameInfo_t *g_info, wins *win);

/**
 * @brief Отрисовка следующей фигуры.
 *
 * @param win Окно, куда отрисовывается следующая фигура
 * @param g_info Запись в массив next следующей фигуры
 */
void print_next_figure(wins *win, GameInfo_t *g_info);

#endif