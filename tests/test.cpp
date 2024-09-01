#include "../include/list.h"

int main() {
  List<std::string> list = List<std::string>();

  list.push_at(0, "Oi");
  list.push_at(0, "Eu sou o Goku!");
  list.print();

  return 0;
}