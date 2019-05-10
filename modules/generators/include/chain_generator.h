// Copyright [year] <Copyright Owner>
#ifndef MODULES_GENERATORS_INCLUDE_CHAIN_GENERATOR_H_
#define MODULES_GENERATORS_INCLUDE_CHAIN_GENERATOR_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
AL<WeightType> chain_generator(int chain_length, int cycle_vertexes,
                                bool weighted = false) {
    const int max_weight = 100000;
    AL <WeightType> graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double>
                    weight(1, weighted ? max_weight : 1);
        graph.n = cycle_vertexes * chain_length;
        graph.edges.resize(graph.n);
        graph.weights.resize(graph.n);
        graph.weight_vertex.resize(graph.n, 1);
        for (int i = 0, chains = 0; chains < chain_length;
                                    i += cycle_vertexes, ++chains) {
            for (int j = 0; j < cycle_vertexes - 1; ++j) {
                graph.edges[i + j].push_back(i + j + 1);
                graph.weights[i + j].push_back(weight(generator));
                graph.edges[i + j + 1].push_back(i + j);
                graph.weights[i + j + 1].push_back(weight(generator));
            }
            if (cycle_vertexes > 2) {
                graph.edges[i].push_back(i + cycle_vertexes - 1);
                graph.weights[i].push_back(weight(generator));
                graph.edges[i + cycle_vertexes - 1].push_back(i);
                graph.weights[i + cycle_vertexes - 1].push_back
                                            (weight(generator));
            }
            if (i != 0) {
                graph.edges[i].push_back(i - cycle_vertexes);
                graph.weights[i].push_back(weight(generator));
                graph.edges[i - cycle_vertexes].push_back(i);
                graph.weights[i - cycle_vertexes].push_back(weight(generator));
            }
        }
    }
    catch (std::bad_alloc& ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

#endif  // MODULES_GENERATORS_INCLUDE_CHAIN_GENERATOR_H_
