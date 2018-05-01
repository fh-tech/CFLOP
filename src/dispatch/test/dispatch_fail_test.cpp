//
// Created by vik on 01.05.18.
//

#include <gtest/gtest.h>
#include "../include/dispatch.h"

#include <gtest/gtest.h>
#include "../include/dispatch.h"

using namespace input_lib;
using namespace output_lib;

// should produce invalid_type response -- nodes do not exist
TEST(dispatch, test_dispatch_fail_edge_post){
    fsm::FinalStateMachine fsm{};
    Request failure_req(EDGES_POST, EDGE, POST, edges_post_s{1, 2, "a"});

    Response r = dispatch_lib::dispatch(failure_req, fsm);
    failure_r_s struc = std::get<failure_r_s>(r.response);

    ASSERT_EQ(r.type, INVALID_TYPE);
    //id should be 0 because tried to post edge between two non-existent nodes
    std::cout << struc.failure << std::endl;
    std::string expected = "Something went wrong... one of the nodes does not exists";
    ASSERT_EQ(struc.failure, expected);
}

// should produce invalid_type response -- node to get does not exist
TEST(dispatch, test_dispatch_fail_nodes_get){
    fsm::FinalStateMachine fsm{};
    Request failure_req(NODES_GET, NODE, GET, nodes_get_s{1});

    Response r = dispatch_lib::dispatch(failure_req, fsm);
    failure_r_s struc = std::get<failure_r_s>(r.response);

    ASSERT_EQ(r.type, INVALID_TYPE);
    // tried to get id that is non existent
    std::string expected = "Node with requested id does not exist";
    ASSERT_EQ(struc.failure, expected);
}
