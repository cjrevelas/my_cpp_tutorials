#include <iostream>

int main()
{	
	int sum=0;
	
	for (int i=1; i<=10; ++i)
	{
		std::cout << "Enter a new integer number or zero to exit." << "\n";
        int x;
	    std::cin >> x;

		if (x==0)
		{
			break;
		}

		sum += x;
	}

	std::cout << "The sum of the numbers you entered is equal to: " << sum << "\n";

	return 0;
}