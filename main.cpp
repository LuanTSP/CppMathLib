#include "include/matrix.hpp"
#include "include/list.hpp"
#include <iostream>
#include <array>
#include <vector>

bool even(int v) {
  return v % 2 == 0;
}

int main() {
  List list = List<int>();
  list.push_back(1).push_back(2).push_back(3).push_back(4);
  list.print();
  List<int> reversed = list.reverse().reverse().reverse();
  reversed.print();
  list.reverse_inplace();
  list.print();
}