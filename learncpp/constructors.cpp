#include <iostream>
#include <string>

class Ball {
 private:
  std::string color_;
  double radius_;

 public:
  // Constructor #1
  Ball(const std::string &color = "black", double radius = 10.0) {
    color_  = color;
    radius_ = radius;
  }

  // Constructor #2
  // The default values must lie in the right-most possible place in the constructor parameters
  Ball(double radius) {
    color_  = "black";
    radius_ = radius;
  }

  // Printing function
  void Print() {
    std::cout << "color: " << color_ << ", radius: " << radius_ << "\n";
  }
};

int main() {
  Ball def;
  def.Print();

  Ball blue("blue");
  blue.Print();

  Ball twenty(20.0);  // The default values must lie in the right-most possible place in the constructor parameters
  twenty.Print();

  Ball blueTwenty("blue", 20.0);
  blueTwenty.Print();

  return 0;
}
