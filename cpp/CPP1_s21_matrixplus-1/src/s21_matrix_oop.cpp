#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) : rows_{rows}, cols_{cols} {
  allocate();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_{other.rows_}, cols_{other.cols_} {
  this->allocate();
  for (int i{}; i < this->rows_; i++)
    for (int j = {}; j < this->cols_; j++)
      this->matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() { deallocate(); }

int S21Matrix::getRows() { return this->rows_; }
int S21Matrix::getCols() { return this->cols_; }

void S21Matrix::setRows(int rows) {
  if (rows > 0) {
    S21Matrix buf(*this);
    this->deallocate();
    this->rows_ = rows;
    this->allocate();
    for (int i{}; i < (buf.rows_ < this->rows_ ? buf.rows_ : this->rows_); i++)
      for (int j{}; j < (buf.cols_ < this->cols_ ? buf.cols_ : this->cols_);
           j++)
        this->matrix_[i][j] = buf.matrix_[i][j];
  }
}
void S21Matrix::setCols(int cols) {
  if (cols > 0) {
    S21Matrix buf(*this);
    this->deallocate();
    this->cols_ = cols;
    this->allocate();
    for (int i{}; i < (buf.rows_ < this->rows_ ? buf.rows_ : this->rows_); i++)
      for (int j{}; j < (buf.cols_ < this->cols_ ? buf.cols_ : this->cols_);
           j++)
        this->matrix_[i][j] = buf.matrix_[i][j];
  }
}

void S21Matrix::allocate() {
  // if (this->rows_ or this->cols_) {
  this->matrix_ = new double* [rows_] {};
  for (int i{}; i < rows_; i++) this->matrix_[i] = new double[cols_]{};
  // } else
  // throw ::invalid_argument("Rows or columns cannot have a value of zero!");
}

void S21Matrix::deallocate() {
  if (this->matrix_) {
    for (int i{}; i < this->rows_; i++) delete[] this->matrix_[i];
    delete[] this->matrix_;
  }
  this->matrix_ = nullptr;
}

int S21Matrix::equalSize(const S21Matrix& other) {
  int eqSize{};
  if (this->rows_ == other.rows_ and this->cols_ == other.cols_) eqSize = 1;
  return eqSize;
}

int S21Matrix::equalSizeForMulMatrix(const S21Matrix& other) {
  int eqSizeForMulMatrix{};
  if (this->rows_ == other.cols_ and this->cols_ == other.rows_)
    eqSizeForMulMatrix = 1;
  return eqSizeForMulMatrix;
}

int S21Matrix::isSquare() {
  int isSquare{};
  if (this->rows_ == this->cols_) isSquare = 1;
  return isSquare;
}

S21Matrix S21Matrix::findMinor(int row, int col) {
  int a{};
  S21Matrix minor(this->rows_ - 1, this->cols_ - 1);
  if (minor.matrix_)
    for (int i{}; i < this->rows_; i++) {
      int b = 0;
      for (int j{}; j < this->cols_; j++) {
        if (!(i == row or j == col)) {
          minor.matrix_[a][b++] = this->matrix_[i][j];
        }
      }
      if (i != row) a++;
    }
  return minor;
}

double S21Matrix::findDeterminant() {
  double det{};
  if (this->cols_ == 2)
    det = this->matrix_[0][0] * this->matrix_[1][1] -
          this->matrix_[0][1] * this->matrix_[1][0];
  else {
    for (int i{}; i < this->cols_; i++) {
      S21Matrix buf = this->findMinor(0, i);
      det += s21_sign(i) * this->matrix_[0][i] * buf.findDeterminant();
    }
  }
  return det;
}

void S21Matrix::SumMatrix_and_SubMatrix(const S21Matrix& other, int oper) {
  if (this->equalSize(other)) {
    for (int i{}; i < this->rows_; i++)
      for (int j{}; j < this->cols_; j++) {
        if (oper)
          this->matrix_[i][j] += other.matrix_[i][j];
        else
          this->matrix_[i][j] -= other.matrix_[i][j];
      }
  } else
    throw ::domain_error("Matrix is not equal");
}

void S21Matrix::print() {
  for (int i{}; i < this->rows_; i++) {
    for (int j{}; j < this->cols_; j++) cout << this->matrix_[i][j] << " ";
    cout << endl << endl;
  }
}

double S21Matrix::s21_sign(int i) { return (i % 2 == 0) ? 1 : -1; }

/*












*/

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  int eq{1};
  if (this->equalSize(other)) {
    for (int i{}; i < this->rows_; i++) {
      for (int j{}; j < this->cols_; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) >= 1e-7) eq = 0;
      }
    }
  } else
    eq = 0;

  return eq;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  this->SumMatrix_and_SubMatrix(other, 1);
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  this->SumMatrix_and_SubMatrix(other, 0);
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i{}; i < this->rows_; i++)
    for (int j{}; j < this->cols_; j++) this->matrix_[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->equalSizeForMulMatrix(other)) {
    S21Matrix result(this->rows_, other.cols_);
    for (int i{}; i < this->rows_; i++) {
      for (int j{}; j < other.cols_; j++) {
        for (int k{}; k < other.rows_; k++)
          result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
    *this = result;
  } else
    throw ::domain_error(
        "The number of columns of the first matrix is not equal to the number "
        "of rows of thclee second matrix");
}

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix result(this->cols_, this->rows_);
  for (int i{}; i < this->rows_; i++)
    for (int j{}; j < this->cols_; j++)
      result.matrix_[j][i] = this->matrix_[i][j];
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result(this->rows_, this->cols_);
  if (this->isSquare()) {
    if (this->rows_ == 1) {
      S21Matrix result(1, 1);
      result.matrix_[0][0] = 1;
      return result;
    } else {
      double det = this->Determinant();
      if (fabs(det) > 0)
        for (int i{}; i < this->rows_; i++)
          for (int j{}; j < this->cols_; j++) {
            S21Matrix buf = findMinor(i, j);
            result.matrix_[i][j] = pow(-1, i + j) * buf.Determinant();
          }
    }
  } else
    throw ::domain_error("Matrix is not square");
  return result;
}

