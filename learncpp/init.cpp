#include<iostream>

int main(){

    //direct initialization
    int x(6);

    //uniform initialization
    int y{6};

    //copy initialization
    int z = 6;

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

    return 0;
}
