#include <iostream>

class Beta{
private:
    int m_var;

public:
    Beta(int y=5){
        m_var = y;
    }

    void print(){
        if (this->m_var==5){
            std::cout << "Hello from an object of class A." << std::endl;
        }
        else if (this->m_var==10){
            std::cout << "Hello from an object of class B." << std::endl;
        }
    }

    ~Beta(){}
};

class Alpha{
public:

    Alpha(){}

    Beta betaNew;

    ~Alpha(){}

};

int main(){

    Beta beta(10);
    beta.print();

    Alpha alpha;
    alpha.betaNew.print();

    return 0;
}
