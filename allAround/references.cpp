#include <iostream>
#include <memory>

// Declare Widget class
class Widget {
 public:
  Widget() {
    std::cout << "Widget has been created\n";
  }

  ~Widget() {
    std::cout << "Widget has been destroyed\n";
  }

  Widget getWidget() {
    return *this;
  }

  const Widget getConstWidget() {
    return *this;
  }
};

// Forward declarations of all possible functions
void ff(Widget &);        // L-value reference
void ff(const Widget &);  // L-value reference to const
void ff(Widget &&);       // R-value reference
void ff(const Widget &&); // R-value reference to const

template<typename T>
void ff(T &&); // Funtion template with a forwarding/universal reference

template<typename T>
void ff(const T &&); // Function template with R-value reference to const

template<typename ...Args>
std::unique_ptr<Widget> create(Args &&...args); // Variadic function template with a forwarding/universal reference

int main() {

  Widget ww1{};
  ff(ww1); // try this with L-value reference function commented out

  const Widget ww2{};
  ff(ww2);

  ff(ww1.getWidget());

  ff(ww1.getConstWidget());

  return 0;
}

// Define the bodies of the reference receiving functions
void ff(Widget &) {
  std::cout << "calling function 1: L-value reference\n\n";
}

void ff(const Widget &) {
  std::cout << "calling function 2: L-value reference to const\n\n";
}

void ff(Widget &&) {
  std::cout << "calling function 3: R-value reference\n\n";
}

void ff(const Widget &&) {
  std::cout << "calling function 4: R-value reference to const\n\n";
}

template<typename T>
void ff(T &&) {
  std::cout << "calling function 5: templated function with forwarding reference\n\n";
}

template<typename T>
void ff(const T &&) {
  std::cout << "calling funtion 6: templated function with R-value reference to const\n\n";
}

template<typename ...Args>
std::unique_ptr<Widget> create(Args &&...args) {
  return std::make_unique<Widget>(std::forward<Args>(args)...);
}
