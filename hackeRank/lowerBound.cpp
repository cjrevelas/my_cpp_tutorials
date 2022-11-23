#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int num_integers;
    std::cin >> num_integers;

    std::vector<int> integers;
    int temp;
    for (int ii=0; ii<num_integers; ++ii){
        std::cin >> temp;
        integers.push_back(temp);
    } 

    int numQueries;
    std::cin >> numQueries;

    int number;
    for (int ii=0; ii<numQueries; ++ii){
        std::cin >> number;

        if (std::binary_search(integers.begin(), integers.end(), number)){
            std::cout << "Yes ";
            std::cout << std::lower_bound(integers.begin(), integers.end(), number) - integers.begin() + 1;
        }else{
            std::cout << "No ";
            std::cout << std::lower_bound(integers.begin(), integers.end(), number) - integers.begin()+ 1;
        }

        std::cout << std::endl;
    }
    return 0;
}
