//
// Created by vik on 30.04.18.
//

#include "requests.h"


Request nodes_post_req(NODES_POST, NODE, POST, nodes_post_s{});
Request nodes_get_req(NODES_GET, NODE, GET, nodes_get_s{1});
Request nodes_delete_req(NODES_DELETE, NODE, DELETE, nodes_delete_s{1});
Request nodes_put_end_req(NODES_PUT_END, NODE, PUT, nodes_put_end_s{1});
Request nodes_put_start_req(NODES_PUT_START, NODE, PUT, nodes_put_start_s{1});

std::vector<Request> nodes_req_vec{nodes_post_req,
                                   nodes_get_req,
                                   nodes_delete_req,
                                   nodes_put_end_req,
                                   nodes_put_start_req
};