#include <iostream>

int main() {
  int xx;
  std::cout << "Enter an integer number." << '\n';
  std::cin >> xx;

  int sum = 0;

  for (int ii = 0; ii <= xx; ++ii) {
    sum += ii;
  }

  std::cout << "The result is: " << sum << '\n';

  return 0;
}
