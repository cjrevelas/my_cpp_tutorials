#include <iostream>
#include <string>

class Solution {
 public:
   bool isHappy(int n) {
     int numDigits = 0;
     int temp = 0;
     int maxNumIter = 100;

     int iter = 0;
     bool res = false;

     for (;;) {
       ++iter;
       if (iter == maxNumIter) break;

       temp = n;

       numDigits = std::to_string(temp).size();

       std::string str = std::to_string(temp);

       n = 0;
       for (int ii=0; ii<numDigits; ++ii) {
         n += static_cast<int>(str[ii]-'0') * static_cast<int>(str[ii]-'0');
       }

       std::cout << n << '\n';

       if (n == 1) {
         res = true;
         break;
       }
     }

     return res;
   }
};

int main() {
  Solution solution;

  std::cout << solution.isHappy(2) << '\n';

  return 0;
}
