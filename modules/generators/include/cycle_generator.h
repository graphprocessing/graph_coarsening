// Copyright [year] <Copyright Owner>
#ifndef MODULES_GENERATORS_INCLUDE_CYCLE_GENERATOR_H_
#define MODULES_GENERATORS_INCLUDE_CYCLE_GENERATOR_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
AL<WeightType> cycle_generator(int n, bool weighted = false) {
    const int max_weight = 100000;
    AL <WeightType> graph;
    if (n <= 0)
        return graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double>
                    weight(1, weighted ? max_weight : 1);
        graph.n = n;
        graph.edges.resize(graph.n);
        graph.weights.resize(graph.n);
        graph.weight_vertex.resize(graph.n, 1);
        for (int i = 0; i < n - 1; ++i) {
            graph.edges[i].push_back(i + 1);
            graph.weights[i].push_back(weight(generator));
            graph.edges[i + 1].push_back(i);
            graph.weights[i + 1].push_back(weight(generator));
        }
        graph.edges[n - 1].push_back(0);
        graph.weights[n - 1].push_back(weight(generator));
        graph.edges[0].push_back(n - 1);
        graph.weights[0].push_back(weight(generator));
    }
    catch (std::bad_alloc& ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

#endif  // MODULES_GENERATORS_INCLUDE_CYCLE_GENERATOR_H_
