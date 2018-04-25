#include <gtest/gtest.h>
#include "input.h"

json edges_get_j = "{\n"
                   "  \"edges\": {\n"
                   "    \"get\": {\n"
                   "      \"id\": 0\n"
                   "    }\n"
                   "  }\n"
                   "}"_json;

json edges_post_j = "{\n"
                    "  \"edges\":{\n"
                    "    \"post\":{\n"
                    "      \"to\": 1,\n"
                    "      \"from\": 2\n"
                    "    }\n"
                    "  }\n"
                    "}"_json;

json edges_delete_j = "{\n"
                      "  \"edges\": {\n"
                      "    \"delete\": {\n"
                      "      \"id\": 0\n"
                      "    }\n"
                      "  }\n"
                      "}"_json;

std::vector<json> edges_j_vec = {edges_get_j, edges_post_j, edges_delete_j};

TEST(extract_helper, extract_all_fromEdge) {
    std::array<endpoint, 3> endpoint_results = {EDGE, EDGE, EDGE};
    std::array<std::string, 3> conversion_results = {"edges", "edges", "edges"};
    std::array<req_method, 3> type_results = {GET, POST, DELETE};

    for(int i = 0; i < endpoint_results.size(); i++) {
        endpoint e = extract_endpoint(edges_j_vec[i]);
        ASSERT_EQ(e, endpoint_results[i]);
        ASSERT_EQ(convert_endpoint(e), conversion_results[i]);
        ASSERT_EQ(extract_req_method(edges_j_vec[i], e), type_results[i]);
    }
}