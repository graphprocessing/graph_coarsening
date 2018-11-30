// Copyright [year] <Copyright Owner>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <random>
#include "../../modules/data_structures/include/graph.h"
#include "../../modules/data_structures/include/csr.h"
#include "../../modules/data_structures/include/jds.h"
#include "../../modules/generators/include/washington_test.h"
#include "../../modules/generators/include/zadeh_test.h"
#include "../../modules/generators/include/cube_test.h"
#include "../../modules/algorithms/include/random_matching.h"
#include "../../modules/algorithms/include/hard_matching.h"

TEST(random_matching_fixed_test, basic_washington_test_csr) {
    CSR graph = washington_test(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 2, 5, 7};
    expected.edge_e = {1, 4, 6, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al) {
    AL graph = washington_test(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 2, 5, 7};
    expected.edge_e = {1, 4, 6, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr) {
    CSR graph = zadeh_test(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {1, 2, 4, 5, 8, 3};
    expected.edge_e = {6, 7, 10, 9, 12, 11};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al) {
    AL graph = zadeh_test(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {1, 2, 4, 5, 8, 3};
    expected.edge_e = {6, 7, 10, 9, 12, 11};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr) {
    CSR graph = cube_test(2);
    Matching matching = random_matching(graph, 0, graph.n, 20);
    Matching expected;
    expected.edge_b = {0, 4, 5, 7};
    expected.edge_e = {2, 6, 1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al) {
    AL graph = cube_test(2);
    Matching matching = random_matching(graph, 0, graph.n, 20);
    Matching expected;
    expected.edge_b = {0, 4, 5, 7};
    expected.edge_e = {2, 6, 1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}
