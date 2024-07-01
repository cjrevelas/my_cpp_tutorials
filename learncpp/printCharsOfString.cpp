#include <cassert>
#include <iostream>
#include <string>

class Mystring {
 private:
  std::string string_;

 public:
  Mystring(const std::string string) : string_(string) {}

  std::string operator()(int begin, int length);
};

std::string Mystring::operator()(int begin, int length) {
  assert(begin + length <= string_.length() && "Mystring operator()(int,int): Substring is out of range.");

  std::string output;

  for (int count = 0; count < length; ++count) {
    output += string_[begin + count];
  }

  return output;
}

int main() {
  Mystring string("Hello, world!");

  std::cout << string(7, 5) << '\n';  // Start at the 7th character and print 5 characters

  return 0;
}
