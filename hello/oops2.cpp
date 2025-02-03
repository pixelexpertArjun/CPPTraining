
#include <iostream>
#include <vector>
#include <array>
//#include <iterator>
//#include <algorithm>

int main (){
    std::array<int,5> array = {1,2,3,4,5};
    std::vector<int> vec = {6,7,8,9,10};

    for (auto &element:vec) {
        std::cout << "element: " << element << std::endl;
    }

    for (auto &elementarray:array) {
        std::cout << "Array element: " << elementarray << std::endl;

    }
    std::cout << "4th element of array: " << array[4] << std::endl;

    //vec.push_back(10);

    for (auto &element:vec) {
        std::cout << "After push back element: " << element << std::endl;
    }

    return 0;
}