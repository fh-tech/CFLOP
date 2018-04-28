//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_EXTRACT_HELPER_H
#define CFLOP_EXTRACT_HELPER_H

#include "request_types.h"
#include "../../libs/json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

/**
 * just extracts the endpoint from the json
 * @param j
 * @return
 */
endpoint extract_endpoint(const json& j);



/**
 * Converts an endpoint to its string representation in json
 * @param e an endpoint enum
 * @return a string representation of the enum in json
 */
std::string convert_endpoint(const endpoint& e);

/**
 * extracts the type of request from a json
 * @param j a json request
 * @param e a endpoint (NODE, EDGE, STATE)
 * @return req_method enum
 */
req_method extract_req_method(const json& j, const endpoint& e);

/**
 * generates the complete req_type needed to differentiate between the different input-jsons
 * @param e the enpoint to call
 * @param method to use on endpoint
 * @param j the complete json
 * @return req_type
 */
req_type make_req_type(const endpoint& e, const req_method& method, const json& j);

/**
 * generates the complete req_type needed to differentiate between the different input-jsons
 * @param j the input json with which to make the call
 * @return the req_type
 */
req_type make_req_type(const json& j);

#endif //CFLOP_EXTRACT_HELPER_H
