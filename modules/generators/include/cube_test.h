// Copyright [year] <Copyright Owner>
#ifndef MODULES_GENERATORS_INCLUDE_CUBE_TEST_H_
#define MODULES_GENERATORS_INCLUDE_CUBE_TEST_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
AL<WeightType> cube_test(int n, bool weighted = false) {
    const int max_weight = 100000;
    AL <WeightType> graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double>
                    weight(1, weighted ? max_weight : 1);
        graph.n = n * n * n;
        graph.edges.resize(graph.n);
        graph.weights.resize(graph.n);
        graph.weight_vertex.resize(graph.n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int vertex = i * n * n + j * n + k;
                    if (i != 0) {
                        graph.edges[vertex].push_back(vertex - n * n);
                        graph.weights[vertex].push_back(weight(generator));
                    }
                    if (i != n - 1) {
                        graph.edges[vertex].push_back(vertex + n * n);
                        graph.weights[vertex].push_back(weight(generator));
                    }
                    if (j != 0) {
                        graph.edges[vertex].push_back(vertex - n);
                        graph.weights[vertex].push_back(weight(generator));
                    }
                    if (j != n - 1) {
                        graph.edges[vertex].push_back(vertex + n);
                        graph.weights[vertex].push_back(weight(generator));
                    }
                    if (k != 0) {
                        graph.edges[vertex].push_back(vertex - 1);
                        graph.weights[vertex].push_back(weight(generator));
                    }
                    if (k != n - 1) {
                        graph.edges[vertex].push_back(vertex + 1);
                        graph.weights[vertex].push_back(weight(generator));
                    }
                }
            }
        }
    }
    catch (std::bad_alloc& ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

#endif  // MODULES_GENERATORS_INCLUDE_CUBE_TEST_H_
