#include <iostream>
#include <map>

void print_map(const std::string &message, const std::map<std::string,int> &mm) {
  std::cout << message;

  for (const std::pair<std::string, int> pp : mm) {
    std::cout << pp.first << " = " << pp.second << "; ";
  }

  // The following for-loop is equivalent and uses structured bindings (check cppreference.com)
  //for (const auto &[key, value] : mm) {
  //  std::cout << key << " = " << value << "; ";
  //}

  std::cout << '\n';
}

int main() {
  std::map<std::string, int> map{ {"CPU",10}, {"GPU",15}, {"RAM",20} };

  print_map("initial map: ", map);

  map["CPU"] = 25;
  map["SSD"] = 30;

  print_map("updated map: ", map);

  std::cin.get();

  return 0;
}

