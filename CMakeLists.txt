cmake_minimum_required(VERSION 3.6)
project(OwnSortingAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES NSort.cpp NSort.h)
add_library(OwnSortingAlgorithm ${SOURCE_FILES})