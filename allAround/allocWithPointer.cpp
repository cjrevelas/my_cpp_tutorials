#include <iostream>

int main() {
  int mm = 5;
  int nn = 4;

  int *A = new int[mm*nn];

  for (int ii=0; ii<mm; ++ii) {
    for (int jj=0; jj<nn; ++jj) {
      *(A + jj + ii*mm) = rand() % 100;
      std::cout << *(A + jj + ii*mm) << ' ';
    }
    std::cout << '\n';
  }

  delete[] A;
  A = nullptr;

  return 0;
}
