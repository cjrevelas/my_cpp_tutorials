#include <iostream>

int main()
{
	int i=5;
	
	while (i>=1)
	{

		int j = i;
		while (j>=1)
		{
			std::cout << j << " ";
			
			--j;
		}
		
		std::cout << "\n";
		
		--i;
	}
	
	return 0;
}