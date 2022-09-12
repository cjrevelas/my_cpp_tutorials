#include <iostream>

void editArray(int *xx);

int main() {
  int *A = new int[5];

  std::cout << "array A at the beginning...\n";

  for(int ii=0; ii<=4; ++ii) {
    A[ii] = ii;
    std::cout << A[ii] << ' ';
  }

  std::cout << '\n';

  std::cout << "array A after modification...\n";

  editArray(A);

  for(int ii=0; ii<=4; ++ii){
    std::cout << A[ii] << ' ';
  }

  std::cout << '\n';

  delete[] A;
  A = nullptr;

  return 0;
}

void editArray(int *xx) {
  for(int jj=0; jj<=4; ++jj){
    xx[jj] = 2*jj+1;
  }

  return;
}
