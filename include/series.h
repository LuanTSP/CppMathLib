#pragma once
#include <iostream>

class Series {
private:
  int lenght;         // Lenght of data
  float initializer = 0;  // Initial value for initializarion
  float *array = nullptr; // Arrary Datastructure
public:
  // Initialization
  Series();           // Initialization
  Series(int lenght); // Initialization with length

  // Destruction
  ~Series(); // Destruction

  // Overloads
  float &operator[](int idx);                  // Index Operator
  Series operator*(const Series &other) const; // Multiplication term by term
  Series operator*(float other) const; // float - Series Multiplication Operator
  Series operator+(const Series &other) const; // Series Addition Operator
  Series operator-(const Series &other) const; // Series Subtraction Operator
  Series operator/(const Series &other) const; // Division term by term;
  Series operator/(float other) const;    // float - Series Division Operator
  Series &operator=(const Series &other); // Assigment Operator

  // Utility
  Series slice(int start, int end) const;
  float dot(const Series &other) const; // Dot Product
  void print();                         // Printing
  int len();                            // Length
  std::string repr();
};

Series operator*(float scale, Series &other); // Global float - Series Operator