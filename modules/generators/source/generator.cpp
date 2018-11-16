// Copyright [year] <Copyright Owner>
#include "../include/generator.h"
#include <random>
static const int max_weight = 1e5;

CSR washington_test(int n, bool weighted) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> weight(1, weighted ? max_weight : 1);
    CSR graph;
    graph.n = 3 * n + 3;
    graph.offset.push_back(0);
    graph.edges.push_back({1, weight(generator)});
    graph.offset.push_back(graph.edges.size());
    for (int i = 2; i < n + 2; ++i)
        graph.edges.push_back({i, weight(generator)});
    graph.offset.push_back(graph.edges.size());
    for (int i = n + 2; i < 2 * n + 2; ++i) {
        graph.edges.push_back({i, weight(generator)});
        graph.offset.push_back(graph.edges.size());
    }
    for (int i = n + 2; i < 2 * n + 2; ++i) {
        graph.edges.push_back({2 * n + 2, weight(generator)});
        graph.offset.push_back(graph.edges.size());
    }
    for (int i = 2 * n + 3; i < 3 * n + 3; ++i) {
        graph.edges.push_back({i, weight(generator)});
        graph.offset.push_back(graph.edges.size());
    }
    graph.offset.push_back(graph.edges.size());
    return graph;
}
