//
// Created by daniel on 25.04.18.
//

#ifndef CFLOP_STATE_H
#define CFLOP_STATE_H
namespace fsm {

    class State {

    public:
        State() {}

        void visit() {}

        bool operator==(const State other) const {
            return true;
        }
    };

}
#endif //CFLOP_STATE_H
