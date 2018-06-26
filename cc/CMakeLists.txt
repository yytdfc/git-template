cmake_minimum_required(VERSION 3.9)
project(project_name)

set(CMAKE_CXX_STANDARD 14)

# set(CMAKE_VERBOSE_MAKEFILE ON)

add_definitions(-DDEFINE_SOMETHING)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--as-needed -Wl,-R/usr/local/lib -Wl,-R/usr/local/lib64")

include_directories(include src)
link_directories(.)

aux_source_directory(src SRC)

add_executable(main src/main.cc ${SRC})
target_link_libraries(main glog)

add_library(example SHARED ${SRC})
target_link_libraries(example glog)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
aux_source_directory(test      TEST)
enable_testing()
foreach(i ${TEST})
  STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" CASE_NAME ${i})
  message(STATUS "Test case : ${CASE_NAME} - ${i}")
  add_executable(${CASE_NAME} ${i})
  target_link_libraries(${CASE_NAME} gtest_main gtest pthread glog)
  add_test(${CASE_NAME} ${CASE_NAME})
endforeach(i)
