#include <iostream>
#include <string>

double printYearsPerLetter(int years, std::string &name);

int main()
{
	int years;
	std::cout << "Please enter your age:\n";
    std::cin  >> years;

	//In the example solution proposed, the following line is not needed because "name" is read after "age".
	std::cin.ignore(32767, '\n');

	std::string name;
	std::cout << "Please enter your name:\n";
	std::getline(std::cin, name);

	std::cout << "You have lived " << printYearsPerLetter(years, name) << " years for each letter in your name " << std::endl;
	return 0;
}

double printYearsPerLetter(int years, std::string &name)
{
	return static_cast<double>(years)/(name.length());
}