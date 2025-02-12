#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

void process1(std::promise<std::string> *pr) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  pr->set_value("Hello from process1");
}

void process2(std::future<std::string> *ft) {

  std::cout << "get future of process2 : " << ft->get() << std::endl;
}

void process3(std::future<std::string> *ft2) {
  std::cout << "get future of process3 : " << ft2->get() << std::endl;
}

int main() {
  std::promise<std::string> pr;
  std::future<std::string> ft = pr.get_future();
  std::future<std::string> ft2 = pr.get_future();

  std::thread t1(process1, &pr);
  std::thread t2(process2, &ft);
  std::thread t3(process3, &ft2);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
