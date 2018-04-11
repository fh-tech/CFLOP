cmake_minimum_required(VERSION 3.9)
project(CFLOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "clang++")

add_executable(CFLOP
        src/main.cpp)

add_library(graph-lib
        src/graph/include
        src/graph/Node.h
        src/graph/Edge.h
        src/graph/Graph.h
        )

set_target_properties(graph-lib PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(CFLOP graph-lib)

##########################################################
include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
        BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )

##########################################################

add_executable(graphlib-tests
        src/graph/tests/test.cpp)

target_link_libraries(graphlib-tests gtest)

target_link_libraries(graphlib-tests graph-lib)
