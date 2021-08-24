#include <iostream>
#include <map>

void print_map(const std::string& message, const std::map<std::string, int>& m) {

	std::cout << message;

	for (const std::pair<std::string, int> p : m) {
		std::cout << p.first << " = " << p.second << "; ";
	}

	//the following for-loop is equivalent (from cppreference.com)
	//for (const auto& [key, value] : m) {     //auto here works without an umbersand as well (!)
	//	std::cout << key << " = " << value << "; ";
	//}

	std::cout << std::endl;

}

int main(){

	std::map<std::string, int> m{ {"CPU",10}, {"GPU",15}, {"RAM",20} };

	print_map("initial map: ", m);

	m["CPU"] = 25;
	m["SSD"] = 30;

	print_map("updated map: ", m);

	std::cin.get();

	return 0;
}

