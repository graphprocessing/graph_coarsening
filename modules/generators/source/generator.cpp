// Copyright [year] <Copyright Owner>
#include "../include/generator.h"

CSR washington_test(int n) {
    CSR graph;
    graph.n = 3 * n + 3;
    graph.offset.push_back(0);
    graph.edges.push_back({1, 1});
    graph.offset.push_back(graph.edges.size());
    for (int i = 2; i < n + 2; ++i)
        graph.edges.push_back({i, 1});
    graph.offset.push_back(graph.edges.size());
    for (int i = n + 2; i < 2 * n + 2; ++i) {
        graph.edges.push_back({i, 1});
        graph.offset.push_back(graph.edges.size());
    }
    for (int i = n + 2; i < 2 * n + 2; ++i) {
        graph.edges.push_back({2 * n + 2, 1});
        graph.offset.push_back(graph.edges.size());
    }
    for (int i = 2 * n + 3; i < 3 * n + 3; ++i) {
        graph.edges.push_back({i, 1});
        graph.offset.push_back(graph.edges.size());
    }
    return graph;
}
