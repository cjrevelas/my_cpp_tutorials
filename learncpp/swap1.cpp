#include <algorithm>  // For std::swap (we are not going to use a temp variable here)
#include <iostream>

int main() {
  const int length = 5;
  int array[length] = {30, 60, 20, 50, 40};

  for (int ii = 0; ii < length - 1; ++ii) {
    int largestIndex = ii;

    for (int jj = ii + 1; jj < length; ++jj) {
      if (array[jj] > array[largestIndex]) {
        largestIndex = jj;  // The inner loop does not swap (like in
                            // second_pv.cpp), it just detects the location of
                            // the largest value (i.e. largestIndex)
      }
    }

    std::swap(array[ii], array[largestIndex]);  // Swap once the location of the
                                                // largest value is detected
  }

  for (int ii = 0; ii < length; ++ii) {
    std::cout << array[ii] << ' ';
  }

  std::cout << '\n';

  return 0;
}
