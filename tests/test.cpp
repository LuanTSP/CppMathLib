#include "../include/tree.h"

int main() {
  Tree<const char *> tree = Tree<const char *>("Hello");

  tree.insert("This");
  tree.insert("Is");
  tree.insert("a");
  tree.insert("Message");

  tree.print();
}