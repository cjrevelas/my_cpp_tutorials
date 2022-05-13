#include <iostream>
#include <vector>

int main(){
   int* a = new int;
   *a = 2;
   std::cout << a << std::endl;
   std::cout << *a << std::endl;
   return 0;
}
