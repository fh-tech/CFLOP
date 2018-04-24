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
 * just extracts the endpoint from the json
 * @param j
 * @return
 */
endpoint extract_endpoint(json& j) {
    //TODO: comparison with != nullptr necessary implicit conversion to boolean not possible
    if(j["nodes"] != nullptr) return NODE ;
    if(j["edges"] != nullptr) return EDGE;
    if(j["state"] != nullptr) return STATE;
}

std::string convert_endpoint(endpoint e) {
    switch(e) {
        case NODE:
            return "nodes";
        case EDGE:
            return "edges";
        case STATE:
            return "state";
        default:
            throw std::runtime_error("invalid endpoint");
    }
}

req_type extract_req_type(json j, endpoint e) {
    std::string endP_s = convert_endpoint(e);
//TODO:    again comparison with != nullptr is necessary
    if(j[endP_s]["get"] != nullptr) return GET;
    if(j[endP_s]["put"] != nullptr) return PUT;
    if(j[endP_s]["post"] != nullptr) return POST;
    if(j[endP_s]["delete"] != nullptr) return DELETE;
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
