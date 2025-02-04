#include <iostream>
#include <memory>
#include <thread>

void process1(std::shared_ptr<int> sharedptrp1) { *sharedptrp1 = 20; }

void process2(std::shared_ptr<int> sharedptrp2) {
  while (*sharedptrp2 == 10) {
    std::cout << "not yet" << std::endl;
  }
  std::cout << "shared_ptr value is chaged : " << *sharedptrp2 << std::endl;
}

int main() {
  std::shared_ptr<int> sharedptr(new int{10});

  std::thread t1(process1, sharedptr);
  std::thread t2(process2, sharedptr);

  t1.join();
  t2.join();
}
