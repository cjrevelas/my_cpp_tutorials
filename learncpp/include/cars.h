#ifndef CARS_H
#define CARS_H

#include <iostream>
#include <string>

class Car {
 private:
  std::string make_;
  std::string model_;

 public:
  Car(std::string make, std::string model)
   : make_(make), model_(model) {}

  friend bool operator==(const Car &c1, const Car &c2);
  friend bool operator!=(const Car &c1, const Car &c2);

  friend bool operator<(const Car &c1, const Car &c2);

  friend std::ostream &operator<<(std::ostream &out, const Car &car);
};

bool operator==(const Car &c1, const Car &c2) {
  return ((c1.make_ == c2.make_) && (c1.model_ == c2.model_));
}

bool operator!=(const Car &c1, const Car &c2) {
  return !(c1==c2);
}

bool operator<(const Car &c1, const Car &c2) {
  if (c1.make_ == c2.make_) {
    return (c1.model_ < c2.model_);
  } else {
    return (c1.make_ < c2.make_);
  }
}

std::ostream &operator<<(std::ostream &out, const Car &c) {
  out << "(" << c.make_ << ", " << c.model_ << ")";
  return out;
}

#endif // CARS_H
