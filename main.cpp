#include "include/matrix.hpp"
#include "include/list.hpp"
#include <iostream>
#include <array>
#include <vector>

bool crit(int a, int b) {
  if (a >= b) return true;
  return false;
}

void sort(List<int> &list, bool (*criterium)(int a, int b)) {
  std::vector a = {1, 2, 3};
  
  int lenght = list.len();
  if (lenght == 1 || lenght == 0) {
    list.print();
    return;
  }
  
  int i = 0;
  while (i < lenght - 1) {
    // switch;
    if (criterium(list[i], list[i+1])) {
      int c = list[i];
      list[i] = list[i+1]; 
      list[i+1] = c;
      i = 0;
    }

    i++;
  }

  list.print();
  return;
}

int main() {
  List list = List<int>();
  list.push_back(2).push_back(0).push_back(-2).push_begin(-8);

  list.sort(crit, true);
  
  std::string a = "Bola"; std::string b = "Bola";
  list.print();
}