//
// Created by vik on 25.04.18.
//

#include <gtest/gtest.h>
#include <input.h>
#include "json_requests.h"

using namespace input_lib;

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

TEST(make_req_type, invalid_json) {
    json j =
            R"({
              "state": {
                "delete": {
                  "id": 0
                }
              }
            })"_json;
    endpoint e = extract_endpoint(j);
    ASSERT_EQ(STATE, e);

    req_method method = extract_req_method(j, e);
    ASSERT_EQ(method, DELETE);

    req_type type = make_req_type(j);
    ASSERT_EQ(type, INVALID_TYPE);
}
