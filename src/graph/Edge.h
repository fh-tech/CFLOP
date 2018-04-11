//
// Created by daniel on 11.04.18.
//

#ifndef CFLOP_EDGE_H
#define CFLOP_EDGE_H

#include <cstddef>
#include "Node.h"

struct edge_id {
    explicit operator bool() const {
        return m_id != 0;
    }
    operator size_t() const {
        return m_id;
    }

    static edge_id next_id(){
        static size_t id = 0;
        return edge_id{++id};
    }

    edge_id(const edge_id& other) = default;

private:
    std::size_t m_id;
    edge_id(size_t t) : m_id(t) {}
};

namespace std {
    template <>
    struct hash<edge_id>{
        std::size_t operator()(const edge_id& c) const {
            return static_cast<size_t>(c);
        }
    };
};

template <typename E>
struct edge_data {
    node_id from;
    node_id to;
    E val;
};

template <typename E>
using edge = std::pair<const edge_id, edge_data<E>>;

template <typename E>
std::pair<const edge_id, edge_data<E>> make_edge(node_id from, node_id to, E val){
    return std::make_pair(edge_id::next_id(), std::move(edge_data<E>{from, to, val}));
}

#endif //CFLOP_EDGE_H
