#include <forward_list>
#include <iostream>

int main() {

  std::forward_list<int> fwd_list = {1, 2, 3};

  fwd_list.push_front(0);

  auto it = fwd_list.begin();

  // Retrieve the first item
  std::cout << *(it) << std::endl;

  return 0;
}
