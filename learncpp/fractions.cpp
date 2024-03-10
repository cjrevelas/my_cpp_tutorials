#include <iostream>

class Fraction {
 private:
  int m_num;
  int m_denom;

 public:
  Fraction(int numerator = 0, int denominator = 1) {
    m_num = numerator;
    m_denom = denominator;
  }

  void printNotReduced() { std::cout << m_num << "/" << m_denom << std::endl; }

  void print() {
    std::cout << reduce(m_num) << "/" << reduce(m_denom) << std::endl;
  }

  friend Fraction operator*(const Fraction &f1, const Fraction &f2);
  friend Fraction operator*(int x, const Fraction &f);
  friend Fraction operator*(const Fraction &f, int x);

  int gcd(int a, int b) { return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b); }

  int reduce(int a) { return (a / gcd(m_num, m_denom)); }
};

Fraction operator*(const Fraction &f1, const Fraction &f2) {
  return Fraction(f1.m_num * f2.m_num, f1.m_denom * f2.m_denom);
}

Fraction operator*(int x, const Fraction &f) {
  return Fraction(x * f.m_num, f.m_denom);
}

Fraction operator*(const Fraction &f, int x) {
  return Fraction(x * f.m_num, f.m_denom);
}

int main() {
  // print the non-reduced form of the fractions
  Fraction f1(2, 5);
  f1.printNotReduced();

  Fraction f2(3, 8);
  f2.printNotReduced();

  Fraction f3 = f1 * f2;
  f3.printNotReduced();

  Fraction f4 = f1 * 2;
  f4.printNotReduced();

  Fraction f5 = 2 * f2;
  f5.printNotReduced();

  Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
  f6.printNotReduced();

  std::cout << "\n";

  // print the reduced form of the same fractions
  // Fraction f1(2, 5);
  f1.print();

  // Fraction f2(3, 8);
  f2.print();

  // Fraction f3 = f1 * f2;
  f3.print();

  // Fraction f4 = f1 * 2;
  // f4.print();

  // Fraction f5 = 2 * f2;
  f5.print();

  // Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
  f6.print();

  return 0;
}
