#ifndef MATRIX_H
#define MATRIX_H

#include <iso646.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define CHECK_(A) !A or !A->matrix or A->rows <= 0 or A->columns <= 0
#define SIGN(x) x % 2 == 0 ? 1 : -1
#define EXP 1e-7
#define FABS(x) x > EXP ? x : x * -1

enum ERROR_CODES { OK, INCORRECT_MATRIX, CALCULATION_ERROR };
/*
0 - OK
1 - Ошибка, некорректная матрица
2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя
провести вычисления и т.д.)
*/

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

//Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result);
//Очистка матриц
void s21_remove_matrix(matrix_t *A);

//Сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);

//Сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
//Вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
//Умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result);

//Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);
//Определитель матрицы
int s21_determinant(matrix_t *A, double *result);
//Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);
/*********************************************************************************/
// sub functions:

//Знак для детериминанта
double s21_sign(int i);

double **create_valid_matrix(int rows, int columns);

//Сложение и вычитание
int s21_operation_for_sum_and_sub(matrix_t *A, matrix_t *B, matrix_t *result,
                                  int a);
//Возвращаем n-1
matrix_t s21_find_minor(int row, int col, matrix_t *A);
//Возвращаем det
double s21_find_determinant(matrix_t *A);
//для теста
void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);
//для теста
void matrix_full(double count, matrix_t *matrix);
//Проверяем размер матриц
int s21_eq_size(matrix_t *A, matrix_t *B);

#endif