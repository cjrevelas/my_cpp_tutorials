#ifndef ANIMALS_H
#define ANIMALS_H 

#include <string>

class Animal {
 protected:
  std::string name_;
  const char *speak_;

  Animal(std::string name, const char *speak) : name_(name), speak_(speak) {}

 public:
  std::string GetName() { return name_; }
  const char *Speak() { return speak_; }
};

class Cat : public Animal {
 public:
  Cat(std::string name) : Animal(name, "Meow") {}
};

class Dog : public Animal {
 public:
  Dog(std::string name) : Animal(name, "Woof") {}
};

#endif // ANIMALS_H
