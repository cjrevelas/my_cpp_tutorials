#include <iostream>

const int add(const int &x, const int &y);
const int subtract(const int &x, const int &y);

int main() {
  int x, y;

  std::cout << "Enter an integer: \n";
  std::cin >> x;

  std::cout << "Enter another integer: \n";
  std::cin >> y;

  std::cout << x << " + " << y << " = " << add(x, y) << '\n';
  std::cout << x << " - " << y << " = " << subtract(x, y) << '\n';

  return 0;
}

const int add(const int &x, const int &y) {
  return (x+y);
}

const int subtract(const int &x, const int &y) {
  return (x-y);
}
