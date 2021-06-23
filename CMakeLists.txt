# Works with 3.11 and tested through 3.20
cmake_minimum_required(VERSION 3.11)

# Project name and a few useful settings. Other commands can pick up the results
project(
  2DINC_NS
  VERSION 0.1
  DESCRIPTION "Noob's 2D Incompressible CFD Solver. :)"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTING "Build tests for this project" ON)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(doc)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()

endif()

add_subdirectory(include)

# The compiled library code is here
add_subdirectory(src)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(test)
endif()
