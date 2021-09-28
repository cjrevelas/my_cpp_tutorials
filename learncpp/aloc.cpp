#include <iostream>
#include <cstdlib>

int main(){
  int m = 5;
  int n = 4;

  int *A = new int[m*n];

  for (int i=0; i<m; ++i){
      for (int j=0; j<n; ++j){

          *(A+j+i*m) = rand() % 100;

          std::cout << *(A+j+i*m) << ' ';
      }

      std::cout << '\n';
  }

  delete[] A;
  A = nullptr;

  return 0;
}
