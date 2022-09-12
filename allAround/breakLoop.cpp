#include <iostream>

int main() {
  int sum=0;

  for (int ii=1; ii<=10; ++ii) {
    std::cout << "Enter a new integer number or zero to exit." << '\n';
    int xx;
    std::cin >> xx;

    if (xx==0) {
      break;
    }

    sum += xx;
  }

  std::cout << "The sum of the numbers you entered is equal to: " << sum << '\n';

  return 0;
}
