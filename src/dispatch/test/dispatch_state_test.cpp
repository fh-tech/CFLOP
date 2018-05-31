//
// Created by vik on 01.05.18.
//

#include <gtest/gtest.h>
#include "../include/dispatch.h"

using namespace input_lib;
using namespace output_lib;

TEST(dispatch, test_dispatch_state_get){
    fsm::FinalStateMachine fsm{};
    fsm.add_state(); // insert node with id 1
    fsm.add_state(); // insert node with id 2
    Request state_get_req(STATE_GET, STATE, GET, state_get_s{});

    Response r = dispatch_lib::dispatch(state_get_req, fsm);
    state_get_r_s struc = std::get<state_get_r_s>(r.response);

    ASSERT_EQ(r.type, STATE_GET);
    ASSERT_EQ(2, struc.nodes.size());
    ASSERT_EQ(0, struc.edges.size());
    ASSERT_EQ(0, struc.active);
    ASSERT_EQ(0, struc.start);
    ASSERT_EQ(0, struc.end);
}

TEST(dispatch, test_dispatch_state_post){
    fsm::FinalStateMachine fsm{};

    //two nodes that are connected with each other
    node n{1, std::vector<size_t>{1}};
    node n2{2, std::vector<size_t>{1}};
    //the edge that connects them
    edge e{1, 1, 2, "a"};

    Request state_post_req(STATE_POST, STATE, POST, state_post_s{
            std::vector<node>{n, n2},
            std::vector<edge>{e},
            1,
            1,
            2
    });

    Response r = dispatch_lib::dispatch(state_post_req, fsm);
    state_post_r_s struc = std::get<state_post_r_s>(r.response);
    ASSERT_EQ(r.type, STATE_POST);

    // check if start = 1 and end = 2;
    size_t start = fsm.get_start();
    size_t end = fsm.get_end();
    ASSERT_EQ(1, start);
    ASSERT_EQ(2, end);

    auto transitions = fsm.get_adjacient_transitions(1);
    ASSERT_EQ(transitions.size(), 1);
}


TEST(dispatch, test_dispatch_state_put){
    fsm::FinalStateMachine fsm{};
    fsm.add_state(); // insert node with id 1
    fsm.add_state(); // insert node with id 2
    fsm.add_transition(1,2, fsm::Transition<std::string>::from("a")); // edge with id 1

    Request state_put_req(STATE_PUT, STATE, PUT, state_put_s{"a"});

    Response r = dispatch_lib::dispatch(state_put_req, fsm);
    state_put_r_s struc = std::get<state_put_r_s>(r.response);

    ASSERT_EQ(r.type, STATE_PUT);
    //no node was set active so id: 0 should be returned
    ASSERT_EQ(0, struc.id);
}

TEST(dispatch, test_dispatch_state_put2){
    fsm::FinalStateMachine fsm{};
    fsm.add_state(); // insert node with id 1
    fsm.add_state(); // insert node with id 2
    fsm.add_transition(1,2, fsm::Transition<std::string>::from("a")); // edge with id 1
    fsm.set_start(1);

    Request state_put_req(STATE_PUT, STATE, PUT, state_put_s{"a"});

    Response r = dispatch_lib::dispatch(state_put_req, fsm);
    state_put_r_s struc = std::get<state_put_r_s>(r.response);

    ASSERT_EQ(r.type, STATE_PUT);
    //node 1 set active so transition to node 2
    ASSERT_EQ(2, struc.id);
}
