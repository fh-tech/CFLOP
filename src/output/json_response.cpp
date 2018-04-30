//
// Created by vik on 30.04.18.
//

#include "json_response.h"

extern json nodes_post_r_j =
        R"({
          "success": {
            "node": { "id": 0 }
          }
        })";

extern json nodes_delete_r_j =
        R"({
          "success": {}
        })";

extern json nodes_get_r_j =
        R"({
          "success": {
            "node":{
              "id": 0,
              "edges": [1,2,3]
            }
          }
        })";

extern json nodes_put_start_r_j =
        R"({
          "success": {}
        })";

extern json nodes_put_end_r_j =
        R"({
          "success": {}
        })";

extern json edges_get_r_j =
        R"({
          "success": {
            "edge": {
              "id": 0,
              "from": 1,
              "to": 2,
            }
          }
        })";

extern json edges_post_r_j =
        R"(  {
         "success": {
           "edge": { "id": 0 }
         }
       })";

extern json edges_delete_r_j =
        R"({
          "success":{}
        })";

extern json state_get_r_j =
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
                }
              ],
              "active": 1,
              "start": 1,
              "end": 0
            }
          }
        })";

memset()


extern json state_post_r_j =
        R"({
          "success": {}
        })";

extern json state_put_r_j =
        R"({
          "success": {
            "node": {"id": 0}
          }
        })";

extern json failure_r_j =
        R"({
          "error": {
            "message": "some fail message"
          }
        })";

