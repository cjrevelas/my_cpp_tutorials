#include <iostream>

template <typename T1, typename T2>
class Pair2{
private:
    T1 m_value1;
    T2 m_value2;

public:
    Pair2(const T1& value1, const T2& value2)
    :m_value1(value1), m_value2(value2){}

    const T1& first() const{
        return m_value1;
    }

    const T2& second() const{
        return m_value2;
    }
};


int main(){

    Pair2<int, double> p1(5, 6.7);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair2<double, int> p2(2.3, 4);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
