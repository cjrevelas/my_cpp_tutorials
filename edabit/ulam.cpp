#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main() {
  const int nn = 495;

  std::vector<int> vec;

  vec.push_back(1);
  vec.push_back(2);

  for (int pp=3; pp<8000; ++pp) {
    int counter = 0;

    for (int ii=0; ii<(int) vec.size()-1; ++ii) {
      for (int jj=ii+1; jj<(int) vec.size(); ++jj) {
        if ((vec[ii]+vec[jj])==pp) { ++counter; }
        if (counter>1) { break; }
      }

      if (counter>1) { break; }
    }

    if (counter == 1) { vec.push_back(pp); }
    if (vec.size()==nn) { break; }
  }

  std::cout << vec.back() << '\n';

  return 0;
}
