cmake_minimum_required(VERSION 3.10)
project(MultithreadingHomework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(DEBUG_LEVEL "Set the debug level" 0)

# Enable testing
enable_testing()

# Set compiler flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -DDEBUG_LEVEL=${DEBUG_LEVEL}")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DDEBUG_LEVEL=${DEBUG_LEVEL}")
endif()

# Define source and test directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include("cmake/gtest_config.cmake")
include("cmake/openmp_config.cmake")

# Test executables
add_executable(test_inner_product ${TEST_DIR}/test_inner_product.cpp)
target_include_directories(test_inner_product PRIVATE
    ${GTEST_INCLUDE_DIRS}
    ${SRC_DIR}
)
target_link_libraries(test_inner_product PRIVATE
    ${GTEST_LIBRARIES}
    gtest_main
    pthread
    OpenMP::OpenMP_CXX
)
add_test(NAME InnerProductTest COMMAND test_inner_product)

add_executable(test_inclusive_scan ${TEST_DIR}/test_inclusive_scan.cpp)
target_include_directories(test_inclusive_scan PRIVATE
    ${GTEST_INCLUDE_DIRS}
    ${SRC_DIR}
)
target_link_libraries(test_inclusive_scan PRIVATE
    ${GTEST_LIBRARIES}
    gtest_main
    pthread
    OpenMP::OpenMP_CXX
)
add_test(NAME InclusiveScanTest COMMAND test_inclusive_scan)
