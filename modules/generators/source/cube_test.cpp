// Copyright [year] <Copyright Owner>
#include <random>
#include <utility>
#include <exception>
#include <iostream>
#include "../include/cube_test.h"
static const int max_weight = 100000;

AL cube_test(int n, bool weighted) {
    AL graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> weight(1, weighted ? max_weight : 1);
        graph.n = n * n * n;
        graph.edges.resize(graph.n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int vertex = i * n * n + j * n + k;
                    if (i != 0)
                        graph.edges[vertex].push_back({vertex - n * n,
                                    weight(generator)});
                    if (i != n - 1)
                        graph.edges[vertex].push_back({vertex + n * n,
                                    weight(generator)});
                    if (j != 0)
                        graph.edges[vertex].push_back({vertex - n,
                                    weight(generator)});
                    if (j != n - 1)
                        graph.edges[vertex].push_back({vertex + n,
                                    weight(generator)});
                    if (k != 0)
                        graph.edges[vertex].push_back({vertex - 1,
                                    weight(generator)});
                    if (k != n - 1)
                        graph.edges[vertex].push_back({vertex + 1,
                                    weight(generator)});
                }
            }
        }
    }
    catch (std::bad_alloc ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

