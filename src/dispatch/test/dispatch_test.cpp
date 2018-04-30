//
// Created by vik on 30.04.18.
//

#include <gtest/gtest.h>
#include "../include/dispatch.h"
#include "requests.h"

//TODO: respone umbauen und alle testen

// tests all nodes end to end
TEST(dispatch, test_dispatch_nodes) {
    FinalStateMachine fsm();
    std::vector<Response> expected;
    for(int i = 0; i < nodes_req_vec.size(); i++) {
        json j = dispatch(nodes_req_vec[i], fsm);
    }
}