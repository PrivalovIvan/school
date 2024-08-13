#ifndef BACKEND_H
#define BACKEND_H

#include <iso646.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "defines.h"
#include "frontend.h"
#include "fsm_m.h"
#include "objects.h"

// BACKEND

/**
 * @brief Запуск игры
 *
 */
void game_loop();

// STATE START

/**
 * @brief Инициализация стартовых значений для данных об игре
 *
 * @param g_info Хранятся значения
 */
int init_stats(GameInfo_t *g_info);

// STATE SPAWN

/**
 * @brief Get the random number object
 *
 * @param min минимальное число
 * @param max максимальное число
 * @param sh хранится предыдущее число для избежания повторения фигур
 * @return int случайное число
 */
int get_random_number(int min, int max, shapes_s *sh);

/**
 * @brief Create a block object
 *
 * @param sh Используется для номера фигуры из списка фигур list
 * @param g_info для добавления в игровое поле фигуры
 * @param list список со всеми фигурами
 */
int create_block(shapes_s *sh, GameInfo_t *g_info, shapes_s *list);

/**
 * @brief Добавление следующего блока в матрицу next.
 *
 * @param g_info Структура для добавления блока в поле
 * @param list Список с фигурами и их данными
 * @param sh Структура используется для использования координат х,у
 */
void add_figure_in_next(GameInfo_t *g_info, shapes_s *list, shapes_s *sh);

/**
 * @brief Добавляет фигуру в поле(в матрицу field)
 *
 * @param g_info в этой структуре в матрицу добавляется фигура
 * @param list Список с фигурами и их данными
 * @param sh Структура используется для использования координат х,у
 */
void add_figure_in_place(GameInfo_t *g_info, shapes_s *list, shapes_s *sh);

/**
 * @brief Выход из игры
 *
 * @param g_info Структура используется для обновления игрового состояния
 * @param win передает окна для указания в каком окне происходит событие
 * @param sh Структура предоставляет переменную run для передачи ей значения 0
 * для выхода из цикла с игрой
 */
void exit_game(GameInfo_t g_info);

// SHIFTING

/**
 * @brief Функция сдвигает фигуру вниз
 *
 * @param g_info Структура предоставляет матрицу с игровым полем для проверки
 * следующего ряда на наличие уже упавших блоков <br> и их последующего
 * предотовращения наезда одного блока на другой
 * @param list список с фигурами используется для получения данных, а именно
 * высоте фигуры для подсчета нахождения низа фигуры
 * @param sh Структура из которой истользуется номер фигуры
 * @param state Используется для смены события
 */
int shifting_block_down(GameInfo_t *g_info, shapes_s *list, shapes_s *sh,
                        state_s *state);

/**
 * @brief Проверка следющей строки
 *
 * @param g_info Из структуры принимается матрица с полем для проверки на
 * занятые ячейки
 * @param list берем фигуру из этого списка
 * @param sh данные для фигуры
 * @param x для возможности проверки свободного места справа
 * @return int возвращает 1 если внизу находится блок и перемещение вниз
 * невозможно
 */
int check_next_rows(GameInfo_t g_info, shapes_s *list, shapes_s sh, int x);

// ATTACHING

/**
 * @brief Проверка последнего(верхнего) ряда
 *
 * @param g_info Из структуры берем игровое поле(матрицу) и проверяем верхний
 * ряд
 * @return int возвращает 1 если там есть фигура и игра заканчивается
 */
int check_last_line(GameInfo_t *g_info);

/**
 * @brief Проверка целых линий и их удаление со сдвигом верхних рядов вниз
 *
 * @param g_info  Из структуры берем игровое поле(матрицу) и зануляем
 * заполненные линии
 * @param win структура для выбора игрового окна
 * @return int 1 в случае нахождения заполненной линии
 */
int check_line(GameInfo_t *g_info /*, shapes_s *list, shapes_s sh*/);

// MOVING

/**
 * @brief Сдвиг блока влево
 *
 * @param sh Структура для изменения координат фигуры и обозначения конкретной
 * фигуры
 * @param g_info Структура для добавления фигуры в матрицу поля
 * @param list список фигур
 */
int shift_left(shapes_s *sh, GameInfo_t g_info, shapes_s *list);

/**
 * @brief Сдвиг блока вправо
 *
 * @param sh Структура для изменения координат фигуры и обозначения конкретной
 * фигуры
 * @param g_info Структура для добавления фигуры в матрицу поля
 * @param list список фигур
 */
int shift_right(shapes_s *sh, GameInfo_t g_info, shapes_s *list);

/**
 * @brief Поворот блока
 *
 * @param g_info Структура для добавления фигуры в матрицу поля
 * @param list список фигур
 * @param sh Структура для изменения координат фигуры и обозначения конкретной
 * фигуры
 */
int turning_the_shape(GameInfo_t g_info, shapes_s *list, shapes_s *sh);

// SUBFUNCTION

/**
 * @brief Проверка окружения справа для поворота
 *
 * @param g_info Структура используется для поиска на поле свободного места
 * @param list список фигур
 * @param sh  Структура для изменения координат фигуры и обозначения конкретной
 * фигуры
 * @param x возможность проверки свободного места справа
 * @return int в случае наличия свободного места справа возвращает 1
 */
int checking_on_the_right_for_turn(GameInfo_t g_info, shapes_s *list,
                                   shapes_s sh, int x);

/**
 * @brief Проверка окружения снизу для поворота
 *
 * @param g_info Структура используется для поиска на поле свободного места
 * @param list список фигур
 * @param sh  Структура для изменения координат фигуры и обозначения конкретной
 * фигуры
 * @param x возможность проверки свободного места справа
 * @return int в случае наличия свободного места снизу возвращает 1
 */
int checking_on_the_down_for_turn(GameInfo_t g_info, shapes_s *list,
                                  shapes_s sh, int x);

/**
 * @brief Функция используется для очищения из матрицы предыдущего состояния
 * блока перед ее следующим перемешением или поворотом
 *
 * @param g_info Структура предоставляет поле(матрицу) для удаления блока
 * @param list список фигур
 * @param sh структура предоставляет данные о фигуре
 */
void remove_block(GameInfo_t *g_info, shapes_s *list, shapes_s *sh);

/**
 * @brief Освобождение памяти от динамических матриц
 *
 * @param g_info  матрицы field and next
 */
void clean_memory_matrix(GameInfo_t *g_info);

/**
 * @brief Функция ставит игру на паузу
 *
 * @param win структура предоставляет игрровое окно для останвки в нем игры
 */
void pause_game(wins *win);

/**
 * @brief Увеличение скорости игры
 *
 * @param g_info Структура используется для обновления данных об игре
 */
void speed_game(GameInfo_t *g_info);

/**
 * @brief Поднимает уровень
 *
 * @param g_info Структура используется для записи данных об игре
 */
void level_up(GameInfo_t *g_info);

/**
 * @brief Запись рекорда в текстовый файл
 *
 * @param g_info Структура используется для записи данных об игре
 */
void write_hi_score(GameInfo_t g_info);

/**
 * @brief Чтение рекорда из текстового файла
 *
 * @param g_info Структура используется для записи данных об игре
 */
void read_hi_score(GameInfo_t *g_info);

/**
 * @brief Инициализация списка фигур
 *
 * @param list_shapes список фигур
 */
void init_list_shape(shapes_s *list_shapes);

void clear_field(GameInfo_t *g_info);

#endif
