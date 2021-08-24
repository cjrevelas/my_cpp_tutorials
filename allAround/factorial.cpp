#include <iostream>

int factorial(int x) {
	if (x > 1) {
		std::cout << x << '\n';
		return x*factorial(x - 1);
	}
	else {
		return 1;
	}
}

int main() {
	int x = 5;
	int y = factorial(x);

	std::cout << "factorial = " << y << '\n';

	std::cin.get();

	return 0;
}