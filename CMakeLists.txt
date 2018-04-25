cmake_minimum_required(VERSION 3.9)
project(CFLOP)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/json/include)

add_executable(CFLOP main.cpp input-interface/Request.h input-interface/extract_helper.h input-interface/request_types.h input-interface/extract_helper.h)

add_executable(run_tests test/test.cpp test/json_lohmann_test.cpp test/node_test.cpp test/edge_test.cpp test/state_test.cpp)

target_link_libraries(run_tests gtest gtest_main)