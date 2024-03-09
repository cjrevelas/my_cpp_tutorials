#include <iostream>

int readInteger();
void writeAnswer(int ans);

int main() {
  int x, y, z;

  std::cout << "First integer: \n";
  x = readInteger();

  std::cout << "Second integer: \n";
  y = readInteger();
  z = x + y;

  writeAnswer(z);

  return 0;
}

int readInteger() {
  int num;

  std::cin >> num;

  return num;
}

void writeAnswer(int ans) {
  std::cout << ans << '\n';

  return;
}
