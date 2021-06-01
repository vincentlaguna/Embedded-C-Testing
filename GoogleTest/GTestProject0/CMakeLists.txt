cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

#add_library(commonLibrary LibraryCode.cpp)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")

#set(GMOCK_LIBRARIES /usr/lib/libgmock.a  /usr/lib/libgmock_main.a)

#add_executable(mainApp main.cpp)
#target_link_libraries(mainApp commonLibrary)

#add_executable(testRunner testRunner.cpp)
add_executable(myExecutable main.cpp)
#target_link_libraries(testRunner commonLibrary ${GTEST_LIBRARIES} pthread)
target_link_libraries(myExecutable ${GTEST_LIBRARIES} pthread)
