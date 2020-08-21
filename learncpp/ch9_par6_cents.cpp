#include <iostream>
#include "cents.h"

int main()
{
	Cents dime(10);
	Cents nickel(5);

	if (nickel > dime)
		std::cout << "a nickel is greater than a dime.\n";
	if (nickel >= dime)
		std::cout << "a nickel is greater than or equal to a dime.\n";
	if (nickel < dime)
		std::cout << "a dime is greater than a nickel.\n";
	if (nickel <= dime)
		std::cout << "a dime is greater than or equal to a nickel.\n";

	return 0;
}

