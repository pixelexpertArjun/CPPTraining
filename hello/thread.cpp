
#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

std::mutex engine_mtx;
std::condition_variable engine_cnd;
int ign = 2; // int ign = 1;
int cluster_init = 0;
int info_init = 0;

void engine_ign() {
  std::cout << "Engine : waiting for ignition..." << std::endl;
  for (int j = 1; j < 11; j++) {
    std::unique_lock<std::mutex> engine_ul(engine_mtx);
    engine_cnd.wait(engine_ul, [] { return ign == 2; });
    std::cout << "Engine ignition started : " << j << std::endl;
    ign = 0;
    cluster_init = 1;
    engine_ul.unlock();
    engine_cnd.notify_all();
  }
}

void cluster() {
  for (int j = 1; j < 11; j++) {
    std::unique_lock<std::mutex> cluster_ul(engine_mtx);
    engine_cnd.wait(cluster_ul, [] { return cluster_init == 1; });
    std::cout << "Cluster turned on... " << j << std::endl;
    info_init = 1;
    cluster_init = 0;
    cluster_ul.unlock();
    engine_cnd.notify_all();
  }
}

void infotaiment() {
  for (int j = 1; j < 11; j++) {
    std::unique_lock<std::mutex> info_ul(engine_mtx);
    engine_cnd.wait(info_ul, [] { return info_init == 1; });
    std::cout << "infotaiment turned on... " << j << std::endl;
    ign = 1;
    info_init = 0;
    info_ul.unlock();
    engine_cnd.notify_all();
  }
}

int main() {
  // ign = 1;
  std::thread t1(engine_ign);
  std::thread t2(cluster);
  std::thread t3(infotaiment);

  t1.join();
  t2.join();
  t3.join();
  std::cout << "Loop ended!!" << std::endl;
}
