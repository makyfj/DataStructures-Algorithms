#include <forward_list>
#include <iostream>

template <typename T>

void print(std::forward_list<T> list) {
  for (auto ele : list) {
    std::cout << ele << std::endl;
  }
}

int main() {

  std::forward_list<int> list1 = {23, 0, 1, -3, 4, 22};

  list1.sort();

  std::cout << "Low to high"
            << "\n";
  print(list1);

  list1.sort(std::greater<int>());

  std::cout << std::endl;
  std::cout << "High to low"
            << "\n";
  print(list1);

  return 0;
}
