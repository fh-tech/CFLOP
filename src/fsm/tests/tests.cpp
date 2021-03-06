//
// Created by daniel on 25.04.18.
//

#include <gtest/gtest.h>
#include <graph.h>
#include "../FinalStateMachine.h"

using namespace fsm;
using namespace graph;

TEST(fsm, test_export){
    node_id::reset();
    edge_id::reset();

    FinalStateMachine fsm{};

    node_id s1 = fsm.add_state();
    node_id s2 = fsm.add_state();
    node_id s3 = fsm.add_state();
    node_id s4 = fsm.add_state();

    edge_id e1 = fsm.add_transition(s1, s3, Transition<std::string>{"1"});
    edge_id e2 = fsm.add_transition(s1, s2, Transition<std::string>{"0"});
    edge_id e3 = fsm.add_transition(s2, s4, Transition<std::string>{"1"});
    edge_id e4 = fsm.add_transition(s2, s1, Transition<std::string>{"0"});
    edge_id e5 = fsm.add_transition(s3, s1, Transition<std::string>{"1"});
    edge_id e6 = fsm.add_transition(s3, s4, Transition<std::string>{"0"});
    edge_id e7 = fsm.add_transition(s4, s2, Transition<std::string>{"1"});
    edge_id e8 = fsm.add_transition(s4, s3, Transition<std::string>{"0"});

    auto edges = fsm.get_Transitions();

    std::vector<edge<Transition<std::string>>> test_v{
            from_parts<Transition<std::string>>(1, Transition<std::string>{"1"}, s1, s3),
            from_parts<Transition<std::string>>(2, Transition<std::string>{"0"}, s1, s2),
            from_parts<Transition<std::string>>(3, Transition<std::string>{"1"}, s2, s4),
            from_parts<Transition<std::string>>(4, Transition<std::string>{"0"}, s2, s1),
            from_parts<Transition<std::string>>(5, Transition<std::string>{"1"}, s3, s1),
            from_parts<Transition<std::string>>(6, Transition<std::string>{"0"}, s3, s4),
            from_parts<Transition<std::string>>(7, Transition<std::string>{"1"}, s4, s2),
            from_parts<Transition<std::string>>(8, Transition<std::string>{"0"}, s4, s3),
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
    node_id::reset();
    edge_id::reset();

    FinalStateMachine fsm{};

    node_id s1 = fsm.add_state();
    node_id s2 = fsm.add_state();
    node_id s3 = fsm.add_state();
    node_id s4 = fsm.add_state();

    edge_id e1 = fsm.add_transition(s1, s3, Transition<std::string>{"1"});
    edge_id e2 = fsm.add_transition(s1, s2, Transition<std::string>{"0"});
    edge_id e3 = fsm.add_transition(s2, s4, Transition<std::string>{"1"});
    edge_id e4 = fsm.add_transition(s2, s1, Transition<std::string>{"0"});
    edge_id e5 = fsm.add_transition(s3, s1, Transition<std::string>{"1"});
    edge_id e6 = fsm.add_transition(s3, s4, Transition<std::string>{"0"});
    edge_id e7 = fsm.add_transition(s4, s2, Transition<std::string>{"1"});
    edge_id e8 = fsm.add_transition(s4, s3, Transition<std::string>{"0"});

    fsm.set_start(s1);
    fsm.set_end(s1);

    ASSERT_EQ(fsm.advance("0"), s2);
    ASSERT_EQ(fsm.advance("1"), s4);
    ASSERT_EQ(fsm.advance("1"), s2);
    ASSERT_EQ(fsm.advance("0"), s1);
    ASSERT_EQ(fsm.advance("1"), s3);
    ASSERT_EQ(fsm.advance("0"), s4);
    ASSERT_EQ(fsm.advance("1"), s2);
    ASSERT_EQ(fsm.advance("0"), s1);

    ASSERT_TRUE(fsm.check_end());


    fsm.advance("0");
    ASSERT_FALSE(fsm.check_end());
    fsm.advance("1");
    ASSERT_FALSE(fsm.check_end());
    fsm.advance("0");
    ASSERT_FALSE(fsm.check_end());
    fsm.advance("1");
    ASSERT_TRUE(fsm.check_end());

}

TEST(fsm, equality){


    FinalStateMachine fsm1{};
    auto s11 = fsm1.add_state();
    auto s12 = fsm1.add_state();
    auto s13 = fsm1.add_state();

    auto t11 = fsm1.add_transition(s11, s12, {"a"});
    auto t12 = fsm1.add_transition(s13, s12, {"b"});

    FinalStateMachine fsm2{};
    auto s21 = fsm2.add_state();
    auto s22 = fsm2.add_state();
    auto s23 = fsm2.add_state();

    auto t21 = fsm2.add_transition(s21, s22, {"a"});
    auto t22 = fsm2.add_transition(s23, s22, {"b"});

    ASSERT_TRUE(fsm1 == fsm2);

    auto edges = fsm1.get_Transitions();
    auto nodes = fsm1.get_States();
    auto current = fsm1.get_current();
    auto start = fsm1.get_start();
    auto end = fsm1.get_end();

    FinalStateMachine fsm3(nodes, edges, start, end, current);

    ASSERT_TRUE(fsm1 == fsm3);


}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}