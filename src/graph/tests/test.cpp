//
// Created by daniel on 11.04.18.
//

#include <gtest/gtest.h>
#include "../include/graph.h"

TEST(test, tester){
    ASSERT_TRUE(!false);
}

TEST(node, graph_makes_new_node){
    Graph<int, int> g{};
    auto id = g.add_node(4);
    ASSERT_EQ(4, g.get_node(id)->second);
}

TEST(edge, graph_makes_new_edge) {
    Graph<int, int> g{};
    auto id1 = g.add_node(1);
    auto id2 = g.add_node(2);

    auto eid = g.add_edge(id1, id2, 5);

    ASSERT_EQ(id1, g.get_edge(eid)->second.from);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}