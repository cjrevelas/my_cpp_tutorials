#include <iostream>

template <typename T1, typename T2>
class Pair2 {
 private:
  T1 value1_;
  T2 value2_;

 public:
  Pair2(const T1 &value1, const T2 &value2)
      : value1_(value1), value2_(value2) {}

  const T1 &first() const { return value1_; }

  const T2 &second() const { return value2_; }
};

int main() {
  Pair2<int, double> p1(5, 6.7);
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair2<double, int> p2(2.3, 4);
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  return 0;
}
