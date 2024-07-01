#include <iostream>
#include <memory>

class Fraction {
 private:
  int numerator_{0};
  int denominator_{1};

 public:
  Fraction(int numerator = 0, int denominator = 1)
   : numerator_{numerator}, denominator_{denominator} {}

  friend std::ostream &operator<<(std::ostream &out, const Fraction &f1) {
    out << f1.numerator_ << "/" << f1.denominator_;
    return out;
  }
};

void printFraction(std::unique_ptr<Fraction> ptr) {
  if (ptr) std::cout << *ptr << '\n';
}

int main() {
  // Solution 1
  // std::unique_ptr<Fraction> fraction{new Fraction{3,5}};

  // Solution 2: recommended
  std::unique_ptr<Fraction> fraction{std::make_unique<Fraction>(3, 5)};

  printFraction(std::move(fraction));

  // delete fraction; // Undefined begavior if not commented out

  return 0;
}
