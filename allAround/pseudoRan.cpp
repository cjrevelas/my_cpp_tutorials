#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  // Obtain the seed from system's clock
  std::srand(static_cast<unsigned int>(std::time(0)));

  for (int count=1; count<=100; ++count) {
    std::cout << std::rand() << '\t';

    if (count%5 == 0) { std::cout << '\n'; }
  }

  return 0;
}
