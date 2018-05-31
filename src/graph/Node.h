//
// Created by daniel on 11.04.18.
//

#ifndef CFLOP_NODE_H
#define CFLOP_NODE_H

#include <cstddef>
#include <utility>

namespace graph {
    struct node_id {
    private:
        std::size_t m_id;
    public:
        explicit operator bool() const;

        operator size_t() const;

        bool operator==(const node_id &other) const;

        static node_id next_id();

        node_id(const node_id &other) = default;

        static node_id invalid_node();

        node_id(size_t t);

        static void reset();

    private:
        static size_t id;
    };

    struct node_hash{
        std::size_t operator() (const graph::node_id& c) const {
            return static_cast<size_t>(c);
        }
    };

}

namespace graph {
    template<typename N>
    using node = std::pair<const node_id, N>;

    template<typename N>
    node<N> from_parts(const size_t &id, N val) {
        return {node_id(id), val};
    }

    template<typename N>
    node<N> make_node(N val) {
        return std::make_pair<node_id, N>(node_id::next_id(), std::move(val));
    }
}

#endif //CFLOP_NODE_H
