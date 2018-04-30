//
// Created by daniel on 25.04.18.
//

#include <gtest/gtest.h>
#include <graph.h>
#include "../FinalStateMachine.h"

TEST(fsm, test_export){
    FinalStateMachine fsm{};

    node_id s1 = fsm.add_state();
    node_id s2 = fsm.add_state();
    node_id s3 = fsm.add_state();
    node_id s4 = fsm.add_state();

    edge_id e1 = fsm.add_transition(s1, s3, Transition<char>{'1'});
    edge_id e2 = fsm.add_transition(s1, s2, Transition<char>{'0'});

    edge_id e3 = fsm.add_transition(s2, s4, Transition<char>{'1'});
    edge_id e4 = fsm.add_transition(s2, s1, Transition<char>{'0'});

    edge_id e5 = fsm.add_transition(s3, s1, Transition<char>{'1'});
    edge_id e6 = fsm.add_transition(s3, s4, Transition<char>{'0'});

    edge_id e7 = fsm.add_transition(s4, s2, Transition<char>{'1'});
    edge_id e8 = fsm.add_transition(s4, s3, Transition<char>{'0'});

    auto edges = fsm.get_Transitions();

    std::vector<edge<Transition<char>>> test_v{
            from_parts<Transition<char>>(1, Transition<char>{'1'}, s1, s3),
            from_parts<Transition<char>>(2, Transition<char>{'0'}, s1, s2),

            from_parts<Transition<char>>(3, Transition<char>{'1'}, s2, s4),
            from_parts<Transition<char>>(4, Transition<char>{'0'}, s2, s1),

            from_parts<Transition<char>>(5, Transition<char>{'1'}, s3, s1),
            from_parts<Transition<char>>(6, Transition<char>{'0'}, s3, s4),

            from_parts<Transition<char>>(7, Transition<char>{'1'}, s4, s2),
            from_parts<Transition<char>>(8, Transition<char>{'0'}, s4, s3),
    };

    ASSERT_TRUE(std::is_permutation(
            edges.begin(),
            edges.end(),
            test_v.begin()
    ));

}

TEST(test, tester){
    ASSERT_TRUE(true);
}

TEST(fsm, test_run){
    FinalStateMachine fsm{};

    node_id s1 = fsm.add_state();
    node_id s2 = fsm.add_state();
    node_id s3 = fsm.add_state();
    node_id s4 = fsm.add_state();

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

    ASSERT_EQ(fsm.advance('0'), s2);
    ASSERT_EQ(fsm.advance('1'), s4);
    ASSERT_EQ(fsm.advance('1'), s2);
    ASSERT_EQ(fsm.advance('0'), s1);
    ASSERT_EQ(fsm.advance('1'), s3);
    ASSERT_EQ(fsm.advance('0'), s4);
    ASSERT_EQ(fsm.advance('1'), s2);
    ASSERT_EQ(fsm.advance('0'), s1);

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