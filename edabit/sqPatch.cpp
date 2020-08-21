#include <iostream>
#include <vector>

std::vector<std::vector<int>> squarePatch(int n);

int main()
{
    squarePatch(10);
    return 0;
}

std::vector<std::vector<int>> squarePatch(int n){

    std::vector<std::vector<int>> square;
    std::vector<int> vec;

    for (int i=0; i<n; ++i){
        vec.clear(); //important
        for (int j=0; j<n; ++j){
            vec.push_back(n);
            //std::cout << vec[j] << ' ';
        }
        //std::cout << std::endl;
        //std::cout << vec.size() << std::endl;
        //std::cout << '\n';

        square.push_back(vec);
    }

    for (std::vector<int> vv : square){
        for (int ii : vv){
            std::cout << ii << ' ';
        }
        std::cout << '\n';
    }

    return square;
}
