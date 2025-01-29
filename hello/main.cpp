#include <iostream>

using namespace std;

class shape {
public:
  virtual float calcarea() = 0;
};

class circle : public shape {
private:
  float radius;
  float area;

public:
  circle(int radius) : radius(radius) { area = calcarea(); }

  float calcarea() override {
    area = 3.14 * radius * radius;
    cout << "Area of circle = " << area << endl;
    return area;
  }
  // void print_value(void) { std::cout << "value of circle" << shape_value; }
};

class square : public shape {
private:
  int length;
  float area;

public:
  square(int length) : length(length) { area = calcarea(); }

  float calcarea() override {
    area = length * length;
    cout << "Area of square = " << area << endl;
    return area;
  }
};

class Totalarea {
private:
  float totalarea;

public:
  Totalarea(float area) : totalarea(area) {}

  Totalarea operator+(shape &s) {
    totalarea += s.calcarea();
    return totalarea;
  }

  void print() { cout << "total area = " << totalarea << endl; }
};

int main() {
  std::cout << "Hello from main file \n";

  circle a1(9);

  square a2(9);

  Totalarea total(0);

  total = total + a1;
  total = total + a2;

  total.print();
}
