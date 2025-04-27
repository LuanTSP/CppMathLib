#include "include/matrix.hpp"
#include "include/list.hpp"
#include "include/tree.hpp"
#include <iostream>

bool greater(int a, int b) {
  return a > b;
}

bool lesser(int a, int b) {
  return a < b;
}

int main() {
  BSTree tree = BSTree<int>(greater);

  tree.insert(1).insert(2).insert(0).insert(10);
  
  std::cout << tree.height() << std::endl;
}