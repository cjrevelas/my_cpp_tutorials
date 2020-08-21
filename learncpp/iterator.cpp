#include <iostream>
#include <vector>
#include <memory>

int main(){

    std::vector<float> vec(3,2.8);

    vec[0] = 0.0;
    vec[2] = 1.0;

    for (std::vector<float>::iterator iter=vec.begin(); iter!=vec.end(); ++iter){
        std::cout << *iter << "\t";
    }

    std::cout << std::endl;

    return 0;
}
