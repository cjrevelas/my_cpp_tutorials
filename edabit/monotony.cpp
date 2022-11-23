#include <iostream>
#include <vector>


int main(){
    std::vector<int> arr{1234, 986, 582, 7, 6};
    int counter1 = 0;
    int counter2 = 0;

    for (int ii=0; ii<(int) arr.size()-1; ++ii){
        if (arr[ii]<arr[ii+1]){++counter1;}
        if (arr[ii]>arr[ii+1]){++counter2;}
    }

    if (counter1 == arr.size()-1){
        std::cout << "increasing";
    }else if (counter2 == arr.size()-1){
        std::cout << "decreasing";
    }else{
        std::cout << "neither";
    }
    return 0;
}
