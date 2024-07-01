#include <iostream>

class Fraction {
 private:
  int num_;
  int denom_;

 public:
  Fraction(int numerator = 0, int denominator = 1) {
    num_   = numerator;
    denom_ = denominator;
  }

  void PrintNotReduced() { std::cout << num_ << '/' << denom_ << '\n'; }

  void Print() {
    std::cout << Reduce(num_) << '/' << Reduce(denom_) << '\n';
  }

  friend Fraction operator*(const Fraction &f1, const Fraction &f2);
  friend Fraction operator*(int xx, const Fraction &ff);
  friend Fraction operator*(const Fraction &ff, int xx);

  int Gcd(int aa, int bb) { return (bb == 0) ? (aa > 0 ? aa : -aa) : Gcd(bb, aa % bb); }

  int Reduce(int aa) { return (aa / Gcd(num_, denom_)); }
};

Fraction operator*(const Fraction &f1, const Fraction &f2) {
  return Fraction(f1.num_ * f2.num_, f1.denom_ * f2.denom_);
}

Fraction operator*(int xx, const Fraction &ff) {
  return Fraction(xx * ff.num_, ff.denom_);
}

Fraction operator*(const Fraction &ff, int xx) {
  return Fraction(xx * ff.num_, ff.denom_);
}

int main() {
  // Print the non-reduced form of the fractions
  Fraction f1(2, 5);
  f1.PrintNotReduced();

  Fraction f2(3, 8);
  f2.PrintNotReduced();

  Fraction f3 = f1 * f2;
  f3.PrintNotReduced();

  Fraction f4 = f1 * 2;
  f4.PrintNotReduced();

  Fraction f5 = 2 * f2;
  f5.PrintNotReduced();

  Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
  f6.PrintNotReduced();

  std::cout << '\n';

  // Print the reduced form of the same fractions
  f1.Print();
  f2.Print();
  f3.Print();
  f4.Print();
  f5.Print();
  f6.Print();

  return 0;
}
