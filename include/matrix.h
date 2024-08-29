#pragma once
#include "../include/series.h"
#include <cstdlib>
#include <iostream>
#include <string>

class Matrix {
private:
  float initializer = 0;   // Initial value for initializarion
  Series *array = nullptr; // Arrary Datastructure
  int rows = 0;            // Number of Rows
  int columns = 0;         // Number of Columns

public:
  // Initialization
  Matrix();                                     // Initialization
  Matrix(int rows, int columns);                // Initialization with shape
  Matrix(int rows, int columns, float **array); // Initialization with array

  // Destruction
  ~Matrix(); // Destruction and heap dealocation

  // Overloads
  Series &operator[](int idx);                 // Index Operator
  Matrix operator*(const Matrix &other) const; // Matrix Multiplication
  Matrix operator*(float other) const;         // float - Matrix Multiplication
  Matrix operator/(float other) const;         // float - Matrix Division
  Matrix operator+(const Matrix &other) const; // Matrix Summation
  Matrix operator-(const Matrix &other) const; // Matrix Subtraction
  Matrix &operator=(const Matrix &other);      // Matrix Assingment

  // Utility
  void print();                // Printing
  Matrix transpose() const;    // Transposition Copy
  Matrix shape() const;        // Shape as Matrix
  std::string shapeAsString(); // Shape as String
};

// Global overloads
Matrix operator*(float scale, Matrix &other); // GLobal float - Matrix Operator
