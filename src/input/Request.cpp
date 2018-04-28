//
// Created by daniel on 28.04.18.
//

#include "Request.h"
#include "extract_helper.h"

Request::Request(req_type type, endpoint ePoint, req_method method, nodes_post_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, nodes_get_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, nodes_delete_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, nodes_put_start_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, nodes_put_end_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, edges_get_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, edges_post_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, edges_delete_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, state_get_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, state_post_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}

Request::Request(req_type type, endpoint ePoint, req_method method, state_put_s s)
        :type(type),
         ePoint(ePoint),
         method(method),
         request(s)
{}
