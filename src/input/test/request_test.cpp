//
// Created by vik on 25.04.18.
//

#include <gtest/gtest.h>
#include <input.h>
#include "json_requests.h"

TEST(construct_request, nodes) {
    std::vector<req_type> results{NODES_POST, NODES_DELETE, NODES_GET, NODES_PUT_START, NODES_PUT_END};

    for(int i = 0; i < nodes_j_vec.size(); i++) {
        Request r = nodes_j_vec[i];
        ASSERT_EQ(r.type, NODES_POST);
        ASSERT_EQ(r.ePoint, NODE);
        ASSERT_EQ(r.method, POST);
    }
}