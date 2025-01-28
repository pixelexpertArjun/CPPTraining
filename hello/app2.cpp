#include <iostream>

class shape {
public:
  int shape_value;

  shape() { shape_value = 50; }
};

class circle : public shape {
private:
  int circle_value;

public:
  circle(int a);

  circle() { circle_value = shape_value; }

  void print_value(void) { std::cout << "value of circle" << shape_value; }
};

int main() {
  std::cout << "Hello from app2";

  circle print;
  print.print_value();
}
