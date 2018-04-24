cmake_minimum_required(VERSION 3.9)
project(CFLOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(CFLOP
        src/main.cpp)

add_library(graph-lib
        src/graph/include/graph.h
        src/graph/Node.h
        src/graph/Edge.h
        src/graph/Graph.h
        )

set_target_properties(graph-lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(fsm-lib PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(CFLOP graph-lib)

##########################################################
add_subdirectory(libs/googletest/googletest)
include_directories(${gtest_include_dir})
##########################################################

add_executable(graphlib-tests
        src/graph/tests/test.cpp)
target_link_libraries(graphlib-tests gtest graph-lib)

target_link_libraries(graphlib-tests gtest)

target_link_libraries(graphlib-tests graph-lib)
