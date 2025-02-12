#include <cstdlib>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

void process1(std::promise<int> *pr) {

  for (int i = 0; i < 10; i++) {
  }
}

void process2(std::future<int> *ft) {}

int main() {

  std::promise<int> pr;
  std::future<int> ft = pr.get_future();

  std::vector<int> v1;

  std::thread t1(process1, &pr);
  std::thread t2(process2, &ft);

  t1.join();
  t2.join();

  return 0;
}
