cmake_minimum_required(VERSION 3.0)
project(CFLOP)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_executable(CFLOP
        src/main.cpp)

add_library(graph-lib
        src/graph/include/graph.h
        src/graph/Graph.h
        src/graph/Node.h
        src/graph/Node.cpp
        src/graph/Edge.h
        src/graph/Edge.cpp)

add_library(fsm-lib
        src/fsm/include/fsm.h
        src/fsm/State.h
        src/fsm/Transition.h
        src/fsm/FinalStateMachine.h)
target_link_libraries(fsm-lib graph-lib)

add_library(input-lib
        src/input/include/input.h
        src/input/Request.h
        src/input/extract_helper.h
        src/input/request_types.h
        src/output/include/output.h)

add_library(output-lib
        src/output/include/output.h
        src/output/response_types.h
        src/output/Response.h)

add_library(dispatch-lib
        src/dispatch/include/dispatch.h
        src/dispatch/dispatcher.h src/dispatch/dispatch.cpp)
target_link_libraries(dispatch-lib input-lib output-lib fsm-lib graph-lib)

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
add_test(NAME graphlib-unittests COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/graphlib-tests)


add_executable(fsmlib-tests
        src/fsm/tests/tests.cpp)
target_link_libraries(fsmlib-tests gtest fsm-lib)
add_test(NAME fsmlib-unittests COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/fsmlib-tests)

add_executable(inputlib-tests
                src/input/test/tests.cpp
                src/input/test/edge_test.cpp
                src/input/test/json_lohmann_test.cpp
                src/input/test/node_test.cpp
                src/input/test/state_tests.cpp
                src/input/test/json_requests.cpp
                src/input/test/req_type_test.cpp
                src/input/test/request_test.cpp
                src/output/include/output.h)
target_link_libraries(inputlib-tests gtest input-lib)

add_test(NAME inputlib-unittests COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/inputlib-tests)


add_executable(outputlib-tests
            src/output/tests/tests.cpp
            src/output/tests/to_json_nodes.cpp
            src/output/tests/to_json_state.cpp
            src/output/tests/to_json_edge.cpp
            src/output/tests/to_json_fail.cpp)
target_link_libraries(outputlib-tests gtest output-lib)

add_test(NAME outputlib-unittests COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/outputlib-tests)

add_executable(dispatchlib-tests
            src/dispatch/test/tests.cpp
            src/dispatch/test/dispatch_node_test.cpp
            src/dispatch/test/dispatch_edge_test.cpp
            src/dispatch/test/dispatch_state_test.cpp
            src/dispatch/test/dispatch_fail_test.cpp)

add_test(NAME dispatchlib-unittests COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/dispatchlib-tests)

target_link_libraries(dispatchlib-tests gtest dispatch-lib)

