//
// Created by vik on 24.04.18.
// Tests all possible json inputs on the node library
//

#include <gtest/gtest.h>
#include <input.h>
#include "json_requests.h"

TEST(extract_endpoint_test, test1) {
    std::string input = "{\"nodes\":{\"put\":{\"start\":{\"id\": 0 }}}}";
    std::istringstream inputS;
    inputS.str(input);

    json j;
    inputS >> j;

    endpoint e = extract_endpoint(j);
    ASSERT_TRUE(e == NODE);
    ASSERT_FALSE(e == STATE);
}

TEST(extract_type, test1) {
    json j = nodes_j_vec[0];

    endpoint e = NODE;
    std::string endP_s = convert_endpoint(e);
    req_method type = extract_req_method(j, e);
    ASSERT_EQ(POST, type);
}

TEST(extract_helper, extract_all_fromNode) {
    std::array<endpoint, 5> endpoint_results = {NODE, NODE, NODE, NODE, NODE};
    std::array<std::string, 5> conversion_results = {"nodes", "nodes", "nodes", "nodes", "nodes"};
    std::array<req_method, 5> type_results = {POST, DELETE, GET, PUT, PUT};

    //for(int i = 0; i < endpoint_results.size(); i++) {
    //    endpoint e = extract_endpoint(nodes_j_vec[i]);
    //    ASSERT_EQ(e, endpoint_results[i]);
    //    ASSERT_EQ(convert_endpoint(e), conversion_results[i]);
    //    ASSERT_EQ(extract_req_method(nodes_j_vec[i], e), type_results[i]);
    //}
}
