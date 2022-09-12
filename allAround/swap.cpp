#include <iostream>
#include <string>
#include <memory>

// Forward declaration: namespace declared so that no conflict with std::swap function occurs
namespace cjr {
  template <typename T>
  void swap(T &&a, T &&b);
}

int main() {
  std::string a("string_A");
  std::string b("string_B");

  std::cout << "Before swapping:\n";
  std::cout << "a = " << a << "\n";
  std::cout << "b = " << b << "\n";

  cjr::swap(std::move(a), std::move(b));

  std::cout << "After swapping:\n";
  std::cout << "a = " << a << "\n";
  std::cout << "b = " << b << "\n";

  return 0;
}

template <typename T>
void cjr::swap(T &&a, T &&b) { // Caution: while a and b here are references to r-values, they themselves are l-values
  std::cout << "Called function for r-value referenced arguments - move semantics will be used.\n";
  T temp(std::move(a)); // Invokes move constructor
  a = std::move(b);     // Invokes move assignment
  b = std::move(temp);  // Invokes move assignment
}
