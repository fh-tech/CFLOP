//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_REQUEST_H
#define CFLOP_REQUEST_H

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
