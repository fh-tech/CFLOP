//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_REQUEST_TYPES_H
#define CFLOP_REQUEST_TYPES_H
#include <iostream>
#include <vector>

#include "../../libs/json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

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
    size_t to;
    size_t from;
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


static void to_json(json &j, const edge& e) {}
static void from_json(const json &j, edge& e) {
    e.id = j.at("id").get<size_t>();
    e.from = j.at("from").get<size_t>();
    e.to = j.at("to").get<size_t>();
}

static void to_json(json &j, const node& n) {}
static void from_json(const json &j, node& n) {
    n.id = j.at("id").get<size_t>();
    n.edges = j.at("edges").get<std::vector<size_t>>();
}

#endif //CFLOP_REQUEST_TYPES_H
