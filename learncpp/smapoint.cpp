#include <iostream>

class Auto_ptr{

private:
    int* m_ptr;

public:
    Auto_ptr(int* ptr) : m_ptr{ptr}{
        //std::cout << "Resource acquired" << std::endl;
        //std::cout << m_ptr << std::endl;
    }


    ~Auto_ptr(){
        delete[] m_ptr;
        m_ptr = NULL;

        //if (!m_ptr) {
        //    std::cout << "Resource deleted" << std::endl;
        //}
    }
};



int main(){

    int num_entries = 5;

    //no memory leak
    while(1){
        Auto_ptr array1(new int[num_entries]); //memory allocation via a smart pointer
    }

    //memory leak
    //while(1){
    //    int* array2(new int[num_entries]); //memory allocation via a dump pointer
    //}

    return 0;
}
