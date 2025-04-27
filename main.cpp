#include "include/matrix.hpp"
#include "include/list.hpp"
#include "include/tree.hpp"
#include <iostream>
#include <vector>

class teste {
public:
  teste() {}
  
  // Make it friend if you define inside class
  friend std::ostream& operator<<(std::ostream& os, const teste& t) {
    os << "Mamamia";
    return os;
  }
}; // <<< SEMICOLON after class

int main() {
  // Matrix mat = Matrix(2, 2); // <-- This will cause an error if Matrix isn't defined
  std::vector<float> vec;
  vec.push_back(-21);
  
  std::cout << vec.at(0) << std::endl;
  std::cout << vec.capacity() << "\n";
  
  teste t;
  std::cout << t << std::endl;
}
