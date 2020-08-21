#include <iostream>
#include "point.h"


int main()
{
	Point point(1.0, 0.0, 0.0);

	if (!point)
		std::cout << "Point is set at the origin." << std::endl;
	else
		std::cout << "Point is not set at the origin." << std::endl;

	std::cout << "(" << +point.getX() << "," << +point.getY() << "," << +point.getZ() << ")" << std::endl;
	std::cout << "(" << -point.getX() << "," << -point.getY() << "," << -point.getZ() << ")" << std::endl;


	return 0;
}