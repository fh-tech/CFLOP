//
// Created by vik on 30.04.18.
//

#ifndef CFLOP_JSON_RESPONSE_H
#define CFLOP_JSON_RESPONSE_H

#include "../include/output.h"

extern json nodes_post_r_j;
extern nodes_post_r_s nodes_post_r_example;
extern json nodes_delete_r_j;
extern nodes_post_r_s nodes_delete_r_example;
extern json nodes_get_r_j;
extern nodes_post_r_s nodes_get_r_example;
extern json nodes_put_start_r_j;
extern nodes_put_start_r_s nodes_put_start_r_example;
extern json nodes_put_end_r_j;
extern nodes_put_end_r_s nodes_put_end_r_example;

extern json edges_get_r_j;
extern edges_get_r_s edges_get_r_example;
extern json edges_post_r_j;
extern edges_post_r_s edges_post_r_example;
extern json edges_delete_r_j;
extern edges_delete_r_s edges_delete_r_example;

extern json state_get_r_j;
extern state_get_r_s state_get_r_example;
extern json state_post_r_j;
extern state_post_r_s state_post_r_example;
extern json state_put_r_j;
extern state_put_r_s state_put_r_example;

extern json failure_r_j;
extern failure_r_s failure_r_example;

extern std::vector<json> node_r_j_vec;
extern std::vector<json> edge_r_j_vec;
extern std::vector<json> state_r_j_vec;

#endif //CFLOP_JSON_RESPONSE_H
