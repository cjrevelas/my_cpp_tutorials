#include <iostream>

int main() {
  int ii = 1;

  while (ii <= 5) {
    int jj = 1;
    while (jj <= ii) {
      std::cout << jj << ' ';

      ++jj;
    }

    std::cout << '\n';
    ++ii;
  }

  return 0;
}
