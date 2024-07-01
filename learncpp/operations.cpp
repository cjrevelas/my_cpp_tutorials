#include <iostream>

int Calculate(int a, int b, char symbol);

int main() {
  std::cout << "Please enter the first integer" << '\n';
  int xx;
  std::cin >> xx;

  std::cout << "Please enter the second integer" << '\n';
  int yy;
  std::cin >> yy;

  std::cout << "Choose the arithmetic operation to be executed" << '\n';
  char operation;
  std::cin >> operation;

  std::cout << "Output: " << Calculate(xx, yy, operation) << '\n';
  return 0;
}

int Calculate(int aa, int bb, char symbol) {
  switch (symbol) {
    case '+':
      return (aa + bb);
      break;
    case '-':
      return (aa - bb);
      break;
    case '*':
      return (aa * bb);
      break;
    case '/':
      return (aa / bb);
      break;
    case '%':
      return (aa % bb);
      break;
    default:
      std::cout << "Error: invalid operation inserted" << '\n';
      return (-1);
      break;
  }
}
