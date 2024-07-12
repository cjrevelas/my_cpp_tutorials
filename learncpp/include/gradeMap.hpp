#ifndef GRADEMAP_H
#define GRADEMAP_H

#include <vector>
#include <string>

struct Student {
  std::string name_;
  char grade_;
};

class GradeMap {
 private:
  std::vector<Student> map_;

 public:
  GradeMap() {}

  char &operator[](const std::string &studentName);  // Overload the subscript operator
};

char &GradeMap::operator[](const std::string &studentName) {
  // Check if the name already exists in the vector
  for (unsigned int ii = 0; ii < map_.size(); ++ii) { // or else a signed/unsigned mismatch compiler warning will occur from the operator <
    if (studentName == map_[ii].name_) return map_[ii].grade_;
  }

  // If it does not exist, add a new Student
  Student temp = {studentName, ' '};

  // Add this Student to the vector
  map_.push_back(temp);

  // Return the grade component of the added (last) element
  return map_.back().grade_;
}

#endif // GRADEMAP_H
