//
// Created by vik on 29.04.18.
//

#ifndef CFLOP_DISPATCHER_H
#define CFLOP_DISPATCHER_H

#include "../input/include/input.h"
#include "../fsm/include/fsm.h"
#include "../output/include/output.h"

namespace dispatch_lib {

/**
 * decides what the request does executes it on the fsm, generates a response transforms it to json and returns it
 * @param r the request object generated out of a json
 * @param fsm a fsm object
 * @return json response
 */
output_lib::Response dispatch(input_lib::Request& r, FinalStateMachine& fsm) {
    json j;
    switch(r.type) {
        case input_lib::INVALID_TYPE: {
            std::string message = "invalid json input";
            output_lib::failure_r_s res{message};
            return output_lib::Response(r.type, res);
        }
        case input_lib::NODES_POST: {
            // get the struct from the request
            auto req = std::get<input_lib::nodes_post_s>(r.request);
            size_t id = fsm.add_state();
            // build the output_lib::Response struct with the return value of fsm
            output_lib::nodes_post_r_s res{id};
            // make json from that
            return output_lib::Response(r.type, res);
        }
        case input_lib::NODES_DELETE: {
            auto req = std::get<input_lib::nodes_delete_s>(r.request);
            fsm.remove_node(req.id);
            output_lib::nodes_delete_r_s res{};
            return output_lib::Response(r.type, res);
        }
        case input_lib::NODES_GET: {
            auto req = std::get<input_lib::nodes_get_s>(r.request);
            auto node_pair = fsm.get_state(req.id);

            if(node_pair) {
                size_t id = node_pair->first;
                std::vector<edge_id> edges = fsm.get_adjacient_transitions(id);
                std::vector<size_t> edges_size_t = {edges.begin(), edges.end()};
                output_lib::nodes_get_r_s res{id, edges_size_t};
                return output_lib::Response(r.type, res);
            } else {
                std::string message = "Node with requested id does not exist";
                output_lib::failure_r_s res{message};
                return output_lib::Response(input_lib::INVALID_TYPE, res);
            }
        }
        case input_lib::NODES_PUT_START: {
            auto req = std::get<input_lib::nodes_put_start_s>(r.request);
            //TODO: can not fail?
            fsm.set_start(req.id);
            output_lib::nodes_put_start_r_s res{};
            return output_lib::Response(r.type, res);
        }
        case input_lib::NODES_PUT_END: {
            auto req = std::get<input_lib::nodes_put_end_s>(r.request);
            //TODO: can not fail?
            fsm.set_end(req.id);
            output_lib::nodes_put_end_r_s res{};
            return output_lib::Response(r.type, res);
        }
        case input_lib::EDGES_GET: {
            auto req = std::get<input_lib::edges_get_s>(r.request);
            auto edge_pair = fsm.get_transtion(req.id);
            size_t id = edge_pair->first;
            size_t from = edge_pair->second.from;
            size_t to = edge_pair->second.to;
            std::string transition = edge_pair->second.val.into();
            output_lib::edges_get_r_s res{id, from, to, transition};
            return output_lib::Response(r.type, res);
        }
        case input_lib::EDGES_POST: {
            auto req = std::get<input_lib::edges_post_s>(r.request);
            size_t id = fsm.add_transition(req.from, req.to, Transition::from(req.transition));
            if(id) {
                output_lib::edges_post_r_s res{id};
                return output_lib::Response(r.type, res);
            } else {
                std::string message = "Something went wrong... one of the nodes does not exists";
                output_lib::failure_r_s res{message};
                return output_lib::Response(input_lib::INVALID_TYPE, res);
            }
        }
        case input_lib::EDGES_DELETE: {
            auto req = std::get<input_lib::edges_delete_s>(r.request);
            fsm.remove_edge(req.id);
            output_lib::edges_delete_r_s res{};
            return output_lib::Response(r.type, res);
        }
        case input_lib::STATE_GET: {
            auto req = std::get<input_lib::state_get_s>(r.request);
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
            output_lib::state_get_r_s res{nodes, edges, active, start, end};
            return output_lib::Response(r.type, res);
        }
        case input_lib::STATE_POST: {
            auto req = std::get<input_lib::state_post_s>(r.request);
            std::vector<node> nodes = req.nodes;
            std::vector<edge> edges{} = req.edges;
            size_t active = req.active;
            size_t start = req.start;
            size_t end = req.end;

            // TODO: finish this
            output_lib::state_post_r_s res{};
            return output_lib::Response(r.type, res);
        }
        case input_lib::STATE_PUT: {
            auto req = std::get<input_lib::state_put_s>(r.request);
            size_t id = fsm.advance(req.input);
            output_lib::state_put_r_s res{id};
            return output_lib::Response(r.type, res);
        }
    }
}

}

#endif //CFLOP_DISPATCHER_H
