#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
  std::ofstream output;

  output.open("Sample.dat");

  output << "this is line 1\n";
  output << "this is line 2\n";

  output.close();

  return 0;
}
