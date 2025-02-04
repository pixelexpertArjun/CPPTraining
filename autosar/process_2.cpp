
#include <unistd.h>

#include <iostream>
using namespace std;

int main() {
  fork();
  cout << "prcess created" << endl;

  return 0;
}
