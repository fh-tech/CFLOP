//
// Created by daniel on 01.05.18.
//

#include "dispatcher.h"

namespace dispatch_lib {
    //REVIEW: zum ausprobiern mit 'Strg+Alt+M' extract method heraus gehoben
    // sieht vl besser aus
    output_lib::Response dispatch_invalid(const input_lib::Request &r) {
        std::__cxx11::string message = "invalid json input";
        output_lib::failure_r_s res{message};
        return output_lib::Response(r.type, res);
    }

    output_lib::Response dispatch_nodes_post(const input_lib::Request &r, fsm::FinalStateMachine &fsm) {// get the struct from the request
        auto req = std::get<input_lib::nodes_post_s>(r.request);
        graph::node_id id = fsm.add_state();
        // build the output_lib::Response struct with the return value of fsm
        output_lib::nodes_post_r_s res{id};
        // make json from that
        return output_lib::Response(r.type, res);
    }

    output_lib::Response dispatch(input_lib::Request &r, fsm::FinalStateMachine &fsm) {
        json j;
        switch (r.type) {
            case input_lib::INVALID_TYPE: {
                return dispatch_invalid(r);
            }
            case input_lib::NODES_POST: {
                return dispatch_nodes_post(r, fsm);
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

                if (node_pair) {
                    size_t id = node_pair->first;
                    std::vector<graph::edge_id> edges = fsm.get_adjacient_transitions(id);
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

                size_t id = fsm.add_transition(
                        req.from,
                        req.to,
                        fsm::Transition<std::string>::from(req.transition)
                );

                if (id) {
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
                //TODO: control that - i cant handle working with grap and fsm lib
                auto req = std::get<input_lib::state_get_s>(r.request);
                auto edges_fsm = fsm.get_Transitions();
                std::vector<input_lib::edge> edges{};
                // transform an fsm_edge vector into a input-lib edge vector
                std::transform(edges_fsm.begin(), edges_fsm.end(), edges.begin(), [](auto fsm_edge) -> input_lib::edge {
                    //TODO: maybe not necessary idk
                    size_t id = fsm_edge.first;
                    size_t to = fsm_edge.second.to;
                    size_t from = fsm_edge.second.from;
                    std::string transition = fsm_edge.second.val.into();
                    //TODO: no idea why - constructor exists
                    return input_lib::edge{id, to, from, transition};
                });
                auto nodes_fsm = fsm.get_States();
                std::vector<input_lib::node> nodes{};
                std::transform(nodes_fsm.begin(), nodes_fsm.end(), nodes.begin(),
                               [&fsm](auto fsm_node) -> input_lib::node {
                                   std::vector<graph::edge_id> edges{};
                                   fsm.get_adjacient_transitions(fsm_node.first);
                                   std::vector<size_t> edges_size_t = {edges.begin(), edges.end()};
                                   size_t id = fsm_node.first;
                                   //TODO: no idea why - constructor exists
                                   return input_lib::node{id, edges_size_t};
                               });
                size_t active = fsm.get_current();
                size_t start = fsm.get_start();
                size_t end = fsm.get_end();
                output_lib::state_get_r_s res{nodes, edges, active, start, end};
                return output_lib::Response(r.type, res);
            }
            case input_lib::STATE_POST: {
                auto req = std::get<input_lib::state_post_s>(r.request);
                std::vector<input_lib::node> nodes = req.nodes;
                std::vector<input_lib::edge> edges = req.edges;
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
