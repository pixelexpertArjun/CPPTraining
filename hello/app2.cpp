#include <iostream>

using namespace std;

class shape {
public:
  int area;
  shape() {}
  virtual void calcarea(int area) {}
};

class circle : public shape {
private:
  float area;

public:
  circle(int a);

  circle() {}

  void clacarea(int radius) {
    area = 3.14 * radius * radius;
    cout << "Area of circle = " << area;
  }

  // void print_value(void) { std::cout << "value of circle" << shape_value; }
};

class square : public shape {
private:
  float area;

public:
  square() {}

  void clacarea(int length) {
    area = length * length;
    cout << "Area of square = " << area;
  }
};

int main() {
  std::cout << "Hello from app2";

  circle a1;
  a1.calcarea(9);

  square a2;
  a2.calcarea(9);
}
