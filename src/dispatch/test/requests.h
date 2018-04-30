//
// Created by vik on 30.04.18.
//

#ifndef CFLOP_REQUESTS_H
#define CFLOP_REQUESTS_H

#include "../include/dispatch.h"

extern Request nodes_post_req;
extern Request nodes_get_req;
extern Request nodes_delete_req;
extern Request nodes_put_end_req;
extern Request nodes_put_start_req;

extern std::vector<Request> nodes_req_vec;

#endif //CFLOP_REQUESTS_H
