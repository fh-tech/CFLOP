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
namespace graph {

    template <typename N, typename E>
    class Graph {

    private:
        std::unordered_map<node_id, N, node_hash> nodes{};
        std::unordered_map<edge_id, edge_data<E>, edge_hash> edges{};
        std::unordered_multimap<node_id, edge_id, node_hash> connections{};

    public:
        Graph() = default;

        Graph(std::vector<node<N>> nodes, std::vector<edge<E>> edges)
            : nodes(nodes.begin(), nodes.end())
            , edges(edges.begin(), edges.end())
        {
            for(auto &e: edges){
                connections.emplace(e.second.from, e.first);
            }
        }

        node_id add_node(N &&val){
            return std::get<0>(
                    *std::get<0>(
                            nodes.emplace(std::move(make_node<N>(val)))
                    ));
        }

        node<N>* get_node(const node_id& id){
            auto search = nodes.find(id);
            if(search != nodes.end()){
                return &(*search);
            } else return nullptr;
        }


        edge_id add_edge(node_id from, node_id to, E&& val){
            if(get_node(from) && get_node(to)) {
                auto id = std::get<0>(
                        *std::get<0>(
                                edges.emplace(std::move(make_edge<E>(from, to, val)))
                        ));
                connections.insert(std::make_pair(from, id));
                return  id;
            }else{
                return edge_id::invalid();
            }

        }

        node_id insert_node(const node<N>& n){
            nodes.insert(n);
            return n.first;
        }

        edge_id insert_edge(const edge<E>& e){
            auto etup = std::pair(e.second.from, e.first);
            if(get_node(e.second.from) && get_node(e.second.to)) {
                edges.insert(e);
                connections.insert(etup);
                return e.first;
            } else {
                return edge_id::invalid();
            }

        }

        edge<E>* get_edge(const edge_id& id){
            auto search = edges.find(id);
            if(search != edges.end()){
                return &(*search);
            } else return nullptr;
        }

        std::vector<edge_id> get_adjacent(const node_id& node) {
            auto [rbegin, rend] = connections.equal_range(node);

            std::vector<edge_id> ret{};
            for(auto it = rbegin; it != rend; ++it){
                ret.push_back(it->second);
            }
            return ret;
        };

        std::vector<edge<E>> get_edges(){
            return { edges.begin(), edges.end() };
        }

        std::vector<node<N>> get_nodes(){
            return { nodes.begin(), nodes.end() };
        }

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

        void remove(const edge_id id){
            edge<E>* e = get_edge(id);
            connections.erase(e->second.from);
            edges.erase(id);
        }

        bool operator==(const Graph& other){
            return nodes == other.nodes
                && edges == other.edges
                && connections == other.connections;
        }
    };
}


#endif //CFLOP_GRAPH_H
