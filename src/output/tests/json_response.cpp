//
// Created by vik on 30.04.18.
//

#include "json_response.h"

json nodes_post_r_j =
    R"({
      "success": {
        "node": { "id": 0 }
      }
    })";

json nodes_delete_r_j =
    R"({
      "success": {}
    })";

json nodes_get_r_j =
    R"({
      "success": {
        "node":{
          "id": 0,
          "edges": [1,2,3]
        }
      }
    })";

json nodes_put_start_r_j =
    R"({
      "success": {}
    })";

json nodes_put_end_r_j =
    R"({
      "success": {}
    })";

json edges_get_r_j =
    R"({
      "success": {
        "edge": {
          "id": 0,
          "from": 1,
          "to": 2,
        }
      }
    })";

json edges_post_r_j =
    R"(  {
     "success": {
       "edge": { "id": 0 }
     }
   })";

json edges_delete_r_j =
    R"({
      "success":{}
    })";

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
            }
          ],
          "active": 1,
          "start": 1,
          "end": 0
        }
      }
    })";

json state_post_r_j =
    R"({
      "success": {}
    })";

json state_put_r_j =
    R"({
      "success": {
        "node": {"id": 0}
      }
    })";

json failure_r_j =
    R"({
      "error": {
        "message": "some fail message"
      }
    })";
