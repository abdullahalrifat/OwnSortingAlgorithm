cmake_minimum_required(VERSION 3.6)
project(OwnSortingAlgorithm)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES NSort.cpp NSort.h)
add_library(OwnSortingAlgorithm ${SOURCE_FILES})

enable_testing()
add_executable(OwnSortingAlgorithmTests tests/sort_test.cpp)
target_link_libraries(OwnSortingAlgorithmTests OwnSortingAlgorithm)
add_test(NAME OwnSortingAlgorithmTests COMMAND OwnSortingAlgorithmTests)
