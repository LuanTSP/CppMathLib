cmake_minimum_required(VERSION 3.14)
project(cppmathlib VERSION 1.0.0)

include(GNUInstallDirs)

add_library(luan SHARED
  src/matrix.cpp
  src/series.cpp
)

# Set target include directories
target_include_directories(luan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include>)

set_target_properties(luan PROPERTIES
  PUBLIC_HEADER 
  "include/luan/list.hpp;
  include/luan/matrix.hpp;
  include/luan/series.hpp;
  include/luan/tree.hpp"
)

install(TARGETS luan
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/luan
)