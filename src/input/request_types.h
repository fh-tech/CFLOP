//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_REQUEST_TYPES_H
#define CFLOP_REQUEST_TYPES_H
#include <iostream>
#include <vector>
#include "../../libs/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;


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


struct node {
//    node() = default;

    size_t id;
    std::vector<size_t> edges{};
};

struct edge {
//    edge() = default;

    size_t id;
    size_t from;
    size_t to;
};

//** NODES TYPES **//
struct nodes_post_s {};
struct nodes_delete_s {
    size_t id;
};
struct nodes_get_s {
    size_t id;
};
struct nodes_put_start_s {
    size_t id;
};
struct nodes_put_end_s {
    size_t id;
};

//** EDGES TYPES **//
struct edges_get_s {
    size_t id;
};

struct edges_post_s {
    size_t id;
};

struct edges_delete_s {
    size_t id;
};


//** STATE TYPES **//
struct state_get_s {};

struct state_post_s {
    std::vector<node> nodes{};
    std::vector<edge> edges{};
    size_t active;
    size_t start;
    size_t end;
};

struct state_put_s {
    std::string input;
};


void to_json(json &j, const edge& e) = delete;
void from_json(const json &j, edge& e);

void to_json(json &j, const node& n) = delete;
void from_json(const json &j, node& n);

#endif //CFLOP_REQUEST_TYPES_H
