#ifndef MATRIX_RAW_POINTERS_2D_H
#define MATRIX_RAW_POINTERS_2D_H

#include <iostream>
#include <cstdlib>
#include <vector>

template<class T>
class Matrix {
 private:
  int rows_;
  int cols_;

  T *pointer_to_row_;
  T **pointer_to_row_pointers_;

 public:
  Matrix(int rows = 0, int cols = 0);
  ~Matrix();

  Matrix<T> &operator=(const Matrix<T> &matrix);
  Matrix<T> &operator+(const Matrix<T> &matrix);

  void Resize(int, int);
  void InitZero();
  void InitRandom();
  void Print() const;

  T &operator()(int row, int col) const { return pointer_to_row_pointers_[row][col]; }
};

template<class T>
Matrix<T>::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  pointer_to_row_pointers_ = new T *[rows_];

  for (int ii = 0; ii < rows_; ++ii) {
    pointer_to_row_ = new T[cols_];

    pointer_to_row_pointers_[ii] = pointer_to_row_;
  }
}

template<class T>
Matrix<T>::~Matrix() {
  for (int ii=0; ii<rows_; ii++) {
    delete[] pointer_to_row_pointers_[ii];
  }

  delete[] pointer_to_row_pointers_;
}

template<class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrix){
  // do the copy
  for (int ii=0; ii<rows_; ++ii) {
    for (int jj=0; jj<cols_; ++jj){
      this->pointer_to_row_pointers_[ii][jj] = matrix.pointer_to_row_pointers_[ii][jj];
    }
  }

  // return the existing object so that we chain this operator
  return (*this);
}

template<class T>
void Matrix<T>::Resize(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;

  pointer_to_row_pointers_ = new T *[rows_];

  for (int ii = 0; ii < rows_; ++ii) {
    pointer_to_row_ = new T[cols_];

    pointer_to_row_pointers_[ii] = pointer_to_row_;
  }
}

template<class T>
void Matrix<T>::InitZero() {
  for (int ii = 0; ii < rows_; ++ii) {
    for (int jj = 0; jj < cols_; ++jj) {
      pointer_to_row_pointers_[ii][jj] = 0;
    }
  }
}

template<class T>
void Matrix<T>::InitRandom() {
  for (int ii = 0; ii < rows_; ++ii) {
    for (int jj = 0; jj < cols_; ++jj) {
      pointer_to_row_pointers_[ii][jj] = random() % 100;
    }
  }
}

template<class T>
void Matrix<T>::Print() const {
  for (int ii = 0; ii < rows_; ++ii) {
    for (int jj = 0; jj < cols_; ++jj) {
      std::cout << pointer_to_row_pointers_[ii][jj] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

template<class T>
Matrix<T> &Matrix<T>::operator+(const Matrix<T> &matrix){
  // do the copy
  for (int ii=0; ii<rows_; ++ii) {
    for (int jj=0; jj<cols_; ++jj){
      this->pointer_to_row_pointers_[ii][jj] += matrix.pointer_to_row_pointers_[ii][jj];
    }
  }

  // return the existing object so that we chain this operator
  return (*this);
}

#endif // MATRIX_RAW_POINTERS_2D_H
