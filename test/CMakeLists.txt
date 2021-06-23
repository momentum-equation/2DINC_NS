# Tests need to be added as executables first

set(THIRDPARTY_DIR "${2DINC_NS_SOURCE_DIR}/thirdparty")

file(GLOB GMSH_HEADERS CONFIGURE_DEPENDS "{THIRDPARTY_DIR}/gmsh/api/gmsh.h")

set(INCLUDE "${CMAKE_SOURCE_DIR}/include")

add_subdirectory(MeshGeneratorTests)
add_subdirectory(PrimitivesTests)

add_executable(MeshGeneratorTest MeshGenerator_test.cpp ${GMSH_HEADERS})
add_executable(PointTest Point_test.cpp "${INCLUDE}/Primitives/Point.h")

include_directories(${INCLUDE})

target_compile_features(MeshGeneratorTest PRIVATE cxx_std_17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_library(TESTING_LIBRARIES NAMES gtest gmock)

# MeshGenerator will compile before MeshGeneratorTest
add_dependencies(MeshGeneratorTest MeshGenerator)
target_link_libraries(MeshGeneratorTest MeshGenerator ${TESTING_LIBRARIES} Threads::Threads)
add_dependencies(PointTest Point)
target_link_libraries(PointTest Point ${TESTING_LIBRARIES} Threads::Threads)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME MeshGeneratorTest COMMAND MeshGeneratorTest) # Command can be a target
add_test(NAME PointTest COMMAND PointTest)

# test suite is a directory(executable) containing tests with related features
# file(s) (classes) to test are to be supplied as arguments to the function 
function(addTestSuite)
    set(filesToTest ARRAY_OF_FILES_TO_TEST)
    set(testSuiteName TEST_SUITE) 

    cmake_parse_arguments(addTestSuite_REQUIRED "{filesToTest}" "${testSuiteName}" ${ARGN})

    if(not exists ${testSuiteName})
        file(MAKE_DIRECTORY ${file})
    endif()

    if(NOT DEFINED addTestSuite_ARRAY_OF_FILES_TO_TEST)
        message(FATAL_ERROR "Error: Please supply at least one file")
    endif()

    file(GLOB SOURCES )

    foreach(FILE_TO_TEST ${filesToTest})
        
    endforeach()
    

endfunction()
