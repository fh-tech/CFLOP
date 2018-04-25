//
// Created by vik on 25.04.18.
//

#ifndef CFLOP_REQUEST_TYPES_H
#define CFLOP_REQUEST_TYPES_H

#include <iostream>

struct node {
    size_t id;
    std::vector<size_t> edges{};
};

struct edge {
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



#endif //CFLOP_REQUEST_TYPES_H
