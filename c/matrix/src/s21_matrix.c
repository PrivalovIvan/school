#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (rows > 0 && columns > 0 && result != NULL) {
    double **matrix = create_valid_matrix(rows, columns);
    if (matrix != NULL) {
      result->matrix = matrix;
      result->rows = rows, result->columns = columns;
    } else
      res = INCORRECT_MATRIX;
  } else
    res = INCORRECT_MATRIX;
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    free(A->matrix);
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (CHECK_(A) or CHECK_(B) or !(s21_eq_size(A, B)))
    res = FAILURE;
  else {
    for (int i = 0; i < A->rows and res == 1; i++) {
      for (int j = 0; j < A->columns and res == 1; j++) {
        double temp = fabs(A->matrix[i][j] - B->matrix[i][j]);
        if (temp >= EXP) res = FAILURE;
      }
    }
  }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = s21_operation_for_sum_and_sub(A, B, result, 1);
  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = s21_operation_for_sum_and_sub(A, B, result, 2);
  return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  if (CHECK_(A) or !result)
    res = INCORRECT_MATRIX;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    if (result->matrix) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (CHECK_(A) or CHECK_(B) or !result)
    res = INCORRECT_MATRIX;
  else if ((A->columns != B->rows))
    res = CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows and result->matrix; i++) {
      for (int j = 0; j < B->columns; j++) {
        double temp = 0;
        for (int k = 0; k < B->rows; k++) {
          temp += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = temp;
      }
    }
  }
  return res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (!result or CHECK_(A))
    res = INCORRECT_MATRIX;
  else {
    s21_create_matrix(A->columns, A->rows, result);
    if (result->matrix) {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (CHECK_(A) or !result)
    res = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    res = CALCULATION_ERROR;
  else if (A->rows == 1 and A->columns == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1;
  } else {
    double det = 0;
    matrix_t buf = {0};
    s21_determinant(A, &det);
    if (fabs(det) > 0) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows and result->matrix; i++)
        for (int j = 0; j < A->columns; j++) {
          buf = s21_find_minor(i, j, A);
          s21_determinant(&buf, &det);
          result->matrix[i][j] = pow(-1, i + j) * det;
          s21_remove_matrix(&buf);
        }
    }
  }
  return res;
}

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (CHECK_(A) or !result)
    res = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    res = CALCULATION_ERROR;
  else if (A->columns == 1)
    *result = A->matrix[0][0];
  else if (A->columns == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  else
    *result = s21_find_determinant(A);
  return res;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  matrix_t buf = {0};
  matrix_t buf2 = {0};
  if (!A or !A->matrix or !result or A->rows <= 0 or A->columns <= 0)
    res = INCORRECT_MATRIX;
  else if (A->columns != A->rows)
    res = CALCULATION_ERROR;
  else {
    double det = 0;
    s21_determinant(A, &det);
    if (fabs(det) >= 1e-7) {
      s21_calc_complements(A, &buf);
      s21_transpose(&buf, &buf2);
      s21_mult_number(&buf2, 1.0 / det, result);
      s21_remove_matrix(&buf);
      s21_remove_matrix(&buf2);
    }
  }
  return res;
}

/********************************************************************************************************/
// sub function

double s21_sign(int i) { return (i % 2 == 0) ? 1 : -1; }

double **create_valid_matrix(int rows, int columns) {
  double **matrix =
      malloc(rows * columns * sizeof(double) + rows * sizeof(double *));
  if (matrix != NULL) {
    double *ptr = (double *)(matrix + rows);
    for (int i = 0; i < rows; i++) matrix[i] = ptr + columns * i;
  }
  return matrix;
}

matrix_t s21_find_minor(int row, int col, matrix_t *A) {
  int a = 0;
  matrix_t buf = {0};
  s21_create_matrix(A->rows - 1, A->rows - 1, &buf);
  if (buf.matrix) {
    for (int i = 0; i < A->columns; i++) {
      int b = 0;
      for (int j = 0; j < A->columns; j++) {
        if (!(i == row or j == col)) {
          buf.matrix[a][b++] = A->matrix[i][j];
        }
      }
      if (i != row) a++;
    }
  }

  return buf;
}

double s21_find_determinant(matrix_t *A) {
  double det = 0;
  if (A->columns == 2)
    det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  else {
    for (int i = 0; i < A->columns; i++) {
      matrix_t buf_minor = s21_find_minor(0, i, A);
      det += s21_sign(i) * A->matrix[0][i] * s21_find_determinant(&buf_minor);
      s21_remove_matrix(&buf_minor);
    }
  }
  return det;
}

int s21_operation_for_sum_and_sub(matrix_t *A, matrix_t *B, matrix_t *result,
                                  int a) {
  int res = OK;
  if (!A or !B or !s21_eq_size(A, B))
    res = CALCULATION_ERROR;
  else if (!result or !A->matrix or !B->matrix)
    res = INCORRECT_MATRIX;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    if (result->matrix) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (a == 1) result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          if (a == 2) result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return res;
}

void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step) {
  if (A != NULL && A->matrix != NULL) {
    double value = start_value;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += iteration_step;
      }
    }
  }
}

void matrix_full(double count, matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = count++;
    }
  }
}

int s21_eq_size(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if ((A->columns != B->columns) or (A->rows != B->rows)) res = FAILURE;
  return res;
}
