//
// Created by vik on 22.04.18.
//

#ifndef CFLOP_REQUEST_H
#define CFLOP_REQUEST_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;


enum req_type {
    GET = 1,
    PUT = 2,
    POST = 3,
    DELETE = 4
};

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
    virtual req_type get_type() const = 0;
    virtual endpoint get_endpoint() const = 0;
};


#endif //CFLOP_REQUEST_H
