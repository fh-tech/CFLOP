//
// Created by vik on 01.05.18.
//

#include <gtest/gtest.h>
#include "../include/output.h"

using namespace output_lib;

TEST(to_json, edges_get) {
std::string transition = "a";
edges_get_r_s edges_get_r_example{0,1,2,transition};
json j;
j = edges_get_r_example;
json edges_get_r_j =
        R"({
      "success": {
        "edge": {
          "id": 0,
          "from": 1,
          "to": 2,
          "transition": "a"
        }
      }
    })"_json;
ASSERT_EQ(j, edges_get_r_j);
}

TEST(to_json, edges_post) {
edges_post_r_s edges_post_r_example{0};
json j;
j = edges_post_r_example;
json edges_post_r_j =
        R"(  {
     "success": {
       "edge": { "id": 0 }
     }
   })"_json;
ASSERT_EQ(j, edges_post_r_j);
}

TEST(to_json, edges_delete) {
edges_delete_r_s edges_delete_r_example{};
json j;
j = edges_delete_r_example;
json edges_delete_r_j =
        R"({
      "success":{}
    })"_json;
ASSERT_EQ(j, edges_delete_r_j);
}