#ifndef POINTVEC1_H
#define POINTVEC1_H

#include <iostream>

class Vector3d {
 private:
  double x_;
  double y_;
  double z_;

  friend class Point3d;

 public:
  Vector3d(double xx = 0.0, double yy = 0.0, double zz = 0.0)
   : x_(xx), y_(yy), z_(zz) {}

  void Print() const {
    std::cout << "Vector(" << x_ << " , " << y_ << " , " << z_ << ")\n";
  }
};

class Point3d {
 private:
  double x_;
  double y_;
  double z_;


 public:
  Point3d(double xx = 0.0, double yy = 0.0, double zz = 0.0)
   : x_(xx), y_(yy), z_(zz) {}

  void Print() const;

  Point3d operator+() const; // Make a copy of the point
  Point3d operator-() const; // Create the negative point

  bool operator!() const; // Return true if the point is set at the origin

  double GetX() const { return x_; }
  double GetY() const { return y_; }
  double GetZ() const { return z_; }

  void SetCoords(double xx, double yy, double zz);
  bool IsEqual(const Point3d &point) const;
  void MoveByVector(const Vector3d &vv);
};

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

void Point3d::Print() const {
    std::cout << "Point(" << x_ << " , " << y_<< " , " << z_ << ")\n";
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

void Point3d::MoveByVector(const Vector3d &vv) {
  x_ += vv.x_;
  y_ += vv.y_;
  z_ += vv.z_;
}

#endif
