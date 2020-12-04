#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

  // Declares vector of size 0;
  std::vector<int> vec;

  // Declares vector of size 5 with provided elements
  std::vector<int> vec2 = {1, 2, 3, 4, 5};

  // Vector of size 10
  std::vector<int> vec3(10);

  // Vector of size 10 with each element's value = 5
  std::vector<int> vec4(10, 5);

  vec2.push_back(7);

  // insert iterator
  vec2.insert(vec2.begin(), 0);

  vec2.push_back(19);

  // Add to potition 2
  vec2.insert(std::find(vec2.begin(), vec2.end(), 2), 99);

  // emplace_back for better performance
  vec2.emplace_back(1111);
  vec2.emplace(std::find(vec2.begin(), vec2.end(), 1), 555);
  vec2.emplace(vec2.begin(), 88);

  std::cout << "Vector: ";
  for (auto ele : vec2) {
    std::cout << ele << ", ";
  }

  std::cout << std::endl;

  std::cout << "Size: " << vec2.size() << std::endl;

  // pop_back and erase
  vec2.pop_back();

  std::cout << "Vector: ";
  for (auto ele : vec2) {
    std::cout << ele << ", ";
  }

  std::cout << std::endl;
  std::cout << "Size: " << vec2.size() << std::endl;

  vec.clear();
  std::cout << "Vector: ";
  for (auto ele : vec2) {
    std::cout << ele << ", ";
  }

  return 0;
}
