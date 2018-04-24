//
// Created by vik on 22.04.18.
//

#ifndef CFLOP_REQUEST_H
#define CFLOP_REQUEST_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;

enum req_type {
    nodes_post = 1,
    nodes_delete = 2,
    nodes_get = 3,
    nodes_put_start = 4,
    nodes_put_end = 5,
    edges_get,
    edges_post,
    edges_delete

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

    union {
        // da sind alle drin
    };

    req_type get_type() const;
    endpoint get_endpoint() const;
};


#endif //CFLOP_REQUEST_H
