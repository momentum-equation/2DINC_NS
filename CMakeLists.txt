# Works with 3.11 and tested through 3.20
cmake_minimum_required(VERSION 3.11)

# Project name and a few useful settings. Other commands can pick up the results
project(
  2DINC_NS
  VERSION 0.1
  DESCRIPTION "Noob's 2D Incompressible CFD Solver. :)"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-fPIC)

option(BUILD_TESTING "Build tests" ON)
option(BUILD_DOC "Build documentation" OFF)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)

  find_package(Doxygen)
  if(BUILD_DOC)
      if(Doxygen_FOUND)
    
    set(DOXYGEN_IN doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")
    
    add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

  else()
    message(STATUS "Doxygen not found, not building docs")
     endif()
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
