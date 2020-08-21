#include <iostream>
#include "fractions.h"


int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin  >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin  >> f2;

	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';
}