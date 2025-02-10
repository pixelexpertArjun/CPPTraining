
#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

std::mutex m1;
std::condition_variable m1cond;
int i = 0;
bool produced = false;
bool consumed = false;

void process1(std::shared_ptr<int> sharedptrp1) {
  for (int j = 0; j < 11; j++) {
    std::unique_lock m1unq(m1);
    m1cond.wait(m1unq, [] { return !produced; });
    i++;
    std::cout << "process 1 : " << i << std::endl;
    produced = true;
    m1unq.unlock();
    m1cond.notify_one();
  }
}

void process2(std::shared_ptr<int> sharedptrp2) {
  for (int j = 0; j < 11; j++) {
    std::unique_lock m1unq(m1);
    m1cond.wait(m1unq, [] { return produced; });
    i--;
    std::cout << "process 2 : " << i << std::endl;
    produced = false;
    m1unq.unlock();
    m1cond.notify_one();
  }
}

int main() {
  std::shared_ptr<int> sharedptr(new int{10});

  std::thread t1(process1, sharedptr);
  std::thread t2(process2, sharedptr);
  // std::thread t3(process3 );

  t1.join();
  t2.join();

  std::cout << "exited!!" << std::endl;
}
