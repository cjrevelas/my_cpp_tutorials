#include <iostream>

template <int n>
class metaClass{
 public:
  enum {
      val = 2*metaClass<n-1>::val
  };
};

template<>
class metaClass<0>{ // Base case of recursion template call
 public:
  enum{
      val = 1
  };
};

int main(){
  std::cout << metaClass<8>::val << '\n';
}
