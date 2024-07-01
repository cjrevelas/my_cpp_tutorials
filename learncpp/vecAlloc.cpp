#include <iostream>
#include <vector>

int main() {
  int mm = 5;
  int nn = 4;

  std::vector<int> A(mm * nn);

  for (int ii = 0; ii < mm; ++ii) {
    for (int jj = 0; jj < nn; ++jj) {
      A[jj + ii * mm] = rand() % 100;

      std::cout << A[jj + ii * mm] << ' ';
    }

    std::cout << '\n';
  }

  return 0;
}
