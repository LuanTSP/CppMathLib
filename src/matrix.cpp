#include "../include/matrix.h"
#include "../include/series.h"
#include <cmath>
#include <cstdlib>
#include <string>

// Initialization
Matrix::Matrix(){};

Matrix::Matrix(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;
  this->array = new Series[rows];
  for (int i = 0; i < rows; i++) {
    this->array[i] = Series(columns);
  }
}

Matrix::Matrix(int rows, int columns, float **array) {
  this->rows = rows;
  this->columns = columns;
  this->array = new Series[rows];
  for (int i = 0; i < this->rows; i++) {
    Series line = Series(columns);
    for (int j = 0; j < this->columns; j++) {
      line[j] = array[i][j];
    }
    this->array[i] = line;
  }
}

// Destruction
Matrix::~Matrix() { delete[] this->array; }

// Overloads
Series &Matrix::operator[](int idx) {
  // Checks
  if (idx > this->rows - 1 || idx < -this->rows) {
    std::cout << "ERROR: Index out of range: Tryed to access index " << idx
              << " of " << "[" << -this->rows << ":" << this->rows - 1 << "]"
              << std::endl;
    exit(EXIT_FAILURE);
  }

  if (idx >= 0) {
    return this->array[idx];
  }

  return this->array[this->rows + idx];
}

Matrix Matrix::operator*(const Matrix &other) const {
  // Checks
  if (this->columns != other.rows) {
    std::cerr << "Incompatible sizes when multiplying matrices: (" +
                     std::to_string(this->rows) + "," +
                     std::to_string(this->columns) + ") (" +
                     std::to_string(other.rows) + "," +
                     std::to_string(other.columns) + ")"
              << std::endl;
    exit(EXIT_FAILURE);
  }

  // Multiplication
  Matrix mat = Matrix(this->rows, other.columns);
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < other.columns; j++) {
      float sum = 0;
      for (int k = 0; k < this->columns; k++) {
        sum += this->array[i][k] * other.array[k][j];
      }
      mat[i][j] = sum;
    }
  }

  return mat;
}

Matrix Matrix::operator*(float other) const {
  Matrix mat = Matrix(this->rows, this->columns);
  for (int i = 0; i < this->rows; i++) {
    mat[i] = this->array[i] * other;
  }

  return mat;
}

Matrix Matrix::operator/(float other) const {
  if (other == 0) {
    std::cout << "ERROR: Division by zero." << std::endl;
    exit(EXIT_FAILURE);
  }

  Matrix dims = this->shape();
  int rows = (int)dims[0][0];
  int columns = (int)dims[0][1];

  Matrix mat = Matrix(rows, columns);
  for (int i = 0; i < rows; i++) {
    mat[i] = this->array[i] / other;
  }

  return mat;
}

Matrix operator*(float scale, Matrix &other) {
  Matrix dims = other.shape();
  int rows = (int)dims[0][0];
  int columns = (int)dims[0][1];

  Matrix mat = Matrix(rows, columns);
  for (int i = 0; i < rows; i++) {
    mat[i] = other[i] * scale;
  }

  return mat;
}

Matrix Matrix::operator+(const Matrix &other) const {
  // Checks
  if (this->rows != other.rows && this->columns != other.columns) {
    std::cerr << "Incompatible sizes when adding matrices: (" +
                     std::to_string(this->rows) + "," +
                     std::to_string(this->columns) + ") (" +
                     std::to_string(other.rows) + "," +
                     std::to_string(other.columns) + ")"
              << std::endl;
    exit(EXIT_FAILURE);
  }

  Matrix mat = Matrix(this->rows, this->columns);
  for (int i = 0; i < this->rows; i++) {
    mat.array[i] = this->array[i] + other.array[i];
  }

  return mat;
}

Matrix Matrix::operator-(const Matrix &other) const {
  // Checks
  if (this->rows != other.rows && this->columns != other.columns) {
    std::cerr << "Incompatible sizes when adding matrices: (" +
                     std::to_string(this->rows) + "," +
                     std::to_string(this->columns) + ") (" +
                     std::to_string(other.rows) + "," +
                     std::to_string(other.columns) + ")"
              << std::endl;
    exit(EXIT_FAILURE);
  }

  Matrix mat = Matrix(this->rows, this->columns);
  for (int i = 0; i < this->rows; i++) {
    mat.array[i] = this->array[i] - other.array[i];
  }

  return mat;
}

Matrix &Matrix::operator=(const Matrix &other) {
  // Delete previous array
  delete[] this->array;

  // Change to new array
  this->array = new Series(other.rows);
  for (int i = 0; i < other.rows; i++) {
    Series line = Series(other.columns);
    for (int j = 0; j < other.columns; j++) {
      line[j] = other.array[i][j];
    }
    this->array[i] = line;
  }

  // Change columns and rows
  this->rows = other.rows;
  this->columns = other.columns;

  // return
  return *this;
}

// Utilities
void Matrix::print() {
  // Print a formated form of the Matrix
  for (int i = 0; i < this->rows; i++) {
    this->array[i].print();
  }
}

Matrix Matrix::transpose() const {
  Matrix trans = Matrix(this->columns, this->rows);
  for (int i = 0; i < this->columns; i++) {
    for (int j = 0; j < this->rows; j++) {
      trans[i][j] = this->array[j][i];
    }
  }
  return trans;
}

Matrix Matrix::shape() const {
  Matrix shape = Matrix(1, 2);
  shape[0][0] = this->rows;
  shape[0][1] = this->columns;

  return shape;
}

std::string Matrix::shapeAsString() {
  std::string shape = "(" + std::to_string(this->rows) + "," +
                      std::to_string(this->columns) + ")";
  return shape;
}