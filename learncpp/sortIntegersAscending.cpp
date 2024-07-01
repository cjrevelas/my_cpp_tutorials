#include <algorithm>
#include <iostream>

int main() {
  const int length = 9;
  int array[length] = {6, 3, 2, 9, 7, 1, 5, 4, 8};

  for (int ii = 0; ii < length - 1; ++ii) {
    for (int jj = ii + 1; jj < length; ++jj) {
      if (array[ii] > array[jj])  // if you change here to ">" it prints in
                                  // ascending order (instead of descending)
      {
        std::swap(array[ii], array[jj]);
      }
    }
  }

  for (int ii = 0; ii < length; ++ii) {
    std::cout << array[ii] << " ";
  }

  std::cout << '\n';

  return 0;
}
