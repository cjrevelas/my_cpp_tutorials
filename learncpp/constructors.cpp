#include <iostream>
#include <string>

class Ball {
 private:
  std::string color_;
  double radius_;

 public:
  // Constructor 1: default values for private members of class ball
  Ball() {
    color_ = "black";
    radius_ = 10.0;
  }

  // Constructor 2: it is best to be const, because we wish to pass by ref an
  // l-value and not change its value
  Ball(const std::string &color) {
    color_ = color;
    radius_ = 10.0;
  }

  // Constructor 3: we do not to specify the radius here as const, since it is
  // passed by value, therefore it cannot affect the original variable
  Ball(double radius) {
    color_ = "black";
    radius_ = radius;
  }

  // Constructor 4
  Ball(const std::string &color, double radius) {
    color_ = color;
    radius_ = radius;
  }

  void Print() const {
    std::cout << "color: " << color_ << ", radius: " << radius_ << "\n";
  }
};

int main() {
  Ball def;
  def.Print();

  Ball blue("blue");
  blue.Print();

  Ball twenty(20.0);
  twenty.Print();

  Ball blueTwenty("blue", 20.0);
  blueTwenty.Print();

  return 0;
}
