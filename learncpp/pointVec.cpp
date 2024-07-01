#include <iostream>

#include "include/pointVec1.h"
//#include "include/pointVec2.h"

int main() {
  Point3d point1;
  point1.SetCoords(1.0, 2.0, 3.0);
  point1.Print();

  Point3d point2;
  point2.SetCoords(1.0, 2.0, 3.0);
  point2.Print();

  Point3d point3;
  point3.SetCoords(3.0, 4.0, 5.0);
  point3.Print();

  if (point1.IsEqual(point2)) {
    std::cout << "point1 and point2 are equal\n";
  } else {
    std::cout << "point1 and point2 are not equal\n";
  }

  if (point1.IsEqual(point3)) {
    std::cout << "point1 and point3 are equal\n";
  } else {
    std::cout << "point1 and point3 are not equal\n";
  }

  Point3d point4(1.0, 0.0, 0.0);

  if (!point4) {
    std::cout << "Point is set at the origin\n";
  } else {
    std::cout << "Point is not set at the origin\n";
  }

  (+point4).Print();
  (-point4).Print();

  Point3d point5(1.0, 2.0, 3.0);
  Vector3d vec1(2.0, 2.0, -3.0);

  point5.Print();
  vec1.Print();

  point5.MoveByVector(vec1);
  point5.Print();

  return 0;
}
