#include <iostream>

int main()
{
	const int length = 5;
	int array[length] = {30, 60, 20, 50, 40};

	for (int i = 0; i < length-1; ++i)
	{
		for (int j = i+1; j < length; ++j)
		{
			if (array[i] < array[j])  //if you change here to ">" it prints in ascending order (instead of descending)
			{
				int temp;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

	}

	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << " " ;
	}

	return 0;
}