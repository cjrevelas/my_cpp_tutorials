#include <iostream>
//#include "matrixRawPointers2D.h"
//#include "matrixSmartPointers2D.h"
#include "matrixRawPointers1D.h"


int main(){
  Matrix<int> matrix(3,2);
  matrix.print();

  std::cin.get();

  matrix(0,0) = 1;
  int a = matrix(0,0);

  std::cout << '\n';
  matrix.print();
  std::cin.get();

  matrix.resize(4,4);
  matrix.initialize();
  matrix.print();

  std::cout << "everything fine\n";

  return 0;
}
