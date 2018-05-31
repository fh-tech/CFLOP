//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_REQUEST_H
#define CFLOP_REQUEST_H

#include <variant>
#include "request_types.h"

namespace input_lib {
/**
 * The total kind of request the json is. INVALID means the json was ill-formed
 */
    enum req_type {
        INVALID_TYPE = 0,
        NODES_POST = 1,
        NODES_DELETE = 2,
        NODES_GET = 3,
        NODES_PUT_START = 4,
        NODES_PUT_END = 5,
        EDGES_GET = 6,
        EDGES_POST = 7,
        EDGES_DELETE = 8,
        STATE_GET = 9,
        STATE_POST = 10,
        STATE_PUT = 11
    };

/**
 * the different request types that can be used INVALID means the json was ill-formed
 */
    enum req_method {
        INVALID_METHOD = 0,
        GET = 1,
        PUT = 2,
        POST = 3,
        DELETE = 4
    };

/**
 * the actual endpoints that can be accessed with the json INVALID means the json was ill-formed
 */
    enum endpoint {
        INVALID_ENDPOINT = 0,
        STATE = 1,
        NODE = 2,
        EDGE = 3
    };

/**
 * Abstract request class
 */

    class Request {
    public:
        req_type type;
        endpoint ePoint;
        req_method method;

        std::variant<nodes_post_s,
                nodes_get_s,
                nodes_delete_s,
                nodes_put_start_s,
                nodes_put_end_s,
                edges_get_s,
                edges_post_s,
                edges_delete_s,
                state_get_s,
                state_post_s,
                state_put_s> request;

        explicit Request() = default;

        explicit Request(req_type type, endpoint ePoint, req_method method, nodes_post_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, nodes_get_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, nodes_delete_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, nodes_put_start_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, nodes_put_end_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, edges_get_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, edges_post_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, edges_delete_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, state_get_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, state_post_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};

        explicit Request(req_type type, endpoint ePoint, req_method method, state_put_s s)
                : type(type),
                  ePoint(ePoint),
                  method(method),
                  request(s) {};
    };

}

#include "extract_helper.h"

namespace input_lib {

    static void to_json(json &j, const Request &r) {}

    static void from_json(const json &j, Request &req) {
        req_type reqType = input_lib::make_req_type(j);
        try {
            switch (reqType) {
                case INVALID_TYPE: {
                    throw std::runtime_error("invalid json_input");
                }
                case NODES_POST: {
                    req = Request(NODES_POST, NODE, POST, nodes_post_s{});
                }
                    break;
                case NODES_DELETE: {
                    auto id_d = j.at("nodes").at("delete").at("id").get<size_t>();
                    req = Request(NODES_DELETE, NODE, DELETE, nodes_delete_s{id_d});
                }
                    break;
                case NODES_GET: {
                    auto id_g = j.at("nodes").at("get").at("id").get<size_t>();
                    req = Request(NODES_GET, NODE, GET, nodes_get_s{id_g});
                }
                    break;
                case NODES_PUT_START: {
                    auto id_put_s = j.at("nodes").at("put").at("start").at("id").get<size_t>();
                    req = Request(NODES_PUT_START, NODE, PUT, nodes_put_start_s{id_put_s});
                }
                    break;
                case NODES_PUT_END: {
                    auto id_put_e = j.at("nodes").at("put").at("end").at("id").get<size_t>();
                    req = Request(NODES_PUT_END, NODE, PUT, nodes_put_end_s{id_put_e});
                }
                    break;
                case EDGES_GET: {
                    auto id_get_ed = j.at("edges").at("get").at("id").get<size_t>();
                    req = Request(EDGES_GET, EDGE, GET, edges_get_s{id_get_ed});
                }
                    break;
                case EDGES_POST: {
                    auto to_post_ed = j.at("edges").at("post").at("to").get<size_t>();
                    auto from_post_ed = j.at("edges").at("post").at("from").get<size_t>();
                    auto transition_post_ed = j.at("edges").at("post").at("transition").get<std::string>();
                    req = Request(EDGES_POST, EDGE, POST, edges_post_s{to_post_ed, from_post_ed, transition_post_ed});
                }
                    break;
                case EDGES_DELETE: {
                    auto id_delete_ed = j.at("edges").at("delete").at("id").get<size_t>();
                    req = Request(EDGES_DELETE, EDGE, DELETE, edges_delete_s{id_delete_ed});
                }
                    break;
                case STATE_GET: {
                    req = Request(STATE_GET, STATE, GET, state_get_s{});
                }
                    break;
                case STATE_POST: {
                    auto nodes = j.at("state").at("post").at("state").at("nodes").get<std::vector<node>>();
                    auto edges = j.at("state").at("post").at("state").at("edges").get<std::vector<edge>>();
                    auto active = j.at("state").at("post").at("state").at("active").get<size_t>();
                    auto start = j.at("state").at("post").at("state").at("start").get<size_t>();
                    auto end = j.at("state").at("post").at("state").at("end").get<size_t>();
                    state_post_s sp_s{nodes, edges, active, start, end};

                    req = Request(STATE_POST, STATE, POST, sp_s);
                }
                    break;
                case STATE_PUT: {
                    auto input = j.at("state").at("put").at("input").get<std::string>();
                    req = Request(STATE_PUT, STATE, PUT, state_put_s{input});
                }
                    break;
            }
        } catch (std::exception &e) {
            throw std::runtime_error("invalid json_input");
        }
    }
}

#endif //CFLOP_REQUEST_H
