//SLOW
#include <sstream>
#include <vector>
#include <iostream>

std::vector<int> parseInts(std::string str){
    std::vector<int> vv;
    std::stringstream ss(str);
	char ch;

    int countCommas, tempInt;

    for (char ch2 : ss.str()){
        if (ch2 == ',') ++countCommas;
    }

    for (int ii=0; ii<countCommas+1; ++ii){
        ss >> tempInt >> ch;
        vv.push_back(tempInt);
    }

    return vv;
}

int main() {
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for(int ii = 0; ii < integers.size(); ++ii) {
        std::cout << integers[ii] << "\n";
    }

    return 0;
}




#include <sstream>
#include <vector>
#include <iostream>

std::vector<int> parseInts(std::string str){
    std::vector<int> vv;
    std::stringstream ss(str);
	char ch;
    int tempInt;
  
    while (ss >> tempInt){
        vv.push_back(tempInt);
        ss >> ch;
    }
	
	//SLOW
    //do {
    //    ss >> tempInt >> ch;
    //    vv.push_back(tempInt);
    //} while(!ss.str().empty());

    return vv;
}

int main() {
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for(int ii = 0; ii < integers.size(); ++ii) {
        std::cout << integers[ii] << "\n";
    }

    return 0;
}