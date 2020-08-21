#include <iostream>
#include <cstdlib>

int main(){

   float x, y;
   char op;

   std::cout << "Enter two float numbers:" << std::endl;

   std::cin >> x;
   std::cin >> y;

   std::cout << "Please enter an arithmetic operation:" << std::endl;

   std::cin >> op;

   if (op == '+')
       std::cout << "The sum of " << x << " and " << y << " equals " << x+y << std::endl;

   else if (op == '-')
       std::cout << "The difference of " << x << " and " << y << " equals " << x-y << std::endl;

   else if (op == '*')
       std::cout << "The product of " << x << " and " << y << " equals " << x*y << std::endl;

   else if (op == '/')
           std::cout << "The division of " << x << " and " << y << " equals " << x/y << std::endl;

   else
      std::cout << "Not valid operator...exiting..." << std::endl;

   return 0;
}
