//Operator Overloading

#include<iostream>

class Complex {
 public:
  int aa, bb;

  void input(const std::string &ss) {
    int v1 = 0;
    int ii = 0;

    while(ss[ii] != '+') {
      v1 = v1*10 + ss[ii] - '0';
      ii++;
    }

    while(ss[ii]==' ' || ss[ii]=='+' || ss[ii]=='i') {
      ii++;
    }

    int v2=0;

    while(ii<ss.length()) {
      v2 = v2*10 + ss[ii] - '0';
      ii++;
    }

    aa = v1;
    bb = v2;
  }
};

Complex operator+(const Complex &c1, const Complex &c2){
  Complex summ;
  summ.aa = c1.aa + c2.aa;
  summ.bb = c1.bb + c2.bb;

  return summ;
}

std::ostream &operator<<(std::ostream &out, const Complex &comp){
  out << comp.aa << "+i" << comp.bb;

  return out;
}

int main() {
  Complex xx, yy;
  std::string s1, s2;

  std::cin >> s1;
  std::cin >> s2;

  xx.input(s1);
  yy.input(s2);

  Complex zz = xx + yy;

  std::cout << zz << '\n';

  return 0;
}
