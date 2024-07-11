#ifndef MATRIX_CPP_H
#define MATRIX_CPP_H

#include <gtest/gtest.h>
#include <iso646.h>

#include <cmath>
#include <iostream>

using namespace std;

class S21Matrix {
 private:
  int rows_, cols_;  // << quantity rows and cols
  double** matrix_;  // << matrix

 public:
  // constructs
  /**
   * @brief Construct a new S21Matrix object
   */
  S21Matrix();
  /**
   * @brief Construct a new S21Matrix object
   * @param rows Quantity rows
   * @param cols Quantity cols
   */
  S21Matrix(int rows, int cols);

  /**
   * @brief Construct copy
   *
   * @param other Source matrix
   */
  S21Matrix(const S21Matrix& other);

  /**
   * @brief Construct move
   *
   * @param other Source matrix
   */
  S21Matrix(S21Matrix&& other);
  // destruct
  /**
   * @brief Destroy the S21Matrix object
   */
  ~S21Matrix();
  // getters and setters
  /**
   * @brief Get the Rows object
   *
   * @return int Quatity rows
   */
  int getRows();

  /**
   * @brief Get the Cols object
   *
   * @return int Quatity cols
   */
  int getCols();

  /**
   * @brief Set the Rows object
   *
   * @param rows new value
   */
  void setRows(int rows);

  /**
   * @brief Set the Cols object
   *
   * @param cols new value
   */
  void setCols(int cols);

  // subfuction
  /**
   * @brief allocate memory for the matrix
   */
  void allocate();

  /**
   * @brief free up memory from the matrix
   *
   */
  void deallocate();

  /**
   * @brief checking matrices for the same size
   *
   * @param other other matrix
   * @return int result checking
   */
  int equalSize(const S21Matrix& other);

  /**
   * @brief checking matrices where the number of columns of the first matrix
   * is equal to the number of rows of the second matrix
   *
   * @param other other matrix
   * @return int result checking
   */
  int equalSizeForMulMatrix(const S21Matrix& other);

  /**
   * @brief checks if the matrix is square
   *
   * @return int result checking
   */
  int isSquare();

  /**
   * @brief find Minor for CalcComplements
   *
   * @return int Minor of matrix
   */
  S21Matrix findMinor(int row, int col);

  /**
   * @brief find determinant
   *
   * @return double result
   */
  double findDeterminant();

  /**
   * @brief знак в зависимости от числа(четное/нечетное)
   *
   * @param i
   * @return double
   */
  double s21_sign(int i);

  /**
   * @brief union SumMatrix and SubMatrix
   *
   * @param other other matrix
   * @param oper 1 - SumMatrix , 0 - SubMatrix
   */
  void SumMatrix_and_SubMatrix(const S21Matrix& other, int oper);

  /**
   * @brief print matrix
   */
  void print();
  /**
   * @brief na vsyakiy sluchai
   *
   * @param num
   * @param other
   * @return S21Matrix
   */
  friend S21Matrix operator*(const double num, const S21Matrix& other) noexcept;

  // fuction for matrix

  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // operators

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num) const noexcept;
  bool operator==(const S21Matrix& other) noexcept;
  S21Matrix operator=(const S21Matrix& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double operator()(int i, int j) const;
  double& operator()(int i, int j);
};

#endif