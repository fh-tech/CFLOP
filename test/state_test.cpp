//
// Created by vik on 24.04.18.
//

#include <gtest/gtest.h>
#include "../input-interface/extract_helper.h"

json state_get_j = "{\n"
"  \"state\":{\n"
"    \"get\":{}\n"
"  }\n"
"}"_json;

json state_post_j = "{\n"
        "  \"state\":{\n"
        "    \"post\":{\n"
        "      \"state\": {\n"
        "        \"nodes\": [\n"
        "          {\n"
        "            \"id\": 0,\n"
        "            \"edges\": [1,2,3]\n"
        "          }, {\n"
        "            \"id\": 1,\n"
        "            \"edges\": [1,3]\n"
        "          }\n"
        "        ],\n"
        "        \"edges\":[\n"
        "          {\n"
        "            \"id\": 1,\n"
        "            \"from\": 0,\n"
        "            \"to\": 1,\n"
        "          }\n"
        "        ],\n"
        "        \"active\": 1,\n"
        "        \"start\": 1,\n"
        "        \"end\": 0\n"
        "      }\n"
        "    }\n"
        "  }\n"
        "}"_json;

json state_put_j = "{\n"
        "  \"state\": {\n"
        "    \"put\": {\n"
        "      \"input\": \"a\"\n"
        "    }\n"
        "  }\n"
        "}"_json;

std::vector<json> state_j_vec = {state_get_j, state_post_j, state_put_j};

TEST(extract_helper, extract_all_fromState) {
    std::array<endpoint, 3> endpoint_results = {STATE, STATE, STATE};
    std::array<std::string, 3> conversion_results = {"state", "state", "state"};
    std::array<req_method, 3> type_results = {GET, POST, PUT};

    for(int i = 0; i < endpoint_results.size(); i++) {
        endpoint e = extract_endpoint(state_j_vec[i]);
        ASSERT_EQ(e, endpoint_results[i]);
        ASSERT_EQ(convert_endpoint(e), conversion_results[i]);
        ASSERT_EQ(extract_req_method(state_j_vec[i], e), type_results[i]);
    }
}