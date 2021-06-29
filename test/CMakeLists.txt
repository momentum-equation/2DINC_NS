set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_library(TESTING_LIBRARIES NAMES gtest gmock)

set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(TESTMAIN "${TEST_DIR}/TestMain.cpp")

function(CREATE_TEST _TEST_FILE_LIST _SOURCE_LIBRARY_LIST _TEST_LIB_NAME)
    set(SRC_FILES ${_TEST_FILE_LIST})
    set(SRC_LIBS ${_SOURCE_LIBRARY_LIST})

    set(TEST_LIB "${_TEST_LIB_NAME}Lib")
    add_library(${TEST_LIB} SHARED ${SRC_FILES})
    add_dependencies(${TEST_LIB} ${SRC_LIBS})
    target_link_libraries(${TEST_LIB} PUBLIC ${SRC_LIBS} ${TESTING_LIBRARIES} Threads::Threads)

    set(TEST_EXE "${_TEST_LIB_NAME}Out")
    add_executable(${TEST_EXE} ${TESTMAIN})
    add_dependencies(${TEST_EXE} ${TEST_LIB})
    target_link_libraries(${TEST_EXE} PRIVATE ${TEST_LIB})

    add_test(NAME ${TEST_EXE} COMMAND ${TEST_EXE})

endfunction()

add_subdirectory(Point)
add_subdirectory(MeshGenerator)