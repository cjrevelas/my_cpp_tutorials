#include <iostream>

int doubleNumber(int x)
{
	return 2*x;
}

int main()
{
	int number;

	std::cout << "Enter an integer number." << "\n";
	std::cin >> number;
	std::cout << "\nDouble = " << doubleNumber(number) << "\n";

	return 0;
}