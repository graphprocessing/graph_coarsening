// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

TEST(max_weight_matching_fixed_test, odd_cycle_test) {
    AL <int> graph = cycle_generator<int>(11);
    Matching matching = max_weight_matching<int>(graph);
    Matching expected;
    expected.edge_b = {10, 8, 6, 4, 2};
    expected.edge_e = {9, 7, 5, 3, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(max_weight_matching_fixed_test, even_cycle_test) {
    AL <int> graph = cycle_generator<int>(10);
    Matching matching = max_weight_matching<int>(graph);
    Matching expected;
    expected.edge_b = {9, 7, 5, 3, 1};
    expected.edge_e = {8, 6, 4, 2, 0};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(max_weight_matching_fixed_test, odd_path_test) {
    AL <int> graph;
    graph.n = 4;
    graph.edges.resize(graph.n);
    graph.weights.resize(graph.n);
    graph.edges[0].push_back(1);
    graph.edges[1].push_back(2);
    graph.edges[1].push_back(0);
    graph.edges[2].push_back(1);
    graph.edges[2].push_back(3);
    graph.edges[3].push_back(2);
    graph.weights[0].push_back(10);
    graph.weights[1].push_back(10);
    graph.weights[1].push_back(10);
    graph.weights[2].push_back(10);
    graph.weights[2].push_back(10);
    graph.weights[3].push_back(10);
    Matching matching = max_weight_matching<int>(graph);
    Matching expected;
    expected.edge_b = {0, 2};
    expected.edge_e = {1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(max_weight_matching_fixed_test, even_path_test) {
    AL <int> graph;
    graph.n = 5;
    graph.edges.resize(graph.n);
    graph.weights.resize(graph.n);
    graph.edges[0].push_back(1);
    graph.edges[1].push_back(2);
    graph.edges[1].push_back(0);
    graph.edges[2].push_back(1);
    graph.edges[2].push_back(3);
    graph.edges[3].push_back(2);
    graph.edges[3].push_back(4);
    graph.edges[4].push_back(3);
    graph.weights[0].push_back(10);
    graph.weights[1].push_back(10);
    graph.weights[1].push_back(10);
    graph.weights[2].push_back(10);
    graph.weights[2].push_back(10);
    graph.weights[3].push_back(10);
    graph.weights[3].push_back(10);
    graph.weights[4].push_back(10);
    Matching matching = max_weight_matching<int>(graph);
    Matching expected;
    expected.edge_b = {0, 2};
    expected.edge_e = {1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}
