#ifndef POINTVEC2_H
#define POINTVEC2_H

#include <iostream>

class Vector3d;  // Forward declaration of class Vector3d, else line 23 will not
                 // know whose class the object to reference.

// Point class
class Point3d {
 private:
  double x_;
  double y_;
  double z_;

 public:
  Point3d(double xx = 0.0, double yy = 0.0, double zz = 0.0)
      : x_(xx), y_(yy), z_(zz) {}

  void Print() const {
    std::cout << "Point(" << x_ << " , " << y_ << " , " << z_ << ")\n";
  }

  Point3d operator+() const; // Make a copy of the point
  Point3d operator-() const; // Create the negative point

  bool operator!() const; // Return true if the point is set at the origin

  double GetX() const { return x_; }
  double GetY() const { return y_; }
  double GetZ() const { return z_; }

  void SetCoords(double xx, double yy, double zz);
  bool IsEqual(const Point3d &point) const;

  void MoveByVector(const Vector3d &vv);  // Forward declaration of the function that will be
                                         // used as friend of class Vector3d
};

// Vector class
class Vector3d {
 private:
  double x_;
  double y_;
  double z_;

 public:
  Vector3d(double xx = 0.0, double yy = 0.0, double zz = 0.0)
   : x_(xx), y_(yy), z_(zz) {}

  void Print() const {
    std::cout << "Vector(" << x_ << " , " << y_ << " , " << z_ << ")\n";
  }

  friend void Point3d::MoveByVector(const Vector3d &vv);
};

// Now we can define Point3d::MoveByVector, which needs to have seen the full
// declaration of class Vector3d
void Point3d::MoveByVector(const Vector3d &vv) {
  x_ += vv.x_;
  y_ += vv.y_;
  z_ += vv.z_;
}

// Member function definitions
Point3d Point3d::operator-() const {
  return Point3d(-x_, -y_, -z_);
}

Point3d Point3d::operator+() const {
  return Point3d(+x_, +y_, +z_);
}

bool Point3d::operator!() const {
  return (x_ == 0.0 && y_ == 0.0 && z_ == 0.0);
}

void Point3d::SetCoords(double xx, double yy, double zz) {
  x_ = xx;
  y_ = yy;
  z_ = zz;
}

bool Point3d::IsEqual(const Point3d &point) const {
  if (x_ == point.x_ && y_ == point.y_ && z_ == point.z_) {
    return true;
  } else {
    return false;
  }
}

#endif // POINTVEC2_H
