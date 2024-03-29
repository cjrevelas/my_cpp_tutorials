#include <iostream>
#include <sstream>
#include <string>

int main(){
  std::cout << "ex. 1\n";

  // os is an object of the stringstream class which belongs in the std namespace, it functions as an I/O buffer
  std::stringstream os;
  os.str("en garde");            // First way to import data into a buffer
  std::cout << os.str() << '\n'; // First way to extract data from a buffer

  os.str("123456 67.8");
  std::string string_1;
  std::string string_2;

  // Second way of exporting data from a buffer
  os >> string_1;
  os >> string_2;

  std::cout << string_1 << '\n';
  std::cout << os.str() << '\n'; // First one returns all buffer data regardless if some of them have already been extracted
  std::cout << string_2 << '\n';

  std::cout << "ex. 2\n";

  // Converting numbers into strings
  os.str(""); // Erase buffer data
  os.clear(); // Reset error flags

  int intValue = 1234567;
  float floatValue = 67.8;

  os << intValue << ' ' << floatValue;   // Second way to import data into a buffer

  std::string stringValue_1, stringValue_2;

  os >> stringValue_1;
  os >> stringValue_2;

  std::cout << stringValue_1 << ' ' << stringValue_2 << '\n';

  std::cout << "ex. 3\n";

  // Converting numerical strings into buffers
  os.str(""); // Erase buffer data
  os.clear(); // Reset error flags

  os << "1234567 67.8"; // or os.srt(...)

  int intValue2;
  float floatValue2;

  os >> intValue2;
  os >> floatValue2;

  std::cout << intValue2 << ' ' << floatValue2 << '\n';
  return 0;
}
