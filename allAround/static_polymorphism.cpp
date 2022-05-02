// The following code exhibits a simple implementation
// of static polymorphism (SP).
// Static polymorphism is also refered to as:
// Curiously Recurring Template Pattern (CRTP)

#include <iostream>

template<typename Child>
class Parent {
 public:
  void implementation() {
    std::cout << "Parent implementation\n";
  }

  void interface() {
    static_cast<Child *>(this)->implementation();
  }
};


class Child1 : public Parent<Child1> {
  public:
    void implementation() {
      std::cout << "Child1 implementation\n";
    }
};

class Child2 : public Parent<Child2> {
  public:
    void implementation() {
      std::cout << "Child2 implementation\n";
    }
};

template <typename T>
void execute(T *parent) {
  parent->interface();
}

int main() {
  Parent<Child1> *ptr1 = new Child1();
  Parent<Child2> *ptr2 = new Child2();
  execute(ptr1);
  execute(ptr2);

  return 0;
}
