#include <iostream>
#include <string>
#include <algorithm>

void enterNamesArray(int &length, std::string *names);  //remember: c++ passes arrays by reference (bu default)
void sortNamesArray(int &length, std::string *names);  
void printNamesArray(int &length, std::string *names);

int main()
{
	//ask user to enter the number of names
	std::cout << "How many names would you like to enter? ";
	int length;
	std::cin >> length;

	std::string *names = new std::string[length];

	//ask user to enter the names
	enterNamesArray(length, names);
	std::cout << std::endl;

	//sort array of names
	sortNamesArray(length, names);

	//print the sorted array of names
	std::cout << "Here is your sorted list:" << std::endl;
	printNamesArray(length, names);

	delete[] names;
	return 0;
}


void enterNamesArray(int &length, std::string *names)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Enter name #" << i+1 << ": ";
		std::cin  >> names[i];
	}
}

void sortNamesArray(int &length, std::string *names)  
{
	for (int i = 0; i < length-1; ++i)
	{
		int smallestIndex = i;

		for (int j = i+1; j < length; ++j)
		{
			if (names[j] < names[smallestIndex])
			{
				smallestIndex = j;
			}
		}

		std::swap(names[i],names[smallestIndex]);
	}
}

void printNamesArray(int &length, std::string *names)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Name #" << i+1 << ": " << names[i] << std::endl;
	}
}



