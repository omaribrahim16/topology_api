cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(topology_api)

add_subdirectory(include/jsoncpp)

add_executable (test src/test.cpp src/api.cpp)
target_link_libraries(test jsoncpp)



