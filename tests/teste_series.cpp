#include "../include/series.hpp"
#include <fstream>


// === CREATION TESTS ===
bool empty_list_creation_test(std::ofstream &ofile) {
  bool passed = true;

  Series s1 = Series();
  ofile << "Empty list creation test: ";
  if (s1.len() != 0) {
    std::cerr << "ERROR: at 'empty_list_creation_test' | series created with lenght different than 0" << std::endl;
    passed = false;
  } else {
    ofile << "OK\n";
  }
  ofile << "Result: " << s1.repr() << "\n\n";
  
  return passed;
}

bool five_lenght_creation_test(std::ofstream &ofile) {
  bool passed = true;

  Series s2 = Series(5);
  ofile << "5 lenght creation test: ";
  if (s2.len() != 5) {
    std::cerr << "ERROR: at 'five_lenght_creation_test' | series with size 10 created with lenght different than 10" << std::endl;
    passed = false;
  }
  for (int i = 0; i < 5; i++) {
    if (s2[i] != 0) {
      std::cerr << "ERROR: at 'five_lenght_creation_test' | series initialized with values "
                   "different from 0";
      passed = false;
    }
  }

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
  }
  ofile << "Result: " << s2.repr() << "\n\n";
  
  return passed;
}

void series_creation_tests(std::ofstream &ofile) {
  bool passed = true;
  ofile << "\n=== SERIES CREATION TESTS ===\n\n";
  passed = passed && empty_list_creation_test(ofile);
  passed = passed && five_lenght_creation_test(ofile);
  
  if (passed) {
    std::cout << "PASSED SERIES CREATION TESTS" << std::endl;
  }
}

// === GET SET ITEM TESTS ===
bool series_get_set_positive_index(std::ostream &ofile) {
  bool passed = true;
  ofile << "get set positive index test: ";
  Series s = Series(5);
  s[1] = 1; s[2] = 2; s[3] = 3; s[4] = 4; // set items

  if (s[0] != 0) passed = false; // get items
  if (s[1] != 1) passed = false;
  if (s[2] != 2) passed = false;
  if (s[3] != 3) passed = false;
  if (s[4] != 4) passed = false; 

  if (!passed) {
    std::cerr << "ERROR: at 'get_set_positive_index' | series set data or retrieved data discrepancy\n";
  }

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
  }

  ofile << "result: " << s.repr() << "\n\n";
  return passed;
}

bool get_set_negative_index(std::ostream &ofile) {
  bool passed = true;
  ofile << "get set negative index test: ";
  Series s = Series(5);
  s[1] = 1; s[2] = 2; s[3] = 3; s[4] = 4; //set items

  if (s[-5] != 0) passed = false; // get items
  if (s[-4] != 1) passed = false;
  if (s[-3] != 2) passed = false;
  if (s[-2] != 3) passed = false;
  if (s[-1] != 4) passed = false; 

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
    std::cerr << "ERROR: at 'get_set_negative_index' | series set data or retrieved data discrepancy\n";
  }

  ofile << "result: " << s.repr() << "\n\n";
  return passed;
}

void get_set_tests(std::ostream &ofile) {
  bool passed = true;
  ofile << "\n=== GET SET TESTS ===\n\n";

  passed = passed && series_get_set_positive_index(ofile);
  passed = passed && get_set_negative_index(ofile);

  if (passed) {
    std::cout << "PASSED SERIES GET SET TESTS" << std::endl;
  }
}

// === ADDITION TESTS ===
bool series_series_addition(std::ostream &ofile) {
  bool passed = true;
  ofile << "series series addition test: ";
  Series s1 = Series(5); 
  Series s2 = Series(5);
  for (int i=0; i < s1.len(); i++) {
    s1[i] = i;
    s2[i] = i;
  }

  Series s3 = s1 + s2;
  if (s3[0] != 0) passed = false;
  if (s3[1] != 2) passed = false;
  if (s3[2] != 4) passed = false;
  if (s3[3] != 6) passed = false;
  if (s3[4] != 8) passed = false;

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
    std::cerr << "ERROR: at 'series_series_addition' | series series addition data with discrepancy\n";
  }
  ofile << "result: " << s3.repr() << "\n\n";

  return passed;
}

void series_addition_tests(std::ostream &ofile) {
  bool passed = true;
  ofile << "\n=== SERIES ADDITION TESTS ===\n\n";

  passed = passed && series_series_addition(ofile);

  if (passed) {
    std::cout << "PASSED SERIES ADDITION TESTS" << std::endl;
  }
}

// === SUBTRACTION TESTS ===
bool series_series_subtraction(std::ostream &ofile) {
  bool passed = true;
  ofile << "series series subtraction test: ";
  Series s1 = Series(5); 
  Series s2 = Series(5);
  for (int i=0; i < s1.len(); i++) {
    s1[i] = i;
    s2[i] = i * i;
  }

  Series s3 = s2 - s1;
  if (s3[0] != 0) passed = false;
  if (s3[1] != 0) passed = false;
  if (s3[2] != 2) passed = false;
  if (s3[3] != 6) passed = false;
  if (s3[4] != 12) passed = false;

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
    std::cerr << "ERROR: at 'series_series_subtraction' | series series subtraction data with discrepancy\n";
  }
  ofile << "result: " << s3.repr() << "\n\n";

  return passed;
}

