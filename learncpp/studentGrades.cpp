#include <iostream>

#include "./include/gradeMap.hpp"

int main() {
  GradeMap grades;

  grades["Joe"] = 'A';
  grades["Frank"] = 'B';

  std::cout << "Joe has a grade of "   << grades["Joe"]   << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

  return 0;
}
