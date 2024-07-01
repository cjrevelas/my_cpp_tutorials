#include <iostream>

class Fraction {
 private:
  int numerator_{0};
  int denominator_{1};

 public:
  Fraction(int numerator = 0, int denominator = 1)
   : numerator_{numerator}, denominator_{denominator} {}

  friend std::ostream &operator<<(std::ostream &out, const Fraction &f1) {
    out << f1.numerator_ << '/' << f1.denominator_;
    return out;
  }
};

void printFraction(const Fraction *const ptr) {
  if (ptr) std::cout << *ptr << '\n';
}

int main() {
  Fraction *ptr{new Fraction{3, 5}};

  printFraction(ptr);

  delete ptr;

  return 0;
}
