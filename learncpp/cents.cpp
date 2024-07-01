#include <iostream>

#include "include/cents.h"

int main() {
  Cents dime(10);
  Cents nickel(5);

  if (nickel > dime) {
    std::cout << "A nickel is greater than a dime.\n";
  } else if (nickel >= dime) {
    std::cout << "A nickel is greater than or equal to a dime.\n";
  } else if (nickel < dime) {
    std::cout << "A dime is greater than a nickel.\n";
  } else if (nickel <= dime) {
    std::cout << "A dime is greater than or equal to a nickel.\n";
  }

  return 0;
}
