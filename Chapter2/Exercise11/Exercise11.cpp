/*
 * Implementing a Graph and Representing it as an Adjancency
 * Matrix
 *
 * Graph representing the network of cities shown in the preceding
 * figure, and demostrate how it can be stored as an adjancency matrix.
 */
#include <iostream>
#include <ostream>
#include <vector>

enum class city : int {
  LONDON,
  MOSCOW,
  INSTABUL,
  DUBAI,
  MUMBAI,
  SEATTLE,
  SINGAPORE
};

std::ostream &operator<<(std::ostream &os, const city c) {
  switch (c) {
  case city::LONDON:
    os << "LONDON";
    return os;
  case city::MOSCOW:
    os << "MOSCOW";
    return os;
  case city::INSTABUL:
    os << "INSTABUL";
    return os;
  case city::DUBAI:
    os << "DUBAI";
    return os;
  case city::MUMBAI:
    os << "MUMBAI";
    return os;
  case city::SEATTLE:
    os << "SEATTLE";
    return os;
  case city::SINGAPORE:
    os << "SINGAPORE";
    return os;
  default:
    return os;
  }
}

struct graph {
  std::vector<std::vector<int>> data;

  graph(int n) {
    data.reserve(n);
    std::vector<int> row(n);
    std::fill(row.begin(), row.end(), -1);
    for (int i = 0; i < n; i++) {
      data.push_back(row);
    }
  }

  // 3 parameters, two cities connected and the weight(distance) of the edge
  void addEdge(const city c1, const city c2, int dis) {
    std::cout << "ADD: " << c1 << "-" << c2 << "=" << dis << std::endl;

    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);

    data[n1][n2] = dis;
    data[n2][n1] = dis;
  }

  // remove an edge from the graph
  void removeEdge(const city c1, const city c2) {
    std::cout << "REMOVE: " << c1 << "-" << c2 << std::endl;

    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);

    data[n1][n2] = -1;
    data[n2][n1] = -1;
  }
};

int main() {
  graph g(7);

  g.addEdge(city::LONDON, city::MOSCOW, 900);
  g.addEdge(city::LONDON, city::INSTABUL, 500);
  g.addEdge(city::LONDON, city::DUBAI, 1000);
  g.addEdge(city::INSTABUL, city::MOSCOW, 1000);
  g.addEdge(city::INSTABUL, city::DUBAI, 500);
  g.addEdge(city::DUBAI, city::MUMBAI, 200);
  g.addEdge(city::INSTABUL, city::SEATTLE, 1500);
  g.addEdge(city::DUBAI, city::SINGAPORE, 500);
  g.addEdge(city::MOSCOW, city::SEATTLE, 1000);
  g.addEdge(city::MUMBAI, city::SINGAPORE, 300);
  g.addEdge(city::SEATTLE, city::SINGAPORE, 700);
  g.addEdge(city::SEATTLE, city::LONDON, 1800);

  g.removeEdge(city::SEATTLE, city::LONDON);
}
