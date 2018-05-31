//
// Created by daniel on 11.04.18.
//

#ifndef CFLOP_EDGE_H
#define CFLOP_EDGE_H

#include <cstddef>
#include <utility>
#include "Node.h"

namespace graph {

    struct edge_id {
        explicit operator bool() const;

        operator size_t() const;

        bool operator==(const edge_id &other) const;

        static edge_id next_id();

        edge_id(const edge_id &other) = default;

        edge_id(size_t t);

        static edge_id invalid();

        static void reset();

    private:
        static size_t id;
        std::size_t m_id;

    };

    struct edge_hash{
        std::size_t operator()(const graph::edge_id& c) const {
            return static_cast<size_t>(c);
        }
    };

}

namespace graph {

    template<typename E>
    struct edge_data {
        node_id from;
        node_id to;
        E val;

        edge_data(node_id from, node_id to, E val)
                : from(from), to(to), val(val) {}

        bool operator==(const edge_data &other) const {
            return other.from == from
                   && other.to == to
                   && other.val == val;
        }
    };

    template<typename E>
    using edge = std::pair<const edge_id, edge_data<E>>;

    template<typename E>
    edge<E> from_parts(size_t id, E val, node_id from, node_id to) {
        return std::make_pair(edge_id(id), edge_data<E>{from, to, val});
    }

    template<typename E>
    std::pair<const edge_id, edge_data<E>> make_edge(node_id from, node_id to, E val) {
        return std::make_pair(edge_id::next_id(), std::move(edge_data<E>{from, to, val}));
    }
}

#endif //CFLOP_EDGE_H
