//
// Created by daniel on 25.04.18.
//

#ifndef CFLOP_FINALSTATEMACHINE_H
#define CFLOP_FINALSTATEMACHINE_H

#include "graph.h"
#include "State.h"
#include "Transition.h"


class FinalStateMachine {
public:

    FinalStateMachine() = default;

    FinalStateMachine(std::vector<node<State>> nodes,
                      std::vector<edge<Transition<std::string>>> edges,
                      node_id start, node_id end, node_id current)
        : graph(nodes, edges)
        , start(start)
        , end(end)
        , current(current)
    {}

    node_id advance(std::string symbol) {

        auto next = graph.get_adjacent(this->current);

        for (edge_id e_id: next) {
            edge<Transition<std::string>> *e = graph.get_edge(e_id);
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

    node_id add_state(){
        return graph.add_node(State{});
    }

    edge_id add_transition(node_id from, node_id to, Transition<std::string> t){
        return graph.add_edge(from, to, std::move(t));
    }

    void set_start(node_id id){
        this->start = id;
        this->current = id;
    }

    void set_end(node_id id){
        this->end = id;
    }

   node_id get_start(){
       return this->start;
    }

   node_id get_end(){
       return this->end;
    }

    node_id get_current(){
        return this->current;
    }

    void remove_node(node_id id) {
        graph.remove(id);
    }

    void remove_edge(edge_id id) {
        graph.remove(id);
    }

    std::vector<edge_id> get_adjacient_transitions(const node_id& id){
        return graph.get_adjacent(id);
    }

    node_id add_sate_form_parts(size_t& id, State& state){
        auto n = from_parts<State>(id, state);
        graph.insert_node(n);
        return n.first;
    }

    edge_id add_transition_from_parts(size_t& id, Transition<std::string>& t, node_id to, node_id from) {
        edge<Transition<std::string>> e = from_parts(id, t, to, from);
        graph.insert_edge(e);
        return e.first;
    }

    std::vector<edge<Transition<std::string>>> get_Transitions(){
        return graph.get_edges();
    }

    std::vector<node<State>> get_States(){
        return graph.get_nodes();
    }

    node<State>* get_state(const node_id& id){
        return graph.get_node(id);
    }

    edge<Transition<std::string>>* get_transtion(const edge_id& id){
        return graph.get_edge(id);
    }

    bool operator==(const FinalStateMachine& other){
        return graph == other.graph
            && start == other.start
            && end == other.end
            && current == other.current;
    }

private:
    Graph<State, Transition<std::string>> graph{};
    node_id start = node_id::invalid_node();
    node_id end = node_id::invalid_node();
    node_id current = node_id::invalid_node();
};



#endif //CFLOP_FINALSTATEMACHINE_H
