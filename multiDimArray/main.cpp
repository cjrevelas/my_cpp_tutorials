#include <iostream>
//#include "matrixRawPointers2D.h"
//#include "matrixSmartPointers2D.h"
//#include "matrixRawPointers1D.h"
#include "matrixSmartPointers1D.h"


int main(){
  Matrix<int> matrix(3,2);
  matrix.Print();

  std::cin.get();

  matrix(0,0) = 1;
  int a = matrix(0,0);

  std::cout << '\n';

  matrix.Print();
  std::cin.get();

  matrix.Resize(4,4);
  matrix.InitZero();
  matrix.Print();

  Matrix<int> m1(3,2);
  Matrix<int> m2(3,2);
  Matrix<int> m3(3,2);

  std::cout << '\n';

  m1.InitRandom();
  m2.InitRandom();

  m1.Print();
  m2.Print();

  m3 = m1 + m2;
  m3.Print();

  std::cout << "Everything fine\n";

  return 0;
}
