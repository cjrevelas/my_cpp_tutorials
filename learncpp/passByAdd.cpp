#include <iostream>

void change_x(int *px)         //Function parameter declaration. It is a pointer which receives the address in the argument of change_x.
{
	*px = 6;                   //Derefernce the pointer to retreive the value of x and change it.
}

int main()
{
	int x = 5;
	std::cout << "x = " << x << std::endl;

	change_x(&x);              //The argument of the function is an address.
	std::cout << "x = " << x << std::endl;


	return 0;
}