#include <iostream>
#include <type_traits>
#include <array>

namespace cjr {
  class MyType {
    private:
      int x_;
      int y_;

    public:
      MyType(int x, int y): x_(x), y_(y) {}
  };
}

int main() {

  auto const ints = {0, 1, 2, 3, 4};
  decltype(ints) ints2;

  std::cout << typeid(ints).name() << '\n';
  std::cout << typeid(ints2).name() << '\n';

  const std::array<int,6> ints3{{1, 2, 3, 4, 5, 6}};

  auto ints4 = ints3;

  std::cout << '\n';
  std::cout << typeid(ints3).name() << '\n';
  std::cout << typeid(ints4).name() << '\n';

  auto type = cjr::MyType(5,3);
  decltype(type) type2 = cjr::MyType(6,9);

  std::cout << '\n';
  std::cout << typeid(type).name() << '\n';
  std::cout << typeid(type2).name() << '\n';

  return 0;
}
