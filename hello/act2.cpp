#include <algorithm>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

std::vector<int> v1(10);
void process1() {
  int sum = accumulate(v1.begin(), v1.end(), 0);
  std::cout << "Sum of the values : " << sum << std::endl;
}

int main() {

  std::generate(v1.begin(), v1.end(), []() { return std::rand() % 20; });
  std::for_each(v1.begin(), v1.end(),
                [](int i) { std::cout << i << std::endl; });

  std::thread t1(process1);
  t1.join();

  std::cout << "Hello from Main thread!" << std::endl;

  return 0;
}
