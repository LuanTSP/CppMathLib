#include "../include/tree.h"

int main() {
  Tree<const char *> tree = Tree<const char *>();

  // TreeNode<const char *> *newNode = new TreeNode<const char *>("teste");
  // tree.root = newNode;
  // std::cout << tree.root->data << std::endl;

  tree.insert("1");
  tree.insert("2");
  tree.insert("3");
  tree.insert("4");
  tree.insert("5");
  tree.insert("6");
  tree.insert("7");
  tree.insert("8");

  tree.printLevel(2);
}