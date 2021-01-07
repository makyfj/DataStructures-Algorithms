/*
 * Implementing a Graph and Representing it as an adjancency List
 *
 * Graph representing the network of cities and demonstrate how it
 * can be stored as an adjancency list
 */
#include <algorithm>
#include <iostream>
#include <vector>

enum class city : int {
  MOSCOW,
  LONDON,
  INSTABUL,
  SEATTLE,
  DUBAI,
  MUMBAI,
  SINGAPORE
};

std::ostream &operator<<(std::ostream &os, const city c) {
  switch (c) {
  case city::MOSCOW:
    os << "MOSCOW";
    return os;
  case city::LONDON:
    os << "LONDON";
    return os;
  case city::INSTABUL:
    os << "INSTABUL";
    return os;
  case city::SEATTLE:
    os << "SEATTLE";
    return os;
  case city::DUBAI:
    os << "DUBAI";
    return os;
  case city::MUMBAI:
    os << "MUMBAI";
    return os;
  case city::SINGAPORE:
    os << "SINGAPORE";
    return os;
  default:
    return os;
  }
}

struct graph {
  std::vector<std::vector<std::pair<int, int>>> data;

  graph(int n) {
    data = std::vector<std::vector<std::pair<int, int>>>(
        n, std::vector<std::pair<int, int>>());
  }

  void addEdge(const city c1, const city c2, int dis) {
    std::cout << "ADD: " << c1 << " - " << c2 << " = " << dis << std::endl;

    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);
    data[n1].push_back({n2, dis});
    data[n2].push_back({n1, dis});
  }

  void removeEdge(const city c1, const city c2) {
    std::cout << "REMOVE: " << c1 << " - " << c2 << std::endl;

    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);

    std::remove_if(data[n1].begin(), data[n1].end(),
                   [n2](const auto &pair) { return pair.first == n2; });

    std::remove_if(data[n2].begin(), data[n2].end(),
                   [n1](const auto &pair) { return pair.first == n1; });
  }
};

int main() {
  graph g(7);

  g.addEdge(city::LONDON, city::MOSCOW, 900);
  g.addEdge(city::INSTABUL, city::MOSCOW, 900);
  g.addEdge(city::MUMBAI, city::MOSCOW, 900);
  g.addEdge(city::SEATTLE, city::MOSCOW, 900);
  g.addEdge(city::SINGAPORE, city::MOSCOW, 900);
  g.addEdge(city::LONDON, city::SINGAPORE, 900);
  g.addEdge(city::LONDON, city::MUMBAI, 900);
}
