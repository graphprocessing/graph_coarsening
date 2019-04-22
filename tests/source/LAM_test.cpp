// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

TEST(LAM_test, personal_test_csr_1) {
    CSR<int> graph;
    graph.n = 6;
    graph.offset = {0, 1, 2, 4, 5, 6, 6};
    graph.edges = {1, 2, 3, 4, 4, 5};
    graph.weights = {20, 1, 1, 10, 5, 17};
    Matching expected;
    Matching ans = LAM(graph);
    expected.edge_b = {0, 4, 2};
    expected.edge_e = {1, 5, 3};
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}

TEST(LAM_test, personal_test_csr_2) {
    CSR<int> graph;
    graph.n = 6;
    graph.offset = {0, 1, 2, 4, 5, 6, 6};
    graph.edges = {1, 2, 3, 4, 4, 5};
    graph.weights = {30, 1, 2, 1, 20, 19};
    Matching expected;
    Matching ans = LAM(graph);
    expected.edge_b = {0, 3};
    expected.edge_e = {1, 4};
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}

TEST(LAM_test, personal_test_csr_3) {
    CSR<double> graph;
    graph.n = 6;
    graph.offset = {0, 1, 2, 4, 5, 6, 6};
    graph.edges = {1, 2, 3, 4, 4, 5};
    graph.weights = {30.4, 1, 2, 30.395, 30.39, 19};
    Matching expected;
    Matching ans = LAM(graph);
    expected.edge_b = {0, 2};
    expected.edge_e = {1, 4};
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}
