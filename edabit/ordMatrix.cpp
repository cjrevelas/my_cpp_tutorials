#include <iostream>
#include <vector>

void orderedMatrix(const int &aa, const int &bb);

int main() {
  int num_rows, num_cols;

  scanf("%d%d", &num_rows, &num_cols);

  orderedMatrix(num_rows, num_cols);

  return 0;
}

void orderedMatrix(const int &aa, const int &bb) {
  std::vector<std::vector<int>> matrix;
  std::vector<int> vec;

  for (int ii=0; ii<aa; ++ii){
    for (int jj=0; jj<bb; ++jj){
      vec.push_back(bb*ii+jj+1);
    }

    matrix.push_back(vec);
    vec.clear();
  }

  for(int ii=0; ii<aa; ++ii) {
    for (int jj=0; jj<bb; ++jj) {
      std::cout << matrix[ii][jj] << ' ';
    }

    std::cout << '\n';
  }
}
