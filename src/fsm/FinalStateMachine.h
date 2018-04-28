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

    node_id advance(char symbol) {

        auto next = graph.get_adjacent(this->current);

        for (edge_id e_id: next) {
            edge<Transition<char>> *e = graph.get_edge(e_id);
            if (e) {
                if (e->second.val.matches(symbol)) {
                    this->current = {e->second.to};
                    graph.get_node(e->second.to)->second.visit();
                    return current;
                }
            }
        }


    }

    bool check_end() const {
        return this->current == this->end;
    }

    node_id add_state(std::string&& name){
        return graph.add_node({std::move(name)});
    }

    edge_id add_transition(node_id from, node_id to, Transition<char> t){
        return graph.add_edge(from, to, std::move(t));
    }

    void set_start(node_id id){
        this->start = id;
        this->current = id;
    }

    void set_end(node_id id){
        this->end = id;
    }

    void remove_node(node_id id) {
        graph.remove(id);
    }

    void remove_edge(edge_id id) {
        graph.remove(id);
    }


private:
    Graph<State, Transition<char>> graph{};
    node_id start = node_id::invalid_node();
    node_id end = node_id::invalid_node();
    node_id current = node_id::invalid_node();
};



#endif //CFLOP_FINALSTATEMACHINE_H
