//
// Created by vik on 01.05.18.
//

#ifndef CFLOP_RESPONSE_H
#define CFLOP_RESPONSE_H

#include "response_types.h"
#include "../input/include/input.h"

class Response {
public:
    req_type type;

    std::variant<nodes_post_r_s,
            nodes_get_r_s,
            nodes_delete_r_s,
            nodes_put_start_r_s,
            nodes_put_end_r_s,
            edges_get_r_s,
            edges_post_r_s,
            edges_delete_r_s,
            state_get_r_s,
            state_post_r_s,
            state_put_r_s,
            failure_r_s> response;

    explicit Response() = default;

    explicit Response(req_type type, nodes_post_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, nodes_get_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, nodes_delete_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, nodes_put_start_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, nodes_put_end_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, edges_get_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, edges_post_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, edges_delete_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, state_get_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, state_post_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, state_put_r_s s)
            : type(type),
              response(s) {}

    explicit Response(req_type type, failure_r_s s)
            : type(type),
              response(s) {}
};

static void to_json(json &j, const Response &r) {
    req_type reqType = r.type;

    switch(r.type) {
        case INVALID_TYPE: {
            failure_r_s struc = std::get<failure_r_s>(r.response);
            j = struc;
        }
            break;
        case NODES_POST: {
            nodes_post_r_s struc = std::get<nodes_post_r_s>(r.response);
            j = struc;
        }
            break;
        case NODES_DELETE: {
            nodes_delete_r_s struc = std::get<nodes_delete_r_s>(r.response);
            j = struc;
        }
            break;
        case NODES_GET: {
            nodes_get_r_s struc = std::get<nodes_get_r_s>(r.response);
            j = struc;
        }
            break;
        case NODES_PUT_START: {
            nodes_put_start_r_s struc = std::get<nodes_put_start_r_s>(r.response);
            j = struc;
        }
            break;
        case NODES_PUT_END: {
            nodes_put_end_r_s struc = std::get<nodes_put_end_r_s>(r.response);
            j = struc;
        }
            break;
        case EDGES_GET: {
            edges_get_r_s struc = std::get<edges_get_r_s>(r.response);
            j = struc;;
        }
            break;
        case EDGES_POST: {
            edges_post_r_s struc = std::get<edges_post_r_s>(r.response);
            j = struc;
        }
            break;
        case EDGES_DELETE: {
            edges_delete_r_s struc = std::get<edges_delete_r_s>(r.response);
            j = struc;
        }
            break;
        case STATE_GET: {
            state_get_r_s struc = std::get<state_get_r_s>(r.response);
            j = struc;
        }
            break;
        case STATE_POST: {
            state_post_r_s struc = std::get<state_post_r_s>(r.response);
            j = struc;
        }
            break;
        case STATE_PUT: {
            state_put_r_s struc = std::get<state_put_r_s>(r.response);
            j = struc;
        }
            break;
    }
}
static void from_json(const json &j, Response &req) {}



#endif //CFLOP_RESPONSE_H
