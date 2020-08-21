#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>


int main() {
    int numQueries;
    scanf("%d", &numQueries);

    int action, number;
    std::set<int> ss;
    std::set<int>::iterator itr;

    for (int ii=0; ii<numQueries; ++ii){

        scanf("%d%d", &action, &number);

        if (action == 1) ss.insert(number);
        if (action == 2) ss.erase(number);
        if (action == 3){
            itr = ss.find(number);
            if (!(itr==ss.end())){
                std::cout << "Yes" << std::endl;
            }else{
                std::cout << "No" << std::endl;
            }
        }
    }

    return 0;
}
