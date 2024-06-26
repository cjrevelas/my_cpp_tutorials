#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1,2,3,4,5};
  
  int kk = 11;

  if (kk > vec.size()) {
      kk %= vec.size();
  }

  std::vector<int> temp(kk);

  for (int ii=0; ii<kk; ++ii) {
    temp[ii] = vec[vec.size()-kk+ii];
  }

  for (int ii=vec.size()-1; ii>kk-1; --ii) {
    vec[ii] = vec[ii-kk];
  }

  for (int ii=0; ii<kk; ++ii) {
    vec[ii] = temp[ii];
  }

  for (const int &num : vec) {
    std::cout << num << ' ';
  }

  std::cout << '\n';

  return 0;
}
