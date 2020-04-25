#include <iostream>
#include <fstream>
#include <cstdlib>

int main(){

    std::ofstream output;

    output.open("Sample.dat");

    output << "this is line 1" << std::endl;
    output << "this is line 2" << std::endl;

    output.close();

    return 0;
}
