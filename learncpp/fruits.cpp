#include <iostream>
#include <string>

class Fruit {
 private:
  std::string name_;
  std::string color_;

 public:
  Fruit(std::string name, std::string color)
   : name_(name), color_(color) {}

  const std::string &GetName() const { return name_; }
  const std::string &GetColor() const { return color_; }
};


class Apple : public Fruit {
 private:
  double fiber_;

 public:
  Apple(std::string name, std::string color, double fiber)
      : Fruit(name, color), fiber_(fiber) {}

  double GetFiber() const { return fiber_; }

  friend std::ostream &operator<<(std::ostream &out, const Apple &apple) {
    out << "Apple (" << apple.GetName() << ", " << apple.GetColor() << ", " << apple.GetFiber() << ")\n";

    return out;
  }
};


class Banana : public Fruit {
 public:
  Banana(std::string name, std::string color) : Fruit(name, color) {}

  friend std::ostream &operator<<(std::ostream &out, const Banana &banana) {
    out << "Banana (" << banana.GetName() << ", " << banana.GetColor() << ")\n";

    return out;
  }
};


int main() {
  const Apple apple("Red delicious", "Red", 4.2);
  std::cout << apple;

  const Banana banana("Cavendish", "Yellow");
  std::cout << banana;

  return 0;
}
