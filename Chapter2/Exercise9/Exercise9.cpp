/*
 * Implementing a Binary Search Tree
 *
 * Add find function to search for elements. We will also try our hand at the
 * intersection and deleteion of elements, as explained in the previous
 * subsections.
 */

#include <iostream>

struct Node {
  int data;
  Node *left, *right;
};

struct bst {
  Node *root = nullptr;

  Node *find(int value) { return findImpl(root, value); }

private:
  Node *findImpl(Node *current, int value) {

    if (!current) {
      std::cout << std::endl;
      return nullptr;
    }

    if (current->data == value) {
      std::cout << "Found: " << value << std::endl;
      return current;
    }

    // value will be in the left subtree
    if (value < current->data) {
      std::cout << "Going left from " << current->data << ", ";
      return findImpl(current->left, value);
    }

    if (value > current->data) {
      std::cout << "Going right from " << current->data << ", ";
      return findImpl(current->right, value);
    }
  }

  void insertImpl(Node *current, int value) {
    if (value < current->data) {
      if (!current->left) {
        current->left = new Node{value, nullptr, nullptr};
      } else {
        insertImpl(current->left, value);
      }
    } else {
      if (!current->right) {
        current->right = new Node{value, nullptr, nullptr};
      } else {
        insertImpl(current->right, value);
      }
    }
  }

  void inorderImpl(Node *start) {
    if (!start) {
      return;
    }
    inorderImpl(start->left);
    std::cout << start->data << " , ";
    inorderImpl(start->right);
  }

  Node *deleteImpl(Node *start, int value) {
    if (!start)
      return nullptr;

    if (value < start->data)
      start->left = deleteImpl(start->left, value);
    else if (value > start->data)
      start->right = deleteImpl(start->right, value);
    else {
      // either both children are absent or only left
      if (!start->left) {
        auto tmp = start->right;
        delete start;
        return tmp;
      }

      // only right child is absent
      if (!start->right) {
        auto tmp = start->left;
        delete start;
        return tmp;
      }

      auto succNode = successor(start);
      start->data = succNode->data;

      // Delete the succesor from right subtree
      // since it will always be in the right subtree
      start->right = deleteImpl(start->right, succNode->data);
    }

    return start;
  }

public:
  void insert(int value) {
    if (!root)
      root = new Node{value, nullptr, nullptr};
    else
      insertImpl(root, value);
  }

  void inorder() { inorderImpl(root); }

  Node *successor(Node *start) {
    auto current = start->right;
    while (current && current->left)
      current = current->left;
    return current;
  }

  void deleteValue(int value) { root = deleteImpl(root, value); }
};

int main() {
  bst tree;

  tree.insert(12);
  tree.insert(10);
  tree.insert(20);
  tree.insert(8);
  tree.insert(11);
  tree.insert(15);
  tree.insert(28);
  tree.insert(4);
  tree.insert(2);

  std::cout << "Inorder: ";
  // this will print all the elements in ascending order
  tree.inorder();
  std::cout << std::endl;

  tree.deleteValue(12);

  std::cout << "Inorder after deleting 12: ";
  tree.inorder();
  std::cout << std::endl;

  if (tree.find(12))
    std::cout << "Element is present in the tree" << std::endl;
  else
    std::cout << "Element is NOT present in the tree" << std::endl;
}
