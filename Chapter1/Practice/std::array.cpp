#include <array>
#include <cstddef>
#include <iostream>

void print(std::array<int, 5> arr);

int main() {

  std::array<int, 10> arr1 = {10, 8, 2, 33, 44, 55, 77, 55, 11, 11};

  for (unsigned int i = 0; i < arr1.size(); i++) {
    std::cout << "Element " << i << " : " << arr1[i] << std::endl;
  }

  std::cout << arr1.at(8) << std::endl;

  // Passing an arry by value
  std::array<int, 5> yes = {1, 2, 3, 4, 5};
  std::array<int, 5> newone = {1, 2, 3, 4, 5};

  // New array
  std::array<int, 5> otherarray = {1, 2, 3, 4, 5};

  print(yes);
  print(newone);
  print(otherarray);

  return 0;
}

void print(std::array<int, 5> arr) {
  for (auto ele : arr) {
    std::cout << "Print: " << ele << std::endl;
  }
}
