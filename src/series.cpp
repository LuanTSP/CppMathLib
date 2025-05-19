#include "../include/series.hpp"
#include <cstdlib>
#include <string>


namespace cppmath {
  // Initialization
  Series::Series() { this->length = 0; }

  Series::Series(int length) {
    if (length < 0) {
      std::cout << "ERROR: Tryed to create Series of length " << length
                << ". Lenght must be grater than 0." << std::endl;
      throw "ERROR";
    }

    this->length = length;

    if (length == 0) {
      return;
    }

    float* tmp = new float[length];

    for (int i = 0; i < length; i++) {
      tmp[i] = this->initializer;
    }
    this->array = tmp;
  }

  // Destruction
  Series::~Series() {
    if (this->array != nullptr) {
      delete[] this->array;
    }
  }

  // Overloads
  float &Series::operator[](int idx) {
    if (idx > this->length - 1 || idx < -this->length) {
      std::cout << "ERROR: Index out of range: Tryed to access index " << idx
                << " of " << "[" << -this->length << ":" << this->length - 1
                << "]" << std::endl;
      throw "ERROR";
    }
    if (idx >= 0) {
      return this->array[idx];
    }
    
    return this->array[this->length + idx];
  }

  Series Series::operator+(const Series &other) const {
    if (other.length != this->length) {
      std::cout << "ERROR: Tryed to add Series of dimensions " << this->length
                << " and " << other.length << std::endl;
      throw "ERROR";
    }

    Series tmp = Series(this->length);
    for (int i = 0; i < this->length; i++) {
      tmp[i] = this->array[i] + other.array[i];
    }

    return tmp;
  }

  Series Series::operator-(const Series &other) const {
    if (other.length != this->length) {
      std::cout << "ERROR: Tryed to subtract Series of dimensions "
                << this->length << " and " << other.length << std::endl;
      throw "ERROR";
    }

    Series tmp = Series(this->length);
    for (int i = 0; i < this->length; i++) {
      tmp[i] = this->array[i] - other.array[i];
    }

    return tmp;
  }

  Series Series::operator*(const Series &other) const {
    if (other.length != this->length) {
      std::cout
          << "ERROR: Tryed to perform multiplication of Series of dimensions "
          << this->length << " and " << other.length << std::endl;
      throw "ERROR";
    }

    Series tmp = Series(this->length);
    for (int i = 0; i < this->length; i++) {
      tmp.array[i] = this->array[i] * other.array[i];
    }

    return tmp;
  }

  Series Series::operator*(float other) const {
    Series tmp = Series(this->length);
    for (int i = 0; i < this->length; i++) {
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
    if (other.length != this->length) {
      std::cout << "ERROR: Tryed to perform dot product of Series of dimensions "
                << this->length << " and " << other.length << std::endl;
      throw "ERROR";
    }

    Series tmp = Series(this->length);
    for (int i = 0; i < this->length; i++) {
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

    Series tmp = Series(this->length);
    for (int i = 0; i < this->length; i++) {
      tmp.array[i] = this->array[i] / other;
    }

    return tmp;
  }

  Series &Series::operator=(const Series &other) {
    // Delete previous array of items
    delete[] this->array;

    // Make new Series and return
    this->array = new float[other.length];
    for (int i = 0; i < other.length; i++) {
      this->array[i] = other.array[i];
    }

    // Set length
    this->length = other.length;

    return *this;
  }

  // Utility
  Series Series::slice(int start, int end) const {
    // Check for valid inputs of start and end positions
    bool validStart = (start >= -this->length && start < this->length);
    bool validEnd = (end >= -this->length && end <= this->length);

    if (!validStart || !validEnd) {
      std::cout << "ERROR: Invalid slice" << std::endl;
      throw "ERROR";
    }

    if (start < 0) {
      start = this->length + start;
    }
    if (end < 0) {
      end = this->length + end;
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
    if (other.length != this->length) {
      std::cout << "ERROR: Tryed to perform dot product of Series of dimensions "
                << this->length << " and " << other.length << std::endl;
      throw "ERROR";
    }

    float tmp = 0;
    for (int i = 0; i < this->length; i++) {
      tmp += this->array[i] * other.array[i];
    }

    return tmp;
  }

  std::string Series::repr() {
    std::string line = "[";
    for (int i = 0; i < this->length; i++) {
      line = line + std::to_string(this->array[i]).substr(0, 4);
      if (i + 1 != this->length) {
        line += ", ";
      }
    }
    line += "]";
    return line;
  }

  void Series::print() { std::cout << this->repr(); }

  int Series::len() { return this->length; }
}