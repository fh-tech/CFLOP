//
// Created by vik on 22.04.18.
//

#ifndef CFLOP_REQUEST_H
#define CFLOP_REQUEST_H

enum req_type {
    nodes_post = 1,
    nodes_delete = 2,
    nodes_get = 3,
    nodes_put_start = 4,
    nodes_put_end = 5,
    edges_get = 6,
    edges_post = 7,
    edges_delete = 8,
    state_get = 9,
    state_post = 10,
    state_put = 11
};

/**
 * the different request types that can be used
 */
enum req_method {
    GET = 1,
    PUT = 2,
    POST = 3,
    DELETE = 4
};

/**
 * the actual endpoints that can be accessed with the json
 */
enum endpoint {
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

    union request {
        struct nodes_post_s;
        struct nodes_get_s;
        struct nodes_put_start_s;
        struct nodes_put_end_s;

        struct edges_get_s;
        struct edges_post_s;
        struct edges_delete_s;

        struct state_get_s;
        struct state_post_s;
        struct state_put_s;
    };

    req_type get_type() const {
        return type;
    }
    endpoint get_endpoint() const {
        return ePoint;
    }
    req_method get_method() const {
        return method;
    }
};

#endif //CFLOP_REQUEST_H
