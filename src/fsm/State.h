//
// Created by daniel on 25.04.18.
//

#ifndef CFLOP_STATE_H
#define CFLOP_STATE_H

class State {
private:
    std::string name;
public:
    State(std::string&& name)
        : name(std::move(name))
    {}

    void visit(){
        std::cout << "Visited state " << name << std::endl;
    }
};


#endif //CFLOP_STATE_H
