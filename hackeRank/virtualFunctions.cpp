#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

class Person {
 protected:
  std::string name_;
  int age_;

 public:
  Person(){}

  virtual void GetData(){}
  virtual void PutData(){}

  virtual ~Person(){}
};


class Student : public Person {
 private:
  int id_;
  static int idGen;
  std::vector<int> marks_;

 public:
  Student() {
    id_ = ++idGen;
  }

  virtual void GetData(){
    std::cin >> name_ >> age_;
    int temp;
    for (int ii=0; ii<6; ++ii){
      std::cin >> temp;
      marks_.push_back(temp);
    }
    std::cin.ignore(11000,'\n');
  }

  virtual void PutData(){
    int sum = 0;
    for (int ii = 0; ii<marks_.size(); ++ii){
      sum += marks_[ii];
    }
    std::cout << name_ << ' ' << age_ << ' ' << sum << ' ' << id_ << '\n';
  }

  virtual ~Student(){}
};


class Professor : public Person {
 private:
  int pubs_, id_;
  static int idGen;

 public:
  Professor(){
    id_ = ++idGen;
  }

  virtual void GetData(){
    std::cin >> name_ >> age_ >> pubs_;
    std::cin.ignore(11000,'\n');
  }

  virtual void PutData() {
    std::cout << name_ << ' ' << age_ << ' ' << pubs_ << ' ' << id_ << '\n';
  }

  virtual ~Professor(){}
};

int Professor::idGen = 0;
int Student::idGen   = 0;

int main(){
  int nn, val;
  std::cin >> nn;
  Person *per[nn];

  for (int ii=0; ii<nn; ii++) {

    std::cin >> val;

    if (val == 1) {
      per[ii] = new Professor;
    }
    else {
      per[ii] = new Student;
    }

    per[ii]->GetData();
  }

  for (int ii=0; ii<nn; ii++) {
    per[ii]->PutData();
  }

  return 0;
}
