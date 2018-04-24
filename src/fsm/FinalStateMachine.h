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
    void advance(char symbol) {

        auto next = graph.get_adjacent(this->current);

        for(edge_id e_id: next){
            edge* e = graph.get_edge(e_id);
            if(e){
                if(e->second.val.matches(symbol)){
                    this->current = e->second.to;
                    graph.get_node(current)->second.visit();
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

    edge_id add_transition(node_id from, node_id to, Transition t){
        return graph.add_edge(from, to, std::move(t));
    }


private:
    Graph<State, Transition<char>> graph;
    node_id start;
    node_id end;
    node_id current;
};



#endif //CFLOP_FINALSTATEMACHINE_H
