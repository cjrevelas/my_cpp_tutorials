#include <iostream>

// Faster solution required.

class Solution {
 public:
  double myPow(double x, int n) {
    double ans = 1.;

    if (x == 1) return 1;
    if (x == 0) return 1;
    if (x == -1) {
      if (n % 2 == 0) {
        return 1;
      } else {
        return -1;
      }
    }

    if (n > 0) {
      for (int ii=0; ii<n; ++ii) {
        ans *= x;
      }
    } else if (n < 0) {
      double inv = 1.;

      int m = -n;

      for (int ii=0; ii<m; ++ii) {
        inv *= x;
      }

      ans = 1./inv;
    } else if (n == 0) {
      ans = 1;
    }

    return ans;
  }
};

int main() {

  Solution solution;

  std::cout << solution.myPow(2.,-2) << '\n';

  return 0;
}
