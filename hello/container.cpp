#include <array>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
  std::array<int, 10> array_var = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto i : array_var) {
    std::cout << "Array element :" << i << std::endl;
  }
  std::cout << "Seventh element :" << array_var[10] << std::endl;

  /*array_var[11] = {10};*/

  std::vector<int> vect_var = {0, 1, 2, 3, 4};

  vect_var.push_back(5);

  for (auto i : vect_var) {
    std::cout << "vector element :" << i << std::endl;
  }

  std::set<int> set_var = {0, 1, 0, 1, 4, 8, 5, 3};
  set_var.insert(10);

  for (auto i : set_var) {
    std::cout << "Set element :" << i << std::endl;
  }

  std::map<int, char> map_var = {{1, 'p'}, {2, 'i'}};
  map_var.insert({3, 'x'});
  auto element = map_var.find(3);

  if (element != map_var.end()) {
    std::cout << "element :" << element->first << " " << element->second
              << std::endl;
  }

  for (auto i : map_var) {
    std::cout << "Map element :" << i.first << " " << i.second << std::endl;
  }

  return 0;
}
