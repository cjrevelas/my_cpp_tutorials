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

  friend std::istream &operator>>(
      std::istream &in,
      Fraction &fraction);  // if the second argument is declared as const
                            // Fraction, then a runtime stack overflow occurs.
  friend std::ostream &operator<<(
      std::ostream &out,
      Fraction &fraction);  // if we do this the tutorial way, i.e. declaring
                            // the second argument as const Fraction, then a
                            // problem with line 77 occurs.
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

std::istream &operator>>(std::istream &in, Fraction &fraction) {
  char c;

  in >> fraction.m_num;
  in >> c;  // ignore the '/' separator
  in >> fraction.m_denom;

  return in;
}

std::ostream &operator<<(std::ostream &out, Fraction &fraction) {
  out << fraction.reduce(fraction.m_num) << "/"
      << fraction.reduce(fraction.m_denom);

  return out;
}
