#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

int main(){
    std::string str("1 2 3 4 5");
    std::vector<std::string> tokens;
    std::vector<int> ints;
    std::string buf;
    std::stringstream ss(str);

    while(ss >> buf)
        tokens.push_back(buf);

    for (int ii=0; ii<tokens.size(); ++ii){
        ints.push_back(atoi(tokens[ii].c_str()));
    }

    std::sort(ints.begin(), ints.end());

    std::cout << ints.back() << " " << ints.front();
    return 0;
}
