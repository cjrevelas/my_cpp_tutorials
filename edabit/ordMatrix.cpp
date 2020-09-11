#include <iostream>
#include <vector>

void orderedMatrix(const int& a, const int& b);

int main(){
    int num_rows, num_cols;
    scanf("%d%d", &num_rows, &num_cols);

    orderedMatrix(num_rows, num_cols);
    return 0;
}

void orderedMatrix(const int& a, const int& b){
    std::vector<std::vector<int>> matrix;
    std::vector<int> vec;

    for (int ii=0; ii<a; ++ii){
        for (int jj=0; jj<b; ++jj){
            vec.push_back(b*ii+jj+1);
        }
        matrix.push_back(vec);
        vec.clear();
    }

    for(int ii=0; ii<a; ++ii){
        for (int jj=0; jj<b; ++jj){
            std::cout << matrix[ii][jj] << ' ';
        }
        std::cout << std::endl;
    }
}
