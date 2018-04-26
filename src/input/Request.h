//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_REQUEST_H
#define CFLOP_REQUEST_H

#include <variant>
#include "request_types.h"


/**
 * The total kind of request the json is. INVALID means the json was ill-formed
 */
enum req_type {
    INVALID_TYPE = 0,
    NODES_POST = 1,
    NODES_DELETE = 2,
    NODES_GET = 3,
    NODES_PUT_START = 4,
    NODES_PUT_END = 5,
    EDGES_GET = 6,
    EDGES_POST = 7,
    EDGES_DELETE = 8,
    STATE_GET = 9,
    STATE_POST = 10,
    STATE_PUT = 11
};

/**
 * the different request types that can be used INVALID means the json was ill-formed
 */
enum req_method {
    INVALID_METHOD = 0,
    GET = 1,
    PUT = 2,
    POST = 3,
    DELETE = 4
};

/**
 * the actual endpoints that can be accessed with the json INVALID means the json was ill-formed
 */
enum endpoint {
    INVALID_ENDPOINT = 0,
    STATE = 1,
    NODE = 2,
    EDGE = 3
};

/**
 * Abstract request class
 */

class Request {
public:
    req_type type;
    endpoint ePoint;
    req_method method;

    std::variant <nodes_post_s,
                nodes_get_s,
                nodes_delete_s,
                nodes_put_start_s,
                nodes_put_end_s,
                edges_get_s,
                edges_post_s,
                edges_delete_s,
                state_get_s,
                state_post_s,
                state_put_s> request;


    explicit Request(req_type type, endpoint ePoint, req_method method, nodes_post_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, nodes_get_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, nodes_put_start_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, nodes_put_end_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, edges_get_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, edges_post_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, edges_delete_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, state_get_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, state_post_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};

    explicit Request(req_type type, endpoint ePoint, req_method method, state_put_s s)
            :type(type),
             ePoint(ePoint),
             method(method),
             request(s)
    {};
};
#endif //CFLOP_REQUEST_H
