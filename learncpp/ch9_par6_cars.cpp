#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "cars.h"

typedef std::vector<Car> vec;

int main()
{
	vec v;
	v.push_back(Car("Toyota", "Corolla"));
	v.push_back(Car("Honda", "Accord"));
	v.push_back(Car("Toyota", "Camry"));
	v.push_back(Car("Honda", "Civic"));

	std::sort(v.begin(), v.end()); //requires an overloaded operator <

	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << "\n" ; //requires an overloaded operator <<
	}

	return 0;
}