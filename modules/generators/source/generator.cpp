// Copyright [year] <Copyright Owner>
#include "../include/generator.h"
#include <random>
#include <utility>
#include <exception>
#include <iostream>
static const int max_weight = 1e5;

AL washington_test(int n, bool weighted) {
    AL graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> weight(1, weighted ? max_weight : 1);
        graph.n = 3 * n + 3;
        graph.edges.resize(graph.n);
        graph.edges[0].push_back({1, weight(generator)});
        for (int i = 2; i < n + 2; ++i)
            graph.edges[1].push_back({i, weight(generator)});
        for (int i = n + 2; i < 2 * n + 2; ++i)
            graph.edges[i - n].push_back({i, weight(generator)});
        for (int i = n + 2; i < 2 * n + 2; ++i)
            graph.edges[i].push_back({2 * n + 2, weight(generator)});
        for (int i = 2 * n + 3; i < 3 * n + 3; ++i)
            graph.edges[i - 1].push_back({i, weight(generator)});
    }
    catch (std::bad_alloc ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

AL zadeh_test(int n, bool weighted) {
    AL graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> weight(1, weighted ? max_weight : 1);
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
    }
    catch (std::bad_alloc ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}
