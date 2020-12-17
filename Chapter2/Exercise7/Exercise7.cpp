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

static void preOrder(Node *start) {
  if (!start) {
    return;
  }
  std::cout << start->position << " , ";
  preOrder(start->first);
  preOrder(start->second);
}

static void inOrder(Node *start) {
  if (!start) {
    return;
  }
  inOrder(start->first);
  std::cout << start->position << " , ";
  inOrder(start->second);
}

static void postOrder(Node *start) {
  if (!start) {
    return;
  }
  postOrder(start->first);
  postOrder(start->second);
  std::cout << start->position << " , ";
}

static void levelOrder(Node *start) {
  if (!start) {
    return;
  }
  std::queue<Node *> que;
  que.push(start);
  while (!que.empty()) {
    int size = que.size();

    for (int i = 0; i < size; i++) {

      auto current = que.front();
      que.pop();

      std::cout << current->position << ", ";
      if (current->first) {
        que.push(current->first);
      }

      if (current->second) {
        que.push(current->second);
      }
    }
    std::cout << std::endl;
  }
}

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

  if (tree.addSubordinate("IT Head", "Security Head"))
    std::cout << "Added Security Head in the tree" << std::endl;
  else
    std::cout << "Couldn't add Security Head in the tree" << std::endl;

  if (tree.addSubordinate("IT Head", "App Development Head"))
    std::cout << "Added App Development Head in the tree" << std::endl;
  else
    std::cout << "Couldn't add App Development Head in the tree" << std::endl;

  if (tree.addSubordinate("Marketing Head", "Logistics Head"))
    std::cout << "Added Logistics Head in the tree" << std::endl;
  else
    std::cout << "Couldn't add Logistics Head in the tree" << std::endl;

  if (tree.addSubordinate("Deputy Director", "Public Relations Head"))
    std::cout << "Added Public Relations Head in the tree" << std::endl;
  else
    std::cout << "Couldn't add Public Relations Head in the tree" << std::endl;

  if (tree.addSubordinate("Deputy Director", "Finance Head"))
    std::cout << "Added Finance Head in the tree" << std::endl;
  else
    std::cout << "Couldn't add Finance Head in the tree" << std::endl;

  std::cout << "PreOrder" << std::endl;
  preOrder(tree.root);

  std::cout << "\nInOrder" << std::endl;
  inOrder(tree.root);

  std::cout << "\nPostOrder" << std::endl;
  postOrder(tree.root);

  std::cout << "\nLevelOrder" << std::endl;
  levelOrder(tree.root);

  return 0;
}
