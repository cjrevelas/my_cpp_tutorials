#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "include/cars.h"

typedef std::vector<Car> vec;

int main() {
  vec vv;
  vv.push_back(Car("Toyota", "Corolla"));
  vv.push_back(Car("Honda", "Accord"));
  vv.push_back(Car("Toyota", "Camry"));
  vv.push_back(Car("Honda", "Civic"));

  std::sort(vv.begin(), vv.end()); // Requires an overloaded operator <

  for (int ii = 0; ii < vv.size(); ++ii) {
    std::cout << vv[ii] << '\n';  // Requires an overloaded operator <<
  }

  return 0;
}
