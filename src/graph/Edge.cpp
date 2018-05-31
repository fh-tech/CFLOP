//
// Created by daniel on 01.05.18.
//

#include "Edge.h"
namespace graph {

    size_t edge_id::id = 0;

    edge_id::operator size_t() const {
        return m_id;
    }

    bool edge_id::operator==(const edge_id &other) const {
        return this->m_id == other.m_id;
    }

    edge_id edge_id::next_id() {
        return edge_id{++id};
    }

    edge_id::edge_id(size_t t) : m_id(t) {
        if (t > id) id = t;
    }

    edge_id edge_id::invalid() {
        return {0};
    }

    void edge_id::reset() {
        id = 0;
    }

    edge_id::operator bool() const {
        return m_id != 0;
    }
}