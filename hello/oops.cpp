#include <iostream>
#include <memory>
#include <algorithm>

template <typename T>
class seat {
public:
  int num_of_seat;
  //seat() { std::cout << "seat created" << std::endl; }
  seat (T value) {
    std::cout << "seat count: " << value << std::endl;
    //std::cout << "seat count of value 2 : " << value2 << std::endl;
    }
};

template <typename T> T sumoftwonumbers(T a, T b) {
  return a + b;
}

int main() {
  int *ptr = new int{5};
  int car[5] = {99,65,21,3,78};
  float car2[5] = {1.1,2.2,3.3,4.4,5.5};

  std::sort(car, car+5,[](int x,int y) { return y < x; });

  for (auto &carelement:car) {
    std::cout << "element: " << carelement << std::endl;
  }

  std::shared_ptr<int> ptr1(new int{5});
  std::shared_ptr<int> ptr2 = ptr1;

  std::cout << "ptr value: " << ptr << std::endl;
  std::cout << "ptr1 value: " << ptr1 << std::endl;

  delete ptr;
  *ptr1 = 0;

  std::cout << "sum of two numbers = " << sumoftwonumbers(5, 6) << std::endl;
  std::cout << "sum of two numbers = " << sumoftwonumbers(std::string("Hellow"), std::string("world")) << std::endl;

  //seat<int> car(6);

  return 0;
}
