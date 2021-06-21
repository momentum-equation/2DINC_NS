# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.
set(PROJECT_INCLUDE_DIR "${2DINC_NS_SOURCE_DIR}/include")

set(THIRDPARTY_DIR "${2DINC_NS_SOURCE_DIR}/thirdparty")

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_INCLUDE_DIR}/MeshGenerator/MeshGenerator.h")

file(GLOB GMSH_HEADERS CONFIGURE_DEPENDS "{THIRDPARTY_DIR}/gmsh/api/gmsh.h")

# Make an automatic library - will be static or dynamic based on user setting
add_library(MeshGenerator SHARED MeshGenerator.cpp ${HEADER_LIST} ${GMSH_HEADERS})

# We need this directory, and users of our library will need it too
target_include_directories(MeshGenerator PUBLIC ${PROJECT_INCLUDE_DIR} ${THIRDPARTY_DIR})
target_link_directories(MeshGenerator PUBLIC "${THIRDPARTY_DIR}/gmsh/build")

target_link_libraries(MeshGenerator PUBLIC gmsh.so)

# All users of this library will need at least C++11
target_compile_features(MeshGenerator PUBLIC cxx_std_17)