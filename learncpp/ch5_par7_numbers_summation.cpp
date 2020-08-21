#include <iostream>

int main()
{
	int x;
	std::cout << "Enter an integer number." << std::endl;
	std::cin  >> x;

	int sum=0;

	for (int i=0; i<=x; ++i)
	{
		sum += i;
	}

	std::cout << "The result is: " << sum << std::endl;

	return 0;
}