// Copyright [year] <Copyright Owner>
#ifndef MODULES_GENERATORS_INCLUDE_STARS_GENERATOR_H_
#define MODULES_GENERATORS_INCLUDE_STARS_GENERATOR_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
AL<WeightType> stars_generator(int n, bool weighted = false) {
    const int max_weight = 100000;
    AL <WeightType> graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double>
                    weight(1, weighted ? max_weight : 1);
        graph.n = 6 * n;
        graph.edges.resize(graph.n);
        graph.weights.resize(graph.n);
        graph.weight_vertex.resize(graph.n, 1);
        for (int i = 0; i < graph.n; i += 6) {
            for (int j = 1; j < 6; ++j) {
                graph.edges[i].push_back(i + j);
                graph.weights[i].push_back(weight(generator));
                graph.edges[i + j].push_back(i);
                graph.weights[i + j].push_back(weight(generator));
            }
            if (i != 0) {
                graph.edges[i].push_back(i - 6);
                graph.weights[i].push_back(weight(generator));
                graph.edges[i - 6].push_back(i);
                graph.weights[i - 6].push_back(weight(generator));
            }
        }
    }
    catch (std::bad_alloc& ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

#endif  // MODULES_GENERATORS_INCLUDE_STARS_GENERATOR_H_
