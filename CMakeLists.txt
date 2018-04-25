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

add_library(fsm-lib
        src/fsm/include/fsm.h
        src/fsm/State.h
        src/fsm/Transition.h
        src/fsm/FinalStateMachine.h)

add_library(input-lib
        src/input/include/input.h
        src/input/Request.h
        src/input/extract_helper.h
        src/input/request_types.h)

include_directories(src/graph/include)
include_directories(src/fsm/include)
include_directories(src/input/include)

set_target_properties(graph-lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(fsm-lib   PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(input-lib PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(CFLOP graph-lib fsm-lib input-lib)

##########################################################
add_subdirectory(libs/googletest/googletest)
include_directories(${gtest_include_dir})
##########################################################

add_executable(graphlib-tests
        src/graph/tests/test.cpp)
target_link_libraries(graphlib-tests gtest graph-lib)

add_executable(fsmlib-tests
        src/fsm/tests/tests.cpp)
target_link_libraries(fsmlib-tests gtest fsm-lib)

add_executable(inputlib-tests
                src/input/test/tests.cpp
                src/input/test/edge_test.cpp
                src/input/test/json_lohmann_test.cpp
                src/input/test/node_test.cpp
                src/input/test/state_tests.cpp)

target_link_libraries(inputlib-tests gtest input-lib)
