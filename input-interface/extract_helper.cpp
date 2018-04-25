//
// Created by vik on 25.04.18.
//

#include "extract_helper.h"

endpoint extract_endpoint(json& j) {
    //TODO: comparison with != nullptr necessary implicit conversion to boolean not possible
    if(j["nodes"] != nullptr) return NODE;
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

req_method extract_req_method(json j, endpoint e) {
    std::string endP_s = convert_endpoint(e);
//TODO:    again comparison with != nullptr is necessary
    if(j[endP_s]["get"] != nullptr) return GET;
    if(j[endP_s]["put"] != nullptr) return PUT;
    if(j[endP_s]["post"] != nullptr) return POST;
    if(j[endP_s]["delete"] != nullptr) return DELETE;
}