#include <iostream>
#include "animals.h"

int main()
{
	Cat fred("Fred"), misty("Misty"), zeke("Zeke");

	Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");

	Animal *animals[] = { &fred, &misty, &zeke, &garbo, &pooky, &truffle };

	for (int iii = 0; iii < 6; ++iii)
	{
		std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << std::endl; //The pointers here point to the Base part of the derived classes.
	}

	return 0;
}