#include <algorithm> //for std::swap (we are not going to use a temp variable here)
#include <iostream>

int main()
{
	const int length = 5;
	int array[length] = {30, 60, 20, 50, 40};

	for (int i = 0; i < length-1; ++i)
	{
		int largest_index = i;

		for (int j = i+1; j < length; ++j)
		{
			if (array[j] > array[largest_index])
			{
				largest_index = j;  //the inner loop does not swap (like in second_pv.cpp), it just detects the location of the largest value (i.e. largest_index)
			}
		}

		std::swap(array[i],array[largest_index]); //swap once the location of the largest value is detected
	}


    for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << " " ;
	}

	return 0;
}
