#include <iostream>

namespace Zoo {
enum Animal { CHICKEN, DOG, CAT, ELEPHANT, DUCK, SNAKE };

}

int main() {
  int legs[Zoo::SNAKE + 1] = {2, 4, 4, 4, 2, 0};

  std::cout << "A chicken has " << legs[Zoo::CHICKEN] << " legs.\n";
  std::cout << "A dog has " << legs[Zoo::DOG] << " legs.\n";
  std::cout << "A cat has " << legs[Zoo::CAT] << " legs.\n";
  std::cout << "An elephant has " << legs[Zoo::ELEPHANT] << " legs.\n";
  std::cout << "A duck has " << legs[Zoo::DUCK] << " legs.\n";
  std::cout << "A snake has " << legs[Zoo::SNAKE] << " legs.\n";

  return 0;
}
