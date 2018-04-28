//
// Created by daniel on 11.04.18.
//

#include <gtest/gtest.h>
#include <stack>
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

TEST(graph, connection){
    Graph<int, int> g{};
    auto id1 = g.add_node(1);
    auto id2 = g.add_node(2);

    auto eid1 = g.add_edge(id1, id2, 5);
    auto id3 = g.add_node(1);
    auto eid2 = g.add_edge(id1, id2, 5);
    auto eid3 = g.add_edge(id1, id3, 10);

    auto expected = std::vector
            { eid1
            , eid2
            , eid3
            };
    auto adj =  g.get_adjacent(id1);
    auto res = std::is_permutation(expected.begin(), expected.end(), adj.begin(), adj.end());
    ASSERT_TRUE(res);
}

TEST(graph, remove_node){
    Graph<int, int> g{};

    auto id1 = g.add_node(1);
    auto id2 = g.add_node(2);
    auto id3 = g.add_node(1);
    auto id4 = g.add_node(1);

    auto eid1 = g.add_edge(id1, id2, 5);
    auto eid2 = g.add_edge(id1, id2, 5);
    auto eid3 = g.add_edge(id1, id3, 10);

    auto eid4 = g.add_edge(id2, id1, 2);
    auto eid5 = g.add_edge(id3, id1, 2);

    auto eid6 = g.add_edge(id2, id3, 2);
    auto eid7 = g.add_edge(id2, id4, 2);
    auto eid8 = g.add_edge(id4, id3, 2);

    g.remove(id1);

    ASSERT_EQ(g.get_edge(eid1), nullptr);
    ASSERT_EQ(g.get_edge(eid2), nullptr);
    ASSERT_EQ(g.get_edge(eid3), nullptr);
    ASSERT_EQ(g.get_edge(eid4), nullptr);
    ASSERT_EQ(g.get_edge(eid5), nullptr);

    ASSERT_NE(g.get_edge(eid6), nullptr);
    ASSERT_NE(g.get_edge(eid7), nullptr);
    ASSERT_NE(g.get_edge(eid8), nullptr);

    ASSERT_EQ(g.get_node(id1), nullptr);
    ASSERT_NE(g.get_node(id2), nullptr);
    ASSERT_NE(g.get_node(id3), nullptr);
    ASSERT_NE(g.get_node(id4), nullptr);


}

TEST(graph, remove_edge){
    Graph<int, int> g{};

    auto nid1 = g.add_node(10);
    auto nid2 = g.add_node(20);
    auto nid3 = g.add_node(30);
    auto nid4 = g.add_node(40);

    auto eid1 = g.add_edge(nid1, nid2, 100);
    auto eid2 = g.add_edge(nid2, nid3, 100);
    auto eid3 = g.add_edge(nid1, nid3, 100);
    auto eid4 = g.add_edge(nid4, nid1, 100);

    auto adj1 = g.get_adjacent(nid1);
    auto adj2 = g.get_adjacent(nid2);
    auto adj3 = g.get_adjacent(nid3);
    auto adj4 = g.get_adjacent(nid4);


    ASSERT_EQ(1,1);

}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}