//
// Created by daniel on 11.04.18.
//

#ifndef CFLOP_GRAPH_H
#define CFLOP_GRAPH_H

#include "Edge.h"
#include "Node.h"
#include <unordered_map>
#include <bits/unordered_map.h>
#include <vector>
#include <iostream>

template <typename N, typename E>
class Graph {
private:
    std::unordered_map<node_id, N> nodes{};
    std::unordered_map<edge_id, edge_data<E>> edges{};
    std::unordered_multimap<node_id, edge_id> connections{};
public:
    Graph() = default;

    node_id add_node(N &&val){
        return std::get<0>(
                *std::get<0>(
                        nodes.emplace(std::move(make_node<N>(val)))
                ));
    }

    node<N>* get_node(node_id& id){
        auto search = nodes.find(id);
        if(search != nodes.end()){
            return &(*search);
        } else return nullptr;
    }


    edge_id add_edge(node_id from, node_id to, E&& val){
        auto id = std::get<0>(
                *std::get<0>(
                        edges.emplace(std::move(make_edge<E>(from, to, val)))
                ));
        connections.insert(std::make_pair(from, id));
        return  id;
    }

    edge<E>* get_edge(edge_id& id){
        auto search = edges.find(id);
        if(search != edges.end()){
            return &(*search);
        } else return nullptr;
    }

    std::vector<edge_id> get_adjacent(const node_id node) {
        auto [rbegin, rend] = connections.equal_range(node);

        std::vector<edge_id> ret{};
        for(auto it = rbegin; it != rend; ++it){
            ret.push_back(it->second);
        }
        return ret;
    };

    void remove(const node_id node) {
        nodes.erase(node);
        for( auto it = connections.begin(); it != connections.end(); ) {
            if( get_edge(it->second)->second.to   == node
            ||  get_edge(it->second)->second.from == node)
            {
                edges.erase(get_edge(it->second)->first);
                it = connections.erase(it);
            }
            else ++it;
        }
    }
};



#endif //CFLOP_GRAPH_H
