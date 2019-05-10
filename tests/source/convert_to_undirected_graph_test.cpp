// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

TEST(convert_to_undirected_graph_test, simple_graph_with_random_matching) {
    AL <int> graph1;
    graph1.n = 4;
    graph1.edges.resize(graph1.n);
    graph1.weights.resize(graph1.n);
    graph1.weight_vertex.resize(graph1.n, 1);
    graph1.edges[0].push_back(1);
    graph1.weights[0].push_back(1);
    graph1.edges[0].push_back(2);
    graph1.weights[0].push_back(1);
    graph1.edges[0].push_back(3);
    graph1.weights[0].push_back(1);
    graph1.edges[2].push_back(1);
    graph1.weights[2].push_back(1);
    AL <int> graph2;
    graph2.n = 4;
    graph2.edges.resize(graph2.n);
    graph2.weights.resize(graph2.n);
    graph2.weight_vertex.resize(graph1.n, 1);
    graph2.edges[1].push_back(0);
    graph2.weights[1].push_back(1);
    graph2.edges[2].push_back(0);
    graph2.weights[2].push_back(1);
    graph2.edges[3].push_back(0);
    graph2.weights[3].push_back(1);
    graph2.edges[1].push_back(2);
    graph2.weights[1].push_back(1);

    graph1 = convert_to_undirected_graph<int>(graph1);
    graph2 = convert_to_undirected_graph<int>(graph2);

    graph1 = graph_coarsening(CSR<int>(graph1),
    [](const CSR<int>& graph1) -> Matching {
    return random_matching<int>(graph1, 0, INT_MAX, 37);
    });
    graph2 = graph_coarsening(CSR<int>(graph2),
    [](const CSR<int>& graph2) -> Matching {
    return random_matching<int>(graph2, 0, INT_MAX, 37);
    });

    for (int i = 0; i < graph1.n; ++i) {
        ASSERT_EQ(graph1.edges[i].size(), graph2.edges[i].size());
        for (unsigned j = 0; j < graph1.edges[i].size(); ++j) {
            auto it = std::find(graph2.edges[i].begin(), graph2.edges[i].end(),
                                    graph1.edges[i][j]);
            ASSERT_NE(graph2.edges[i].end(), it);
            int pos_in_graph2 = it - graph2.edges[i].begin();
            ASSERT_EQ(graph1.weights[i][j], graph2.weights[i][pos_in_graph2]);
        }
    }
}

TEST(convert_to_undirected_graph_test,
     simple_washington_test_with_random_matching) {
    AL <int> graph1 = washington_test<int>(2);
    AL <int> graph2 = washington_test<int>(2);
    graph2.edges[0].pop_back();
    graph2.weights[0].pop_back();
    graph2.edges[1].push_back(0);
    graph2.weights[1].push_back(1);

    graph1 = convert_to_undirected_graph<int>(graph1);
    graph2 = convert_to_undirected_graph<int>(graph2);

    graph1 = graph_coarsening(CSR<int>(graph1),
    [](const CSR<int>& graph1) -> Matching {
    return random_matching<int>(graph1, 0, INT_MAX, 35);
    });
    graph2 = graph_coarsening(CSR<int>(graph2),
    [](const CSR<int>& graph2) -> Matching {
    return random_matching<int>(graph2, 0, INT_MAX, 35);
    });

    for (int i = 0; i < graph1.n; ++i) {
        ASSERT_EQ(graph1.edges[i].size(), graph2.edges[i].size());
        for (unsigned j = 0; j < graph1.edges[i].size(); ++j) {
            auto it = std::find(graph2.edges[i].begin(), graph2.edges[i].end(),
                                graph1.edges[i][j]);
            ASSERT_NE(graph2.edges[i].end(), it);
            int pos_in_graph2 = it - graph2.edges[i].begin();
            ASSERT_EQ(graph1.weights[i][j], graph2.weights[i][pos_in_graph2]);
        }
    }
}

