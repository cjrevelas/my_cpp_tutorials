#include <iostream>
#include <vector>

std::vector<std::vector<int>> TransposeMatrix(std::vector<std::vector<int>> &arr);
std::vector<std::vector<int>> TransposeMatrixAlternative(std::vector<std::vector<int>> &arr);

int main() {
  std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  std::cout << "\nOriginal matrix:\n";

  for (std::vector<int> &vec : matrix) {
    for (int &ii : vec) {
      std::cout << ii << ' ';
    }
    std::cout << '\n';
  }

  std::vector<std::vector<int>> transp1 = TransposeMatrix(matrix);

  std::cout << "\nTransposed matrix (1):\n";

  for (std::vector<int> &vec : transp1) {
    for (int &ii : vec) {
      std::cout << ii << ' ';
    }
    std::cout << '\n';
  }

  std::vector<std::vector<int>> transp2 = TransposeMatrixAlternative(matrix);

  std::cout << "\nTransposed matrix (2):\n";

  for (std::vector<int> &vec : transp2) {
    for (int &ii : vec) {
      std::cout << ii << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}

std::vector<std::vector<int>> TransposeMatrix(std::vector<std::vector<int>> &arr) {
  int arr_rows = arr.size();
  int arr_cols = arr[0].size();
  std::vector<int> tempVector;

  std::vector<std::vector<int>> transp;

  for (int jj=0; jj<arr_cols; ++jj){
    for (int ii=0; ii<arr_rows; ++ii){
      tempVector.push_back(arr[ii][jj]);
    }

    transp.push_back(tempVector);
    tempVector.clear();
  }

  return transp;
}

std::vector<std::vector<int>> TransposeMatrixAlternative(std::vector<std::vector<int>> &arr) {
  std::vector<std::vector<int>> res(arr[0].size(), std::vector<int>(arr.size()));

  for(int i=0; i<arr.size(); ++i) {
    for(int j=0;j<arr[i].size();++j) {
      res[i][j]=arr[j][i];
    }
  }

  return res;
}
