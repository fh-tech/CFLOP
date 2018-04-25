//
// Created by vik on 24.04.18.
//

#include <gtest/gtest.h>
#include <input.h>

json state_get_j =
        R"({
          "state":{
            "get":{}
          }
        })"_json;

json state_post_j =
        R"({
          "state":{
            "post":{
              "state": {
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
                    "to": 1
                  }
                ],
                "active": 1,
                "start": 1,
                "end": 0
              }
            }
          }
        })"_json;

json state_put_j =
        R"({
          "state": {
            "put": {
              "input": "a"
            }
          }
        })"_json;

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