#include <forward_list>
#include <iostream>

template <typename T>

void print(std::forward_list<T> list) {
  for (auto ele : list) {
    std::cout << ele << ", ";
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

  std::cout << std::endl;

  // Using reverse, sort and unique
  std::forward_list<int> list2 = {2, 53, 1, 0, 4, 10};

  std::cout << "Original list" << std::endl;
  print(list2);

  list2.reverse();

  std::cout << "\nReverse list" << std::endl;
  print(list2);

  list2 = {0, 1, 0, 1, -1, 10, 5, 10, 5, 0};

  list2.sort();

  std::cout << "\nSorting list" << std::endl;
  print(list2);

  list2.unique();

  std::cout << "\nUnique number in the list: " << std::endl;
  print(list2);

  // Another example
  list2 = {0, 1, 0, 1, -1, 10, 5, 10, 5, 0};

  list2.sort();

  std::cout << "\nSorting list" << std::endl;
  print(list2);

  // Remove elements if they are not greater than the
  // previously valid element by at least 2
  list2.unique([](int a, int b) { return (b - a) < 2; });
  std::cout << "\nUnique list" << std::endl;
  print(list2);

  return 0;
}
