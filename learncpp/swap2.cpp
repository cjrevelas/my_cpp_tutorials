#include <iostream>

int main() {
  const int length = 5;
  int array[length] = {30, 60, 20, 50, 40};

  for (int ii = 0; ii < length - 1; ++ii) {
    for (int jj = ii + 1; jj < length; ++jj) {
      if (array[ii] < array[jj])  // If you change here to ">" it prints in
                                  // ascending order (instead of descending)
      {
        int temp;
        temp = array[ii];
        array[ii] = array[jj];
        array[jj] = temp;
      }
    }
  }

  for (int ii = 0; ii < length; ++ii) {
    std::cout << array[ii] << ' ';
  }

  std::cout << '\n';

  return 0;
}
