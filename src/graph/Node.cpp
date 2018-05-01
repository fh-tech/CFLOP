//
// Created by daniel on 01.05.18.
//

#include "Node.h"
namespace graph {
    size_t node_id::id = 0;

    node_id::operator bool() const {
        return m_id != 0;
    }

    node_id::operator size_t() const {
        return m_id;
    }

    bool node_id::operator==(const node_id &other) const {
        return ((size_t) *this) == (size_t) other;
    }

    node_id node_id::next_id() {
        return node_id{++id};
    }

    node_id node_id::invalid_node() {
        return {0};
    }

    node_id::node_id(size_t t) : m_id(t) {
        if (t > id) id = t;
    }

    void node_id::reset() {
        id = 0;
    }
}