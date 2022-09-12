#include <iostream>
#include <cstdlib>

int main() {
  float x, y;
  char op;

  std::cout << "Enter two float numbers:\n";

  std::cin >> x;
  std::cin >> y;

  std::cout << "Please enter an arithmetic operation:\n";

  std::cin >> op;

  if (op == '+') {
    std::cout << "The sum of " << x << " and " << y << " equals " << x+y << '\n';
  } else if (op == '-') {
    std::cout << "The difference of " << x << " and " << y << " equals " << x-y << '\n';
  } else if (op == '*') {
    std::cout << "The product of " << x << " and " << y << " equals " << x*y << '\n';
  } else if (op == '/') {
    std::cout << "The division of " << x << " and " << y << " equals " << x/y << '\n';
  } else {
    std::cout << "Not valid operator...exiting...\n";
  }

  return 0;
}
