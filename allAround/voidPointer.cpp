#include <iostream>

int getValue(void* a) {
	int* temp = *(static_cast<int**>(a));
	
	return *temp;
}

int main() {
	int x = 2;
	void* pointer1 = &x;
	void* pointer2 = &pointer1;

	std::cout << x << ' ' << pointer1 << ' ' << pointer2 << std::endl;
	std::cout << *static_cast<int*>(pointer1) << ' ' << **static_cast<int**>(pointer2) << std::endl;;

	int y = getValue(pointer2);

	std::cout << y << ' ' << &y << std::endl;
	std::cin.get();
	
	return 0;
}