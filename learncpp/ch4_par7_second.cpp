#include <iostream>
#include "Fraction.h"

Fraction& getFraction(Fraction &fraction)
{
	std::cout << "Enter the numerator of the fraction." << std::endl;
	std::cin  >> fraction.numerator;

	std::cout << "Enter the denominator of the fraction." << std::endl;
	std::cin  >> fraction.denominator;

	return fraction;
}

void printProduct(Fraction &fraction__1, Fraction &fraction__2)
{
	double product;
	product = (static_cast<double>(fraction__1.numerator*fraction__2.numerator))/(fraction__1.denominator*fraction__2.denominator);

	std::cout << "The product of the two given fractions is equal to: " << product << std::endl;

}

int main()
{
	Fraction fraction_1;
	Fraction fraction_2;

	getFraction(fraction_1);
	getFraction(fraction_2);

	printProduct(fraction_1, fraction_2);

	return 0;
}