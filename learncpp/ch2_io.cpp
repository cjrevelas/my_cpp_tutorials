#include <iostream>

int& readInteger()
{
    int a;
    std::cout << "Enter an integer value " << std::endl;
    std::cin >> a;

    return(a);
}

void writeAnswer(int& answer)
{
    std::cout << "The sum is " << answer << std::endl;

    return;
}