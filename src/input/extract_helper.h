//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_EXTRACT_HELPER_H
#define CFLOP_EXTRACT_HELPER_H

#include "Request.h"
#include "../../libs/json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

namespace input_lib {
    /**
 * just extracts the endpoint from the json
 * @param j
 * @return
 */
    inline endpoint extract_endpoint(const json& j) {
        //j.find returns iterator if != j.end() we found it
        if(j.find("nodes") != j.end()) return NODE;
        if(j.find("edges") != j.end()) return EDGE;
        if(j.find("state") != j.end()) return STATE;
        return INVALID_ENDPOINT;
    }

/**
 * Converts an endpoint to its string representation in json
 * @param e an endpoint enum
 * @return a string representation of the enum in json
 */
    inline std::string convert_endpoint(const endpoint& e) {
        switch(e) {
            case NODE:
                return "nodes";
            case EDGE:
                return "edges";
            case STATE:
                return "state";
            case INVALID_ENDPOINT:
                return "invalid";
        }
    }

/**
 * extracts the type of request from a json
 * @param j a json request
 * @param e a endpoint (NODE, EDGE, STATE)
 * @return req_method enum
 */
    inline req_method extract_req_method(const json& j, const endpoint& e) {
        std::string endP_s = convert_endpoint(e);
        //j.find returns iterator if != j.end() we found it
        if(j[endP_s].find("get") != j[endP_s].end()) return GET;
        if(j[endP_s].find("put") != j[endP_s].end()) return PUT;
        if(j[endP_s].find("post") != j[endP_s].end()) return POST;
        if(j[endP_s].find("delete") != j[endP_s].end()) return DELETE;
        return INVALID_METHOD;
    }

/**
 * generates the complete req_type needed to differentiate between the different input-jsons
 * @param e the enpoint to call
 * @param method to use on endpoint
 * @param j the complete json
 * @return req_type
 */
    inline req_type make_req_type(const endpoint& e, const req_method& method, const json& j) {
        switch(e) {
            case STATE:
                switch(method) {
                    case GET:
                        return STATE_GET;
                    case PUT:
                        return STATE_PUT;
                    case POST:
                        return STATE_POST;
//                DELETE not yet used on STATE
                    case DELETE:
                        return INVALID_TYPE;
                    case INVALID_METHOD:
                        return INVALID_TYPE;
                }
                break;
            case NODE:
                switch(method) {
                    case POST:
                        return NODES_POST;
                    case DELETE:
                        return NODES_DELETE;
                    case GET:
                        return NODES_GET;
                    case PUT:
                        if(j["nodes"]["put"].find("start") != j["nodes"]["put"].end()) return NODES_PUT_START;
                        if(j["nodes"]["put"].find("end") != j["nodes"]["put"].end()) return NODES_PUT_END;
                        return INVALID_TYPE;
                    case INVALID_METHOD:
                        return INVALID_TYPE;
                }
                break;
            case EDGE:
                switch(method) {
                    case GET:
                        return EDGES_GET;
                    case POST:
                        return EDGES_POST;
                    case DELETE:
                        return EDGES_DELETE;
//                PUT not yet used on EDGE
                    case PUT:
                        return INVALID_TYPE;
                    case INVALID_METHOD:
                        return INVALID_TYPE;
                }
            case INVALID_ENDPOINT:
                return INVALID_TYPE;
        }
    }

/**
 * generates the complete req_type needed to differentiate between the different input-jsons
 * @param j the input json with which to make the call
 * @return the req_type
 */
    inline req_type make_req_type(const json& j) {
        const endpoint e = extract_endpoint(j);
        const req_method method = extract_req_method(j, e);
        return make_req_type(e, method , j);
    }
}




#endif //CFLOP_EXTRACT_HELPER_H
