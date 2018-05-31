//
// Created by vik on 24.04.18.
//

#include <gtest/gtest.h>
#include <input.h>
#include "json_requests.h"

using namespace input_lib;

TEST(convert_endpoint, convert_state) {
    const endpoint e = STATE;
    ASSERT_EQ("state", convert_endpoint(e));
}

TEST(convert_endpoint, invalid_endpoint) {
    const endpoint e = INVALID_ENDPOINT;
    ASSERT_EQ("invalid", convert_endpoint(e));
}