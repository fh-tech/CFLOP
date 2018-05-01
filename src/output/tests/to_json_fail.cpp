//
// Created by vik on 01.05.18.
//

#include <gtest/gtest.h>
#include "../include/output.h"

TEST(to_json, failure) {
failure_r_s failure_r_example{"some fail message"};
json j;
j = failure_r_example;
json failure_r_j =
        R"({
      "error": {
        "message": "some fail message"
      }
    })"_json;
ASSERT_EQ(j, failure_r_j);
}
