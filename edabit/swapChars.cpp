#include <iostream>
#include <string>
#include <utility>

std::string doubleSwap(std::string string, char c1, char c2);

int main() {
  std::cout << doubleSwap("random w#rds writt&n h&r&", '#', '&');

  return 0;
}

std::string doubleSwap(std::string ss, char c1, char c2) {
  for (int ii=0; ii<(int) ss.size(); ++ii) {
    if (ss[ii] == c1) {
      ss[ii] = c2;
    } else if (ss[ii] == c2) {
      ss[ii] = c1;
    }
  }

  return ss;
}
