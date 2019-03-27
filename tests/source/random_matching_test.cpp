// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

#ifdef __linux__

TEST(random_matching_fixed_test, basic_washington_test_csr) {
    CSR<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 2, 5, 7};
    expected.edge_e = {1, 4, 6, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 2, 5, 7};
    expected.edge_e = {1, 4, 6, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 1, 2, 4, 8};
    expected.edge_e = {5, 6, 11, 9, 7};
    std::cout << std::endl;
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 1, 2, 4, 8};
    expected.edge_e = {5, 6, 11, 9, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 20);
    Matching expected;
    expected.edge_b = {0, 4, 5, 7};
    expected.edge_e = {2, 6, 1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 20);
    Matching expected;
    expected.edge_b = {0, 4, 5, 7};
    expected.edge_e = {2, 6, 1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_2) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 59);
    Matching expected;
    expected.edge_b = {0, 2, 3, 6};
    expected.edge_e = {1, 4, 5, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_2) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 59);
    Matching expected;
    expected.edge_b = {0, 2, 3, 6};
    expected.edge_e = {1, 4, 5, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_2) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {0, 2, 6, 8, 3, 1};
    expected.edge_e = {4, 9, 5, 10, 11, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_2) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {0, 2, 6, 8, 3, 1};
    expected.edge_e = {4, 9, 5, 10, 11, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_2) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {0, 4, 7, 1};
    expected.edge_e = {2, 6, 5, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_2) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {0, 4, 7, 1};
    expected.edge_e = {2, 6, 5, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_3) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 2354);
    Matching expected;
    expected.edge_b = {1, 4, 7, 3};
    expected.edge_e = {2, 6, 8, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_3) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 2354);
    Matching expected;
    expected.edge_b = {1, 4, 7, 3};
    expected.edge_e = {2, 6, 8, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_3) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1364);
    Matching expected;
    expected.edge_b = {0, 1, 3, 5, 7};
    expected.edge_e = {2, 6, 4, 8, 10};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_3) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1364);
    Matching expected;
    expected.edge_b = {0, 1, 3, 5, 7};
    expected.edge_e = {2, 6, 4, 8, 10};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_3) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 8767);
    Matching expected;
    expected.edge_b = {1, 5, 7, 0};
    expected.edge_e = {3, 4, 6, 2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_3) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 8767);
    Matching expected;
    expected.edge_b = {1, 5, 7, 0};
    expected.edge_e = {3, 4, 6, 2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_4) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10001);
    Matching expected;
    expected.edge_b = {0, 2, 3, 6};
    expected.edge_e = {1, 4, 5, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_4) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10001);
    Matching expected;
    expected.edge_b = {0, 2, 3, 6};
    expected.edge_e = {1, 4, 5, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_4) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10002);
    Matching expected;
    expected.edge_b = {1, 3, 5, 10, 2};
    expected.edge_e = {8, 4, 7, 11, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_4) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10002);
    Matching expected;
    expected.edge_b = {1, 3, 5, 10, 2};
    expected.edge_e = {8, 4, 7, 11, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_4) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10003);
    Matching expected;
    expected.edge_b = {0, 2, 3, 4};
    expected.edge_e = {1, 6, 7, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_4) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10003);
    Matching expected;
    expected.edge_b = {0, 2, 3, 4};
    expected.edge_e = {1, 6, 7, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_5) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1010);
    Matching expected;
    expected.edge_b = {1, 4, 3, 7};
    expected.edge_e = {2, 6, 5, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_5) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1010);
    Matching expected;
    expected.edge_b = {1, 4, 3, 7};
    expected.edge_e = {2, 6, 5, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_5) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1011);
    Matching expected;
    expected.edge_b = {0, 2, 3, 8, 7};
    expected.edge_e = {5, 6, 9, 10, 4};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_5) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1011);
    Matching expected;
    expected.edge_b = {0, 2, 3, 8, 7};
    expected.edge_e = {5, 6, 9, 10, 4};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_5) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {7, 0, 1, 4};
    expected.edge_e = {3, 2, 5, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_5) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {7, 0, 1, 4};
    expected.edge_e = {3, 2, 5, 6};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cycle_generator_csr_1) {
    CSR<int> graph = cycle_generator<int>(10);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {9, 0, 2, 4, 6};
    expected.edge_e = {8, 1, 3, 5, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cycle_generator_csr_2) {
    CSR<int> graph = cycle_generator<int>(9);
    Matching matching = random_matching(graph, 0, graph.n, 1013);
    Matching expected;
    expected.edge_b = {0, 2, 4, 6};
    expected.edge_e = {8, 1, 5, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cycle_generator_csr_3) {
    CSR<int> graph = cycle_generator<int>(5);
    Matching matching = random_matching(graph, 0, graph.n, 1014);
    Matching expected;
    expected.edge_b = {3, 4};
    expected.edge_e = {2, 0};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cycle_generator_csr_4) {
    CSR<int> graph = cycle_generator<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1015);
    Matching expected;
    expected.edge_b = {0};
    expected.edge_e = {1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cycle_generator_csr_5) {
    CSR<int> graph = cycle_generator<int>(7);
    Matching matching = random_matching(graph, 0, graph.n, 1016);
    Matching expected;
    expected.edge_b = {0, 1, 3};
    expected.edge_e = {6, 2, 4};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_stars_generator_csr_1) {
    CSR<int> graph = stars_generator<int>(1);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {5};
    expected.edge_e = {0};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_stars_generator_csr_2) {
    CSR<int> graph = stars_generator<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1013);
    Matching expected;
    expected.edge_b = {0, 6};
    expected.edge_e = {4, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_stars_generator_csr_3) {
    CSR<int> graph = stars_generator<int>(1);
    Matching matching = random_matching(graph, 0, graph.n, 1014);
    Matching expected;
    expected.edge_b = {3};
    expected.edge_e = {0};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_stars_generator_csr_4) {
    CSR<int> graph = stars_generator<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1015);
    Matching expected;
    expected.edge_b = {0, 6};
    expected.edge_e = {4, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_stars_generator_csr_5) {
    CSR<int> graph = stars_generator<int>(1);
    Matching matching = random_matching(graph, 0, graph.n, 1016);
    Matching expected;
    expected.edge_b = {0};
    expected.edge_e = {5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_stars_generator_csr_6) {
    CSR<int> graph = stars_generator<int>(3);
    Matching matching = random_matching(graph, 0, graph.n, 1016);
    Matching expected;
    expected.edge_b = {0, 12};
    expected.edge_e = {6, 13};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_chain_generator_csr_1) {
    CSR<int> graph = chain_generator<int>(3, 3);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {8, 0, 3};
    expected.edge_e = {7, 2, 4};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_chain_generator_csr_2) {
    CSR<int> graph = chain_generator<int>(3, 3);
    Matching matching = random_matching(graph, 0, graph.n, 1013);
    Matching expected;
    expected.edge_b = {0, 4, 6};
    expected.edge_e = {2, 3, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_chain_generator_csr_3) {
    CSR<int> graph = chain_generator<int>(1, 4);
    Matching matching = random_matching(graph, 0, graph.n, 1014);
    Matching expected;
    expected.edge_b = {3, 0};
    expected.edge_e = {2, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_chain_generator_csr_4) {
    CSR<int> graph = chain_generator<int>(2, 5);
    Matching matching = random_matching(graph, 0, graph.n, 1015);
    Matching expected;
    expected.edge_b = {0, 2, 5, 8};
    expected.edge_e = {4, 3, 6, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_chain_generator_csr_5) {
    CSR<int> graph = chain_generator<int>(1, 3);
    Matching matching = random_matching(graph, 0, graph.n, 1016);
    Matching expected;
    expected.edge_b = {0};
    expected.edge_e = {2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_chain_generator_csr_6) {
    CSR<int> graph = chain_generator<int>(1, 2);
    Matching matching = random_matching(graph, 0, graph.n, 1016);
    Matching expected;
    expected.edge_b = {0};
    expected.edge_e = {1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

#endif  // __linux__

#ifdef _WIN32

TEST(random_matching_fixed_test, basic_washington_test_csr) {
    CSR<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 7, 2, 3};
    expected.edge_e = {1, 8, 4, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 7, 2, 3};
    expected.edge_e = {1, 8, 4, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 7, 6, 1, 2, 3};
    expected.edge_e = {4, 10, 5, 9, 11, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {0, 7, 6, 1, 2, 3};
    expected.edge_e = {4, 10, 5, 9, 11, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 20);
    Matching expected;
    expected.edge_b = {0, 4, 2, 7};
    expected.edge_e = {1, 5, 6, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 20);
    Matching expected;
    expected.edge_b = {0, 4, 2, 7};
    expected.edge_e = {1, 5, 6, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_2) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 59);
    Matching expected;
    expected.edge_b = {0, 7, 2, 3};
    expected.edge_e = {1, 8, 4, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_2) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 59);
    Matching expected;
    expected.edge_b = {0, 7, 2, 3};
    expected.edge_e = {1, 8, 4, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_2) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {0, 1, 10, 6, 2, 9};
    expected.edge_e = {4, 7, 11, 5, 3, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_2) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {0, 1, 10, 6, 2, 9};
    expected.edge_e = {4, 7, 11, 5, 3, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_2) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {0, 4, 3};
    expected.edge_e = {1, 6, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_2) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {0, 4, 3};
    expected.edge_e = {1, 6, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_3) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 2354);
    Matching expected;
    expected.edge_b = {5, 0, 2, 7};
    expected.edge_e = {6, 1, 4, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_3) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 2354);
    Matching expected;
    expected.edge_b = {5, 0, 2, 7};
    expected.edge_e = {6, 1, 4, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_3) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1364);
    Matching expected;
    expected.edge_b = {0, 3, 10, 9, 1, 6};
    expected.edge_e = {5, 7, 11, 4, 8, 2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_3) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1364);
    Matching expected;
    expected.edge_b = {0, 3, 10, 9, 1, 6};
    expected.edge_e = {5, 7, 11, 4, 8, 2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_3) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 8767);
    Matching expected;
    expected.edge_b = {2, 1, 0, 3};
    expected.edge_e = {6, 5, 4, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_3) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 8767);
    Matching expected;
    expected.edge_b = {2, 1, 0, 3};
    expected.edge_e = {6, 5, 4, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_4) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10001);
    Matching expected;
    expected.edge_b = {4, 7, 0, 3};
    expected.edge_e = {6, 8, 1, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_4) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10001);
    Matching expected;
    expected.edge_b = {4, 7, 0, 3};
    expected.edge_e = {6, 8, 1, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_4) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10002);
    Matching expected;
    expected.edge_b = {0, 1, 2, 8, 5, 9};
    expected.edge_e = {3, 6, 7, 4, 11, 10};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_4) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10002);
    Matching expected;
    expected.edge_b = {0, 1, 2, 8, 5, 9};
    expected.edge_e = {3, 6, 7, 4, 11, 10};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_4) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10003);
    Matching expected;
    expected.edge_b = {4, 1, 2, 7};
    expected.edge_e = {6, 3, 0, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_4) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10003);
    Matching expected;
    expected.edge_b = {4, 1, 2, 7};
    expected.edge_e = {6, 3, 0, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_5) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1010);
    Matching expected;
    expected.edge_b = {5, 0, 7, 2};
    expected.edge_e = {6, 1, 8, 4};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_5) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1010);
    Matching expected;
    expected.edge_b = {5, 0, 7, 2};
    expected.edge_e = {6, 1, 8, 4};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_5) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1011);
    Matching expected;
    expected.edge_b = {0, 8, 6, 9, 1, 4};
    expected.edge_e = {5, 2, 3, 10, 7, 11};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_5) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1011);
    Matching expected;
    expected.edge_b = {0, 8, 6, 9, 1, 4};
    expected.edge_e = {5, 2, 3, 10, 7, 11};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_5) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {6, 0, 2, 1};
    expected.edge_e = {7, 4, 3, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_5) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {6, 0, 2, 1};
    expected.edge_e = {7, 4, 3, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

#endif  // _WIN32

#ifdef __APPLE__
TEST(random_matching_fixed_test, basic_washington_test_csr) {
    CSR<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {4, 3, 0, 7};
    expected.edge_e = {6, 5, 1, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {4, 3, 0, 7};
    expected.edge_e = {6, 5, 1, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {9, 10, 7, 6, 8, 0};
    expected.edge_e = {3, 11, 5, 4, 2, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10);
    Matching expected;
    expected.edge_b = {9, 10, 7, 6, 8, 0};
    expected.edge_e = {3, 11, 5, 4, 2, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 20);
    Matching expected;
    expected.edge_b = {3, 4, 5, 1};
    expected.edge_e = {2, 6, 7, 0};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 20);
    Matching expected;
    expected.edge_b = {3, 4, 5, 1};
    expected.edge_e = {2, 6, 7, 0};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_2) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 59);
    Matching expected;
    expected.edge_b = {1, 2, 5, 7};
    expected.edge_e = {3, 4, 6, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_2) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 59);
    Matching expected;
    expected.edge_b = {1, 2, 5, 7};
    expected.edge_e = {3, 4, 6, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_2) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {2, 3, 5, 7, 9, 0};
    expected.edge_e = {8, 4, 11, 6, 10, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_2) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {2, 3, 5, 7, 9, 0};
    expected.edge_e = {8, 4, 11, 6, 10, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_2) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {7, 3, 4, 0};
    expected.edge_e = {6, 1, 5, 2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_2) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 7893);
    Matching expected;
    expected.edge_b = {7, 3, 4, 0};
    expected.edge_e = {6, 1, 5, 2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_3) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 2354);
    Matching expected;
    expected.edge_b = {4, 7, 1, 3};
    expected.edge_e = {6, 8, 2, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_3) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 2354);
    Matching expected;
    expected.edge_b = {4, 7, 1, 3};
    expected.edge_e = {6, 8, 2, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_3) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1364);
    Matching expected;
    expected.edge_b = {5, 6, 7, 8, 10, 0};
    expected.edge_e = {4, 3, 2, 9, 11, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_3) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1364);
    Matching expected;
    expected.edge_b = {5, 6, 7, 8, 10, 0};
    expected.edge_e = {4, 3, 2, 9, 11, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_3) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 8767);
    Matching expected;
    expected.edge_b = {7, 3, 4, 0};
    expected.edge_e = {6, 1, 5, 2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_3) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 8767);
    Matching expected;
    expected.edge_b = {7, 3, 4, 0};
    expected.edge_e = {6, 1, 5, 2};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_4) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10001);
    Matching expected;
    expected.edge_b = {1, 2, 5, 7};
    expected.edge_e = {3, 4, 6, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_4) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10001);
    Matching expected;
    expected.edge_b = {1, 2, 5, 7};
    expected.edge_e = {3, 4, 6, 8};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_4) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10002);
    Matching expected;
    expected.edge_b = {1, 2, 4, 6, 8};
    expected.edge_e = {7, 3, 5, 10, 9};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_4) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10002);
    Matching expected;
    expected.edge_b = {1, 2, 4, 6, 8};
    expected.edge_e = {7, 3, 5, 10, 9};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_4) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10003);
    Matching expected;
    expected.edge_b = {5, 6, 0, 2};
    expected.edge_e = {7, 4, 1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_4) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 10003);
    Matching expected;
    expected.edge_b = {5, 6, 0, 2};
    expected.edge_e = {7, 4, 1, 3};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_csr_5) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1010);
    Matching expected;
    expected.edge_b = {4, 7, 1, 3};
    expected.edge_e = {6, 8, 2, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_washington_test_al_5) {
    AL<int> graph = washington_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1010);
    Matching expected;
    expected.edge_b = {4, 7, 1, 3};
    expected.edge_e = {6, 8, 2, 5};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_csr_5) {
    CSR<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1011);
    Matching expected;
    expected.edge_b = {5, 6, 7, 3, 8, 0};
    expected.edge_e = {9, 4, 2, 11, 10, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_zadeh_test_al_5) {
    AL<int> graph = zadeh_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1011);
    Matching expected;
    expected.edge_b = {5, 6, 7, 3, 8, 0};
    expected.edge_e = {9, 4, 2, 11, 10, 1};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_csr_5) {
    CSR<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {2, 4, 5};
    expected.edge_e = {3, 0, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

TEST(random_matching_fixed_test, basic_cube_test_al_5) {
    AL<int> graph = cube_test<int>(2);
    Matching matching = random_matching(graph, 0, graph.n, 1012);
    Matching expected;
    expected.edge_b = {2, 4, 5};
    expected.edge_e = {3, 0, 7};
    ASSERT_EQ(expected.edge_b, matching.edge_b);
    ASSERT_EQ(expected.edge_e, matching.edge_e);
}

#endif  // __APPLE__
