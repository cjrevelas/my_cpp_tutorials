#include <iostream>

template <typename T>
class Pair1 {
 private:
  T value1_;
  T value2_;

 public:
  Pair1(const T &value1, const T &value2)
      : value1_(value1), value2_(value2) {}

  const T &first() const { return value1_; }

  const T &second() const { return value2_; }
};

int main() {
  Pair1<int> p1(5, 8);
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair1<double> p2(2.3, 4.5);
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  return 0;
}
