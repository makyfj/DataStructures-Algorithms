#include <iostream>
#include <vector>

int main() {

  std::vector<int> vec1 = {1, 2, 3, 4, 5};

  std::vector<std::vector<int>> vec2 = {{1, 1, 1, 1, 1}, {3, 2, 4}, {5, 5, 5}};

  for (long unsigned int i = 0; i < vec2.size(); i++) {
    for (long unsigned int j = 0; j < vec2[i].size(); j++) {
      std::cout << vec2[i][j] << ", ";
    }

    std::cout << std::endl;
  }

  return 0;
}
