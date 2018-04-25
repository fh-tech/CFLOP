//
// Created by vik on 24.04.18.
//

#ifndef CFLOP_EXTRACT_HELPER_H
#define CFLOP_EXTRACT_HELPER_H

#include "Request.h"

/**
 * just extracts the endpoint from the json
 * @param j
 * @return
 */
endpoint extract_endpoint(json& j);

/**
 * Converts an endpoint to its string representation in json
 * @param e an endpoint enum
 * @return a string representation of the enum in json
 */
std::string convert_endpoint(endpoint e);

/**
 * extracts the type of request from a json
 * @param j a json request
 * @param e a endpoint (NODE, EDGE, STATE)
 * @return req_method enum
 */
req_method extract_req_method(json j, endpoint e);


#endif //CFLOP_EXTRACT_HELPER_H
