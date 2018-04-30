//
// Created by vik on 29.04.18.
//

#ifndef CFLOP_DISPATCH_H
#define CFLOP_DISPATCH_H

#include "../input/include/input.h"
#include "../fsm/include/fsm.h"
#include "../output/include/output.h"


//TODO: function that takes a Request Object, a FinalStateMachine Object and makes a Response object out of it

/**
 * decides what the request does executes it on the fsm, generates a response transforms it to json and returns it
 * @param r the request object generated out of a json
 * @param fsm a fsm object
 * @return json response
 */
json dispatch(Request& r, FinalStateMachine& fsm) {
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
            //TODO: warum std::string übergeben
            size_t id = fsm.add_state();
            // build the response struct with the return value of fsm
            nodes_post_r_s res{id};
            // make json from that
            j = res;
        }
            break;
        case NODES_DELETE: {
            auto req = std::get<nodes_delete_s>(r.request);
            //TODO: delete can not fail?
            fsm.remove_node(req.id);
            nodes_delete_r_s res{};
            j = res;
        }
            break;
        case NODES_GET: {
            auto req = std::get<nodes_get_s>(r.request);
            fsm.get_States();
            //TODO: how to get a node?
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
            fsm.get_Transitions();
            //TODO how to get one edge
        }
            break;
        case EDGES_POST: {
            auto req = std::get<edges_post_s>(r.request);
            size_t id = fsm.add_transition(req.from, req.to, req.transition);
            edges_post_r_s res{id};
            j = res;
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
        }
            break;
        case STATE_POST: {
            auto req = std::get<state_post_s>(r.request);

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

#endif //CFLOP_DISPATCH_H
