/*
 * Find the largest element of a given array
 */

#include <iostream>
#include <vector>

void printLargest(std::vector<int> n) {

  int large = n[0];

  for (long unsigned int i = 0; i < n.size(); i++) {
    if (n[i] >= large) {
      large = n[i];
    }
  }
  std::cout << large;
}

int main() {

  std::vector<int> numbers = {99, 2, 103, 10034, 3, -1};

  printLargest(numbers);

  return 0;
}
