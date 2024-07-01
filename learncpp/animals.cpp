#include <iostream>
#include <string>

enum Animal { PIG = 0, CHICKEN = 1, GOAT = 2, CAT = 3, DOG = 4, OSTRICH = 5 };

std::string getAnimalName(Animal animal);
int printNumberOfLegs(Animal animal);

int main() {
  Animal animal;
  animal = OSTRICH;
  std::cout << getAnimalName(animal) << std::endl;

  animal = CAT;
  std::cout << "A " << getAnimalName(animal) << " has "
            << printNumberOfLegs(animal) << " legs." << std::endl;

  animal = CHICKEN;
  std::cout << "A " << getAnimalName(animal) << " has "
            << printNumberOfLegs(animal) << " legs." << std::endl;
  return 0;
}

std::string getAnimalName(
    Animal animal)  // passed by value and given the same name
{
  std::string animal_name;

  switch (animal) {
    case PIG:
      animal_name = "Pig";
      break;

    case CHICKEN:
      animal_name = "Chicken";
      break;

    case GOAT:
      animal_name = "Goat";
      break;

    case CAT:
      animal_name = "Cat";
      break;

    case DOG:
      animal_name = "Dog";
      break;

    case OSTRICH:
      animal_name = "Ostrich";
      break;

    default:
      animal_name = "Error: invalid animal name entered.";
      break;
  }

  return animal_name;
}

int printNumberOfLegs(Animal animal) {
  int numberOfLegs;

  switch (animal) {
    case PIG:
    case GOAT:
    case CAT:
    case DOG:
      numberOfLegs = 4;
      break;

    case CHICKEN:
    case OSTRICH:
      numberOfLegs = 2;
      break;

    default:
      std::cout << "Error: invalid animal name entered.";
      numberOfLegs = -1;
      break;
  }

  return numberOfLegs;
}