//
// Created by vik on 24.04.18.
//

#ifndef CFLOP_EXTRACT_HELPER_H
#define CFLOP_EXTRACT_HELPER_H

#include <nlohmann/json.hpp>
#include "Request.h"

using json = nlohmann::json;

req_method extract_req_method(json j, endpoint e);
endpoint extract_endpoint(json& j);
std::string convert_endpoint(endpoint e);

/**
 * just extracts the endpoint from the json
 * @param j
 * @return
 */
endpoint extract_endpoint(json& j) {
    //TODO: comparison with != nullptr necessary implicit conversion to boolean not possible
    if(j["nodes"] != nullptr) return NODE;
    if(j["edges"] != nullptr) return EDGE;
    if(j["state"] != nullptr) return STATE;
}

/**
 * extracts the type of request from a json
 * @param j a json request
 * @param e a endpoint (NODE, EDGE, STATE)
 * @return req_method enum
 */
req_method extract_req_method(json j, endpoint e) {
    std::string endP_s = convert_endpoint(e);
//TODO:    again comparison with != nullptr is necessary
    if(j[endP_s]["get"] != nullptr) return GET;
    if(j[endP_s]["put"] != nullptr) return PUT;
    if(j[endP_s]["post"] != nullptr) return POST;
    if(j[endP_s]["delete"] != nullptr) return DELETE;
}

/**
 * Converts an endpoint to its string representation in json
 * @param e an endpoint enum
 * @return a string representation of the enum in json
 */
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




#endif //CFLOP_EXTRACT_HELPER_H
