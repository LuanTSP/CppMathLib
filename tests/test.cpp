#include "../include/series.h"

int main() {
  int lenght = 4;

  Series s1 = Series(lenght);
  for (int i = 0; i < s1.len(); i++) {
    s1[i] = i;
  }
  s1.print();

  for (int i = -lenght; i <= lenght; i++) {
    for (int j = -lenght; j <= lenght; j++) {
      try {
        std::cout << "[" << i << "," << j << "] ";
        s1.slice(i, j).print();
      } catch (...) {
        continue;
      }
    }
  }
}