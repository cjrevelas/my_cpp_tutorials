#include <iostream>
#include <cmath>

enum ErrorCode                 //Not a C++11 compiler, so the "enum class" option is not possible.
{
	ERROR_SUCCESS = 0,
	ERROR_NEGATIVE_NUMBER = -1,
};

ErrorCode doSomething(int x_value)
{
	if (x_value < 0)
	{
		return ERROR_NEGATIVE_NUMBER;
	}

	return ERROR_SUCCESS;

}

int main()
{
tryAgain:

	std::cout << "Enter a positive number" << "\n";
	int x;
	std::cin >> x;

	if (doSomething(x) == ERROR_NEGATIVE_NUMBER)
	{
		std::cout << "You entered a negative number! Try again.\n";
		goto tryAgain;
	}
	else
	{
		std::cout << "Nice job bro!\n";
		long double y;
		y = sqrt(static_cast<long double>(x));

		std::cout << "The square root of the entered number" << x << "is:" << y << "\n";
	}

	return 0;
}