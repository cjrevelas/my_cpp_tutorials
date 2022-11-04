#include <iostream>
#include <memory>

class Parent {
  public:
    Parent() {
      std::cout << "Constructing the Parent class\n";
    }

    virtual void PrintMessage() {
      std::cout << "Printing from Parent class\n";
    }

    ~Parent() {}
};


class Child : public Parent {
  public:
    Child() {
      std::cout << "Constructing the Child class\n";
    }

    void PrintMessage() override {
      std::cout << "Printing from Child class\n";
    }

    ~Child() {}
};

int main() {
  Parent *parent1 = new Parent();
  Parent *parent2 = new Child();

  std::unique_ptr<Parent> parent3{std::make_unique<Child>()};

  parent1->PrintMessage();
  parent2->PrintMessage();
  parent3->PrintMessage();

  return 0;
}
