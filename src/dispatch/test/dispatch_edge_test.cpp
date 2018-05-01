//
// Created by vik on 01.05.18.
//

#include <gtest/gtest.h>
#include "../include/dispatch.h"

using namespace input_lib;
using namespace output_lib;

TEST(dispatch, test_dispatch_edges_post){
    fsm::FinalStateMachine fsm{};
    Request edges_post_req(EDGES_POST, EDGE, POST, edges_post_s{1, 2, "a"});

    Response r = dispatch_lib::dispatch(edges_post_req, fsm);


    //if a user tries to connect to non existing nodes the request is invalid
    ASSERT_EQ(r.type, input_lib::INVALID_TYPE);
}

TEST(dispatch, test_dispatch_edges_post2){
    fsm::FinalStateMachine fsm{};
    fsm.add_state(); // insert node with id 1
    fsm.add_state(); // insert node with id 2
    Request edges_post_req(EDGES_POST, EDGE, POST, edges_post_s{1, 2, "a"});

    Response r = dispatch_lib::dispatch(edges_post_req, fsm);
    edges_post_r_s struc = std::get<edges_post_r_s>(r.response);

    ASSERT_EQ(r.type, EDGES_POST);
    ASSERT_EQ(1, struc.id);
}

TEST(dispatch, test_dispatch_edges_get){
    fsm::FinalStateMachine fsm{};
    fsm.add_state(); // insert node with id 1
    fsm.add_state(); // insert node with id 2
    fsm.add_transition(1,2, fsm::Transition<std::string>::from("a")); //edge with id 1

    Request edges_get_req(EDGES_GET, EDGE, GET, edges_get_s{1});

    Response r = dispatch_lib::dispatch(edges_get_req, fsm);
    edges_get_r_s struc = std::get<edges_get_r_s>(r.response);
    ASSERT_EQ(r.type, EDGES_GET);
    ASSERT_EQ(1, struc.id);

    auto edge_added = fsm.get_adjacient_transitions(1);
    ASSERT_EQ(edge_added.size(), 1);
}

TEST(dispatch, test_dispatch_edges_delete){
    fsm::FinalStateMachine fsm{};
    fsm.add_state(); // insert node with id 1
    fsm.add_state(); // insert node with id 2
    fsm.add_transition(1,2, fsm::Transition<std::string>::from("a")); // edge with id 1

    Request edges_delete_req(EDGES_DELETE, EDGE, DELETE, edges_delete_s{1});

    Response r = dispatch_lib::dispatch(edges_delete_req, fsm);
    edges_delete_r_s struc = std::get<edges_delete_r_s>(r.response);

    ASSERT_EQ(r.type, EDGES_DELETE);

    // check if nodes still here
    auto node_1 = fsm.get_state(1);
    auto node_2 = fsm.get_state(2);
    ASSERT_EQ(1, node_1->first);
    ASSERT_EQ(2, node_2->first);

    //check if edge really is gone
    auto edge_deleted = fsm.get_adjacient_transitions(1);
    ASSERT_EQ(edge_deleted.size(), 0);
}

