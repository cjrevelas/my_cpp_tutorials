#include <iostream>

void editArray(int* x);

int main(){

    int* A = new int[5];

    std::cout << "array A at the beginning...\n";

    for(int i=0; i<=4; ++i){
        A[i] = i;
        std::cout << A[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "array A after modification...\n";

    editArray(A);

    for(int i=0; i<=4; ++i){
        std::cout << A[i] << " ";
    }

    std::cout << std::endl;

    delete[] A;
    A = nullptr;

    return 0;
}


void editArray(int* x){

    for(int j=0; j<=4; ++j){
        x[j] = 2*j+1;
    }

    return;
}
