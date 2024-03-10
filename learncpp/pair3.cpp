#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair3 {
 private:
  T1 value1_;
  T2 value2_;

 public:
  Pair3(const T1 &value1, const T2 &value2)
      : value1_(value1), value2_(value2) {}

  const T1 &first() const { return value1_; }

  const T2 &second() const { return value2_; }
};

template <typename T3>
class StringValuePair : public Pair3<std::string, T3> {
 public:
  StringValuePair(const std::string &string, const T3 &value3)
      : Pair3<std::string, T3>(string, value3) {}
};

int main() {
  StringValuePair<int> svp("Hello", 5);
  std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

  return 0;
}
