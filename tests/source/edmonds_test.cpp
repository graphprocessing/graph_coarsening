// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

TEST(edmonds_test, personal_test_csr_1) {
    CSR<int> graph;
    graph.n = 10;
    graph.offset = {0, 4, 7, 10, 13, 16, 20, 24, 27, 31, 32};
    graph.edges = {9, 1, 7, 3, 2, 6, 0, 1, 6, 8, 4, 5, 0, 3, 5,
     8, 4, 8, 3, 6, 7, 2, 1, 5, 6, 8, 0, 5, 7, 2, 4, 0};
    Matching expected;
    Matching ans = edmonds(graph);
    expected.edge_b = {0, 1, 3, 5, 6};
    expected.edge_e = {9, 2, 4, 8, 7};
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}

TEST(edmonds_test, personal_test_csr_2) {
    CSR<int> graph;
    graph.n = 12;
    graph.offset = {0, 2, 6, 7, 10, 13, 19, 21, 24, 25, 28, 30, 32};
    graph.edges = {1, 3, 0, 2, 8, 5, 1, 4, 5, 0, 3, 6, 7, 3, 9, 10,
     6, 1, 7, 4, 5, 11, 4, 5, 1, 5, 10, 11, 5, 9, 7, 9};
    Matching expected;
    Matching ans = edmonds(graph);
    expected.edge_b = {1, 3, 4, 7, 9};
    expected.edge_e = {8, 5, 6, 11, 10};
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}

TEST(edmonds_test, personal_test_csr_3) {
    CSR<int> graph;
    Matching expected;
    graph.n = 10;
    graph.offset = {0, 2, 4, 6, 9, 11, 12, 15, 18, 19, 20};
    graph.edges = {1, 3, 0, 2, 1, 5, 0, 4, 6, 3, 6, 2, 3, 7, 4, 6, 8, 9, 7, 7};
    expected.edge_b = {0, 2, 4, 7};
    expected.edge_e = {3, 5, 6, 9};
    Matching ans = edmonds(graph);
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}

TEST(edmonds_test, personal_test_csr_4) {
    CSR<int> graph;
    Matching expected;
    graph.n = 2;
    graph.offset = {0, 1, 2};
    graph.edges = {1, 0};
    expected.edge_b = {0};
    expected.edge_e = {1};
    Matching ans = edmonds(graph);
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}

TEST(edmonds_test, personal_test_csr_5) {
    CSR<int> graph;
    Matching expected;
    graph.n = 3;
    graph.offset = {0, 2, 4, 6};
    graph.edges = {1, 2, 0, 2, 1, 0};
    expected.edge_b = {1};
    expected.edge_e = {2};
    Matching ans = edmonds(graph);
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}

TEST(edmonds_test, personal_test_csr_6) {
    CSR<int> graph;
    Matching expected;
    graph.n = 10;
    graph.offset = {0, 2, 5, 10, 14, 17, 21, 28, 32, 37, 40};
    graph.edges = {9, 1, 0, 6, 9, 4, 5, 3, 7, 6, 8, 2, 7, 5, 6, 2, 8,
     2, 8, 6, 3, 4, 7, 9, 1, 2, 5, 8, 3, 6, 2, 8, 3, 5, 4, 7, 6, 0, 6, 1};
    expected.edge_b = {0, 1, 2, 3, 4};
    expected.edge_e = {9, 6, 5, 7, 8};
    Matching ans = edmonds(graph);
    ASSERT_EQ(expected.edge_b, ans.edge_b);
    ASSERT_EQ(expected.edge_e, ans.edge_e);
}



