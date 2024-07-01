#include <iostream>

int main() {
  char i = 'a';

  while (i <= 'z') {
    std::cout << i << ":  " << static_cast<int>(i) << std::endl;
    ++i;
  }

  return 0;
}