// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

static std::random_device rd;
static std::mt19937 generator(rd());

TEST(al_test, basic_washington_test_generates) {
    ASSERT_NO_THROW(AL<int> al = washington_test<int>(2));
}

TEST(al_test, random_washington_test_generates) {
    int n = std::uniform_int_distribution<int>(1, 10000)(generator);
    ASSERT_NO_THROW(AL<int> al = washington_test<int>(n, true));
}

TEST(al_test, basic_zadeh_test_generates) {
    ASSERT_NO_THROW(CSR<int> csr = zadeh_test<int>(2));
}

TEST(al_test, random_zadeh_test_generates) {
    int n = std::uniform_int_distribution<int>(1, 1000)(generator);
    ASSERT_NO_THROW(CSR<int> csr = zadeh_test<int>(n, true));
}

TEST(al_test, graph_file_operations) {
    AL<int> graph = washington_test<int>(20);
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.write("test.bin")));
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.read("test.bin")));
}

TEST(al_test, run_bfs_on_basic_washington_test) {
    AL<int> al = washington_test<int>(2);
    ASSERT_EQ(6, al.bfs(0, al.n - 1));
}

TEST(al_test, run_dfs_on_basic_washington_test) {
    AL<int> al = washington_test<int>(2);
    std::vector <int> dfs_result = al.dfs(0);
    std::vector <int> expected_dfs_result = {1, 2, 3, 3, 4, 4, 5, 6, 7};
    ASSERT_EQ(expected_dfs_result, dfs_result);
}

TEST(al_test, correct_hard_matching_on_basic_washington_test) {
    AL<int> al = washington_test<int>(2);
    std::vector <char> used(al.n, 0);
    auto matching = hard_matching(al);
    for (int i = 0; i < matching.n; ++i)
        used[matching.edge_b[i]] = used[matching.edge_e[i]] = true;
    for (int i = 0; i < al.n; ++i) {
        if (!used[i]) {
            for (unsigned j = 0; j < al.edges[i].size(); ++j) {
                ASSERT_EQ(true, used[al.edges[i][j]]);
            }
        }
    }
}

TEST(al_test, run_dfs_on_random_washington_test) {
    int n = std::uniform_int_distribution<int>(1, 1000)(generator);
    AL<int> al = washington_test<int>(n, true);
    std::vector <int> expected_dfs_result;
    expected_dfs_result.push_back(1);
    expected_dfs_result.push_back(2);
    for (int i = 0; i < n; ++i)
        expected_dfs_result.push_back(3);
    for (int i = 0; i < n; ++i)
        expected_dfs_result.push_back(4);
    for (int i = 0; i <= n; ++i)
        expected_dfs_result.push_back(i + 5);
    std::vector <int> dfs_result = al.dfs(0);
    ASSERT_EQ(expected_dfs_result, dfs_result);
}

TEST(al_test, basic_washington_test_generates_double) {
    ASSERT_NO_THROW(AL<double> al = washington_test<double>(2, true));
}

TEST(al_test, graph_file_operations_float) {
    AL<float> graph = washington_test<float>(20, true);
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.write("test.bin")));
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.read("test.bin")));
}

TEST(al_test, graph_file_operations_double) {
    AL<double> graph = washington_test<double>(20, true);
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.write("test.bin")));
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.read("test.bin")));
}
