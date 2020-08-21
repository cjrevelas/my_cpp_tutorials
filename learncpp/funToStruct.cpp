#include <iostream>

struct Employee
{
	short  id;
	int    age;
	double wage;
};

void printInformation(Employee employee)
{
	std::cout << "ID:" << employee.id << "\n";
	std::cout << "AGE:" << employee.age << "\n";
	std::cout << "WAGE:" << employee.wage << "\n";
}

int main()
{
	Employee joe = {14, 32, 24.15};
	Employee frank = {15, 28, 15.27};

	//print joe's information
	printInformation(joe);

	std::cout << "\n";

	//print frank's information
	printInformation(frank);

	return 0;
}