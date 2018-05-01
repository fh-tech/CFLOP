//
// Created by vik on 30.04.18.
//

#include <gtest/gtest.h>
#include "../include/dispatch.h"

//TODO: improve tests

using namespace input_lib;
using namespace output_lib;

TEST(dispatch, test_dispatch_nodes_post){
    fsm::FinalStateMachine fsm{};
    Request nodes_post_req(NODES_POST, NODE, POST, nodes_post_s{});

    Response r = dispatch_lib::dispatch(nodes_post_req, fsm);
    nodes_post_r_s struc = std::get<nodes_post_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_POST);
    ASSERT_TRUE(struc.id != 0);
}

TEST(dispatch, test_dispatch_nodes_delete){
    fsm::FinalStateMachine fsm{};
    fsm.add_state(); // insert node with id 1

    Request nodes_delete_req(NODES_DELETE, NODE, DELETE, nodes_delete_s{1});

    Response r = dispatch_lib::dispatch(nodes_delete_req, fsm);
    nodes_delete_r_s struc = std::get<nodes_delete_r_s>(r.response);
    ASSERT_EQ(r.type, NODES_DELETE);

    //should be gone
    auto node_deleted = fsm.get_state(1);
    ASSERT_EQ(node_deleted, nullptr);
}

TEST(dispatch, test_dispatch_nodes_get){
    fsm::FinalStateMachine fsm{};
    fsm.add_state(); // insert node with id 1

    Request nodes_get_req(NODES_GET, NODE, GET, nodes_get_s{1});

    Response r = dispatch_lib::dispatch(nodes_get_req, fsm);
    nodes_get_r_s struc = std::get<nodes_get_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_GET);
    ASSERT_EQ(struc.id, 1);
    ASSERT_EQ(struc.edges.size(), 0);
}
TEST(dispatch, test_dispatch_nodes_put_start){
    fsm::FinalStateMachine fsm{};
    fsm.add_state();

    Request nodes_put_start_req(NODES_PUT_START, NODE, PUT, nodes_put_start_s{1});

    Response r = dispatch_lib::dispatch(nodes_put_start_req, fsm);
    nodes_put_start_r_s struc = std::get<nodes_put_start_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_PUT_START);

    // is the node now start?
    auto node_start = fsm.get_start();
    ASSERT_EQ(1, node_start);
}

TEST(dispatch, test_dispatch_nodes_put_end){
    fsm::FinalStateMachine fsm{};
    Request nodes_put_end_req(NODES_PUT_END, NODE, PUT, nodes_put_end_s{1});

    Response r = dispatch_lib::dispatch(nodes_put_end_req, fsm);
    nodes_put_end_r_s struc = std::get<nodes_put_end_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_PUT_END);

    //is the node now end?
    auto node_end = fsm.get_end();
    ASSERT_EQ(1, node_end);
}

