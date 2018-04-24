//
// Created by daniel on 25.04.18.
//

#include <gtest/gtest.h>
#include <graph.h>
#include "../FinalStateMachine.h"

TEST(test, tester){
    ASSERT_TRUE(true);
}

TEST(fsm, transitions){
    FinalStateMachine fsm{};

    auto s1 = fsm.add_state("Even Zero : Even One");
    auto s2 = fsm.add_state("Odd  Zero : Even One");
    auto s3 = fsm.add_state("Even Zero : Odd  One");
    auto s4 = fsm.add_state("Odd  Zero : Odd  One");

    auto e1 = fsm.add_transition(s1, s3, Transition{'1'});
    auto e2 = fsm.add_transition(s1, s2, Transition{'0'});

    auto e3 = fsm.add_transition(s2, s4, Transition{'1'});
    auto e4 = fsm.add_transition(s1, s2, Transition{'0'});

    auto e5 = fsm.add_transition(s3, s1, Transition{'1'});
    auto e6 = fsm.add_transition(s3, s4, Transition{'0'});

    auto e7 = fsm.add_transition(s4, s2, Transition{'1'});
    auto e8 = fsm.add_transition(s4, s3, Transition{'0'});

    fsm.advance('0');
    fsm.advance('1');
    fsm.advance('1');
    fsm.advance('0');
    fsm.advance('1');
    fsm.advance('0');
    fsm.advance('1');
    fsm.advance('0');

}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}