#include <iostream>
#include <string>

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


template <typename T3>
class StringValuePair : public Pair2<std::string, T3>{

public:
    StringValuePair(const std::string& string, const T3& value3)
    :Pair2<std::string, T3>(string, value3){}

};


int main(){

    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
