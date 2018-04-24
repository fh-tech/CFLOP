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

endpoint extract_endpoint(json j) {
    if(j["nodes"]) return NODE;
    if(j["edges"]) return EDGE;
    if(j["state"]) return STATE;
}

std::string convert_endpoint(endpoint e) {
    switch(e) {
        case NODE:
            return "nodes";
        case EDGE:
            return "edges";
        case STATE:
            return "state";
    }
}

req_type extract_req_type(json j, endpoint e = NULL) {
    std::string endP_s;
    if(!e) endpoint e = extract_endpoint(j);

    endP_s = convert_endpoint(e);
    if(j[endP_s]["get"]) return GET;
    if(j[endP_s]["put"]) return PUT;
    if(j[endP_s]["post"]) return POST;
    if(j[endP_s]["delete"]) return DELETE;
}


/**
 * Abstract request class
 */
class Request {
public:
    virtual req_type get_type() const = 0;
    virtual endpoint get_endpoint() const = 0;
    virtual json get_json() const = 0;
};


#endif //CFLOP_REQUEST_H
