//
// Created by vik on 30.04.18.
//

#include <gtest/gtest.h>
#include "../include/dispatch.h"

//TODO: improve tests

TEST(dispatch, test_dispatch_nodes_post){
    FinalStateMachine fsm{};
    Request nodes_post_req(NODES_POST, NODE, POST, nodes_post_s{});

    Response r = dispatch(nodes_post_req, fsm);
    nodes_post_r_s struc = std::get<nodes_post_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_POST);
    ASSERT_TRUE(struc.id != NULL);
}

TEST(dispatch, test_dispatch_nodes_delete){
    FinalStateMachine fsm{};
    Request nodes_get_req(NODES_GET, NODE, GET, nodes_get_s{1});

    Response r = dispatch(nodes_get_req, fsm);
    nodes_delete_r_s struc = std::get<nodes_delete_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_DELETE)
}

TEST(dispatch, test_dispatch_nodes_get){
    FinalStateMachine fsm{};
    Request nodes_delete_req(NODES_DELETE, NODE, DELETE, nodes_delete_s{1});

    Response r = dispatch(nodes_delete_req, fsm);
    nodes_get_r_s struc = std::get<nodes_get_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_GET);
}
TEST(dispatch, test_dispatch_nodes_put_start){
    FinalStateMachine fsm{};
    Request nodes_put_start_req(NODES_PUT_END, NODE, PUT, nodes_put_end_s{1});

    Response r = dispatch(nodes_put_start_req, fsm);
    nodes_put_start_r_s struc = std::get<nodes_put_start_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_PUT_START);
}

TEST(dispatch, test_dispatch_nodes_put_end){
    FinalStateMachine fsm{};
    Request nodes_put_end_req(NODES_PUT_START, NODE, PUT, nodes_put_end_s{1});

    Response r = dispatch(nodes_put_end_req, fsm);
    nodes_put_end_r_s struc = std::get<nodes_put_end_r_s>(r.response);

    ASSERT_EQ(r.type, NODES_PUT_END);
}

