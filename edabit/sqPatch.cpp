#include <iostream>
#include <vector>

std::vector<std::vector<int>> squarePatch(int nn);

int main() {
  squarePatch(10);

  return 0;
}

std::vector<std::vector<int>> squarePatch(int nn) {
  std::vector<std::vector<int>> square;
  std::vector<int> vec;

  for (int i=0; i<nn; ++i) {
    vec.clear();
    for (int j=0; j<nn; ++j) {
      vec.push_back(nn);
    }

    square.push_back(vec);
  }

  for (std::vector<int> vv : square) {
    for (int ii : vv) {
      std::cout << ii << ' ';
    }

    std::cout << '\n';
  }

  return square;
}
