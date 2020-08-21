#include <algorithm>
#include <iostream>

int main()
{
	const int length = 9;
	int array[length] = {6, 3, 2, 9, 7, 1, 5, 4, 8};

	for (int i = 0; i < length-1; ++i)
	{
		for (int j = i+1; j < length; ++j)
		{
			if (array[i] > array[j])  //if you change here to ">" it prints in ascending order (instead of descending)
			{
				std::swap(array[i],array[j]);
			}
		}

	}

	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << " " ;
	}

	return 0;
}