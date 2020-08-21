#include <iostream>

bool isEven(int x);

int main()
{
	std::cout << "Give an integer number.\n";
	int x;
	std::cin  >> x;

	bool even = isEven(x);

	if (even)
	{
		std::cout << "The number you entered is even.\n";
	}
	else
	{
		std::cout << "The number you entered is odd.\n";
	}

	return 0;
}


bool isEven(int x)
{
	if (x % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
