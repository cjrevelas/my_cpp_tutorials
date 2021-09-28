#include <iostream>
#include <cstdlib>
#include <vector>

int main(){
  int m = 5;
  int n = 4;

  std::vector<int> A(m*n);

  for (int i=0; i<m; ++i){
      for (int j=0; j<n; ++j){

          A[j+i*m] = rand() % 100;

          std::cout << A[j+i*m] << ' ';
      }

      std::cout << '\n';
  }

  return 0;
}
