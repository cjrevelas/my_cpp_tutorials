#include <iostream>
#include <vector>

int letterCounter(std::vector<std::vector<char>> arr, char c);

int main(){
    std::vector<std::vector<char>> vec;

    std::vector<char> vec1{'D', 'E', 'Y', 'H', 'A', 'D'};
    std::vector<char> vec2{'C', 'B', 'Z', 'Y', 'J', 'K'};
    std::vector<char> vec3{'D', 'B', 'C', 'A', 'M', 'N'};
    std::vector<char> vec4{'F', 'G', 'G', 'R', 'S', 'R'};
    std::vector<char> vec5{'V', 'X', 'H', 'A', 'S', 'S'};

    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);
    vec.push_back(vec5);

    std::cout << letterCounter(vec, 'D') << std::endl;

    return 0;
}

int letterCounter(std::vector<std::vector<char>> vec, char c){
    int count = 0;

    for (auto cc_vector : vec){
        for (auto cc : cc_vector){
            if (cc == c){
                ++count;
            }
        }
    }

    return count;
}
