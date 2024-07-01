#include <iostream>

int main() {
  int ii = 5;

  while (ii >= 1) {
    int jj = ii;
    while (jj >= 1) {
      std::cout << jj << ' ';

      --jj;
    }

    std::cout << '\n';

    --ii;
  }

  return 0;
}
