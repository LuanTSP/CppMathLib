cmake_minimum_required(VERSION 3.31.6)
project(cppmathlib)
add_library(cppmath src/matrix.cpp src/series.cpp)
set_target_properties(cppmath PROPERTIES PUBLIC_HEADER cppmath.hpp)
target_include_directories(cppmath PUBLIC include/)
install(
  TARGETS cppmath 
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)