set(GCC_CXX_FLAGS "-fPIC")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_library(TESTING_LIBRARIES NAMES gtest gmock)

set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(TESTMAIN "${TEST_DIR}/TestMain.cpp")

function(CREATE_TEST _TEST_FILE_LIST _SOURCE_LIBRARY_LIST _TEST_LIB_NAME)
    set(SOURCES ${_TEST_FILE_LIST})
    set(SOURCE_LIBS ${_SOURCE_LIBRARY_LIST})

    set(TEST_LIB_TO_CREATE "${_TEST_LIB_NAME}Lib")
    add_library(${TEST_LIB_TO_CREATE} SHARED ${SOURCES})
    add_dependencies(${TEST_LIB_TO_CREATE} ${SOURCE_LIBS})
    target_link_libraries(${TEST_LIB_TO_CREATE} PUBLIC ${SOURCE_LIBS} ${TESTING_LIBRARIES} Threads::Threads)

    set(TEST_EXE_TO_CREATE "${_TEST_LIB_NAME}Out")
    add_executable(${TEST_EXE_TO_CREATE} ${TESTMAIN})
    add_dependencies(${TEST_EXE_TO_CREATE} ${TEST_LIB_TO_CREATE})
    target_link_libraries(${TEST_EXE_TO_CREATE} PRIVATE ${TEST_LIB_TO_CREATE})

    add_test(NAME ${TEST_EXE_TO_CREATE} COMMAND ${TEST_EXE_TO_CREATE})

endfunction()

add_subdirectory(Point)
add_subdirectory(MeshGenerator)