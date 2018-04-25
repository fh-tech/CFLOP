//
// Created by vik on 25.04.18.
//

#ifndef CFLOP_JSON_REQUESTS_H
#define CFLOP_JSON_REQUESTS_H

//TODO: how to avoid having to inline them? -- otherwise multiple definitions because included in all test cases!

inline json nodes_post_j =
        R"(  {
          "nodes": {
            "post": {}
          }
        })"_json;

inline json nodes_delete_j =
        R"({
          "nodes": {
            "delete": {
              "id": 0
            }
          }
        })"_json;


inline json nodes_get_j =
        R"({
            "nodes": {
              "get": {
                "id": 0
              }
            }
        })"_json;

inline json nodes_put_start_j =
        R"({
          "nodes":{
            "put":{
              "start":{
                "id": 0
              }
            }
          }
        })"_json;

inline json nodes_put_end_j =
        R"({
          "nodes":{
            "put":{
              "end":{
                "id": 0
              }
            }
          }
        })"_json;

inline json state_get_j =
        R"({
          "state":{
            "get":{}
          }
        })"_json;

inline json state_post_j =
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

inline json state_put_j =
        R"({
          "state": {
            "put": {
              "input": "a"
            }
          }
        })"_json;


inline json edges_get_j =
        R"({
          "edges": {
            "get": {
              "id": 0
            }
          }
        })"_json;

inline json edges_post_j =
        R"({
          "edges":{
            "post":{
              "to": 1,
              "from": 2
            }
          }
        })"_json;

inline json edges_delete_j =
        R"({
          "edges": {
            "delete": {
              "id": 0
            }
          }
        })"_json;



inline std::vector<json> nodes_j_vec = {nodes_post_j,
                                 nodes_delete_j,
                                 nodes_get_j,
                                 nodes_put_start_j,
                                 nodes_put_end_j};

inline std::vector<json> state_j_vec = {state_get_j,
                                 state_post_j,
                                 state_put_j};

inline std::vector<json> edges_j_vec = {edges_get_j,
                                 edges_post_j,
                                 edges_delete_j};

#endif //CFLOP_JSON_REQUESTS_H

