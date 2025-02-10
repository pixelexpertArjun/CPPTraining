#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <ostream>
#include <thread>

std::mutex engine_mtx;
std::condition_variable engine_cnd;
int ign = 2; // int ign = 1;
bool cluster_init = false;
bool info_init = false;

void engine_ign() {
  std::cout << "Engine : waiting for ignition..." << std::endl;
  for (int j = 1; j < 6; j++) {
    std::unique_lock<std::mutex> engine_ul(engine_mtx);
    engine_cnd.wait(engine_ul, [] { return ign == 2; });
    std::cout << std::endl
              << std::endl
              << "Engine ignition started : " << j << std::endl;
    ign = 0;
    cluster_init = true;
    info_init = true;
    engine_ul.unlock();
    engine_cnd.notify_all();
  }
}

void cluster() {
  for (int j = 1; j < 6; j++) {
    std::unique_lock<std::mutex> cluster_ul(engine_mtx);
    engine_cnd.wait(cluster_ul, [] { return cluster_init; });
    std::cout << "Cluster turned on... " << j << std::endl;
    ign++;
    cluster_init = false;
    cluster_ul.unlock();
    engine_cnd.notify_all();
  }
}

void infotaiment() {
  for (int j = 1; j < 6; j++) {
    std::unique_lock<std::mutex> info_ul(engine_mtx);
    engine_cnd.wait(info_ul, [] { return info_init; });
    std::cout << "Infotaiment turned on... " << j << std::endl;
    ign++;
    info_init = false;
    info_ul.unlock();
    engine_cnd.notify_all();
  }
}

int main() {
  std::thread t1(engine_ign);
  std::thread t2(cluster);
  std::thread t3(infotaiment);

  t1.join();
  t2.join();
  t3.join();

  std::cout << std::endl << "Loop ended!!" << std::endl;
}
