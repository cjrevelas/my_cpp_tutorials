#include <iostream>
#include <cstdlib>
#include "include/myConstants.h"

float readTowerHeight();
void  printBallHeight(float towerHeight, int i);

int main(){

    float towerHeight;

    std::cout << "Initial velocity is assumed to be equal to zero." << std::endl;

    towerHeight = readTowerHeight();

    for (int i=0; i<6; ++i){
        printBallHeight(towerHeight, i);
    }

    return 0;
}

float readTowerHeight(){

    float h;
    std::cout << "Give the tower height in meters:" << std::endl;
    std::cin >> h;

    return h;
}

void printBallHeight(float towerHeight, int i){

    float ballHeight;

    ballHeight = towerHeight - constants::g * float(i)*float(i)/2.;

    if (ballHeight > 0.)
        std::cout << "At " << i << " seconds, " << "the ball is at height: " << ballHeight << " meters." << std::endl;
    else
        std::cout << "At " << i << " seconds, " << "the ball is on the ground." << std::endl;
}
