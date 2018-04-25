//
// Created by vik on 25.04.18.
//

#ifndef CFLOP_EXTRACT_HELPER_H
#define CFLOP_EXTRACT_HELPER_H


#include "Request.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

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

/**
 * extracts the type of request from a json
 * @param j a json request
 * @param e a endpoint (NODE, EDGE, STATE)
 * @return req_method enum
 */
req_method extract_req_method(json j, endpoint e) {
    std::string endP_s = convert_endpoint(e);
    if(j[endP_s]["get"] != nullptr) return GET;
    if(j[endP_s]["put"] != nullptr) return PUT;
    if(j[endP_s]["post"] != nullptr) return POST;
    if(j[endP_s]["delete"] != nullptr) return DELETE;
    //TODO:    again comparison with != nullptr is necessary
}

req_type make_req_type(endpoint e, req_method method, json j) {
    switch(e) {
        case STATE:
            switch(method) {
                case GET:
                    return state_get;
                case PUT:
                    return state_put;
                case POST:
                    return state_post;
            }
            break;
        case NODE:
            switch(method) {
                case POST:
                    return nodes_post;
                case DELETE:
                    return nodes_delete;
                case GET:
                    return nodes_get;
                case PUT:
                    if(j["nodes"]["put"]["start"] != nullptr) return nodes_put_start;
                    if(j["nodes"]["put"]["end"] != nullptr) return nodes_put_end;
                    break;
            }
            break;
        case EDGE:
            switch(method) {
                case GET:
                    return edges_get;
                case POST:
                    return edges_post;
                case DELETE:
                    return edges_delete;
            }
            break;
    }
}

req_type make_req_type(json j) {
    endpoint e = extract_endpoint(j);
    req_method method = extract_req_method(j, e);
    return make_req_type(e, method , j);
}


#endif //CFLOP_EXTRACT_HELPER_H
