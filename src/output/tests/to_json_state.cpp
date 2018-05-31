//
// Created by vik on 01.05.18.
//

#include <gtest/gtest.h>
#include "../include/output.h"

using namespace output_lib;

TEST(to_json, state_get) {
    input_lib::node n1{0, std::vector<size_t>{1,2,3}};
    input_lib::node n2{1, std::vector<size_t>{1,3}};
    std::vector<input_lib::node> nodes{n1,n2};
    input_lib::edge e1{1,0,1};
    std::vector<input_lib::edge> edges{e1};
    state_get_r_s state_get_r_example{nodes, edges, 1, 1, 0};
    json j;
    j = state_get_r_example;
    json state_get_r_j =
            R"({
      "success":{
        "state":{
          "nodes": [
            {
              "id": 0,
              "edges": [1,2,3]
            }, {
              "id": 1,
              "edges": [1,3]
            }
          ],
          "edges":[
            {
              "id": 1,
              "from": 0,
              "to": 1,
              "transition": ""
            }
          ],
          "active": 1,
          "start": 1,
          "end": 0
        }
      }
    })"_json;
    std::cout << j << std::endl << std::endl;
    std::cout << state_get_r_j << std::endl;

    ASSERT_EQ(j, state_get_r_j);
}

TEST(to_json, state_post) {
    state_post_r_s state_post_r_example{};
    json j;
    j = state_post_r_example;
    json state_post_r_j =
            R"({
      "success": {}
    })"_json;
    ASSERT_EQ(j, state_post_r_j);
}

TEST(to_json, state_put) {
    state_put_r_s state_put_r_example{0};
    json j;
    j = state_put_r_example;
    json state_put_r_j =
            R"({
      "success": {
        "node": {"id": 0}
      }
    })"_json;
    ASSERT_EQ(j, state_put_r_j);
}
