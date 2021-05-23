cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

add_library(commonLibrary LibraryCode.cpp)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")

add_executable(mainApp main.cpp)
target_link_libraries(mainApp commonLibrary)

add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner commonLibrary ${GTEST_LIBRARIES} pthread)