double S21Matrix::Determinant() {
  double res{};
  if (this->isSquare()) {
    if (this->cols_ == 1)
      res = this->matrix_[0][0];
    else if (this->cols_ == 2)
      res = this->matrix_[0][0] * this->matrix_[1][1] -
            this->matrix_[0][1] * this->matrix_[1][0];
    else
      res = this->findDeterminant();
  } else
    throw ::domain_error("Matrix is not square");
  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  double d = Determinant();
  if (fabs(d) >= 1e-7) {
    S21Matrix buf = CalcComplements();
    S21Matrix result{buf.Transpose()};
    result.MulNumber(1.0 / d);
    return result;
  } else
    throw ::domain_error("The determinant of the matrix is 0");
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix sumMatrix(*this);
  sumMatrix.SumMatrix(other);
  return sumMatrix;
}
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix subMatrix(*this);
  subMatrix.SubMatrix(other);
  return subMatrix;
}
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix mulMatrix(*this);
  mulMatrix.MulMatrix(other);
  return mulMatrix;
}
S21Matrix S21Matrix::operator*(const double num) const noexcept {
  S21Matrix mulNumber(*this);
  mulNumber.MulNumber(num);
  return mulNumber;
}
bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  return this->EqMatrix(other);
}
S21Matrix S21Matrix::operator=(const S21Matrix& other) noexcept {
  if (this != &other) {
    deallocate();
    this->cols_ = other.cols_;
    this->rows_ = other.rows_;
    this->matrix_ = other.matrix_;
    allocate();
    for (int i{}; i < this->rows_; i++)
      for (int j{}; j < this->cols_; j++) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
  }
  return *this;
}
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}
double S21Matrix::operator()(int i, int j) const {
  if (i > this->rows_ or j > this->cols_)
    throw ::out_of_range("The argument is larger than the size of the matrix");
  return this->matrix_[i][j];
}
double& S21Matrix::operator()(int i, int j) {
  if (i > this->rows_ or j > this->cols_)
    throw ::out_of_range("The argument is larger than the size of the matrix");
  return this->matrix_[i][j];
}
S21Matrix operator*(const double num, const S21Matrix& other) noexcept {
  return other * num;
}
