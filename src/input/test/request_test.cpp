//
// Created by vik on 25.04.18.
//

#include <gtest/gtest.h>
#include <input.h>
#include "json_requests.h"

TEST(construct_request, nodes) {
    std::vector<req_type> type_results{NODES_POST, NODES_DELETE, NODES_GET, NODES_PUT_START, NODES_PUT_END};
    std::vector<req_method> m_results{POST, DELETE, GET, PUT, PUT};

    for (int i = 0; i < nodes_j_vec.size(); i++) {
        std::optional<Request> r = nodes_j_vec[i];

        ASSERT_EQ(r.value().type, type_results[i]);
        ASSERT_EQ(r.value().ePoint, NODE);
        ASSERT_EQ(r.value().method, m_results[i]);
    }
}

TEST(construct_request, to_optional){
    json j = R"(  {
      "nodes": {
        "patch": {}
      }
    })"_json;

    std::optional<Request> r = j;

    ASSERT_TRUE(!r.has_value());
}


TEST(construct_request, edges) {
    std::vector<req_type> type_results{EDGES_GET, EDGES_POST, EDGES_DELETE};
    std::vector<req_method> m_results{GET, POST, DELETE};

    for(int i = 0; i < edges_j_vec.size(); i++) {
        std::optional<Request> r = edges_j_vec[i];
        ASSERT_EQ(r.value().type, type_results[i]);
        ASSERT_EQ(r.value().ePoint, EDGE);
        ASSERT_EQ(r.value().method, m_results[i]);
    }
}

TEST(construct_request, state) {
    std::vector<req_type> type_results{STATE_GET, STATE_POST, STATE_PUT};
    std::vector<req_method> m_results{GET, POST, PUT};

    for(int i = 0; i < state_j_vec.size(); i++) {
        std::optional<Request> r = state_j_vec[i];
        ASSERT_EQ(r.value().type, type_results[i]);
        ASSERT_EQ(r.value().ePoint, STATE);
        ASSERT_EQ(r.value().method, m_results[i]);
    }
}