#include <iostream>

class d1 {
public:
  int a = 20;
  d1() {}
};

class d2 {
public:
  int b = 10;
  d2() {}
};

class b : public d1, public d2 {
public:
  int var_b = 0;

  b() {
    var_b = a + b;
    std::cout << "total" << var_b;
  }
};

int main() {
  b b1;
  b1;
}
