//
// Created by vik on 22.04.18.
//

#ifndef CFLOP_NODE_REQUEST_H
#define CFLOP_NODE_REQUEST_H


#include "Request.h"

class NODE_Request : public Request {
public:
    NODE_Request(json j)
            :j(j)
    {}
    req_type get_type() const {

    }
    endpoint get_endPoint() const {

    }

    json get_json() const {
        return j;
    }


private:
    json j;

};


#endif //CFLOP_NODE_REQUEST_H
