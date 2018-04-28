//
// Created by daniel on 28.04.18.
//

#include "request_types.h"

void from_json(const json &j, node &n) {
    n.id = j.at("id").get<size_t>();
    n.edges = j.at("edges").get<std::vector<size_t>>();
}

void from_json(const json &j, edge &e) {
    e.id = j.at("id").get<size_t>();
    e.from = j.at("from").get<size_t>();
    e.to = j.at("to").get<size_t>();
}
