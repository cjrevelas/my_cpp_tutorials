#include <iostream>

struct Employee {
  short  id;
  int    age;
  double wage;
};

void printInformation(const Employee &employee) {
  std::cout << "ID:"   << employee.id   << '\n';
  std::cout << "AGE:"  << employee.age  << '\n';
  std::cout << "WAGE:" << employee.wage << '\n';
  std::cout << '\n';
}

int main() {
  Employee joe = {14, 32, 24.15};
  Employee frank = {15, 28, 15.27};

  printInformation(joe);
  printInformation(frank);

  return 0;
}
