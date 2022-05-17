#include <iostream>

int getValue(void *ii) {
  int *temp = *(static_cast<int **>(ii));

  return *temp;
}

int main() {
  int xx = 2;
  void *pointer1 = &xx;
  void *pointer2 = &pointer1;

  std::cout << xx << ' ' << pointer1 << ' ' << pointer2 << '\n';
  std::cout << *(static_cast<int *>(pointer1)) << ' ' << **(static_cast<int **>(pointer2)) << '\n';

  int yy = getValue(pointer2);

  std::cout << yy << ' ' << &yy << '\n';
  std::cin.get();

  return 0;
}
