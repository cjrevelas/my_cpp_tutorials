#include <iostream>
#include "vector.h"

int main(){
    //instantiation check
    cjr::vector<int> vec(4);
    std::cout << std::endl;

    vec.print();
    std::cout << "size: " << vec.Size() << ", capacity: " << vec.Capacity() << std::endl;
    std::cout << std::endl;

    //reAllocation check
    vec.reAllocate(6);
    vec.initialize();
    vec.print();
    std::cout << "size: " << vec.Size() << ", capacity: " << vec.Capacity() << std::endl;
    std::cout << std::endl;
    
    //indexing check
    vec[2] = 2;
    vec.print();
    std::cout << "size: " << vec.Size() << ", capacity: " << vec.Capacity() << std::endl;
    std::cout << std::endl;
    
    //push_back check
    vec.push_back(4);
    vec.print();
    std::cout << "size: " << vec.Size() << ", capacity: " << vec.Capacity() << std::endl;
    std::cout << std::endl;

    //clean-up and exit
    vec.deAllocate();
    std::cin.get();
    return 0;
}