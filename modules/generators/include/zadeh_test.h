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
        graph.n = 6*n;
        graph.edges.resize(6*n);
        graph.weights.resize(6*n);
        graph.weight_vertex.resize(6*n, 1);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < 2*n; j++) {
                    graph.edges[i].push_back(n + j);
                    graph.weights[i].push_back(weight(generator));
                }
            } else {
                for (int j = 0; j < 2*n; j++) {
                    graph.edges[i].push_back(n + 2*n + j);
                    graph.weights[i].push_back(weight(generator));
                }
            }
        }

        for (int i = n; i < 3*n; i++) {
            for (int j = 0; j < 2*n; j++) {
                graph.edges[i].push_back(3*n + j);
                graph.weights[i].push_back(weight(generator));
            }
            for (int j = 5*n + 1; j < 6*n; j += 2) {
                graph.edges[i].push_back(j);
                graph.weights[i].push_back(weight(generator));
            }
        }
        for (int i = 3*n; i < 5*n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                graph.edges[i].push_back(n + j);
                graph.weights[i].push_back(weight(generator));
            }
            for (int j = 5*n; j < 6*n; j += 2) {
                graph.edges[i].push_back(j);
                graph.weights[i].push_back(weight(generator));
            }
        }
        for (int i = 0; i < 6*n - 1; i++) {
            bool f = false;
            for (unsigned j = 0; j < graph.edges[i].size(); j++) {
                int to = graph.edges[i][j];
                if ((to - i) == 1) f = true;
            }
            if (!f) {
                if ((i != (3*n - 1)) && (i != (5*n - 1))) {
                    if (i >= n && i < 5*n) {
                        graph.edges[i].push_back(i + 1);
                        graph.weights[i].push_back(weight(generator));
                        graph.edges[i + 1].push_back(i);
                        graph.weights[i + 1].push_back(weight(generator));
                    } else {
                        graph.edges[i].push_back(i + 1);
                        graph.weights[i].push_back(weight(generator));
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

#endif  // MODULES_GENERATORS_INCLUDE_ZADEH_TEST_H_
