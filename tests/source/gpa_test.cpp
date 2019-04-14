// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

#ifdef __linux__

TEST(gpa_test, random_matching_and_cycle_generator_fixed_test) {
    CSR <int> graph = cycle_generator<int>(11);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {3, 8, 10, 2, 5};
    expected.edge_e = {4, 9, 0, 1, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_washington_fixed_test) {
    CSR <int> graph = washington_test<int>(2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {3, 8, 2, 5};
    expected.edge_e = {1, 7, 4, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_zadeh_fixed_test) {
    CSR <int> graph = zadeh_test<int>(2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {3, 8, 11, 2, 0, 4};
    expected.edge_e = {6, 7, 10, 9, 1, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_cube_fixed_test) {
    CSR <int> graph = cube_test<int>(2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {3, 7, 1, 4};
    expected.edge_e = {2, 5, 0, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_stars_fixed_test) {
    CSR <int> graph = stars_generator<int>(2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {3, 8};
    expected.edge_e = {0, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_chain_fixed_test_1) {
    CSR <int> graph = chain_generator<int>(2, 3);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {3, 1};
    expected.edge_e = {4, 0};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_chain_fixed_test_2) {
    CSR <int> graph = chain_generator<int>(3, 2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {3, 5, 1};
    expected.edge_e = {2, 4, 0};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

#endif  // __linux__

#ifdef _WIN32

TEST(gpa_test, random_matching_and_cycle_generator_fixed_test) {
    CSR <int> graph = cycle_generator<int>(11);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {2, 9, 5, 7};
    expected.edge_e = {1, 10, 4, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_washington_fixed_test) {
    CSR <int> graph = washington_test<int>(2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {2, 6, 0, 5};
    expected.edge_e = {4, 7, 1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_zadeh_fixed_test) {
    CSR <int> graph = zadeh_test<int>(2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {2, 9, 0, 5, 7, 10};
    expected.edge_e = {3, 8, 1, 4, 6, 11};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_cube_fixed_test) {
    CSR <int> graph = cube_test<int>(2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {2, 6, 0, 5};
    expected.edge_e = {3, 7, 1, 4};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_stars_fixed_test) {
    CSR <int> graph = stars_generator<int>(2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {2, 9};
    expected.edge_e = {0, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_chain_fixed_test_1) {
    CSR <int> graph = chain_generator<int>(2, 3);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {2, 4, 0};
    expected.edge_e = {1, 5, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(gpa_test, random_matching_and_chain_fixed_test_2) {
    CSR <int> graph = chain_generator<int>(3, 2);
    Matching matching = GPA(graph, [](const CSR<int>& graph) {
        return random_matching(graph, 0, INT_MAX, 1070);
    });
    Matching expected;
    expected.edge_b = {2, 0};
    expected.edge_e = {4, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

#endif  // _WIN32
