//
// Created by daniel on 25.04.18.
//

#ifndef CFLOP_FINALSTATEMACHINE_H
#define CFLOP_FINALSTATEMACHINE_H

#include "graph.h"
#include "State.h"
#include "Transition.h"

namespace fsm {

class FinalStateMachine {
public:

    FinalStateMachine() = default;

    FinalStateMachine(std::vector<graph::node<State>> nodes,
                      std::vector<graph::edge<Transition<std::string>>> edges,
                      graph::node_id start, graph::node_id end, graph::node_id current)
        : graph(nodes, edges)
        , start(start)
        , end(end)
        , current(current)
    {}

    graph::node_id advance(std::string symbol) {

        auto next = graph.get_adjacent(this->current);

        for (graph::edge_id e_id: next) {
            graph::edge<Transition<std::string>> *e = graph.get_edge(e_id);
            if (e) {
                if (e->second.val.matches(symbol)) {
                    this->current = { e->second.to };
                    graph.get_node(e->second.to)->second.visit();

                }
            }
        }

        return current;
    }

    bool check_end() const {
        return this->current == this->end;
    }

    graph::node_id add_state(){
        return graph.add_node(State{});
    }

    graph::edge_id add_transition(graph::node_id from, graph::node_id to, Transition<std::string> t){
        return graph.add_edge(from, to, std::move(t));
    }

    void set_start(graph::node_id id){
        this->start = id;
        this->current = id;
    }

    void set_end(graph::node_id id){
        this->end = id;
    }

    graph::node_id get_start(){
       return this->start;
    }

    graph::node_id get_end(){
       return this->end;
    }

    graph::node_id get_current(){
        return this->current;
    }

    void remove_node(graph::node_id id) {
        graph.remove(id);
    }

    void remove_edge(graph::edge_id id) {
        graph.remove(id);
    }

    std::vector<graph::edge_id> get_adjacient_transitions(const graph::node_id& id){
        return graph.get_adjacent(id);
    }

    graph::node_id add_sate_form_parts(size_t& id, State& state){
        auto n = graph::from_parts<State>(id, state);
        return graph.insert_node(n);
    }

    graph::edge_id add_transition_from_parts(size_t& id, Transition<std::string>& t, size_t to, size_t from) {
        graph::edge<Transition<std::string>> e = graph::from_parts(id, t, graph::node_id{to}, graph::node_id{from});
        return graph.insert_edge(e);
    }

    std::vector<graph::edge<Transition<std::string>>> get_Transitions(){
        return graph.get_edges();
    }

    std::vector<graph::node<State>> get_States(){
        return graph.get_nodes();
    }

    graph::node<State>* get_state(const graph::node_id& id){
        return graph.get_node(id);
    }

    graph::edge<Transition<std::string>>* get_transtion(const graph::edge_id& id){
        return graph.get_edge(id);
    }

    bool operator==(const FinalStateMachine& other){
        return graph   == other.graph
            && start   == other.start
            && end     == other.end
            && current == other.current;
    }

private:
    graph::Graph<State, Transition<std::string>> graph{};
    graph::node_id start = graph::node_id::invalid_node();
    graph::node_id end = graph::node_id::invalid_node();
    graph::node_id current = graph::node_id::invalid_node();
};

}

#endif //CFLOP_FINALSTATEMACHINE_H
