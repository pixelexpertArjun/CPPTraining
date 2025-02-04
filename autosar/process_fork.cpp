
#include <unistd.h>

#include <iostream>
#include <memory>

int main() {
  pid_t c_pid = fork();
  auto var_shared = std::make_shared<std::string>("No hello from process :/C");

  if (c_pid > 0) {
    std::string parent("Hello from parent process");
    std::cout << "printed from parent process " << getpid() << std::endl
              << c_pid << std::endl;

    var_shared = parent;

    ;
  } else {
    std::cout << "printed from child process " << getpid() << std::endl
              << c_pid << std::endl;
  }

  return 0;
}
