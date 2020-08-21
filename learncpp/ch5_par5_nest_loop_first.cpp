#include <iostream>

int main()
{
	int i=1;
	
	while (i<=5)
	{
		int j = 1;
		while (j<=i)
		{
			std::cout << j << " ";
			
			++j;
		}
		
		std::cout << "\n";
		++i;
	}
	
	return 0;
}