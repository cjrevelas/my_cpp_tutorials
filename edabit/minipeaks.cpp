#include <iostream>
#include <vector>

std::vector<int> miniPeaks(std::vector<int>& arr);

int main()
{
    std::vector<int> arr{4, 5, 2, 1, 4, 9, 7, 2};
    miniPeaks(arr);
    return 0;
}

std::vector<int> miniPeaks(std::vector<int>& arr){
	  std::vector<int> ansVec;
	  int ss = arr.size();

	  for (int ii=1; ii<ss-1; ++ii){
            //std::cout << arr[ii-1] << ' ' << arr[ii+1] << ' ' << ((arr[ii]>arr[ii-1]) && (arr[ii]>arr[ii+1])) << std::endl;
            if ((arr[ii]>arr[ii-1]) && (arr[ii]>arr[ii+1])){
                //std::cout << ii << ' ' << arr[ii] << std::endl;
                ansVec.push_back(arr[ii]);
            }
      }

      int ssVec = ansVec.size();
      std::cout << '[';
      for (int ii : ansVec){
      //for (int ii=0; ii<ssVec; ++ii){
          std::cout << ansVec[ii] << ' ';
      }
      std::cout << ']' << std::endl;

	  return ansVec;
}
