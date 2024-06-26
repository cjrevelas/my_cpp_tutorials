#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
   int hIndex(std::vector<int> &citations) {
     std::sort(citations.begin(), citations.end());
     std::reverse(citations.begin(), citations.end());

     int hIndex = 0;

     for (int ii=0; ii<citations.size(); ++ii) {
       if (citations[ii]>=ii+1) {
         hIndex += 1;
       }
     }

     return hIndex;
   }
};

int main() {

  Solution solution;

  std::vector<int> citations{3, 0, 6, 1, 5};

  int hIndex = solution.hIndex(citations);

  std::cout << hIndex << '\n';

  return 0;
}
