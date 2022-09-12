#include <iostream>

void change_x(int *px) {
  *px = 6;
}

int main() {
  int xx = 5;
  std::cout << "x = " << xx << '\n';

  change_x(&xx);
  std::cout << "x = " << xx << '\n';

  return 0;
}