void series_subtraction_tests(std::ostream &ofile) {
  bool passed = true;
  ofile << "\n=== SERIES SUBTRACTION TESTS ===\n\n";

  passed = passed && series_series_subtraction(ofile);

  if (passed) {
    std::cout << "PASSED SERIES SUBTRACTION TESTS" << std::endl;
  }
}

// === MULTIPLICATION TESTS ===
bool series_series_multiplication(std::ofstream &ofile) {
  bool passed = true;

  ofile << "series series multiplication test: ";
  Series s1 = Series(5);
  s1[0] = 0;
  s1[1] = 1;
  s1[2] = 2;
  s1[3] = 3;
  s1[4] = 4;

  Series s2 = Series(5);
  s2[0] = 5;
  s2[1] = 6;
  s2[2] = 7;
  s2[3] = 8;
  s2[4] = 9;

  Series s3 = s1 * s2;
  
  if (s3[0] != 0) passed = false;
  if (s3[1] != 6) passed = false;
  if (s3[2] != 14) passed = false;
  if (s3[3] != 24) passed = false;
  if (s3[4] != 36) passed = false;

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
    std::cerr << "ERROR: at 'series_series_multiplication' | series_series_multiplication data with discrepancy\n";
  }
  ofile << "result: " << s3.repr() << "\n\n";

  
  return passed;

}

bool series_float_multiplication(std::ofstream &ofile) {
  bool passed = true;

  ofile << "series float multiplication test: ";
  Series s1 = Series(5);
  s1[0] = 0;
  s1[1] = 1;
  s1[2] = 2;
  s1[3] = 3;
  s1[4] = 4;

  // teste float * series
  Series s2 = 2 * s1;

  if (s2[0] != 0) passed = false;
  if (s2[1] != 2) passed = false;
  if (s2[2] != 4) passed = false;
  if (s2[3] != 6) passed = false;
  if (s2[4] != 8) passed = false;

  // test series * float
  Series s3 = s1 * 2;

  for (int i=0; i < s3.len(); i++) {
    if (s3[i] != s2[i]) passed = false;
  }

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
    std::cerr << "ERROR: at 'series_float_multiplication' | series_float_multiplication data with discrepancy\n";
  }
  ofile << "result: " << s2.repr() << "\n\n";

  
  return passed;
}

void series_multiplication_tests(std::ofstream &ofile) {
  bool passed = true;
  ofile << "\n=== SERIES MULTIPLICATION TESTS ===\n\n";

  passed = passed && series_series_multiplication(ofile);
  passed = passed && series_float_multiplication(ofile);


  if (passed) {
    std::cout << "PASSED SERIES MULTIPLICATION TESTS" << std::endl;
  }
}

// === DIVISION TESTS ===
bool series_series_division(std::ofstream &ofile) {
  bool passed = true;

  ofile << "series series division test: ";
  Series s1 = Series(5);
  s1[0] = 0;
  s1[1] = 1;
  s1[2] = 2;
  s1[3] = 3;
  s1[4] = 4;

  Series s2 = Series(5);
  s2[0] = 5;
  s2[1] = 6;
  s2[2] = 7;
  s2[3] = 8;
  s2[4] = 9;

  Series s3 = s1 / s2;
  
  if (s3[0] != 0) passed = false;
  if (s3[1] != (float) 1 / 6) passed = false;
  if (s3[2] != (float) 2 / 7) passed = false;
  if (s3[3] != (float) 3 / 8) passed = false;
  if (s3[4] != (float) 4 / 9) passed = false;

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
    std::cerr << "ERROR: at 'series_series_division' | series_series_division data with discrepancy\n";
  }
  ofile << "result: " << s3.repr() << "\n\n";

  
  return passed;

}

bool series_float_division(std::ofstream &ofile) {
  bool passed = true;

  ofile << "series float division test: ";
  Series s1 = Series(5);
  s1[0] = 0;
  s1[1] = 1;
  s1[2] = 2;
  s1[3] = 3;
  s1[4] = 4;

  // teste float * series
  Series s2 = s1 / 2;

  if (s2[0] != 0) passed = false;
  if (s2[1] != 0.5) passed = false;
  if (s2[2] != 1) passed = false;
  if (s2[3] != 1.5) passed = false;
  if (s2[4] != 2) passed = false;

  if (passed) {
    ofile << "OK\n";
  } else {
    ofile << "Failed\n";
    std::cerr << "ERROR: at 'series_float_division' | series_float_division data with discrepancy\n";
  }
  ofile << "result: " << s2.repr() << "\n\n";

  
  return passed;
}

void series_division_tests(std::ofstream &ofile) {
  bool passed = true;
  ofile << "\n=== SERIES DIVISION TESTS ===\n\n";

  passed = passed && series_series_division(ofile);
  passed = passed && series_float_division(ofile);


  if (passed) {
    std::cout << "PASSED SERIES DIVISION TESTS" << std::endl;
  }
}


int main() {
  // filepath
  const char* filepath = "test_series.txt"; 
  std::ofstream ofile(filepath);
  
  // run tests
  series_creation_tests(ofile);
  get_set_tests(ofile);
  series_addition_tests(ofile);
  series_subtraction_tests(ofile);
  series_multiplication_tests(ofile);
  series_division_tests(ofile);
  
  // log file console indication
  std::cout << "=== tests log file written to " << filepath << " ===\n";
}