#include <iostream>

int calculate(int a, int b, char symbol);

int main()
{
	std::cout << "Please enter the first integer" << std::endl;
	int x;
	std::cin  >> x;

    std::cout << "Please enter the second integer" << std::endl;
    int y;
	std::cin  >> y;

	std::cout << "Choose the arithmetic operation to be executed" << std::endl;
	char operation;
	std::cin  >> operation;

	std::cout << "Output: " << calculate(x, y, operation) << std::endl;
	return 0;
}


int calculate(int a, int b, char symbol)
{

	switch(symbol)
	{
		case '+':
			return (a + b);
			break;
		case '-':
			return (a - b);
			break;
		case '*':
			return (a * b);
			break;
		case '/':  
			return (a / b);
			break;
		case '%':
			return (a % b);
			break;
		default:
			std::cout << "Error: invalid operation inserted" << std::endl;
			return (-1);
			break;
	}
}