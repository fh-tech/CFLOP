//
// Created by daniel on 25.04.18.
//

#ifndef CFLOP_TRANSITION_H
#define CFLOP_TRANSITION_H

template <class T>
class Transition {

private:
    T t;

public:
    Transition(T t)
        :t(t)
    {}

    bool matches(T& other){
        return t == other;
    }

};


#endif //CFLOP_TRANSITION_H
