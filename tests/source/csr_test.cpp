// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

static std::random_device rd;
static std::mt19937 generator(rd());

TEST(csr_test, basic_washington_test_generates_and_converts_to_csr) {
    ASSERT_NO_THROW(CSR<int> csr = washington_test<int>(20));
}

TEST(csr_test, random_washington_test_generates_and_converts_to_csr) {
    int n = std::uniform_int_distribution<int>(1, 100000)(generator);
    ASSERT_NO_THROW(CSR<int> csr = washington_test<int>(n, true));
}

TEST(csr_test, basic_zadeh_test_generates_and_converts_to_csr) {
    ASSERT_NO_THROW(CSR<int> csr = zadeh_test<int>(20));
}

TEST(csr_test, random_zadeh_test_generates_and_converts_to_csr) {
    int n = std::uniform_int_distribution<int>(1, 1000)(generator);
    ASSERT_NO_THROW(CSR<int> csr = zadeh_test<int>(n, true));
}

TEST(csr_test, graph_file_operations) {
    CSR<int> graph = washington_test<int>(20);
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.write("test.bin")));
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.read("test.bin")));
}

TEST(csr_test, run_bfs_on_basic_washington_test) {
    CSR<int> csr = washington_test<int>(2);
    ASSERT_EQ(6, csr.bfs(0, csr.n - 1));
}

TEST(csr_test, run_dfs_on_basic_washington_test) {
    CSR<int> csr = washington_test<int>(2);
    std::vector <int> dfs_result = csr.dfs(0);
    std::vector <int> expected_dfs_result = {1, 2, 3, 3, 4, 4, 5, 6, 7};
    ASSERT_EQ(expected_dfs_result, dfs_result);
}

TEST(csr_test, run_Dijkstra_on_not_weighted_basic_washington_test) {
    CSR<int> csr = washington_test<int>(2);
    ASSERT_EQ(csr.Dijkstra(0, csr.n - 1), csr.bfs(0, csr.n - 1));
}

TEST(al_test, run_Dijkstra_on_not_weighted_basic_washington_test) {
    AL<int> al = washington_test<int>(2);
    ASSERT_EQ(al.Dijkstra(0, al.n - 1), al.bfs(0, al.n - 1));
}

TEST(csr_test, run_dfs_on_random_washington_test) {
    int n = std::uniform_int_distribution<int>(1, 1000)(generator);
    CSR<int> csr = washington_test<int>(n, true);
    std::vector <int> expected_dfs_result;
    expected_dfs_result.push_back(1);
    expected_dfs_result.push_back(2);
    for (int i = 0; i < n; ++i)
        expected_dfs_result.push_back(3);
    for (int i = 0; i < n; ++i)
        expected_dfs_result.push_back(4);
    for (int i = 0; i <= n; ++i)
        expected_dfs_result.push_back(i + 5);
    std::vector <int> dfs_result = csr.dfs(0);
    ASSERT_EQ(expected_dfs_result, dfs_result);
}

TEST(csr_test, basic_washington_test_double_generates_and_converts_to_csr) {
    ASSERT_NO_THROW(CSR<double> csr = washington_test<double>(20));
}

TEST(csr_test, graph_file_operations_float) {
    CSR<float> graph = washington_test<float>(20, true);
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.write("test.bin")));
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.read("test.bin")));
}

TEST(csr_test, graph_file_operations_double) {
    CSR<double> graph = washington_test<double>(20, true);
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.write("test.bin")));
    ASSERT_NO_THROW(ASSERT_EQ(true, graph.read("test.bin")));
}
