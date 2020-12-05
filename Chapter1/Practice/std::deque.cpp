#include <deque>
#include <iostream>

void print(std::deque<int> deq) {
  for (auto ele : deq)
    std::cout << ele << ", ";
  std::cout << std::endl;
}

int main() {

  std::deque<int> deq = {1, 2, 3, 4, 5};

  print(deq);

  deq.push_front(6);

  print(deq);

  deq.push_back(10);

  print(deq);

  deq.insert(deq.begin() + 2, 10);

  print(deq);

  deq.pop_back();

  print(deq);

  deq.pop_front();

  print(deq);

  deq.erase(deq.begin() + 2);

  print(deq);

  deq.erase(deq.begin() + 1, deq.end());

  print(deq);
  return 0;
}
