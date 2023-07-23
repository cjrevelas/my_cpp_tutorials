#include <iostream>

class Auto_ptr {
 private:
  int *m_ptr;

 public:
  Auto_ptr(int *ptr) : m_ptr{ptr} {
    //std::cout << "Resource acquired\n";
    //std::cout << m_ptr << '\n';
  }

  ~Auto_ptr() {
    delete[] m_ptr;
    m_ptr = NULL;

    //if (!m_ptr) {
    //  std::cout << "Resource deleted\n";
    //}
  }
};


int main() {
  int num_entries = 5;

  // No memory leak
  while(1){
    Auto_ptr array1(new int[num_entries]); // Memory allocation via a smart pointer
  }

  // Memory leak
  //while(1){
  //  int *array2(new int[num_entries]); // Memory allocation via a dump pointer
  //}

  return 0;
}
