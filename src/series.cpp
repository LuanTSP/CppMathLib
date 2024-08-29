#include "../include/series.h"

Series::Series() {}

Series::Series(int lenght) {
  if (lenght < 1) {
    std::cout << "ERROR: Tryed to create Series of lenght " << lenght
              << ". Lenght must be grater than one." << std::endl;
    exit(EXIT_FAILURE);
  }

  this->lenght = lenght;
  float *tmp = new float[lenght];

  for (int i = 0; i < lenght; i++) {
    tmp[i] = this->initializer;
  }
  this->array = tmp;
}

Series::~Series() { delete[] this->array; }

float &Series::operator[](int idx) {
  if (idx > this->lenght - 1 || idx < -this->lenght) {
    std::cout << "ERROR: Index out of range: Tryed to access index " << idx
              << " of " << "[" << -this->lenght << ":" << this->lenght - 1
              << "]" << std::endl;
    exit(EXIT_FAILURE);
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
    exit(EXIT_FAILURE);
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
    exit(EXIT_FAILURE);
  }

  Series tmp = Series(this->lenght);
  for (int i = 0; i < this->lenght; i++) {
    tmp[i] = this->array[i] - other.array[i];
  }

  return tmp;
}

float Series::operator*(const Series &other) const {
  if (other.lenght != this->lenght) {
    std::cout << "ERROR: Tryed to perform dot product of Series of dimensions "
              << this->lenght << " and " << other.lenght << std::endl;
    exit(EXIT_FAILURE);
  }

  float tmp = 0;
  for (int i = 0; i < this->lenght; i++) {
    tmp += this->array[i] * other.array[i];
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

Series Series::operator/(float other) const {
  if (other == 0) {
    std::cout << "ERROR: Division by zero." << std::endl;
    exit(EXIT_FAILURE);
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

  this->lenght = other.lenght;

  return *this;
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
  std::cout << line << std::endl;
}

int Series::len() { return this->lenght; }