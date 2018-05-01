//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_REQUEST_TYPES_H
#define CFLOP_REQUEST_TYPES_H
#include <iostream>
#include <vector>

#include "../../libs/json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

namespace input_lib {

    struct node {
        size_t id = 0;
        std::vector<size_t> edges{};

        node() = default;

        node(size_t id, std::vector<size_t > &&vec)
                : id (id)
                , edges(std::move(vec))
        {}
    };
    static void to_json(json &j, const node& n) {
        j["id"] = n.id;
        j["edges"] = n.edges;
    }
    static void from_json(const json &j, node& n) {
        n.id = j.at("id").get<size_t>();
        n.edges = j.at("edges").get<std::vector<size_t>>();
    }


    struct edge {
        size_t id;
        size_t from;
        size_t to;
        std::string transition;
    };
    static void to_json(json &j, const edge& e) {
        j["id"] = e.id;
        j["from"] = e.from;
        j["to"] = e.to;
        j["transition"] = e.transition;
    }
    static void from_json(const json &j, edge& e) {
        e.id = j.at("id").get<size_t>();
        e.from = j.at("from").get<size_t>();
        e.to = j.at("to").get<size_t>();
    }

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
        std::string transition;
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
}


#endif //CFLOP_REQUEST_TYPES_H
