#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

int main() {
    int numQueries;
    scanf("%d", &numQueries);

    int action, points;
    std::string name;
    std::map<std::string,int> mm;
    std::map<std::string,int>::iterator itr;

    for (int ii=0; ii<numQueries; ++ii){
        std::cin >> action >> name;
        itr = mm.find(name);

        if (action==1){
            std::cin >> points;
            if (itr==mm.end()){
                mm.insert(make_pair(name,points));
            }else{
                itr->second += points;
            }

        }

        if (action==2){
            itr->second = 0;
        }

        if (action==3){
			if (itr==mm.end()){
				std::cout << '0' << std::endl;                
            }else{	
                std::cout << itr->second << std::endl;	
            }
        }			
        std::cin.ignore(11000, '\n');
    }
    return 0;
}