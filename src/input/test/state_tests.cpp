//
// Created by vik on 24.04.18.
//

#include <gtest/gtest.h>
#include <input.h>
#include "json_requests.h"


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