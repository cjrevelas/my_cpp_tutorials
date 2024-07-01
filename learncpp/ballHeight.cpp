#include <cstdlib>
#include <iostream>

#include "include/myConstants.h"

float ReadTowerHeight();
void PrintBallHeight(float towerHeight, int ii);

int main() {
  float towerHeight;

  std::cout << "Initial velocity is assumed to be equal to zero." << '\n';

  towerHeight = ReadTowerHeight();

  for (int ii = 0; ii < 6; ++ii) {
    PrintBallHeight(towerHeight, ii);
  }

  return 0;
}

float ReadTowerHeight() {
  float height;
  std::cout << "Give the tower height in meters:" << '\n';
  std::cin >> height;

  return height;
}

void PrintBallHeight(float towerHeight, int ii) {
  float ballHeight;

  ballHeight = towerHeight - constants::g * float(ii) * float(ii) / 2.;

  if (ballHeight > 0.) {
    std::cout << "At " << ii << " seconds, "
              << "the ball is at height: " << ballHeight << " meters."
              << '\n';
  } else {
    std::cout << "At " << ii << " seconds, "
              << "the ball is on the ground." << '\n';
  }
}
