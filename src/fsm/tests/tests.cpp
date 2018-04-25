//
// Created by daniel on 25.04.18.
//

#include <gtest/gtest.h>
#include <graph.h>
#include "../FinalStateMachine.h"

TEST(test, tester){
    ASSERT_TRUE(true);
}

TEST(fsm, fsm_test){
    FinalStateMachine fsm{};

    node_id s1 = fsm.add_state("Even Zero : Even One");
    node_id s2 = fsm.add_state("Odd  Zero : Even One");
    node_id s3 = fsm.add_state("Even Zero : Odd  One");
    node_id s4 = fsm.add_state("Odd  Zero : Odd  One");

    edge_id e1 = fsm.add_transition(s1, s3, Transition<char>{'1'});
    edge_id e2 = fsm.add_transition(s1, s2, Transition<char>{'0'});

    edge_id e3 = fsm.add_transition(s2, s4, Transition<char>{'1'});
    edge_id e4 = fsm.add_transition(s2, s1, Transition<char>{'0'});

    edge_id e5 = fsm.add_transition(s3, s1, Transition<char>{'1'});
    edge_id e6 = fsm.add_transition(s3, s4, Transition<char>{'0'});

    edge_id e7 = fsm.add_transition(s4, s2, Transition<char>{'1'});
    edge_id e8 = fsm.add_transition(s4, s3, Transition<char>{'0'});

    fsm.set_start(s1);
    fsm.set_end(s1);

    fsm.advance('0');
    fsm.advance('1');
    fsm.advance('1');
    fsm.advance('0');
    fsm.advance('1');
    fsm.advance('0');
    fsm.advance('1');
    fsm.advance('0');

    ASSERT_TRUE(fsm.check_end());


    fsm.advance('0');
    ASSERT_FALSE(fsm.check_end());
    fsm.advance('1');
    ASSERT_FALSE(fsm.check_end());
    fsm.advance('0');
    ASSERT_FALSE(fsm.check_end());
    fsm.advance('1');
    ASSERT_TRUE(fsm.check_end());

}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}