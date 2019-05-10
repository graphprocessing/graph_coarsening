// Copyright [year] <Copyright Owner>
#ifndef MODULES_GENERATORS_INCLUDE_WASHINGTON_TEST_H_
#define MODULES_GENERATORS_INCLUDE_WASHINGTON_TEST_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
AL<WeightType> washington_test(int n, bool weighted = false) {
    const int max_weight = 100000;
    AL <WeightType> graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double>
                    weight(1, weighted ? max_weight : 1);
        graph.n = 3 * n + 3;
        graph.edges.resize(graph.n);
        graph.weight_vertex.resize(graph.n, 1);
        graph.weights.resize(graph.n);
        graph.edges[0].push_back(1);
        graph.weights[0].push_back(weight(generator));
        for (int i = 2; i < n + 2; ++i) {
            graph.edges[1].push_back(i);
            graph.weights[1].push_back(weight(generator));
        }
        for (int i = n + 2; i < 2 * n + 2; ++i) {
            graph.edges[i - n].push_back(i);
            graph.weights[i - n].push_back(weight(generator));
        }
        for (int i = n + 2; i < 2 * n + 2; ++i) {
            graph.edges[i].push_back(2 * n + 2);
            graph.weights[i].push_back(weight(generator));
        }
        for (int i = 2 * n + 3; i < 3 * n + 3; ++i) {
            graph.edges[i - 1].push_back(i);
            graph.weights[i - 1].push_back(weight(generator));
        }
    }
    catch (std::bad_alloc& ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

#endif  // MODULES_GENERATORS_INCLUDE_WASHINGTON_TEST_H_
