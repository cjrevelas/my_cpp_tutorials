#include <algorithm>
#include <iostream>
#include <string>

void EnterNames(int &length, std::string *names);
void SortNames(int &length, std::string *names);
void PrintNames(int &length, std::string *names);

int main() {
  // Ask user to enter the number of names
  std::cout << "How many names would you like to enter? ";
  int length;
  std::cin >> length;

  std::string *names = new std::string[length];

  // Ask user to enter the names
  EnterNames(length, names);
  std::cout << '\n';

  // Sort array of names
  SortNames(length, names);

  // Print the sorted array of names
  std::cout << "Here is your sorted list of names:" << '\n';
  PrintNames(length, names);

  delete[] names;
  return 0;
}

void EnterNames(int &length, std::string *names) {
  for (int ii = 0; ii < length; ++ii) {
    std::cout << "Enter name #" << ii + 1 << ": ";
    std::cin >> names[ii];
  }
}

void SortNames(int &length, std::string *names) {
  for (int ii = 0; ii < length - 1; ++ii) {
    int smallestIndex = ii;

    for (int jj = ii + 1; jj < length; ++jj) {
      if (names[jj] < names[smallestIndex]) {
        smallestIndex = jj;
      }
    }

    std::swap(names[ii], names[smallestIndex]);
  }
}

void PrintNames(int &length, std::string *names) {
  for (int ii = 0; ii < length; ++ii) {
    std::cout << "Name #" << ii + 1 << ": " << names[ii] << '\n';
  }
}
