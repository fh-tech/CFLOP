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
        Request r = nodes_j_vec[i];

        ASSERT_EQ(r.type, type_results[i]);
        ASSERT_EQ(r.ePoint, NODE);
        ASSERT_EQ(r.method, m_results[i]);

        switch(r.type) {
            case NODES_POST:
                {
                    nodes_post_s struc = std::get<nodes_post_s>(r.request);
                }
                break;
            case NODES_DELETE:
                {
                    nodes_delete_s struc = std::get<nodes_delete_s>(r.request);
                    ASSERT_EQ(struc.id, 0);
                    ASSERT_FALSE(struc.id == 3.9);
                }
                break;
            case NODES_GET:
                {
                    nodes_get_s struc = std::get<nodes_get_s>(r.request);
                    ASSERT_EQ(struc.id, 0);
                    ASSERT_FALSE(struc.id == 'A');
                }
                break;
            case NODES_PUT_START:
                {
                    nodes_put_start_s struc = std::get<nodes_put_start_s>(r.request);
                    ASSERT_EQ(struc.id, 0);
                    ASSERT_FALSE(struc.id == 'a');
                }
                break;
            case NODES_PUT_END:
                {
                    nodes_put_end_s struc = std::get<nodes_put_end_s>(r.request);
                    ASSERT_EQ(struc.id, 0);
                    ASSERT_FALSE(struc.id == 94);
                }
                break;
        }
    }
}


TEST(construct_request, edges) {
    std::vector<req_type> type_results{EDGES_GET, EDGES_POST, EDGES_DELETE};
    std::vector<req_method> m_results{GET, POST, DELETE};

    for(int i = 0; i < edges_j_vec.size(); i++) {
        Request r = edges_j_vec[i];
        ASSERT_EQ(r.type, type_results[i]);
        ASSERT_EQ(r.ePoint, EDGE);
        ASSERT_EQ(r.method, m_results[i]);

        switch(r.type) {
            case EDGES_GET:
                {
                    edges_get_s struc = std::get<edges_get_s>(r.request);
                    ASSERT_EQ(struc.id, 0);
                    ASSERT_FALSE(struc.id == 3.9);
                }
                break;
            case EDGES_POST:
                {
                    edges_post_s struc = std::get<edges_post_s>(r.request);
                    ASSERT_EQ(struc.to, 1);
                    ASSERT_FALSE(struc.to == 3.9);
                    ASSERT_EQ(struc.from, 2);
                    ASSERT_FALSE(struc.from == '2');
                }
                break;
            case EDGES_DELETE:
                {
                    edges_delete_s struc = std::get<edges_delete_s>(r.request);
                    ASSERT_EQ(struc.id, 0);
                    ASSERT_FALSE(struc.id == 'A');
                }
                break;
        }
    }
}

TEST(construct_request, state) {
    std::vector<req_type> type_results{STATE_GET, STATE_POST, STATE_PUT};
    std::vector<req_method> m_results{GET, POST, PUT};

    for(int i = 0; i < state_j_vec.size(); i++) {
        Request r = state_j_vec[i];
        ASSERT_EQ(r.type, type_results[i]);
        ASSERT_EQ(r.ePoint, STATE);
        ASSERT_EQ(r.method, m_results[i]);


        switch(r.type) {
            case STATE_GET:
                {
                    state_get_s struc = std::get<state_get_s>(r.request);
                }
                break;
            case STATE_POST:
                {
                    state_post_s struc = std::get<state_post_s>(r.request);
                    ASSERT_EQ(struc.active, 1);
                    ASSERT_FALSE(struc.active == 3.9);
                    ASSERT_EQ(struc.start, 1);
                    ASSERT_FALSE(struc.start == '2');
                    ASSERT_EQ(struc.end, 0);
                    ASSERT_FALSE(struc.end == '0');
                    ASSERT_FALSE(struc.end == '0');


                    ASSERT_EQ(struc.nodes.size(), 2);
                    ASSERT_EQ(struc.nodes.at(0).id, 0);
                    ASSERT_EQ(struc.nodes.at(0).edges.at(0), 1);
                    ASSERT_EQ(struc.nodes.at(0).edges.at(1), 2);
                    ASSERT_EQ(struc.nodes.at(0).edges.at(2), 3);

                    ASSERT_EQ(struc.nodes.at(1).id, 1);
                    ASSERT_EQ(struc.nodes.at(1).edges.at(0), 1);
                    ASSERT_EQ(struc.nodes.at(1).edges.at(1), 3);

                    ASSERT_EQ(struc.edges.size(), 1);
                    ASSERT_EQ(struc.edges.at(0).id, 1);
                    ASSERT_EQ(struc.edges.at(0).from, 0);
                    ASSERT_EQ(struc.edges.at(0).to, 1);
                }
                break;
            case STATE_PUT:
                {
                    state_put_s struc = std::get<state_put_s>(r.request);
                    std::string input("a");
                    ASSERT_EQ(struc.input, input);
                }
                break;
        }
    }
}

TEST(construct_request, invalid_json) {
    json state_putINVALID_j =
            R"({
      "state": {
        "put": {
          "inputt": "a"
        }
      }
    })"_json;

    ASSERT_ANY_THROW(Request r = state_putINVALID_j);
}

TEST(construct_request, invalid_json2) {
    json state_postINVALID_j =
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

    try {
        Request r = state_postINVALID_j;
    }catch(std::runtime_error& e) {
        ASSERT_EQ(e.what(), "invalid json_input");
    }


}