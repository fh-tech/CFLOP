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
output_lib::Response dispatch(input_lib::Request& r, fsm::FinalStateMachine& fsm);

}

#endif //CFLOP_DISPATCHER_H
