#include <cmath>
#include <iostream>

enum ErrorCode { // If compiler does not support C++11, the "enum class" option is not possible
  ERROR_SUCCESS = 0,
  ERROR_NEGATIVE_NUMBER = -1,
};

ErrorCode doSomething(int value) {
  if (value < 0) {
    return ERROR_NEGATIVE_NUMBER;
  }

  return ERROR_SUCCESS;
}

int main() {

  tryAgain:

  std::cout << "Enter a positive number" << '\n';
  int xx;
  std::cin >> xx;

  if (doSomething(xx) == ERROR_NEGATIVE_NUMBER) {
    std::cout << "You entered a negative number! Try again.\n";
    goto tryAgain;
  } else {
    std::cout << "Good job\n";
    long double yy;
    yy = sqrt(static_cast<long double>(xx));

    std::cout << "The square root of number " << xx << " is: " << yy << '\n';
  }

  return 0;
}
