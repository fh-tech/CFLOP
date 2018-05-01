//
// Created by vik on 01.05.18.
//

#include <gtest/gtest.h>
#include "../include/output.h"


TEST(to_json, nodes_post) {
    nodes_post_r_s nodes_post_r_example{0};
    json j;
    j = nodes_post_r_example;
    json nodes_post_r_j =
            R"({
      "success": {
        "node": { "id": 0 }
      }
    })"_json;
    ASSERT_EQ(j, nodes_post_r_j);
}

TEST(to_json, nodes_delete) {
    nodes_delete_r_s nodes_delete_r_example{};
    json j;
    j = nodes_delete_r_example;
    json nodes_delete_r_j =
            R"({
      "success": {}
    })"_json;
    ASSERT_EQ(j, nodes_delete_r_j);
}

TEST(to_json, nodes_get) {
    nodes_get_r_s nodes_get_r_example{0, std::vector<size_t>{1,2,3}};
    json j;
    j = nodes_get_r_example;
    json nodes_get_r_j =
            R"({
      "success": {
        "node":{
          "id": 0,
          "edges": [1,2,3]
        }
      }
    })"_json;
    ASSERT_EQ(j, nodes_get_r_j);
}

TEST(to_json, nodes_put_start) {
    nodes_put_start_r_s nodes_put_start_r_example{};
    json j;
    j = nodes_put_start_r_example;
    json nodes_put_start_r_j =
            R"({
      "success": {}
    })"_json;
    ASSERT_EQ(j, nodes_put_start_r_j);
}

TEST(to_json, nodes_put_end) {
    nodes_put_end_r_s nodes_put_end_r_example{};
    json j;
    j = nodes_put_end_r_example;
    json nodes_put_end_r_j =
            R"({
      "success": {}
    })"_json;
    ASSERT_EQ(j, nodes_put_end_r_j);
}