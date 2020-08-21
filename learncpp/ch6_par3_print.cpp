#include <iostream>

int main()
{
	//check user input
	bool boolVar = true;
	int number;

	while (boolVar)
	{
		std::cout << "Please given an integer number from 1 to 9." << std::endl;
		//int number must not be declared here because it will go out of scope before the program ends.
		std::cin >> number;

		if (number >= 1 && number <=9)
		{
			boolVar = false;
		}

		std::cin.ignore(32767, '\n');
	}

	//initialize and print the array
	int array[] = {4, 6, 7, 3, 8, 2, 1, 9, 5};

	int arrayLength = sizeof(array)/sizeof(array[0]);

	for (int i=0; i<arrayLength; ++i)
	{
		std::cout << array[i] << " ";
	}

	std::cout << '\n';

	//return number index to the user
	int index;

	for (int i=0; i<arrayLength; ++i)
	{
		if (array[i]==number)
		{
			index = i;
			break;
		}
	}
	
	std::cout << "The index of the number you entered is: " << index << std::endl;

	return 0;
}
