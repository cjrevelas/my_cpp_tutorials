#ifndef MATRIX_SMART_POINTERS_1D_H
#define MATRIX_SMART_POINTERS_1D_H

#include <iostream>
#include <memory>

template<class T>
class Matrix {
 private:
  int rows_;
  int cols_;

  using smp1d = std::unique_ptr<T []>;

  smp1d pointer_;

 public:
  Matrix(int rows = 0, int cols = 0);
  ~Matrix();

  Matrix<T> &operator=(const Matrix<T> &matrix);
  Matrix<T> &operator+(const Matrix<T> &matrix);

  void Resize(int, int);
  void InitZero();
  void InitRandom();
  void Print() const;

  T &operator()(int row, int col) const { return pointer_[row * cols_ + col]; }
};

template<class T>
Matrix<T>::Matrix(int rows, int cols) : rows_(rows), cols_(cols) { pointer_ = std::make_unique<T []>(rows_ * cols_); }

template<class T>
Matrix<T>::~Matrix() {}

template<class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrix){
  // do the copy
  for (int ii=0; ii<rows_; ++ii) {
    for (int jj=0; jj<cols_; ++jj){
      this->pointer_[ii * cols_ + jj] = matrix.pointer_[ii * cols_ + jj];
    }
  }

  // return the existing object so that we chain this operator
  return (*this);
}

template<class T>
void Matrix<T>::Resize(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;

  pointer_ = std::make_unique<T []>(rows_ * cols_);
}


template<class T>
void Matrix<T>::InitZero() {
  for (int ii = 0; ii < rows_; ++ii) {
    for (int jj = 0; jj < cols_; ++jj) {
      pointer_[ii * cols_ + jj] = 0;
    }
  }
}

template<class T>
void Matrix<T>::InitRandom() {
  for (int ii = 0; ii < rows_; ++ii) {
    for (int jj = 0; jj < cols_; ++jj) {
      pointer_[ii * cols_ + jj] = rand() % 100;
    }
  }
}

template<class T>
void Matrix<T>::Print() const {
  for (int ii = 0; ii < rows_; ++ii) {
    for (int jj = 0; jj < cols_; ++jj) {
      std::cout << pointer_[ii * cols_ + jj] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

template<class T>
Matrix<T> &Matrix<T>::operator+(const Matrix<T> &matrix) {
  for (int ii=0; ii<rows_; ++ii) {
    for (int jj=0; jj<cols_; ++jj) {
      this->pointer_[ii * cols_ + jj] += matrix.pointer_[ii * cols_ + jj];
    }
  }

  return (*this);
}

#endif // MATRIX_SMART_POINTERS_1D_H
