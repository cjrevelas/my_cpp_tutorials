#include <iostream>

int primeNumbers(int num);

int main()
{
    std::cout << primeNumbers(20);
    return 0;
}

int primeNumbers(int num){
	int countPrimeNumbers = 0, countNonDivisions;
	for (int ii=2; ii<num+1; ++ii){
           countNonDivisions = 0;
		   for (int jj=2; jj<ii; ++jj){
		       if (ii%jj==0){
                   std::cout << ii << " is not a prime number" << ' ' << '-' << ' ' << std::endl;
                   break;
		       }
               if (ii%jj!=0) ++countNonDivisions;
               if (countNonDivisions == ii-2){
                    ++countPrimeNumbers;
                    std::cout << ii << " is a prime number " << ' ' << countNonDivisions << ' ' << std::endl;
               }
           }
	}

    if (num >= 2){
		 return countPrimeNumbers+1; //account for 1 as well
	}else{
		 return 0;
	}
}
