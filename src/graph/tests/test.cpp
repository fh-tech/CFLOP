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
    edge_id::reset();
    node_id::reset();

    auto id = g.add_node(4);
    ASSERT_EQ(4, g.get_node(id)->second);
}

TEST(edge, graph_makes_new_edge) {
    Graph<int, int> g{};
    edge_id::reset();
    node_id::reset();

    auto id1 = g.add_node(1);
    auto id2 = g.add_node(2);

    auto eid = g.add_edge(id1, id2, 5);

    ASSERT_EQ(id1, g.get_edge(eid)->second.from);
}

TEST(graph, connection){
    Graph<int, int> g{};
    edge_id::reset();
    node_id::reset();

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
    edge_id::reset();
    node_id::reset();

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

TEST(graph, check_adjacient){
    Graph<int, int> g{};
    edge_id::reset();
    node_id::reset();

    auto nid1 = g.add_node(1);
    auto nid2 = g.add_node(1);
    auto nid3 = g.add_node(1);
    auto nid4 = g.add_node(1);
    auto nid5 = g.add_node(1);

    auto eid1 = g.add_edge(nid1, nid2, 1);
    auto eid2 = g.add_edge(nid2, nid3, 1);
    auto eid3 = g.add_edge(nid4, nid3, 1);
    auto eid4 = g.add_edge(nid4, nid1, 1);

    auto eid5 = g.add_edge(nid5, nid1, 1);
    auto eid6 = g.add_edge(nid2, nid5, 1);
    auto eid7 = g.add_edge(nid3, nid5, 1);
    auto eid8 = g.add_edge(nid4, nid5, 1);

    auto adj1 = g.get_adjacent(nid1);
    ASSERT_TRUE(std::is_permutation(adj1.begin(), adj1.end(), std::vector{eid1}.begin()));

    auto adj2 = g.get_adjacent(nid2);
    ASSERT_TRUE(std::is_permutation(adj2.begin(), adj2.end(), std::vector{eid2, eid6}.begin()));

    auto adj3 = g.get_adjacent(nid3);
    ASSERT_TRUE(std::is_permutation(adj3.begin(), adj3.end(), std::vector{eid7}.begin()));

    auto adj4 = g.get_adjacent(nid4);
    ASSERT_TRUE(std::is_permutation(adj4.begin(), adj4.end(), std::vector{eid3, eid8, eid4}.begin()));

    auto adj5 = g.get_adjacent(nid5);
    ASSERT_TRUE(std::is_permutation(adj5.begin(), adj5.end(), std::vector{eid5}.begin()));

}

TEST(graph, remove_node_adj){
    Graph<int, int> g{};
    edge_id::reset();
    node_id::reset();

    auto nid1 = g.add_node(1);
    auto nid2 = g.add_node(1);
    auto nid3 = g.add_node(1);
    auto nid4 = g.add_node(1);
    auto nid5 = g.add_node(1);

    auto eid1 = g.add_edge(nid1, nid2, 1);
    auto eid2 = g.add_edge(nid2, nid3, 1);
    auto eid3 = g.add_edge(nid4, nid3, 1);
    auto eid4 = g.add_edge(nid4, nid1, 1);

    auto eid5 = g.add_edge(nid5, nid1, 1);
    auto eid6 = g.add_edge(nid2, nid5, 1);
    auto eid7 = g.add_edge(nid3, nid5, 1);
    auto eid8 = g.add_edge(nid4, nid5, 1);

    g.remove(nid5);

    auto adj1 = g.get_adjacent(nid1);
    ASSERT_TRUE(std::is_permutation(adj1.begin(), adj1.end(), std::vector{eid1}.begin()));

    auto adj2 = g.get_adjacent(nid2);
    ASSERT_TRUE(std::is_permutation(adj2.begin(), adj2.end(), std::vector{eid2}.begin()));

    auto adj3 = g.get_adjacent(nid3);
    ASSERT_TRUE(std::is_permutation(adj3.begin(), adj3.end(), std::vector<edge_id>{}.begin()));

    auto adj4 = g.get_adjacent(nid4);
    ASSERT_TRUE(std::is_permutation(adj4.begin(), adj4.end(), std::vector{eid3, eid4}.begin()));

    auto adj5 = g.get_adjacent(nid5);
    ASSERT_TRUE(std::is_permutation(adj5.begin(), adj5.end(), std::vector<edge_id>{}.begin()));
}

TEST(graph, remove_edge){
    Graph<int, int> g{};
    edge_id::reset();
    node_id::reset();

    auto nid1 = g.add_node(1);
    auto nid2 = g.add_node(1);
    auto nid3 = g.add_node(1);
    auto nid4 = g.add_node(1);
    auto nid5 = g.add_node(1);

    auto eid1 = g.add_edge(nid1, nid2, 1);
    auto eid2 = g.add_edge(nid2, nid3, 1);
    auto eid3 = g.add_edge(nid4, nid3, 1);
    auto eid4 = g.add_edge(nid4, nid1, 1);

    auto eid5 = g.add_edge(nid5, nid1, 1);
    auto eid6 = g.add_edge(nid2, nid5, 1);
    auto eid7 = g.add_edge(nid3, nid5, 1);
    auto eid8 = g.add_edge(nid4, nid5, 1);

    g.remove(eid8);

    auto adj1 = g.get_adjacent(nid1);
    ASSERT_TRUE(std::is_permutation(adj1.begin(), adj1.end(), std::vector{eid1}.begin()));

    auto adj2 = g.get_adjacent(nid2);
    ASSERT_TRUE(std::is_permutation(adj2.begin(), adj2.end(), std::vector{eid2, eid6}.begin()));

    auto adj3 = g.get_adjacent(nid3);
    ASSERT_TRUE(std::is_permutation(adj3.begin(), adj3.end(), std::vector{eid7}.begin()));

    auto adj4 = g.get_adjacent(nid4);
    ASSERT_TRUE(std::is_permutation(adj4.begin(), adj4.end(), std::vector{eid3, eid4}.begin()));

    auto adj5 = g.get_adjacent(nid5);
    ASSERT_TRUE(std::is_permutation(adj5.begin(), adj5.end(), std::vector{eid5}.begin()));


    g.remove(eid7);

    auto adj11 = g.get_adjacent(nid1);
    ASSERT_TRUE(std::is_permutation(adj11.begin(), adj11.end(), std::vector{eid1}.begin()));

    auto adj12 = g.get_adjacent(nid2);
    ASSERT_TRUE(std::is_permutation(adj12.begin(), adj12.end(), std::vector{eid2, eid6}.begin()));

    auto adj13 = g.get_adjacent(nid3);
    ASSERT_TRUE(std::is_permutation(adj13.begin(), adj13.end(), std::vector<edge_id>().begin()));

    auto adj14 = g.get_adjacent(nid4);
    ASSERT_TRUE(std::is_permutation(adj14.begin(), adj14.end(), std::vector{eid3, eid4}.begin()));

    auto adj15 = g.get_adjacent(nid5);
    ASSERT_TRUE(std::is_permutation(adj15.begin(), adj15.end(), std::vector{eid5}.begin()));

}

TEST(node, from_parts){
    edge_id::reset();
    node_id::reset();

    node<char> n = make_node('1');
    node<char> n2 = make_node('2');

    node<char> t1 = from_parts((size_t)n.first, '1');
    node<char> t2 = from_parts((size_t)n2.first, '2');

    ASSERT_EQ(n, t1);
    ASSERT_EQ(n2, t2);
}

TEST(edge, from_parts){
    edge_id::reset();
    node_id::reset();

    auto n1 = make_node('1');
    auto n2 = make_node('1');
    auto n3 = make_node('1');
    auto n4 = make_node('1');

    auto e1 = make_edge(n1.first, n2.first, 1);
    auto e2 = make_edge(n3.first, n1.first, 2);
    auto e3 = make_edge(n4.first, n2.first, 3);

    auto t1 = from_parts(1, 1, n1.first, n2.first);
    auto t2 = from_parts(2, 2, n3.first, n1.first);
    auto t3 = from_parts(3, 3, n4.first, n2.first);

    ASSERT_EQ(e1, t1);
    ASSERT_EQ(e2, t2);
    ASSERT_EQ(e3, t3);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}