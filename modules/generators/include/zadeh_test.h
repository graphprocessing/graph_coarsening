// Copyright [year] <Copyright Owner>
#ifndef MODULES_GENERATORS_INCLUDE_ZADEH_TEST_H_
#define MODULES_GENERATORS_INCLUDE_ZADEH_TEST_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
AL<WeightType> zadeh_test(int n, bool weighted = false) {
    const int max_weight = 100000;
    AL <WeightType> graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double>
                    weight(1, weighted ? max_weight : 1);
        graph.n = 6*n+1;
        graph.edges.resize(6*n+1);
        graph.weights.resize(6*n+1);
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < 2*n; j++) {
                    graph.edges[i].push_back(3*n + 1 + j);
                    graph.weights[i].push_back(weight(generator));
                }
                graph.edges[i].push_back(i + 1);
                graph.weights[i].push_back(weight(generator));
            } else {
                for (int j = 0; j < 2*n; j++) {
                    graph.edges[i].push_back(n + 1 + j);
                    graph.weights[i].push_back(weight(generator));
                }
                graph.edges[i].push_back(i + 1);
                graph.weights[i].push_back(weight(generator));
            }
        }
        if (n % 2 == 0) {
            for (int j = 0; j < 2*n; j++) {
                graph.edges[n].push_back(3*n + 1 + j);
                graph.weights[n].push_back(weight(generator));
            }
        } else {
            for (int j = 0; j < 2*n; j++) {
                graph.edges[n].push_back(n + 1 + j);
                graph.weights[n].push_back(weight(generator));
            }
        }
        if (n > 0 && n % 2 == 0) {
            graph.edges[n].push_back(n + 1);
            graph.weights[n].push_back(weight(generator));
        }
        for (int i = n + 1; i <= 3*n; i++) {
            for (int j = 0; j < 2*n; j++) {
                graph.edges[i].push_back(3*n + 1 + j);
                graph.weights[i].push_back(weight(generator));
                graph.edges[3*n + 1 + j].push_back(i);
                graph.weights[3*n + 1 + j].push_back(weight(generator));
            }
            for (int k = 6*n - 1; k > 5*n; k -= 2) {
                graph.edges[i].push_back(k);
                graph.weights[i].push_back(weight(generator));
            }
        }
        for (int i = 3*n + 1; i <= 5*n; i++) {
            for (int k = 6*n; k > 5*n; k -= 2) {
                graph.edges[i].push_back(k);
                graph.weights[i].push_back(weight(generator));
            }
        }
        for (int i = 5*n; i < 6*n; i++) {
            graph.edges[i].push_back(i + 1);
            graph.weights[i].push_back(weight(generator));
        }
    }
    catch (std::bad_alloc ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

#endif  // MODULES_GENERATORS_INCLUDE_ZADEH_TEST_H_
