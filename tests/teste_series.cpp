#include "../include/series.h"
#include <fstream>

void creation_test(std::ofstream &ofile) {
  ofile << "### CREATION TEST ###\n";

  // CREATE EMPTY LIST
  Series s1 = Series();
  ofile << s1.repr() << "\n";
  if (s1.len() != 0) {
    std::cout << "ERROR: at 'creation_test' | series created with lenght "
                 "different than 0"
              << std::endl;
    throw "ERROR";
  }

  // CREATE WITH LENGHT
  Series s2 = Series(10);
  ofile << s2.repr();
  if (s2.len() != 10) {
    std::cout << "ERROR: at 'creation_test' | series with size 10 created with "
                 "lenght "
                 "different than 10"
              << std::endl;
    throw "ERROR";
  }
  for (int i = 0; i < 10; i++) {
    if (s2[i] != 0) {
      std::cout << "ERROR: at 'creation_test' | series initialized with values "
                   "different from 0";
      throw "ERROR";
    }
  }
}

int main() {
  std::ofstream ofile("test_series.txt");
  creation_test(ofile);
}