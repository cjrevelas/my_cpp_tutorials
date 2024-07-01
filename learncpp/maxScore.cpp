#include <iostream>

int main() {
  int scores[] = {84, 92, 76, 81, 56};
  const int numStudents = sizeof(scores) / sizeof(scores[0]);

  int indexMaxScore = 0;

  // now look for a largest score
  for (int student = 1; student < numStudents; ++student) {
    if (scores[student] > scores[indexMaxScore]) {
      indexMaxScore = student;
    }
  }

  std::cout << "The best score was: " << scores[indexMaxScore] << '\n';

  return 0;
}
