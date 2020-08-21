#include <iostream>
#include <memory>

class Fraction{

private:
    int m_numerator{0};
    int m_denominator{1};

public:
    Fraction(int numerator = 0, int denominator = 1) :
    m_numerator{numerator}, m_denominator{denominator} {}

    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1){
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }
};

void printFraction(std::unique_ptr<Fraction> ptr){
    if (ptr)
        std::cout << *ptr << '\n';
}

int main(){
    //solution 1
    //std::unique_ptr<Fraction> fraction{new Fraction{3,5}};

    //solution 2: recommended
    std::unique_ptr<Fraction> fraction{std::make_unique<Fraction>(3,5)};

    printFraction(std::move(fraction));

    //delete fraction; //undefined begavior if not commented out

    return 0;
}
