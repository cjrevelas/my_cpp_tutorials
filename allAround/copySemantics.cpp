#include <iostream>

template<class T>
class Auto_ptr1 {
 private:
  T *m_ptr;

 public:
  // Pass in a pointer to "own" via the constructor
  Auto_ptr1(T *ptr=nullptr)
   : m_ptr(ptr) {}

  // The destructor will make sure it gets deallocated
  ~Auto_ptr1() {
    delete m_ptr;
  }

  // Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr
  T &operator*()  const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
};

class Resource {
 public:
  Resource()  { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main() {
  Auto_ptr1<Resource> res(new Resource()); // This is like saying: m_ptr = new Resource, thus m_ptr = res owns the allocated Resource object

  // No explicit delete needed, res goes out of scope here, and destroys the allocated Resource for us.
  return 0;
}
