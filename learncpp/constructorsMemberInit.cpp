#include <cstdint>
#include <iostream>

class RGBA {
 private:
  std::uint8_t red_;
  std::uint8_t green_;
  std::uint8_t blue_;
  std::uint8_t alpha_;

 public:
  RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255)
   : red_(red), green_(green), blue_(blue), alpha_(alpha) {}

  void Print() const {
    std::cout << " r = " << static_cast<int>(red_)
              << " g = "  << static_cast<int>(green_)
              << " b = "  << static_cast<int>(blue_)
              << " a = "  << static_cast<int>(alpha_) << '\n';
  }
};

int main() {
  RGBA teal(0, 127, 127);
  teal.Print();

  return 0;
}
