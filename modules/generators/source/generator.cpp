// Copyright [year] <Copyright Owner>
#include "../include/generator.h"
#include <random>
#include <utility>
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

AL zadeh_test(int n, bool weighted) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> weight(1, weighted ? max_weight : 1);
    AL graph;
    graph.n = 6*n;
    graph.edges.resize(6*n);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 2*n; j++) {
                graph.edges[i].push_back(std::make_pair(3*n + 1 + j,
                weight(generator)));
            }
            graph.edges[i].push_back(std::make_pair(i + 1,
            weight(generator)));
        } else {
            for (int j = 0; j < 2*n; j++) {
                graph.edges[i].push_back(std::make_pair(n + 1 + j,
                weight(generator)));
            }
            graph.edges[i].push_back(std::make_pair(i + 1,
            weight(generator)));
        }
    }
    if (n % 2 == 0) {
        for (int j = 0; j < 2*n; j++) {
           graph.edges[n].push_back(std::make_pair(3*n + 1 + j,
           weight(generator)));
        }
    } else {
        for (int j = 0; j < 2*n; j++) {
           graph.edges[n].push_back(std::make_pair(n + 1 + j,
           weight(generator)));
        }
    }
    for (int i = n + 1; i <= 3*n; i++) {
        for (int j = 0; j < 2*n; j++) {
            graph.edges[i].push_back(std::make_pair(3*n + 1 + j,
            weight(generator)));
            graph.edges[3*n + 1 + j].push_back(std::make_pair(i,
            weight(generator)));
        }
        for (int k = 6*n - 1; k > 5*n; k -= 2) {
            graph.edges[i].push_back(std::make_pair(k, weight(generator)));
        }
    }
    for (int i = 3*n + 1; i <= 5*n; i++) {
        for (int k = 6*n; k > 5*n; k -= 2) {
            graph.edges[i].push_back(std::make_pair(k,
            weight(generator)));
        }
    }
    for (int i = 5*n; i < 6*n; i++) {
        graph.edges[i].push_back(std::make_pair(i + 1,
        weight(generator)));
    }
    return graph;
}
