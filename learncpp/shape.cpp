#include <iostream>

class Shape {
 public:
  Shape(){}

  virtual std::ostream &print(std::ostream &out) const = 0;

  friend std::ostream &operator<<(std::ostream &out, const Shape &shape){
    return shape.print(out);
  }

  virtual ~Shape() {}
};
