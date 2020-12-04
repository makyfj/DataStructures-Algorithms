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

  for (auto ele : vec2) {
    std::cout << ele << std::endl;
  }

  return 0;
}
