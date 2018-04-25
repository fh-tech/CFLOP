//
// Created by vik on 25.04.18.
//

#include <gtest/gtest.h>
#include <input.h>
#include "json_requests.h"

TEST(make_req_type, req_type_nodes) {
    std::array<req_type,5> results = {NODES_POST, NODES_DELETE, NODES_GET, NODES_PUT_START, NODES_PUT_END};
    for(int i = 0; i < nodes_j_vec.size(); i++) {
        req_type type = make_req_type(nodes_j_vec[i]);
        ASSERT_EQ(type, results[i]);
    }
}

TEST(make_req_type, req_type_edges) {
    std::array<req_type,3> results = {EDGES_GET, EDGES_POST, EDGES_DELETE};
    for(int i = 0; i < edges_j_vec.size(); i++) {
        req_type type = make_req_type(edges_j_vec[i]);
        ASSERT_EQ(type, results[i]);
    }
}

TEST(make_req_type, req_type_state) {
    std::array<req_type,3> results = {STATE_GET, STATE_POST, STATE_PUT};
    for(int i = 0; i < state_j_vec.size(); i++) {
        req_type type = make_req_type(state_j_vec[i]);
        ASSERT_EQ(type, results[i]);
    }
}