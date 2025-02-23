#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

std::vector<int> v1(10);
void process1(std::promise<int> *pr) {
  for (int j = 0; j < 10; j++) {
    std::generate(v1.begin(), v1.end(), []() { return std::rand() % 25; });
    for (int i = 0; i < 10; i++) {
      std::cout << "value of v[" << i << "] : " << v1[i] << std::endl;
    }
    pr->set_value(j);
  }
}

void process2(std::future<int> *ft) {
  for (int i = 0; i < 10; i++) {
    if (ft->get() == i) {
      int sum = std::accumulate(v1.begin(), v1.end(), 0);
      std::cout << "Sum of the vector values : " << sum << std::endl;
    }
  }
}

int main() {
  std::promise<int> pr;
  std::future<int> ft = pr.get_future();
  std::thread t1(process1, &pr);
  std::thread t2(process2, &ft);

  t1.join();
  t2.join();

  return 0;
}
