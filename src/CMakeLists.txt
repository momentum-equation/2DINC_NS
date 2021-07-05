set(PROJECT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# use thirdparty packages from src
set(THIRDPARTY_DIR "${CMAKE_SOURCE_DIR}/thirdParty/")
set(BLITZ_INC "${THIRDPARTY_DIR}/blitz/")

include_directories("${BLITZ_INC}")

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_INCLUDE_DIR}/MeshGenerator/MeshGenerator.h")
file(GLOB GMSH_HEADERS CONFIGURE_DEPENDS "${THIRDPARTY_DIR}/gmsh/api/gmsh.h")

add_library(MeshGenerator SHARED MeshGenerator.cpp ${HEADER_LIST} ${GMSH_HEADERS})
target_compile_features(MeshGenerator PUBLIC cxx_std_17)
target_include_directories(MeshGenerator PUBLIC ${PROJECT_INCLUDE_DIR} ${THIRDPARTY_DIR})
target_link_directories(MeshGenerator PUBLIC "${THIRDPARTY_DIR}/gmsh/build")
target_link_libraries(MeshGenerator PUBLIC gmsh.so)

add_library(Point SHARED Point.cpp "${PROJECT_INCLUDE_DIR}/Geometry/Point.h")
target_compile_features(Point PUBLIC cxx_std_17)
target_include_directories(Point PUBLIC ${PROJECT_INCLUDE_DIR})
target_link_libraries(Point PUBLIC blitz.so)
