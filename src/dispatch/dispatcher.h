//
// Created by vik on 29.04.18.
//

#ifndef CFLOP_DISPATCHER_H
#define CFLOP_DISPATCHER_H

#include "../input/include/input.h"
#include "../fsm/include/fsm.h"
#include "../output/include/output.h"


/**
 * decides what the request does executes it on the fsm, generates a response transforms it to json and returns it
 * @param r the request object generated out of a json
 * @param fsm a fsm object
 * @return json response
 */

//TODO: in output-lib Response + Response tojson()
//TODO: auf Reponse umschreiben


Response dispatch(Request& r, FinalStateMachine& fsm) {
    json j;
    switch(r.type) {
        case INVALID_TYPE: {
            std::string message = "invalid json input";
            failure_r_s res{message};
            j = res;
        }
            break;
        case NODES_POST: {
            // get the struct from the request
            auto req = std::get<nodes_post_s>(r.request);
            size_t id = fsm.add_state();
            // build the response struct with the return value of fsm
            nodes_post_r_s res{id};
            // make json from that
            Response()
        }
            break;
        case NODES_DELETE: {
            auto req = std::get<nodes_delete_s>(r.request);
            fsm.remove_node(req.id);
            nodes_delete_r_s res{};
            j = res;
        }
            break;
        case NODES_GET: {
            auto req = std::get<nodes_get_s>(r.request);
            auto node_pair = fsm.get_state(req.id);

            if(node_pair) {
                size_t id = node_pair->first;
                std::vector<edge_id> edges = fsm.get_adjacient_transitions(id);
                std::vector<size_t> edges_size_t = {edges.begin(), edges.end()};
                nodes_get_r_s res{id, edges_size_t};
            } else {
                // INVALID gleich wie INVALID TYPE
                // Node with id ... does not exist.
            }
        }
            break;
        case NODES_PUT_START: {
            auto req = std::get<nodes_put_start_s>(r.request);
            //TODO: can not fail?
            fsm.set_start(req.id);
            nodes_put_start_r_s res{};
            j = res;
        }
            break;
        case NODES_PUT_END: {
            auto req = std::get<nodes_put_end_s>(r.request);
            //TODO: can not fail?
            fsm.set_end(req.id);
            nodes_put_end_r_s res{};
            j = res;
        }
            break;
        case EDGES_GET: {
            auto req = std::get<edges_get_s>(r.request);
            auto edge_pair = fsm.get_transtion(req.id);
            size_t id = edge_pair->first;
            size_t from = edge_pair->second.from;
            size_t to = edge_pair->second.to;
            std::string transition = edge_pair->second.val.into();
            edges_get_r_s res{id, from, to, transition};
            j = res;
        }
            break;
        case EDGES_POST: {
            auto req = std::get<edges_post_s>(r.request);
            size_t id = fsm.add_transition(req.from, req.to, Transition::from(req.transition));
            if(id) {
                edges_post_r_s res{id};
                j = res;
            } else {
                // something went wrong... one of the nodes does not exists
            }
        }
            break;
        case EDGES_DELETE: {
            auto req = std::get<edges_delete_s>(r.request);
            fsm.remove_edge(req.id);
            edges_delete_r_s res{};
            j = res;
        }
            break;
        case STATE_GET: {
            auto req = std::get<state_get_s>(r.request);
            auto edges_fsm = fsm.get_Transitions();
            std::vector<edge> edges{};
            // transform an fsm_edge vector into a input-lib edge vector
            std::transform(edges_fsm.begin(), edges_fsm.end(), edges.begin(), [](edge fsm_edge) -> edge {
                return edge(fsm_edge.to, fsm_edge.from, fsm_edge.transition.into);
            });
            auto nodes_fsm = fsm.get_States();
            std::vector<node> nodes{};
            std::transform(nodes_fsm.begin(), nodes_fsm.end(), nodes.begin(), [](node fsm_node) -> node {
                std::vector<edge_id> edges{};
                fsm.get_adjacient_transitions(fsm_node.first);
                std::vector<size_t> edges_size_t = {edges.begin(), edges.end()};
                return node(fsm_node.id, edges_size_t);
            });
            size_t active = fsm.get_current();
            size_t start = fsm.get_start();
            size_t end = fsm.get_end();
            state_get_r_s res{nodes, edges, active, start, end};
        }
            break;
        case STATE_POST: {
            auto req = std::get<state_post_s>(r.request);
            std::vector<node> nodes = req.nodes;
            std::vector<edge> edges{} = req.edges;
            size_t active = req.active;
            size_t start = req.start;
            size_t end = req.end;

            fsm.add

            state_post_r_s res{};
            j = res;
        }
            break;
        case STATE_PUT: {
            auto req = std::get<state_put_s>(r.request);
            size_t id = fsm.advance(req.input);
            state_put_r_s res{id};
            j = res;
        }
            break;
    }
    return j;
}

#endif //CFLOP_DISPATCHER_H
