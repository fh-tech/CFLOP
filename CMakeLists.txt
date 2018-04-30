cmake_minimum_required(VERSION 3.9)
project(CFLOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(CFLOP
        src/main.cpp)

add_library(graph-lib
        src/graph/include/graph.h
        src/graph/Node.h
        src/graph/Edge.h
        src/graph/Graph.h)

add_library(fsm-lib
        src/fsm/include/fsm.h
        src/fsm/State.h
        src/fsm/Transition.h
        src/fsm/FinalStateMachine.h)

add_library(input-lib
        src/input/include/input.h
        src/input/Request.h
        src/input/extract_helper.h
        src/input/request_types.h src/output/include/output.h)

add_library(output-lib
        src/output/include/output.h
        src/output/response_types.h
        src/output/tests/json_response.cpp)

add_library(dispatch-lib
        src/dispatch/include/dispatch.h
        src/dispatch/dispatcher.h)

include_directories(src/graph/include)
include_directories(src/fsm/include)
include_directories(src/input/include)
include_directories(src/output/include)
include_directories(src/dispatch/include)

set_target_properties(graph-lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(fsm-lib   PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(input-lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(output-lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(dispatch-lib PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(CFLOP graph-lib fsm-lib input-lib output-lib dispatch-lib)

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
                src/input/test/state_tests.cpp
                src/input/test/json_requests.cpp
                src/input/test/req_type_test.cpp
                src/input/test/request_test.cpp src/output/include/output.h)
target_link_libraries(inputlib-tests gtest input-lib)

add_executable(outputlib-tests
            src/output/tests/tests.cpp
            src/output/tests/json_response.cpp
            src/input/test/json_requests.cpp src/output/tests/to_json_test.cpp)
target_link_libraries(outputlib-tests gtest output-lib)

add_executable(dispatchlib-tests
            src/dispatch/test/tests.cpp
            src/dispatch/test/dispatch_test.cpp
            src/dispatch/test/requests.cpp)
target_link_libraries(dispatchlib-tests gtest output-lib)
