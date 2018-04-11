//
// Created by daniel on 11.04.18.
//

#ifndef CFLOP_NODE_H
#define CFLOP_NODE_H

#include <cstddef>

struct node_id {
private:
    std::size_t m_id;
public:
    explicit operator bool() const {
        return m_id != 0;
    }
    operator size_t() const{
        return m_id;
    }

    static node_id next_id() {
        static size_t id = 0;
        return node_id{++id};
    }

    node_id(const node_id& other) = default;

private:
    node_id(size_t t): m_id(t) {}
};


namespace std {
    template <>
    struct hash<node_id>{
        std::size_t operator()(const node_id& c) const {
            return static_cast<size_t>(c);
        }
    };
};

template <typename N>
using node = std::pair<const node_id, N>;

template <typename N>
node<N> make_node(N val){
    return std::make_pair<node_id, N>(node_id::next_id(), std::move(val));
}


#endif //CFLOP_NODE_H
