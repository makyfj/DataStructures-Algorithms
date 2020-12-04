/*
 * Exploring Different Types of Iterators
 *
 * List of the winners of The Singapore F1 Grand Prix from
 * the last few years. With the help of vector iterators,
 * we'll discover how we can retrieve useful information
 * from this data. After that, we'll try to do the same
 * thing with forward_list, and see how it differs from the
 * vectors iterators.
 */

#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

  // Vector with list of winners
  std::vector<std::string> vec = {
      "Lewis Hamilton",   "Lewis Hamilton",   "Nico Roseberg",
      "Sebastian Vettel", "Lewis Hamilton",   "Sebastian Vettel",
      "Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"};

  auto it = vec.begin(); // constant time

  std::cout << "\nVector List" << std::endl;
  std::cout << "Latest winner is: " << *it << std::endl;

  it += 8; // constant time
  std::cout << "Winne before 8 years was: " << *it << std::endl;

  std::advance(it, -3); // constant time
  std::cout << "Winner before 3 years of that was: " << *it << std::endl;

  // Lets try with forward_list
  std::cout << "\nForward List" << std::endl;
  std::forward_list<std::string> fwd(vec.begin(), vec.end());

  auto itfwd = fwd.begin();

  std::cout << "Latest winner is: " << *itfwd << std::endl;

  // Time taken is proportional to the numbers of elements
  std::advance(itfwd, 5);

  std::cout << "Winner before 5 years was: " << *itfwd << std::endl;

  // Going back will result in compile time error as forward_list only
  // allows us to move towards the end.

  // This will result in a compiler error
  // std::advance(itfwd, -2);
  // itfwd += 2; - Compiler error as well

  return 0;
}
