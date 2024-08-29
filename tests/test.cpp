#include "../include/matrix.h"

int main() {
  // Matrix 1
  Matrix mat1 = Matrix(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      mat1[i][j] = i + j;
    }
  }

  // Matrix 2
  Matrix mat2 = Matrix(4, 3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      mat2[i][j] = i + j;
    }
  }

  Matrix mat3 = mat1 * mat2;
  mat3.print();
}