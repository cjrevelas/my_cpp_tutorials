#include <iostream>

#include "include/animals.h"

int main() {
  Cat fred("Fred"), misty("Misty"), zeke("Zeke");

  Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");

  Animal *animals[] = {&fred, &misty, &zeke, &garbo, &pooky, &truffle};

  for (int ii = 0; ii < 6; ++ii) {
    std::cout << animals[ii]->GetName() << " says " << animals[ii]->Speak() << '\n';  // The pointers here point to the Base part of the derived classes
  }

  return 0;
}
