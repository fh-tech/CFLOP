//
// Created by vik on 30.04.18.
//

#ifndef CFLOP_JSON_RESPONSE_H
#define CFLOP_JSON_RESPONSE_H

#include "../../../libs/json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

extern json nodes_post_r_j;
extern json nodes_delete_r_j;
extern json nodes_get_r_j;
extern json nodes_put_start_r_j;
extern json nodes_put_end_r_j;

extern json edges_get_r_j;
extern json edges_post_r_j;
extern json edges_delete_r_j;

extern json state_get_r_j;
extern json state_post_r_j;
extern json state_put_r_j;

extern json failure_r_j;

extern std::vector<json> node_r_j_vec;
extern std::vector<json> edge_r_j_vec;
extern std::vector<json> state_r_j_vec;

#endif //CFLOP_JSON_RESPONSE_H
