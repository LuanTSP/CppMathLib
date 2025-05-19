cmake_minimum_required(VERSION 3.31.6)
project(cppmathlib)
add_library(cppmath STATIC src/matrix.cpp src/series.cpp)
set_target_properties(cppmath PROPERTIES PUBLIC_HEADER
  include/matrix.hpp
)
target_include_directories(cppmath PUBLIC ${CMAKE_SOURCE_DIR}/include/)
install(
  TARGETS cppmath 
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)