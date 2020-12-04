/*
 * Conditional Removal of Elements from a linked list
 * Using remove_if
 */
#include <forward_list>
#include <iostream>
#include <ostream>

struct citizen {
  std::string name;
  int age;
};

std::ostream &operator<<(std::ostream &os, const citizen &c) {
  return (os << "[Name: " << c.name << ", Age: " << c.age << "]");
}

int main() {

  std::forward_list<citizen> citizens = {
      {"Franklin", 22}, {"Nick", 21}, {"Kaitli", 14}, {"Andrea", 17}};

  // Make a copy to avoid to initialize again
  auto citizens_copy = citizens;

  std::cout << "All citizens: ";
  for (const auto &c : citizens) {
    std::cout << c << " ";
  }

  std::cout << std::endl;

  // Remove citizens if < 18
  citizens.remove_if([](const citizen &c) { return (c.age < 18); });

  std::cout << "Citizens eligible to vote: ";
  for (const auto &c : citizens) {
    std::cout << c << " ";
  }

  // Who will be eligible to vote next year
  citizens_copy.remove_if([](const citizen &c) {
    // Returns true if age is less than 18
    return (c.age != 17);
  });

  std::cout << std::endl;

  std::cout << "Citizens eligible to vote next year: ";
  for (const auto &c : citizens_copy) {
    std::cout << c << " ";
  }

  return 0;
}
