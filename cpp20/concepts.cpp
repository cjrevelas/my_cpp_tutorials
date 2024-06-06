// Concepts are used to constraint template parameters

#include <iostream>
#include <concepts>


// Concept definition
template<typename T>
concept Float = std::floating_point<T>;

// Concept usage
// 1) -- "Requires" clause --
template<typename T1> requires Float<T1>
class Type1 {
  private:
    T1 x_;
    T1 y_;

  public:
    Type1(T1 x, T1 y): x_(x), y_(y) { std::cout << "Class concept template: \"Requires\" clause\n"; }

    T1 Sum() const { return (x_ + y_); }
};

// 2) -- Restricted template parameter --
template<Float T2>
class Type2 {
  private:
    T2 x_;
    T2 y_;

  public:
    Type2(T2 x, T2 y): x_(x), y_(y) { std::cout << "Class concept template: Restricted template parameter\n"; }

    T2 Sum() const { return (x_ + y_); }
};

// 3) --Abbreviated function template syntax --
Float auto AddNumbers1(Float auto a, Float auto b) {
  std::cout << "Function concept template: Abbreviated function template syntax\n";

  return (a + b);
}

// 4) -- Trailing "Requires" clause --
template<typename T>
T AddNumbers2(T a, T b) requires Float<T> {
  std::cout << "Function concept template: Trailing \"Requires\" clause\n";

  return (a + b);
}

int main() {
  Type1 type1(5.0f, 3.0f); 
  std::cout << type1.Sum() << '\n';

  Type2 type2(5.0f, 5.0f); 
  std::cout << type2.Sum() << '\n';

  std::cout << AddNumbers1(1.0f, 2.0f) << '\n';
  std::cout << AddNumbers2(2.0f, 2.0f) << '\n';

  return 0;
}
