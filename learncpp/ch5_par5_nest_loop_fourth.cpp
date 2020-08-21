#include <iostream>

int main()
{
	int i=1;

	while (i<=5)
	{
		int j=5;
		while(j>=1)
		{

			if (j<=i)
			{
				std::cout << j << " ";
			}
			else
			{
				std::cout << "  ";
			}

		

		    --j;
		}

		std::cout << "\n";
        ++i;
	}


	return 0;
}