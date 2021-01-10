#include <boost/functional/hash.hpp>
#include <unordered_map>
#include <unordered_set>

struct Car {
  std::string model;
  std::string brand;
  int buildYead;
};

struct CarHasher {
  std::size_t operator()(const Car &car) const {
    std::size_t seed = 0;
    boost::hash_combine(seed, car.model);
    boost::hash_combine(seed, car.brand);
    return seed;
  }
};

struct CarComparator {
  bool operator()(const Car &car1, const Car &car2) const {
    return (car1.model == car2.model) && (car1.brand == car2.brand);
  }
};

int main() {

  // We can use the hasher as follows
  std::unordered_set<Car, CarHasher, CarComparator> carSet;
  std::unordered_map<Car, std::string, CarHasher, CarComparator>
      carDescriptionMap;
}