TEST(convert_to_undirected_graph_test,
     simple_washington_test_with_double_random_matching) {
    AL <int> graph1 = washington_test<int>(2);
    AL <int> graph2 = washington_test<int>(2);
    graph2.edges[0].pop_back();
    graph2.weights[0].pop_back();
    graph2.edges[1].push_back(0);
    graph2.weights[1].push_back(1);

    graph1 = convert_to_undirected_graph<int>(graph1);
    graph2 = convert_to_undirected_graph<int>(graph2);

    graph1 = graph_coarsening(CSR<int>(graph1),
    [](const CSR<int>& graph1) -> Matching {
    return random_matching<int>(graph1, 0, INT_MAX, 410);
    });
    graph2 = graph_coarsening(CSR<int>(graph2),
    [](const CSR<int>& graph2) -> Matching {
    return random_matching<int>(graph2, 0, INT_MAX, 410);
    });

    graph1 = graph_coarsening(CSR<int>(graph1),
    [](const CSR<int>& graph1) -> Matching {
    return random_matching<int>(graph1, 0, INT_MAX, 2359);
    });
    graph2 = graph_coarsening(CSR<int>(graph2),
    [](const CSR<int>& graph2) -> Matching {
    return random_matching<int>(graph2, 0, INT_MAX, 2359);
    });

    for (int i = 0; i < graph1.n; ++i) {
        ASSERT_EQ(graph1.edges[i].size(), graph2.edges[i].size());
        for (unsigned j = 0; j < graph1.edges[i].size(); ++j) {
            auto it = std::find(graph2.edges[i].begin(), graph2.edges[i].end(),
                                graph1.edges[i][j]);
            ASSERT_NE(graph2.edges[i].end(), it);
            int pos_in_graph2 = it - graph2.edges[i].begin();
            ASSERT_EQ(graph1.weights[i][j], graph2.weights[i][pos_in_graph2]);
        }
    }
}

TEST(convert_to_undirected_graph_test,
     converts_simple_cube_test_to_the_same_graph) {
    AL <int> graph1 = cube_test<int>(2);
    AL <int> graph2 = cube_test<int>(2);
    graph2 = convert_to_undirected_graph(graph2);
    ASSERT_EQ(graph1.n, graph2.n);
    ASSERT_EQ(graph1.edges, graph2.edges);
    ASSERT_EQ(graph1.weights, graph2.weights);
}

TEST(convert_to_undirected_graph_test,
     adds_opposite_edge_in_graph_with_two_vertices) {
    AL <int> graph;
    graph.n = 2;
    graph.edges.resize(graph.n);
    graph.weights.resize(graph.n);
    graph.edges[0].push_back(1);
    graph.weights[0].push_back(1);
    graph = convert_to_undirected_graph(graph);
    ASSERT_EQ(1u, graph.edges[0].size());
    ASSERT_EQ(1u, graph.edges[1].size());
    ASSERT_EQ(1u, graph.weights[0].size());
    ASSERT_EQ(1u, graph.weights[1].size());
    ASSERT_NE(graph.edges[0].end(),
                std::find(graph.edges[0].begin(), graph.edges[0].end(), 1));
    ASSERT_NE(graph.edges[1].end(),
                std::find(graph.edges[1].begin(), graph.edges[1].end(), 0));
    ASSERT_EQ(1, graph.weights[0][0]);
    ASSERT_EQ(1, graph.weights[1][0]);
}

TEST(convert_to_undirected_graph_test,
     adds_opposite_edge_in_graph_with_two_vertices_2) {
    AL <int> graph;
    graph.n = 2;
    graph.edges.resize(graph.n);
    graph.weights.resize(graph.n);
    graph.edges[1].push_back(0);
    graph.weights[1].push_back(1);
    graph = convert_to_undirected_graph(graph);
    ASSERT_EQ(1u, graph.edges[0].size());
    ASSERT_EQ(1u, graph.edges[1].size());
    ASSERT_EQ(1u, graph.weights[0].size());
    ASSERT_EQ(1u, graph.weights[1].size());
    ASSERT_NE(graph.edges[0].end(),
                std::find(graph.edges[0].begin(), graph.edges[0].end(), 1));
    ASSERT_NE(graph.edges[1].end(),
                std::find(graph.edges[1].begin(), graph.edges[1].end(), 0));
    ASSERT_EQ(1, graph.weights[0][0]);
    ASSERT_EQ(1, graph.weights[1][0]);
}

TEST(convert_to_undirected_graph_test, doesnt_modify_graph_with_only_noose) {
    AL <int> graph;
    graph.n = 2;
    graph.edges.resize(graph.n);
    graph.weights.resize(graph.n);
    graph.edges[1].push_back(1);
    graph.weights[1].push_back(1);
    graph = convert_to_undirected_graph(graph);
    ASSERT_EQ(0u, graph.edges[0].size());
    ASSERT_EQ(1u, graph.edges[1].size());
    ASSERT_EQ(0u, graph.weights[0].size());
    ASSERT_EQ(1u, graph.weights[1].size());
    ASSERT_EQ(1, graph.edges[1][0]);
    ASSERT_EQ(1, graph.weights[1][0]);
}

TEST(convert_to_undirected_graph_test, doesnt_modify_graph_without_edges) {
    AL <int> graph;
    graph.n = 16;
    graph.edges.resize(graph.n);
    graph.weights.resize(graph.n);
    graph = convert_to_undirected_graph(graph);
    for (int i = 0; i < graph.n; ++i) {
        ASSERT_EQ(0u, graph.edges[i].size());
        ASSERT_EQ(0u, graph.weights[i].size());
    }
}
