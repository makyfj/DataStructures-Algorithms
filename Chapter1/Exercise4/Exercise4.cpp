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

  std::cout << "Latest winner is: " << *it << std::endl;

  it += 8; // constant time
  std::cout << "Winne before 8 years was: " << *it << std::endl;

  std::advance(it, -3); // constant time
  std::cout << "Winner before 3 years of that was: " << *it << std::endl;

  // Lets try with forward

  return 0;
}
