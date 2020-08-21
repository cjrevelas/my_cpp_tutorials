#include <iostream>

void checkPrime(int x);

int main()
{
	std::cout << "Give a single digit number.\n" ;
    int x;
	std::cin >> x;

	checkPrime(x);

	return 0;
}

void checkPrime(int x)
{
	if (x == 2 || x==3 || x==5 || x==7) 
	{
		std::cout << "The number you entered is prime\n";
	}
	else
	{
		std::cout << "The number you entered is not prime\n";
	}
}