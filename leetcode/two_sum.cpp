#include <iostream>
#include <vector>
#include <map>

class Solution {
 public:
   std::vector<int> twoSum(std::vector<int> &nums, int target) {
     std::map<int, int> myMap;

     myMap = {};

     std::vector<int> res;

     for (int ii=0; ii<nums.size(); ++ii) {
       int required = target - nums[ii];

       if (myMap.find(required)!=myMap.end()) {
         res.push_back(myMap[required]);
         res.push_back(ii);
       } else {
         myMap[nums[ii]] = ii;
       }
     }
   
     return res;
   }
};

int main() {

  Solution solution;

  std::vector<int> nums{2,7,11,15};

  int target = 9;

  std::vector<int> ans = solution.twoSum(nums, target);

  for (const int &num : ans) {
    std::cout << num << ' ';
  }

  std::cout << '\n';

  return 0;
}
