#pragma once
#include <iostream>

class Series {
private:
  int lenght;             // Lenght of data
  float initializer = 0;  // Initial value for initializarion
  float *array = nullptr; // Arrary Datastructure
public:
  // Initialization
  Series();           // Initialization
  Series(int lenght); // Initialization with length

  // Destruction
  ~Series(); // Destruction

  // Overloads
  float &operator[](int idx);                 // Index Operator
  float operator*(const Series &other) const; // Dot Product
  Series operator*(float other) const; // float - Series Multiplication Operator
  Series operator+(const Series &other) const; // Series Addition Operator
  Series operator-(const Series &other) const; // Series Subtraction Operator
  Series operator/(float other) const;    // float - Series Division Operator
  Series &operator=(const Series &other); // Assigment Operator

  // Utility
  void print(); // Printing
  int len();    // Length
};

Series operator*(float scale, Series &other); // Global float - Series Operator