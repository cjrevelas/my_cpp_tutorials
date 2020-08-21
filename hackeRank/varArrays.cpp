#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
    int numLines, numQueries, kk, temp;
    scanf("%d%d", &numLines, &numQueries);

    std::vector<std::vector<int>> vec;

    for (int ii=0; ii<numLines; ++ii){
        vec.resize(ii+1);
        std::cin >> kk;

        for (int jj=0; jj<kk; ++jj){
            std::cin >> temp;
            vec[ii].push_back(temp);
        }
    }

    int lineId, elemId;
    std::vector<int> ansVec;

    for (int ii=0; ii<numQueries; ++ii){
        std::cin >> lineId >> elemId;
        std::cin.ignore('80','\n');
        ansVec.push_back(vec[lineId][elemId]);;
    }

    for (int ii=0; ii<ansVec.size(); ++ii){
        std::cout << ansVec[ii] << ' ';
    }

    return 0;
}
