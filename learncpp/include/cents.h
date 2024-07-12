#ifndef CENTS_H
#define CENTS_H

class Cents {
 private:
  int cents_;

 public:
  Cents(int cents) { cents_ = cents; }

  friend bool operator>(const Cents &c1, const Cents &c2);
  friend bool operator<(const Cents &c1, const Cents &c2);

  friend bool operator>=(const Cents &c1, const Cents &c2);
  friend bool operator<=(const Cents &c1, const Cents &c2);
};

bool operator>(const Cents &c1, const Cents &c2) {
  return (c1.cents_ > c2.cents_);
}

bool operator>=(const Cents &c1, const Cents &c2) {
  return (c1.cents_ >= c2.cents_);
}

bool operator<(const Cents &c1, const Cents &c2) {
  return !(c1 >= c2);
}

bool operator<=(const Cents &c1, const Cents &c2) {
  return !(c1 > c2);
}

#endif // CENTS_H
