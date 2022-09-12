#include <iostream>

void passByValue(int xx);
void passByAddress(int *xx);

int main() {
  int aa = 13;
  int bb = 13;

  passByValue(aa);
  passByAddress(&bb);

  std::cout << "variable a is now:" << aa << '\n';
  std::cout << "variable b is now:" << bb << '\n';
}

void passByValue(int xx) {
  xx = 99;   // Access to the copy of variable aa, not a itself.
}

void passByAddress(int *xx) {
  *xx = 66;  // Direct access to variable bb through its memory address given by the pointer.
}
