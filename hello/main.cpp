#include <iostream>

using namespace std;

class shape {
public:
  int length;
  float area;
  shape() {}
  virtual float calcarea() { return area; }
};

class circle : public shape {
private:
  float area;

public:
  circle(int radius) { calcarea(radius); }

private:
  float calcarea(int radius) {
    area = 3.14 * radius * radius;
    cout << "Area of circle = " << area << endl;
    return area;
  }
  // void print_value(void) { std::cout << "value of circle" << shape_value; }
};

class square : public shape {
private:
  float area;

public:
  square(int length) { calcarea(length); }

private:
  float calcarea(int length) {
    area = length * length;
    cout << "Area of square = " << area << endl;
    return area;
  }
};

class Totalarea : public shape {
private:
  float totalarea;

public:
  Totalarea(float a1, float a2) { totalarea = a1 + a2; }

  Totalarea operator+(shape(a1), shape(a2)) {
    totalarea = a1.calcarea() + a2.calcarea();
  }
};

int main() {
  std::cout << "Hello from main file \n";

  circle a1(9);

  square a2(9);

  Totalarea a1 + a2;
}
