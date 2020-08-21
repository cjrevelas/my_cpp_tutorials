#include <iostream>
#include "include/matrix.h"

int main(){

    Matrix m1(3,3);
    Matrix m2(3,3);
    Matrix m3(3,3);

    m3.print();

    std::cout << "--------------------------------------------" << std::endl;

    m1.initRandom();
    m1.print();

    std::cout << "--------------------------------------------" << std::endl;

    m2.initRandom();
    m2.print();

    m3 = m1 + m2;

    std::cout << "--------------------------------------------" << std::endl;

    m3.print();

    return 0;
}
