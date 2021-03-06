#include <gtest/gtest.h>

#include "input.h"
#include "json_requests.h"

using namespace input_lib;

TEST(extract_helper, extract_all_fromEdge) {
    std::array<endpoint, 3> endpoint_results = {EDGE, EDGE, EDGE};
    std::array<std::string, 3> conversion_results = {"edges", "edges", "edges"};
    std::array<req_method, 3> type_results = {GET, POST, DELETE};

    for(int i = 0; i < endpoint_results.size(); i++) {
        const endpoint e = extract_endpoint(edges_j_vec[i]);
        ASSERT_EQ(e, endpoint_results[i]);
        ASSERT_EQ(convert_endpoint(e), conversion_results[i]);
        ASSERT_EQ(extract_req_method(edges_j_vec[i], e), type_results[i]);
    }
}

TEST(convert_endpoint, convert_edge) {
    const endpoint e = EDGE;
    ASSERT_EQ("edges", convert_endpoint(e));
}