//
// Created by vik on 29.04.18.
//

#ifndef CFLOP_RESPONSE_TYPES_H
#define CFLOP_RESPONSE_TYPES_H

//TODO: to/from json + structs mit entsprechenden daten füllen

struct nodes_post_r_s {
    size_t id;
};
static void to_json(json &j, const nodes_post_r_s &res) {
    j["success"]["node"]["id"] = res.id;
}
static void from_json(const json &j, nodes_post_r_s &res) {}


struct nodes_delete_r_s {};
static void to_json(json &j, const nodes_delete_r_s &res) {
    j["success"] = {};
}
static void from_json(const json &j, nodes_delete_r_s &res) {}


struct nodes_get_r_s {
    size_t id;
    std::vector<edge> edges;
};
static void to_json(json &j, const nodes_get_r_s &res) {
    j["success"]["node"]["id"] = res.id;
    j["success"]["node"]["edges"] = res.edges;
}
static void from_json(const json &j, nodes_get_r_s &req) {}


struct nodes_put_start_r_s {};
static void to_json(json &j, const nodes_put_start_r_s &res) {
    j["success"] = {};
}
static void from_json(const json &j, nodes_put_start_r_s &req) {}


struct nodes_put_end_r_s {};
static void to_json(json &j, const nodes_put_end_r_s &res) {
    j["success"] = {};
}
static void from_json(const json &j, nodes_put_end_r_s &re


struct edges_get_r_s {

};

struct edges_post_r_s {

};

struct edges_delete_r_s {

};

struct state_get_r_s {

};

struct state_post_r_s {

};

struct state_put_r_s {

};

struct failure_r_s {
    std::string failure;
};


#endif //CFLOP_RESPONSE_TYPES_H
