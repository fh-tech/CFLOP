#include <iostream>

#include <dispatch.h>
#include <input.h>
#include <output.h>

namespace in = input_lib;
namespace out = output_lib;
namespace dispatch = dispatch_lib;

int main() {

    in::Request r;
    fsm::FinalStateMachine fsm{};
    while (true){

        json j_in;
        std::cin >> j_in;
        r = j_in;
        auto response = dispatch::dispatch(r, fsm);
        json j_out = response;
        std::cout << j_out;
    }

}