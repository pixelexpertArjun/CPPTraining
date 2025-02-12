#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

std::mutex m1;
std::condition_variable cv;

std::vector<int> v1(10);

int cnd_p1 = 1;
int cnd_p2 = 1;

void process1() {
  std::unique_lock<std::mutex> p1ul(m1);
  for (int i = 0; i < 5; i++) {
    cv.wait(p1ul, [] { return cnd_p1 == 1; });
    std::cout << std::endl << std::endl;
    std::generate(v1.begin(), v1.end(), []() { return std::rand() % 20; });
    std::for_each(v1.begin(), v1.end(),
                  [](int i) { std::cout << i << std::endl; });
    cnd_p2 = 0;
    cnd_p1 = 0;
    cv.notify_one();
  }
}

void process2() {
  std::unique_lock<std::mutex> p2ul(m1);
  for (int i = 0; i < 5; i++) {
    cv.wait(p2ul, [] { return cnd_p2 == 0; });
    cnd_p2 = 1;
    cnd_p1 = 1;
    int sum = accumulate(v1.begin(), v1.end(), 0);
    std::cout << "Sum of the values : " << sum << std::endl;
    cv.notify_one();
  }
}

int main() {
  std::thread t1(process1);
  std::thread t2(process2);

  t1.join();
  t2.join();

  return 0;
}
