#include <iostream>
#include <string>

int main()
{
	std::string names[] = {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

	std::cout << "Enter a name: ";
	std::string name;
	std::cin  >> name;

	for (std::string arrayName : names)
		if (arrayName == name)
			std::cout << name << " was found." << std::endl;
		else
			std::cout << name << " was not found." << std::endl;


	return 0;
}