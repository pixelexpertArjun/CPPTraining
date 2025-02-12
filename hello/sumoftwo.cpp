#include <iostream>
#include <ostream>

class A {
public:
  int num1, num2, sum;
  A();
  A(int a, int b);
  int sumoftwo(int a, int b) { return a + b; };
  A &sumoftwo(A &a);
  ~A();
};

A::A(int a, int b) : num1(a), num2(b) {}

A &A::sumoftwo(A &a) {
  num1 = num1 + a.num1;
  num2 = num2 + a.num2;
  sum = num1 + num2;

  std::cout << "num1 : " << num1 << std::endl;
  std::cout << "num2 : " << num2 << std::endl;
  std::cout << "sum : " << sum << std::endl;

  return *this;
}

A::~A() {}

int main() {

  A obj_a(1, 2);
  std::cout << "Sum of value : " << obj_a.sum << std::endl;
  obj_a = obj_a.sumoftwo(obj_a).sumoftwo(obj_a);

  std::cout << "Sum of value : " << obj_a.sum << std::endl;
  return 0;
}
