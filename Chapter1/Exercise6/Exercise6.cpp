/*
 * Insertion and Deletion functions for std::list
 *
 * Create a simple list of integers using std::list
 * and explore various ways in which we can insert and
 * delete elements from it.
 */

#include <iostream>
#include <iterator>
#include <list>

void print(std::list<int> list1) {
  for (auto ele : list1)
    std::cout << ele << ", ";
  std::cout << std::endl;
}
int main() {

  std::list<int> list1 = {1, 2, 3, 4, 5};

  list1.push_back(6);

  print(list1);

  list1.insert(std::next(list1.begin()), 0);

  print(list1);

  list1.insert(list1.end(), 7);

  print(list1);

  list1.pop_back();

  print(list1);
  return 0;
}
