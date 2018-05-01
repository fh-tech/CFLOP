//
// Created by vik on 29.04.18.
//

#ifndef CFLOP_RESPONSE_TYPES_H
#define CFLOP_RESPONSE_TYPES_H

#include "../../../libs/json/single_include/nlohmann/json.hpp"
#include "../input/include/input.h"
using json = nlohmann::json;


struct nodes_post_r_s {
    size_t id;
};
static void to_json(json &j, const nodes_post_r_s &res) {
    j["success"]["node"]["id"] = res.id;
}
static void from_json(const json &j, nodes_post_r_s &res) {}


struct nodes_delete_r_s {};
static void to_json(json &j, const nodes_delete_r_s &res) {
    j["success"] = json::object();
}
static void from_json(const json &j, nodes_delete_r_s &res) {}


struct nodes_get_r_s {
    size_t id;
    std::vector<size_t> edges;
};
static void to_json(json &j, const nodes_get_r_s &res) {
    j["success"]["node"]["id"] = res.id;
    j["success"]["node"]["edges"] = res.edges;
}
static void from_json(const json &j, nodes_get_r_s &req) {}


struct nodes_put_start_r_s {};
static void to_json(json &j, const nodes_put_start_r_s &res) {
    j["success"] = json::object();
}
static void from_json(const json &j, nodes_put_start_r_s &req) {}


struct nodes_put_end_r_s {};
static void to_json(json &j, const nodes_put_end_r_s &res) {
    j["success"] = json::object();
}
static void from_json(const json &j, nodes_put_end_r_s &res) {}


struct edges_get_r_s {
    size_t id;
    size_t from;
    size_t to;
    std::string transition;
};
static void to_json(json &j, const edges_get_r_s &res) {
    j["success"]["edge"]["id"] = res.id;
    j["success"]["edge"]["from"] = res.from;
    j["success"]["edge"]["to"] = res.to;
    j["success"]["edge"]["transition"] = res.transition;
}
static void from_json(const json &j, edges_get_r_s &res) {}


struct edges_post_r_s {
    size_t id;
};
static void to_json(json &j, const edges_post_r_s &res) {
    j["success"]["edge"]["id"] = res.id;
}
static void from_json(const json &j, edges_post_r_s &res) {}


struct edges_delete_r_s {};
static void to_json(json &j, const edges_delete_r_s &res) {
    j["success"] = json::object();
}
static void from_json(const json &j, edges_delete_r_s &res) {}


struct state_get_r_s {
    std::vector<node> nodes;
    std::vector<edge> edges;
    size_t active;
    size_t start;
    size_t end;
};
static void to_json(json &j, const state_get_r_s &res) {
    j["success"]["state"]["nodes"] = res.nodes;
    j["success"]["state"]["edges"] = res.edges;
    j["success"]["state"]["active"] = res.active;
    j["success"]["state"]["start"] = res.start;
    j["success"]["state"]["end"] = res.end;
}
static void from_json(const json &j, state_get_r_s &res) {}


struct state_post_r_s {};
static void to_json(json &j, const state_post_r_s &res) {
    j["success"] = json::object();
}
static void from_json(const json &j, state_post_r_s &res) {}


struct state_put_r_s {
    size_t id;
};
static void to_json(json &j, const state_put_r_s &res) {
    j["success"]["node"]["id"] = res.id;
}
static void from_json(const json &j, state_put_r_s &res) {}


struct failure_r_s {
    std::string failure;
};
static void to_json(json &j, const failure_r_s &res) {
    j["error"]["message"] = res.failure;
}
static void from_json(const json &j, failure_r_s &res) {}


#endif //CFLOP_RESPONSE_TYPES_H
