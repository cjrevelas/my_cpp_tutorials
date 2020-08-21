#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <vector>

class Matrix{

private:
    int matrix_rows;
    int matrix_cols;

    std::vector<int> value;

public:
    Matrix(int rows = 0, int cols = 0)
        : matrix_rows(rows), matrix_cols(cols){

        value.resize(matrix_rows*matrix_cols);

        std::cout << "a new matrix has been created:\n";

        initZero();
    }


    void initZero(){

        for (int i=0; i<matrix_rows; ++i){
            for (int j=0; j<matrix_cols; ++j){
                value[i*matrix_rows+j] = 0.0;
            }
        }
    }



    void initRandom(){

        for (int i=0; i<matrix_rows; ++i){
            for (int j=0; j<matrix_cols; ++j){
                value[i*matrix_rows+j] = rand() % 100;
            }
        }
    }



    void print(){

        for (int i=0; i<matrix_rows; ++i){
            for (int j=0; j<matrix_cols; ++j){
                std::cout << value[i*matrix_rows+j] << " ";
            }

            std::cout << std::endl;
        }
    }


    Matrix operator+(const Matrix &mm);


    ~Matrix(){}
};


Matrix Matrix::operator+(const Matrix &mm){

    for (int i=0; i < this->matrix_rows; ++i){
        for (int j=0; j < this->matrix_cols; ++j){
            this->value[i * this->matrix_rows + j] += mm.value[i * mm.matrix_rows + j];
        }
    }

    return *this;
}

#endif
