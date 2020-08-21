#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x;
	std::cin  >> x;

	std::cout << "Enter a larger integer: ";
	int y;
	std::cin  >> y;

	if (y <= x)
	{
		std::cout << "Swapping the values\n";
		int temp = y;
		y = x;
		x = temp;
	}  //temp variable dies here
	
	std::cout << "The smaller value is: " << x << "\n";
	std::cout << "The larger value is: "  << y << "\n";
	return 0;
	
}  // x and y variables die here