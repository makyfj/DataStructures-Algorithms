/*
 * Creating an Organizational Structure
 *
 * Implement a basic version of the organization tree we saw in
 * the introduction to this chapter.
 */
#include <iostream>
#include <queue>

struct Node {
  std::string position;
  Node *first, *second;
};

struct orgTree {
  Node *root;

  static orgTree createOrgStrucutre(const std::string &position) {
    orgTree tree;
    tree.root = new Node{position, nullptr, nullptr};
    return tree;
  }

  static Node *find(Node *root, const std::string &value) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->position == value) {
      return root;
    }

    auto firstFound = orgTree::find(root->first, value);

    if (firstFound != nullptr) {
      return firstFound;
    }

    return orgTree::find(root->second, value);
  }

  // Insert function
  bool addSubordinate(const std::string &manager,
                      const std::string &subordinate) {
    auto manageNode = orgTree::find(root, manager);

    if (!manageNode) {
      std::cout << "No position named " << manager << std::endl;
      return false;
    }

    if (manageNode->first && manageNode->second) {
      std::cout << manager << " alaready has 2 subordinates." << std::endl;
      return false;
    }

    if (!manageNode->first) {
      manageNode->first = new Node{subordinate, nullptr, nullptr};
    } else {
      manageNode->second = new Node{subordinate, nullptr, nullptr};
    }

    return true;
  }
};

int main() {
  auto tree = orgTree::createOrgStrucutre("CEO");

  if (tree.addSubordinate("CEO", "Deputy Director"))
    std::cout << "Added Deputy Director in the tree" << std::endl;
  else
    std::cout << "Couldn't add Deputy Director in the tree" << std::endl;

  if (tree.addSubordinate("Deputy Director", "IT Head"))
    std::cout << "Added IT Head in the tree" << std::endl;
  else
    std::cout << "Couldn't add IT Head in the tree" << std::endl;

  if (tree.addSubordinate("Deputy Director", "Marketing Head"))
    std::cout << "Added Marketing Head in the tree" << std::endl;
  else
    std::cout << "Couldn't add Marketing Head in the tree" << std::endl;

  return 0;
}
