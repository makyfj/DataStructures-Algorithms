/*
 * Find the largest three elements in a array
 */

#include <array>
#include <iostream>
#include <vector>

void threeLargest(std::vector<int> arr) {

  std::vector<int> store;

  int large = arr[0];

  for (long unsigned int i = 0; i < arr.size(); i++) {
    if (arr[i] >= large) {
      store.push_back(arr[i]);
      for (long unsigned int j = 0; j < store.size(); j++) {
        if (store[j] < store[j + 1]) {
          store.erase(store.begin() + j, store.begin() + j + 1);
        }
      }
    }
  }

  for (auto ele : store) {
    std::cout << ele << ", ";
  }
}

int main() {
  std::vector<int> numbers = {100, 99, 33, 11, 10, 88, 101, 900, 2, 300, 1};
  threeLargest(numbers);
  return 0;
}
