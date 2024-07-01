#include <iostream>

int main() {
  bool boolVar = true;
  int number;

  while (boolVar) {
    std::cout << "Please given an integer number from 1 to 9." << '\n';
    std::cin >> number;

    if (number >= 1 && number <= 9) {
      boolVar = false;
    }

    std::cin.ignore(32767, '\n');
  }

  int array[] = {4, 6, 7, 3, 8, 2, 1, 9, 5};

  int arrayLength = sizeof(array) / sizeof(array[0]);

  for (int ii = 0; ii < arrayLength; ++ii) {
    std::cout << array[ii] << ' ';
  }

  std::cout << '\n';

  int index;

  for (int ii = 0; ii < arrayLength; ++ii) {
    if (array[ii] == number) {
      index = ii;
      break;
    }
  }

  std::cout << "The index of the number you entered is: " << index << '\n';

  return 0;
}
