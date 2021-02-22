#include <iostream>
#include <string>
#include <utility>

std::string doubleSwap(std::string string, char c1, char c2);

int main(){
    std::cout << doubleSwap("random w#rds writt&n h&r&", '#', '&');
    return 0;
}

std::string doubleSwap(std::string s, char c1, char c2){
    for (int ii=0; ii<(int) s.size(); ++ii){
        if (s[ii] == c1){
            s[ii] = c2;
        }else if (s[ii] == c2){
            s[ii] = c1;
        }
    }
    return s;
}
