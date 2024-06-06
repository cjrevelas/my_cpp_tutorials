// This snippet examines if a variable is
// indeed calculated during compile-time

#include<iostream>
#include<type_traits>

constexpr int Multiply(int x, int y) {
  return static_cast<int>(std::is_constant_evaluated());
}

int main () {
  constexpr int x{5};
  constexpr int y{2};

  constexpr int z{Multiply(x,y)};

  std::cout << z << '\n';

  return 0;
}
