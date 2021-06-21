# Tests need to be added as executables first

set(THIRDPARTY_DIR "${2DINC_NS_SOURCE_DIR}/thirdparty")

file(GLOB GMSH_HEADERS CONFIGURE_DEPENDS "{THIRDPARTY_DIR}/gmsh/api/gmsh.h")

add_executable(MeshGeneratorTest MeshGenerator_test.cpp ${GMSH_HEADERS})

# I'm using C++17 in the test
target_compile_features(MeshGeneratorTest PRIVATE cxx_std_17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_library(TESTING_LIBRARIES NAMES gtest gmock)

# MeshGenerator will compile before MeshGeneratorTest
add_dependencies(MeshGeneratorTest MeshGenerator)
target_link_libraries(MeshGeneratorTest MeshGenerator ${TESTING_LIBRARIES} Threads::Threads)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME MeshGeneratorTest COMMAND MeshGeneratorTest) # Command can be a target