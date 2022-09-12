#include <iostream>
#include "matrix.h"

Matrix<int> &get_matrix(Matrix<int> &matrix) { return matrix; }

int main(){
  Matrix<int> matrix(3,2);

  matrix.print();
  std::cin.get();

  matrix(0,0) = 1;

  int a = matrix(0, 0);

  std::cout << '\n';
  matrix.print();
  std::cin.get();
}
