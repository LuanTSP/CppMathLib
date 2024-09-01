#include "../include/series.h"
#include <cstdlib>

// Initialization
Series::Series() {}

Series::Series(int lenght) {
  if (lenght < 1) {
    std::cout << "ERROR: Tryed to create Series of lenght " << lenght
              << ". Lenght must be grater than one." << std::endl;
    throw "ERROR";
  }

  this->lenght = lenght;
  float *tmp = new float[lenght];

  for (int i = 0; i < lenght; i++) {
    tmp[i] = this->initializer;
  }
  this->array = tmp;
}

// Destruction
Series::~Series() { delete[] this->array; }

// Overloads
float &Series::operator[](int idx) {
  if (idx > this->lenght - 1 || idx < -this->lenght) {
    std::cout << "ERROR: Index out of range: Tryed to access index " << idx
              << " of " << "[" << -this->lenght << ":" << this->lenght - 1
              << "]" << std::endl;
    throw "ERROR";
  }
  if (idx >= 0) {
    return this->array[idx];
  }

  return this->array[this->lenght + idx];
}

Series Series::operator+(const Series &other) const {
  if (other.lenght != this->lenght) {
    std::cout << "ERROR: Tryed to add Series of dimensions " << this->lenght
              << " and " << other.lenght << std::endl;
    throw "ERROR";
  }

  Series tmp = Series(this->lenght);
  for (int i = 0; i < this->lenght; i++) {
    tmp[i] = this->array[i] + other.array[i];
  }

  return tmp;
}

Series Series::operator-(const Series &other) const {
  if (other.lenght != this->lenght) {
    std::cout << "ERROR: Tryed to subtract Series of dimensions "
              << this->lenght << " and " << other.lenght << std::endl;
    throw "ERROR";
  }

  Series tmp = Series(this->lenght);
  for (int i = 0; i < this->lenght; i++) {
    tmp[i] = this->array[i] - other.array[i];
  }

  return tmp;
}

Series Series::operator*(const Series &other) const {
  if (other.lenght != this->lenght) {
    std::cout
        << "ERROR: Tryed to perform multiplication of Series of dimensions "
        << this->lenght << " and " << other.lenght << std::endl;
    throw "ERROR";
  }

  Series tmp = Series(this->lenght);
  for (int i = 0; i < this->lenght; i++) {
    tmp.array[i] = this->array[i] * other.array[i];
  }

  return tmp;
}

Series Series::operator*(float other) const {
  Series tmp = Series(this->lenght);
  for (int i = 0; i < this->lenght; i++) {
    tmp.array[i] = this->array[i] * other;
  }

  return tmp;
}

Series operator*(float scale, Series &other) {
  int length = other.len();

  Series tmp = Series(length);
  for (int i = 0; i < length; i++) {
    tmp[i] = other[i] * scale;
  }

  return tmp;
}

Series Series::operator/(const Series &other) const {
  if (other.lenght != this->lenght) {
    std::cout << "ERROR: Tryed to perform dot product of Series of dimensions "
              << this->lenght << " and " << other.lenght << std::endl;
    throw "ERROR";
  }

  Series tmp = Series(this->lenght);
  for (int i = 0; i < this->lenght; i++) {
    if (other.array[i] == 0) {
      std::cout << "ERROR: Division by zero in series / series division"
                << std::endl;
      throw "ERROR";
    }
    tmp.array[i] = this->array[i] / other.array[i];
  }

  return tmp;
}

Series Series::operator/(float other) const {
  if (other == 0) {
    std::cout << "ERROR: Division by zero." << std::endl;
    throw "ERROR";
  }

  Series tmp = Series(this->lenght);
  for (int i = 0; i < this->lenght; i++) {
    tmp.array[i] = this->array[i] / other;
  }

  return tmp;
}

Series &Series::operator=(const Series &other) {
  // Delete previous array of items
  delete[] this->array;

  // Make new Series and return
  this->array = new float[other.lenght];
  for (int i = 0; i < other.lenght; i++) {
    this->array[i] = other.array[i];
  }

  // Set lenght
  this->lenght = other.lenght;

  return *this;
}

// Utility
Series Series::slice(int start, int end) const {
  // Check for valid inputs of start and end positions
  bool validStart = (start >= -this->lenght && start < this->lenght);
  bool validEnd = (end >= -this->lenght && end <= this->lenght);

  if (!validStart || !validEnd) {
    std::cout << "ERROR: Invalid slice" << std::endl;
    throw "ERROR";
  }

  if (start < 0) {
    start = this->lenght + start;
  }
  if (end < 0) {
    end = this->lenght + end;
  }

  // Slicing
  Series tmp;
  if (end > start) {
    int len = end - start;
    tmp = Series(len);

    for (int i = 0; i < len; i++) {
      tmp.array[i] = this->array[start + i];
    }
  } else {
    int len = start - end;
    tmp = Series(len);

    for (int i = 0; i < len; i++) {
      tmp.array[i] = this->array[start - i];
    }
  }

  return tmp;
}

float Series::dot(const Series &other) const {
  if (other.lenght != this->lenght) {
    std::cout << "ERROR: Tryed to perform dot product of Series of dimensions "
              << this->lenght << " and " << other.lenght << std::endl;
    throw "ERROR";
  }

  float tmp = 0;
  for (int i = 0; i < this->lenght; i++) {
    tmp += this->array[i] * other.array[i];
  }

  return tmp;
}

void Series::print() {
  std::string line = "[";
  for (int i = 0; i < this->lenght; i++) {
    line = line + std::to_string(this->array[i]).substr(0, 4);
    if (i + 1 != this->lenght) {
      line += ", ";
    } else {
      line += "]";
    }
  }
  std::cout << line;
}

int Series::len() { return this->lenght; }