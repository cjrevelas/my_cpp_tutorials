#include <iostream>
#include <deque>
#include <vector>

void printKMax(int arr[], int nn, int kk){
    std::deque<int> deq;

    int maxvalue = 0;
    for (int ii=0; ii<kk; ++ii){
        deq.push_back(arr[ii]);
        if (deq[ii]>maxvalue) maxvalue=deq[ii];
    }

    std::cout << maxvalue << ' ';

    for (int jj=0; jj<nn-kk; ++jj){
        deq.pop_front();
        deq.push_back(arr[jj+kk]);

        maxvalue = 0;
        for (int ii=0; ii<kk; ++ii){
            if (deq[ii]>maxvalue) maxvalue=deq[ii];
        }
        std::cout << maxvalue << ' ';
    }
    std::cout << std::endl;
}

int main(){

    int tt;
    std::cin >> tt;
    while(tt>0) {
        int nn, kk;
        std::cin >> nn >> kk;
        int ii;
        int arr[nn];
        for(ii=0;ii<nn;ii++)
              std::cin >> arr[ii];
        printKMax(arr, nn, kk);
        tt--;
      }
      return 0;
}