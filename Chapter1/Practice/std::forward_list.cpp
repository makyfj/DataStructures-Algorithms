#include <forward_list>
#include <iostream>

int main() {

  std::forward_list<int> fwd_list = {1, 2, 3};

  fwd_list.push_front(0);

  auto it = fwd_list.begin();

  // Retrieve the first item
  std::cout << *(it) << std::endl;

  fwd_list.insert_after(it, 4);

  fwd_list.insert_after(it, 6);

  // emplace_after and emplace_front better for perfomance
  fwd_list.emplace_after(it, 10);

  fwd_list.emplace_front(100);

  std::cout << "Forward_List: ";
  for (auto ele : fwd_list) {
    std::cout << ele << ", ";
  }

  std::cout << std::endl;

  // Removing elements from a forward_list

  // pop first element
  fwd_list.pop_front();

  auto it2 = fwd_list.begin();

  // erase element after first element
  fwd_list.erase_after(it2);

  // erase every element except first one
  fwd_list.erase_after(it2, fwd_list.end());

  std::cout << "Forward_List: ";
  for (auto ele : fwd_list) {
    std::cout << ele << ", ";
  }

  return 0;
}
