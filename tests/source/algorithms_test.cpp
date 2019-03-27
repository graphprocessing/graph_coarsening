// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

TEST(graph_distances_test, basic_cube_test_eccentricity) {
    CSR <int> graph = cube_test<int>(2);
    std::vector <int> ecc = vertexes_eccentricity(graph);
    std::vector <int> expected_ecc = {3, 3, 3, 3, 3, 3, 3, 3};
    ASSERT_EQ(expected_ecc, ecc);
}

TEST(graph_distances_test, basic_cube_test_graph_diameter) {
    CSR <int> graph = cube_test<int>(2);
    ASSERT_EQ(3, graph_diameter(graph));
}

TEST(graph_distances_test, basic_cube_test_graph_radius) {
    CSR <int> graph = cube_test<int>(2);
    ASSERT_EQ(3, graph_radius(graph));
}

TEST(count_bridges_test, basic_cube_test) {
    CSR <int> graph = cube_test<int>(2);
    ASSERT_EQ(0, count_bridges(graph));
}

TEST(count_joint_points_test, basic_cube_test) {
    CSR <int> graph = cube_test<int>(2);
    ASSERT_EQ(0, count_joint_points(graph));
}

TEST(cost_of_minimal_spanning_tree_test, basic_cube_test_unweighted) {
    CSR <int> graph = cube_test<int>(2);
    ASSERT_EQ(7, get_cost_of_minimal_spanning_tree(graph));
}

TEST(strongly_connected_components, basic_cube_test) {
    CSR <int> graph = cube_test<int>(2);
    std::vector <int> comp;
    find_strongly_connected_components(&comp, graph);
    std::vector <int> expected = {1, 1, 1, 1, 1, 1, 1, 1};
    ASSERT_EQ(expected, comp);
}

TEST(strongly_connected_components, basic_washington_test) {
    CSR <int> graph = washington_test<int>(2);
    std::vector <int> comp;
    find_strongly_connected_components(&comp, graph);
    std::sort(begin(comp), end(comp));
    std::vector <int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(expected, comp);
}

TEST(strongly_connected_components, basic_zadeh_test) {
    CSR <int> graph = zadeh_test<int>(2);
    std::vector <int> comp;
    find_strongly_connected_components(&comp, graph);
    std::vector <int> expected = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5};
    ASSERT_EQ(expected, comp);
}

TEST(dsu_test, is_disjoint_initially_test) {
    const int n = 10;
    DSU dsu(n);
    std::set <int> s;
    for (int i = 0; i < n; ++i)
        s.insert(dsu.get(i));
    ASSERT_EQ(n, s.size());
}

TEST(dsu_test, unite_all_elements_test) {
    const int n = 10;
    DSU dsu(n);
    for (int i = 0; i < n - 1; ++i)
        dsu.unite(i, i + 1);
    std::set <int> s;
    for (int i = 0; i < n; ++i)
        s.insert(dsu.get(i));
    ASSERT_EQ(1u, s.size());
}

TEST(dsu_test, hang_all_elements_to_one_test) {
    const int n = 10;
    DSU dsu(n);
    for (int i = 0; i < n - 1; ++i)
        dsu.unite(0, i + 1);
    std::set <int> s;
    for (int i = 0; i < n; ++i)
        s.insert(dsu.get(i));
    ASSERT_EQ(1u, s.size());
}

TEST(dsu_test, unite_odd_and_even_test) {
    const int n = 10;
    DSU dsu(n);
    for (int i = 0; i < n - 1; ++i)
        (i % 2) ? dsu.unite(0, i) : dsu.unite(1, i);
    std::set <int> s;
    for (int i = 0; i < n; ++i)
        s.insert(dsu.get(i));
    ASSERT_EQ(2u, s.size());
}

TEST(export_for_visualization_test, basic_washington_test) {
    CSR <int> graph = washington_test<int>(2);
    export_for_visualization(graph, "test.txt");
    std::ifstream file("test.txt");
    ASSERT_EQ(true, file.is_open());
    std::stringstream ss;
    ss << file.rdbuf();
    ASSERT_EQ("0 1 1\n"
              "1 2 1\n"
              "1 3 1\n"
              "2 4 1\n"
              "3 5 1\n"
              "4 6 1\n"
              "5 6 1\n"
              "6 7 1\n"
              "7 8 1\n",
              ss.str());
}

TEST(export_for_visualization_test, basic_zadeh_test) {
    CSR <int> graph = zadeh_test<int>(2);
    export_for_visualization(graph, "test.txt");
    std::ifstream file("test.txt");
    ASSERT_EQ(true, file.is_open());
    std::stringstream ss;
    ss << file.rdbuf();
    ASSERT_EQ("0 2 1\n"
              "0 3 1\n"
              "0 4 1\n"
              "0 5 1\n"
              "0 1 1\n"
              "1 6 1\n"
              "1 7 1\n"
              "1 8 1\n"
              "1 9 1\n"
              "1 2 1\n"
              "2 6 1\n"
              "2 7 1\n"
              "2 8 1\n"
              "2 9 1\n"
              "2 11 1\n"
              "2 3 1\n"
              "3 6 1\n"
              "3 7 1\n"
              "3 8 1\n"
              "3 9 1\n"
              "3 11 1\n"
              "3 2 1\n"
              "3 4 1\n"
              "4 6 1\n"
              "4 7 1\n"
              "4 8 1\n"
              "4 9 1\n"
              "4 11 1\n"
              "4 3 1\n"
              "4 5 1\n"
              "5 6 1\n"
              "5 7 1\n"
              "5 8 1\n"
              "5 9 1\n"
              "5 11 1\n"
              "5 4 1\n"
              "6 2 1\n"
              "6 3 1\n"
              "6 4 1\n"
              "6 5 1\n"
              "6 10 1\n"
              "6 7 1\n"
              "7 2 1\n"
              "7 3 1\n"
              "7 4 1\n"
              "7 5 1\n"
              "7 10 1\n"
              "7 6 1\n"
              "7 8 1\n"
              "8 2 1\n"
              "8 3 1\n"
              "8 4 1\n"
              "8 5 1\n"
              "8 10 1\n"
              "8 7 1\n"
              "8 9 1\n"
              "9 2 1\n"
              "9 3 1\n"
              "9 4 1\n"
              "9 5 1\n"
              "9 10 1\n"
              "9 8 1\n"
              "10 11 1\n",
              ss.str());
}

TEST(export_for_visualization_test, basic_cube_test) {
    CSR <int> graph = cube_test<int>(2);
    export_for_visualization(graph, "test.txt");
    std::ifstream file("test.txt");
    ASSERT_EQ(true, file.is_open());
    std::stringstream ss;
    ss << file.rdbuf();
    ASSERT_EQ("0 4 1\n"
              "0 2 1\n"
              "0 1 1\n"
              "1 5 1\n"
              "1 3 1\n"
              "1 0 1\n"
              "2 6 1\n"
              "2 0 1\n"
              "2 3 1\n"
              "3 7 1\n"
              "3 1 1\n"
              "3 2 1\n"
              "4 0 1\n"
              "4 6 1\n"
              "4 5 1\n"
              "5 1 1\n"
              "5 7 1\n"
              "5 4 1\n"
              "6 2 1\n"
              "6 4 1\n"
              "6 7 1\n"
              "7 3 1\n"
              "7 5 1\n"
              "7 6 1\n",
              ss.str());
}
